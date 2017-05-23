#include "common/Player.hpp"

namespace boardio {

  Player::Player() : id_("007"), name_("James") { }
  
  Player::Player(const std::string &id, const std::string &name)
    : id_(id), name_(name) { }

  Player::~Player() { }
  
  const std::string &Player::getID(void) { return id_; }
  const std::string &Player::getName(void) { return name_; }
  void Player::setName(const std::string &name) { name_ = name; }

  std::ostream &operator<<(std::ostream &out, const Player &p) {
    out << p.id_ << " " << p.name_;
    return out;
  }
}
