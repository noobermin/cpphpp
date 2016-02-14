#include "xrange.hpp"
#include <iostream>
using namespace cpphpp;

int main(){
  auto start=45.02, end=45.01, step=-1e-3,
    check = start;
  bool success=true;
  for (auto i: xrange(start, end, step)) {
    std::cout
      << "(" << i << "==" << check
      << ")=="
      << ((success = (success && i == check)) ? "true" : "false")
      << std::endl;
    check += step;
  }
  return success ? 0 : -1;
}
