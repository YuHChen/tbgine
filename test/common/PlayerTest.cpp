#include "common/Player.hpp"
#include "common/Input.hpp"

#include <cassert>
#include <iostream>

class BasicPlayer : public boardio::Player {
public:
  BasicPlayer(const std::string &id, const std::string &name)
    : boardio::Player(id, name) { }

  boardio::Input onTurn(void) {
    return boardio::Input();
  }
};

int main() {
  {
    std::string id = "700";
    std::string name = "Bond";
    boardio::Player* p1 = new BasicPlayer(id, name);
    std::cout << *p1 << std::endl;
    delete p1;
  }
}
