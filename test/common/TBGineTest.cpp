#include "common/TBGine.hpp"

#include <cassert>
#include <iostream>

class BasicTBGine : public tbgine::TBGine {
public:
  BasicTBGine() { }
  ~BasicTBGine() { }
};

int main() {
  {
    tbgine::TBGine *engine1 = new BasicTBGine();
    engine1->run();
    delete engine1;
  }
  
  return 0;
}
