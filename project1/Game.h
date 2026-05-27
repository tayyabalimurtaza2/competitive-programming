#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"
#include "SaveLoad.h"
#include <memory>
#include <vector>

class Game {
public:
    void run();

private:
    std::unique_ptr<Character> player;
    bool running = false;

    void mainMenu();
    void newGame();
    void loadGame();
    void gameLoop();
    void battle(std::unique_ptr<Enemy> enemy);
    void levelUpCheck();
    void showStatus() const;
    void saveCurrentGame() const;
    void showHelp() const;
};

#endif