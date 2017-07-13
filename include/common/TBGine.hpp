#ifndef TBGINE_HPP
#define TBGINE_HPP

#include "common/Player.hpp"

#include <cstddef>
#include <memory> // shared_ptr
#include <set>

namespace tbgine {

  class TBGine {
    
  public:
    TBGine();
    TBGine(std::size_t maxPlayers);
    virtual ~TBGine();

    // Add a Player to the game
    // Duplicate Players are ignored
    void addPlayer(std::shared_ptr<Player> p);

    // Remove a Player from the game
    // No effect if Player is not in this game
    void removePlayer(std::shared_ptr<Player> p);
    
    // Run the engine and start game
    virtual void run(void);
    
  protected:
    static bool playerShPtrCmp(const std::shared_ptr<Player> &lhs,
                               const std::shared_ptr<Player> &rhs);
    
  private:
    std::size_t max_players_;
    std::set< std::shared_ptr<Player> > players_;
    
  }; // TBGine

}  // tbgine

#endif /* TBGINE_HPP */
