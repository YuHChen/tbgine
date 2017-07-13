#include "common/TBGine.hpp"

#include <limits>

namespace tbgine {

  TBGine::TBGine() {
    players_ = std::set< std::shared_ptr<Player> > (&playerShPtrCmp);
    max_players_ = players_.max_size();
  }

  TBGine::TBGine(size_t maxPlayers) : TBGine() {
    max_players_(maxPlayers);
  }

  TBGine::~TBGine() { }

  void TBGine::addPlayer(std::shared_ptr<Player> p) {
    players_.push_back(p);
  }

  void TBGine::removePlayer(std::shared_ptr<Player> p) {
    players_.erase(p);
  }

  void TBGine::run(void) {
    for (auto iter = players_begin(); iter != players_.end(); ++iter) {
      iter->get()->onTurn();
    }
  }

  bool TBGine::playerShPtrCmp(const std::shared_ptr<Player> &lhs,
                              const std::shared_ptr<Player> &rhs) {
    return lhs.get()->getOrder() < rhs.get()->getOrder();
  }
  
}
