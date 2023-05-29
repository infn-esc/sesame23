#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <sys/types.h>
#include <unistd.h>

const char* suffix(int i) {
  if (i > 100) {
    i = i % 100;
  }
  if (i > 20) {
    i = i % 10;
  }
  if (i == 1) {
    return "st";
  }
  if (i == 2) {
    return "nd";
  }
  if (i == 3) {
    return "rd";
  }
  return "th";
}

void pause_and_continue(void) {
  usleep(1000000);
  return;
}

// Arbitrary value
constexpr const int ARRAY_SIZE = 3 * 1024 * 102;
constexpr const int STEPS = 10;

void allocate_step(char* a[STEPS][ARRAY_SIZE], int step) {
  char** p = a[step];
  // malloc in small chunks such that we are always below the mmap threshold for these allocations.
  int mallocSize = 16 * 1024;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    // allocate a random amount between 0 and 16k
    int size = std::rand() % mallocSize;
    p[i] = (char*)malloc(size);
    // Write something to make sure the page is backed by physical RAM
    *p[i] = 'a';
  }
  printf("The %d%s block of %d 5KB chunks has been allocated\n", step + 1, suffix(step + 1), ARRAY_SIZE);
}

void free_step(char* a[STEPS][ARRAY_SIZE], int step) {
  char** p = a[step];
  for (int i = 0; i < ARRAY_SIZE; i++) {
    free(p[i]);
  }
  printf("The %d%s block of %d 5KB chunks has been freed\n", step + 1, suffix(step + 1), ARRAY_SIZE);
}

int main() {
  // initialise the random number seed to a fixed value, to generate a reproducible sequence
  std::srand(99351533);

  printf("Hello!  This program will fragment its process heap.  Run top -p %d to follow along!\n", getpid());
  pause_and_continue();

  // Because we're asking for a large size at the get-go, the backing memory for these arrays will be mmap'd.  But the pointers stored here will be for
  // small allocations that we expect to be brk()'d.  We keep the mapping so we can free them later.
  auto p = (char*(*)[ARRAY_SIZE])malloc(sizeof(char* [STEPS][ARRAY_SIZE]));

  // -------------------------------------

  for (int step = 0; step < STEPS; ++step) {
    // malloc in small chunks such that we are always below the mmap threshold for these allocations.
    allocate_step(p, step);
    pause_and_continue();

    // free the allocations
    free_step(p, step);
    pause_and_continue();
  }

  // -------------------------------------

  // malloc in small chunks such that we are always below the mmap threshold for these allocations.
  allocate_step(p, 0);
  pause_and_continue();

  for (int step = 1; step < STEPS; ++step) {
    // malloc in small chunks such that we are always below the mmap threshold for these allocations.
    allocate_step(p, step);
    pause_and_continue();

    // free the allocations
    free_step(p, step - 1);
    pause_and_continue();
  }

  // free the allocations
  free_step(p, STEPS - 1);
  pause_and_continue();

  // -------------------------------------

  free(p);

  return 0;
}
