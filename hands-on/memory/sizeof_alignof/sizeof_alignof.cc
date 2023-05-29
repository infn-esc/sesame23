#include <atomic>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <memory>
#include <typeinfo>
#include <vector>

// user-defined types

struct Mixed {
  int i;
  short s;
};

struct alignas(16) Wide {
  int i;
  short s;
};


// template function and macro to print type information

template <typename T>
void print_info(const char * type) {
  std::cout << "  sizeof(" << type << "): " << sizeof(T) << " bytes, alignof(" << type << "): " << alignof(T) << " bytes" << std::endl;
}

#define PRINT_INFO(TYPE)    print_info<TYPE>(#TYPE)


//

int main(void) {
  std::cout << "\ninteger types\n";
  PRINT_INFO(bool);
  PRINT_INFO(char);
  PRINT_INFO(short);
  PRINT_INFO(int);
  PRINT_INFO(long);
  PRINT_INFO(long long);
#if defined __x86_64__
  PRINT_INFO(__int128);
#else
  std::cout << "\n";
#endif

  std::cout << "\nother standard types\n";
  PRINT_INFO(size_t);
  PRINT_INFO(uintptr_t);
  PRINT_INFO(intptr_t);

  std::cout << "\nfloating point types\n";
  PRINT_INFO(float);
  PRINT_INFO(double);
  PRINT_INFO(long double);

  std::cout << "\npointer types\n";
  PRINT_INFO(void *);

  std::cout << "\nSTL types\n";
  PRINT_INFO(std::atomic_flag);
  PRINT_INFO(std::atomic_bool);
  PRINT_INFO(std::atomic_int);
  PRINT_INFO(std::chrono::nanoseconds);
  PRINT_INFO(std::vector<int>);
  PRINT_INFO(std::list<int>);
  PRINT_INFO(std::string);

  std::cout << "\nstructs\n";
  PRINT_INFO(Mixed);
  PRINT_INFO(Wide);

  std::cout << "\narrays\n";
  PRINT_INFO(int[4]);
  PRINT_INFO(double[4]);
  PRINT_INFO(Mixed[4]);
  PRINT_INFO(Wide[4]);

  std::cout << "\n";
}
