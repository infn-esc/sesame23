#include <atomic>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <memory>
#include <typeinfo>
#include <vector>

#include <cxxabi.h>

template <typename T>
class c_buffer {

public:
  c_buffer(T * b) :
    buffer(b) 
  { }

  ~c_buffer() {
    free((void *) buffer);
    buffer = 0;
  }

  T & operator*() {
    return * buffer;
  }

  T * operator->() {
    return buffer;
  }

private:
  T * buffer;
};

template <typename T>
void print_size(const char * type) {
  std::cout << "sizeof(" << type << "): " << sizeof(T) << " bytes, alignof(" << type << "): " << alignof(T) << " bytes" << std::endl;
}

template <typename T>
void print_size(void) {
  int status;
  const char * type = c_buffer<const char>( abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) ).operator->();
  print_size<T>(type);
}

#define PRINT_SIZE(TYPE)    print_size<TYPE>(#TYPE)

struct XYZ {
  float x;
  float y;
  float z;
};


int main(void) {
  std::cout << "\ninteger types\n";
  PRINT_SIZE(bool);
  PRINT_SIZE(char);
  PRINT_SIZE(short);
  PRINT_SIZE(int);
  PRINT_SIZE(long);
  PRINT_SIZE(long long);
#if defined __x86_64__
  PRINT_SIZE(__int128);
#else
  std::cout << "\n";
#endif

  std::cout << "\nother standard types\n";
  PRINT_SIZE(size_t);
  PRINT_SIZE(uintptr_t);
  PRINT_SIZE(intptr_t);

  std::cout << "\nfloating point types\n";
  PRINT_SIZE(float);
  PRINT_SIZE(double);
  PRINT_SIZE(long double);

  std::cout << "\npointer types\n";
  PRINT_SIZE(void *);

  std::cout << "\nSTL types\n";
  PRINT_SIZE(std::atomic_flag);
  PRINT_SIZE(std::atomic_bool);
  PRINT_SIZE(std::atomic_int);
  PRINT_SIZE(std::chrono::nanoseconds);
  PRINT_SIZE(std::vector<int>);
  PRINT_SIZE(std::list<int>);
  PRINT_SIZE(std::string);

  std::cout << "\nstructs\n";
  PRINT_SIZE(XYZ);

  std::cout << "\narrays\n";
  PRINT_SIZE(int[4]);
  PRINT_SIZE(XYZ[4]);

  std::cout << "\n";
}
