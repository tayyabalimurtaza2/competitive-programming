#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <limits>

void Game::run() {
    mainMenu();
}

void Game::mainMenu() {
    int choice = 0;
    while (true) {
        std::cout << "\n=== RPG BATTLE ARENA ===\n";
        std::cout << "1. New Game\n";
        std::cout << "2. Load Game\n";
        std::cout << "3. Help\n";
        std::cout << "4. Quit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: newGame(); return;
            case 2: loadGame(); return;
            case 3: showHelp(); break;
            case 4: std::cout << "Goodbye!\n"; exit(0);
            default: std::cout << "Invalid choice.\n";
        }
    }
}

void Game::newGame() {
    std::string name;
    std::cout << "Enter your hero's name: ";
    std::cin >> name;
    player = std::make_unique<Character>(name);
    std::cout << "\nWelcome, " << name << "! Your adventure begins.\n";
    gameLoop();
}

void Game::loadGame() {
    player = SaveLoad::loadGame();
    if (player) {
        std::cout << "Game loaded successfully!\n";
        gameLoop();
    } else {
        std::cout << "No saved game found. Starting new game.\n";
        newGame();
    }
}

void Game::gameLoop() {
    running = true;
    while (running && player->isAlive()) {
        showStatus();
        std::cout << "\n1. Rest (recover HP/MP)\n";
        std::cout << "2. Search for enemy\n";
        std::cout << "3. Save game\n";
        std::cout << "4. Quit to menu\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                player->rest();
                break;
            case 2: {
                auto enemy = Enemy::createRandomEnemy(player->getLevel());
                battle(std::move(enemy));
                break;
            }
            case 3:
                saveCurrentGame();
                break;
            case 4:
                running = false;
                mainMenu();
                return;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    if (!player->isAlive()) {
        std::cout << "\nYou have been defeated... Game Over.\n";
        mainMenu();
    }
}

void Game::battle(std::unique_ptr<Enemy> enemy) {
    std::cout << "\n=== BATTLE ===\n";
    std::cout << "A " << enemy->getName() << " appears!\n";

    while (player->isAlive() && enemy->isAlive()) {
        std::cout << "\n" << player->getName() << " [HP: " << player->getHp()
                  << "/" << player->getMaxHp() << " MP: " << player->getMp()
                  << "/" << player->getMaxMp() << "]\n";
        std::cout << enemy->getName() << " [HP: " << enemy->getHp()
                  << "/" << enemy->getMaxHp() << "]\n";

        std::cout << "\nActions:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Use Skill\n";
        std::cout << "3. Use Item\n";
        std::cout << "4. Flee (50% chance)\n";
        std::cout << "Choice: ";

        int action;
        std::cin >> action;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        bool playerTurnDone = false;
        switch (action) {
            case 1:
                player->attack(*enemy);
                playerTurnDone = true;
                break;
            case 2: {
                player->listSkills();
                int idx;
                std::cout << "Select skill (0 to cancel): ";
                std::cin >> idx;
                if (idx > 0 && idx <= static_cast<int>(player->getSkills().size())) {
                    if (player->useSkill(idx - 1, *enemy)) {
                        playerTurnDone = true;
                    }
                }
                break;
            }
            case 3:
                player->getInventory().listItems();
                int itemIdx;
                std::cout << "Use item (0 to cancel): ";
                std::cin >> itemIdx;
                if (itemIdx > 0 && itemIdx <= player->getInventory().getSize()) {
                    player->useItem(itemIdx - 1);
                    playerTurnDone = true;
                }
                break;
            case 4:
                if (Utils::random(1, 100) <= 50) {
                    std::cout << "You fled successfully!\n";
                    return;
                } else {
                    std::cout << "Failed to flee!\n";
                    playerTurnDone = true;
                }
                break;
            default:
                std::cout << "Invalid action.\n";
        }

        if (playerTurnDone && enemy->isAlive()) {
            enemy->aiAction(*player);
        }

        if (!player->isAlive()) {
            std::cout << "You were slain by the " << enemy->getName() << "!\n";
            return;
        }
    }

    // Victory
    int expGain = enemy->getExpValue();
    int goldGain = enemy->getGoldValue();
    std::cout << "\nVictory! Gained " << expGain << " XP and " << goldGain << " gold.\n";
    player->addExp(expGain);
    player->addGold(goldGain);
    levelUpCheck();

    // Chance to drop a healing potion
    if (Utils::random(1, 100) <= 30) {
        player->getInventory().addItem(Item("Healing Potion", ItemType::HealingPotion));
        std::cout << "The enemy dropped a Healing Potion!\n";
    }
}

void Game::levelUpCheck() {
    while (player->getExp() >= player->getExpToNextLevel()) {
        player->levelUp();
        std::cout << "\n*** " << player->getName() << " reached level "
                  << player->getLevel() << "! ***\n";
        std::cout << "Max HP +" << player->getMaxHpBonus() << ", Max MP +"
                  << player->getMaxMpBonus() << ", Strength +"
                  << player->getStrBonus() << ", Agility +"
                  << player->getAgiBonus() << ", Intelligence +"
                  << player->getIntBonus() << "\n";
        player->restoreFull();
    }
}

void Game::showStatus() const {
    std::cout << "\n=== STATUS ===\n";
    std::cout << "Name: " << player->getName() << " (Level " << player->getLevel() << ")\n";
    std::cout << "HP: " << player->getHp() << "/" << player->getMaxHp() << "\n";
    std::cout << "MP: " << player->getMp() << "/" << player->getMaxMp() << "\n";
    std::cout << "XP: " << player->getExp() << "/" << player->getExpToNextLevel() << "\n";
    std::cout << "Gold: " << player->getGold() << "\n";
    std::cout << "Str: " << player->getStrength() << " Agi: "
              << player->getAgility() << " Int: " << player->getIntelligence() << "\n";
    std::cout << "Inventory: ";
    player->getInventory().listItemsShort();
}

void Game::saveCurrentGame() const {
    if (SaveLoad::saveGame(*player)) {
        std::cout << "Game saved.\n";
    } else {
        std::cout << "Save failed!\n";
    }
}

void Game::showHelp() const {
    std::cout << "\n=== HELP ===\n";
    std::cout << "- Combat is turn-based. Choose attack, skills, items, or flee.\n";
    std::cout << "- Skills cost MP and have cooldowns. Check your skill list.\n";
    std::cout << "- Healing Potions restore 30% of max HP.\n";
    std::cout << "- Resting at the camp recovers HP/MP but may invite enemies? (Not yet)\n";
    std::cout << "- Leveling up increases stats and fully restores you.\n";
    std::cout << "- Save your progress anytime from the main menu.\n";
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}