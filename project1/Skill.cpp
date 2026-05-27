#include "Skill.h"
#include "Character.h"
#include "Utils.h"
#include <iostream>

Skill::Skill(const std::string& name, int manaCost, float modifier, SkillType type, int cooldownMax)
    : name(name), manaCost(manaCost), modifier(modifier), type(type), cooldownMax(cooldownMax) {}

void Skill::use(Character& user, Character& target) {
    if (type == SkillType::Heal) {
        int healAmount = static_cast<int>(user.getMaxHp() * modifier);
        if (healAmount == 0) healAmount = user.getMaxHp() * 0.3;
        user.heal(healAmount);
        std::cout << user.getName() << " uses " << name << " and heals " << healAmount << " HP.\n";
    } else {
        int damage = 0;
        if (type == SkillType::Physical) {
            damage = static_cast<int>((user.getStrength() * 2) * modifier);
        } else {
            damage = static_cast<int>((user.getIntelligence() * 2.5) * modifier);
        }
        damage = Utils::random(damage - 5, damage + 5);
        std::cout << user.getName() << " uses " << name << " for " << damage << " damage!\n";
        target.takeDamage(damage);
    }
}