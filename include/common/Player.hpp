#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Input.hpp"

#include <string>
#include <ostream>

namespace tbgine {

  class Player {

  public:
    Player(const std::string &id, const std::string &name);
    // TODO move constructor
    virtual ~Player();
    
    const std::string &getID(void);
    const std::string &getName(void);
    int getOrder(void);

    void setName(const std::string &name);
    void setOrder(int order);
    
    // On this player's turn, prompt for user input
    virtual Input onTurn(void) = 0;
    
    friend std::ostream &operator<<(std::ostream &out, const Player &p);

  protected:
    std::string id_;   // player ID
    std::string name_; // display name
    int order_;        // player's order
    
  private:
    Player();
  
  }; // Player

} // tbgine

#endif /* PLAYER_HPP */
