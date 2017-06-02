#include "common/GameState.hpp"

#include <cassert>
#include <iostream>

class BasicGameState : public tbgine::GameState {
public:
  BasicGameState() {
    board[0] = '7'; board[1] = '8'; board[2] = '9';
    board[3] = '4'; board[4] = '5'; board[5] = '6';
    board[6] = '1'; board[7] = '2'; board[8] = '3';
  }
  void render(void) {
    for (int i = 0; i < 6; i += 3) {
      for (int j = 0; j < 2; j++) {
        std::cout << " " << board[i+j] << " |";
      }
      std::cout << " " << board[i+2] << std::endl;
      std::cout << "---+---+---" << std::endl;
    }
    for (int i = 6; i < 8; i++) {
      std::cout << " " << board[i] << " |";
    }
    std::cout << " " << board[8] << std::endl;
  }
private:
  char board[9];
};

int main() {
  {
    tbgine::GameState *gs1 = new BasicGameState();
    gs1->render();
    delete gs1;
  }
}
