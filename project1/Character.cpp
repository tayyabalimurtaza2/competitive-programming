#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.h"
#include "Skill.h"
#include <string>
#include <vector>
#include <memory>

class Enemy; // forward declaration

class Character {
public:
    Character(const std::string& name);
    virtual ~Character() = default;

    // Stats
    std::string getName() const { return name; }
    int getLevel() const { return level; }
    int getHp() const { return hp; }
    int getMaxHp() const { return maxHp; }
    int getMp() const { return mp; }
    int getMaxMp() const { return maxMp; }
    int getExp() const { return exp; }
    int getExpToNextLevel() const { return expToNext; }
    int getGold() const { return gold; }
    int getStrength() const { return strength; }
    int getAgility() const { return agility; }
    int getIntelligence() const { return intelligence; }
    int getDefense() const { return defense; }

    // For level up messages
    int getMaxHpBonus() const { return maxHpBonus; }
    int getMaxMpBonus() const { return maxMpBonus; }
    int getStrBonus() const { return strBonus; }
    int getAgiBonus() const { return agiBonus; }
    int getIntBonus() const { return intBonus; }

    bool isAlive() const { return hp > 0; }
    void takeDamage(int damage);
    void heal(int amount);
    void restoreMp(int amount);
    void restoreFull();
    void rest();

    void attack(Character& target);
    virtual void addExp(int amount);
    void addGold(int amount);
    void levelUp();

    Inventory& getInventory() { return inventory; }
    const std::vector<Skill>& getSkills() const { return skills; }
    void listSkills() const;
    bool useSkill(int index, Character& target);
    void useItem(int index);

    // Setters for save/load
    void setLevel(int lvl) { level = lvl; }
    void setHp(int h) { hp = h; }
    void setMp(int m) { mp = m; }
    void setExp(int e) { exp = e; }
    void setGold(int g) { gold = g; }
    void setStrength(int s) { strength = s; }
    void setAgility(int a) { agility = a; }
    void setIntelligence(int i) { intelligence = i; }
    void setDefense(int d) { defense = d; }

protected:
    std::string name;
    int level = 1;
    int hp = 100, maxHp = 100;
    int mp = 50, maxMp = 50;
    int exp = 0, expToNext = 100;
    int gold = 100;
    int strength = 15;
    int agility = 10;
    int intelligence = 10;
    int defense = 5;

    Inventory inventory;
    std::vector<Skill> skills;

    // Bonuses for level up display
    int maxHpBonus = 0, maxMpBonus = 0, strBonus = 0, agiBonus = 0, intBonus = 0;

    void initSkills();
    virtual int calculateDamage() const;
    int calculateDefense() const { return defense; }
};

#endif