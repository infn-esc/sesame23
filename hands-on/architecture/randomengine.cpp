#include <random>
#include <iostream>

int main(){


  std::mt19937 engine;
  std::uniform_int_distribution<> uniformDist(0,256);

  auto a = uniformDist;
  auto b = uniformDist;
  auto& c = uniformDist;

  auto e = engine;
  auto f = engine;
  auto& g = engine;
    for( int i = 0; i< 10; i++)
    {
        std::cout << a(engine) << std::endl;
        std::cout << b(engine) << std::endl;
        std::cout << c(engine) << std::endl;
        std::cout << uniformDist(e) << std::endl;
        std::cout << uniformDist(f) << std::endl;
        std::cout << uniformDist(g) << std::endl;

    }

}