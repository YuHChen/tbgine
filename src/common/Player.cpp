#include "common/Player.hpp"

namespace tbgine {

  Player::Player() : id_("007"), name_("James"), order_(0) { }
  
  Player::Player(const std::string &id, const std::string &name)
    : id_(id), name_(name), order_(0) { }

  Player::~Player() { }
  
  const std::string &Player::getID(void) { return id_; }
  const std::string &Player::getName(void) { return name_; }
  int Player::getOrder(void) { return order_; }
  
  void Player::setName(const std::string &name) { name_ = name; }
  void Player::setOrder(int order) { order_ = order; }
  
  std::ostream &operator<<(std::ostream &out, const Player &p) {
    out << "Player " << p.order_ << ": "
        << p.name_ << "(" << p.id_ << ")";
    return out;
  }
}
