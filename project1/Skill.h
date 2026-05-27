#ifndef SKILL_H
#define SKILL_H

#include <string>

enum class SkillType { Physical, Magical, Heal };

class Character; // forward

class Skill {
public:
    Skill(const std::string& name, int manaCost, float modifier, SkillType type, int cooldownMax);

    std::string getName() const { return name; }
    int getManaCost() const { return manaCost; }
    int getCurrentCooldown() const { return currentCooldown; }
    int getCooldownMax() const { return cooldownMax; }

    void use(Character& user, Character& target);
    void startCooldown() { currentCooldown = cooldownMax; }
    void decrementCooldown() { if (currentCooldown > 0) currentCooldown--; }

private:
    std::string name;
    int manaCost;
    float modifier;
    SkillType type;
    int cooldownMax;
    int currentCooldown = 0;
};

#endif