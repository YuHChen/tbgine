#include "common/Player.hpp"
#include "common/Input.hpp"

#include <cassert>
#include <iostream>

class BasicPlayer : public tbgine::Player {
public:
  BasicPlayer(const std::string &id, const std::string &name)
    : tbgine::Player(id, name) { }

  tbgine::Input onTurn(void) {
    return tbgine::Input();
  }
};

int main() {
  {
    std::string id = "700";
    std::string name = "Bond";
    tbgine::Player* p1 = new BasicPlayer(id, name);
    std::cout << *p1 << std::endl;
    delete p1;
  }
}
