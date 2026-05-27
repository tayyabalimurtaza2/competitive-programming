#include "SaveLoad.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>

bool SaveLoad::saveGame(const Character& c) {
    std::ofstream file("savegame.dat", std::ios::binary);
    if (!file) return false;

    // Write basic stats
    auto write = [&file](const auto& data) { file.write(reinterpret_cast<const char*>(&data), sizeof(data)); };
    std::string name = c.getName();
    size_t len = name.size();
    write(len);
    file.write(name.c_str(), len);
    write(c.getLevel());
    write(c.getHp());
    write(c.getMp());
    write(c.getExp());
    write(c.getGold());
    write(c.getStrength());
    write(c.getAgility());
    write(c.getIntelligence());
    write(c.getDefense());

    // Inventory
    int invSize = c.getInventory().getSize();
    write(invSize);
    for (int i = 0; i < invSize; ++i) {
        Item item = c.getInventory().getItem(i);
        len = item.name.size();
        write(len);
        file.write(item.name.c_str(), len);
        int type = static_cast<int>(item.type);
        write(type);
        write(item.value);
    }
    return true;
}

std::unique_ptr<Character> SaveLoad::loadGame() {
    std::ifstream file("savegame.dat", std::ios::binary);
    if (!file) return nullptr;

    auto read = [&file](auto& data) { file.read(reinterpret_cast<char*>(&data), sizeof(data)); };
    size_t len;
    read(len);
    std::string name(len, ' ');
    file.read(&name[0], len);
    auto c = std::make_unique<Character>(name);
    int val;
    read(val); c->setLevel(val);
    read(val); c->setHp(val);
    read(val); c->setMp(val);
    read(val); c->setExp(val);
    read(val); c->setGold(val);
    read(val); c->setStrength(val);
    read(val); c->setAgility(val);
    read(val); c->setIntelligence(val);
    read(val); c->setDefense(val);

    int invSize;
    read(invSize);
    for (int i = 0; i < invSize; ++i) {
        read(len);
        std::string itemName(len, ' ');
        file.read(&itemName[0], len);
        int typeInt;
        read(typeInt);
        int value;
        read(value);
        c->getInventory().addItem(Item(itemName, static_cast<ItemType>(typeInt), value));
    }
    return c;
}