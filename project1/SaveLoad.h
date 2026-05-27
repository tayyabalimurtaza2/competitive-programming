#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "Character.h"
#include <memory>

class SaveLoad {
public:
    static bool saveGame(const Character& character);
    static std::unique_ptr<Character> loadGame();
};

#endif