#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

namespace tbgine {

  class GameState {

  public:
    GameState();
    virtual ~GameState();

    // Render the current GameState
    virtual void render(void) = 0;

  protected:
    
    
  private:

    
  }; // GameState

}  // tbgine

#endif /* GAMESTATE_HPP */
