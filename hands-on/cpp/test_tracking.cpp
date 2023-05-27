#include "tracking.hpp"
#include <utility>

auto f(Tracking t)
{
  return Tracking{};
}

int main(int argc, char* argv[])
{
  Tracking t1;
  Tracking t2 = t1;
  t1 = std::move(t2);
  auto t3 = f(t1);
}