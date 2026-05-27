#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

bool Inventory::removeItem(int index) {
    if (index < 0 || index >= static_cast<int>(items.size())) return false;
    items.erase(items.begin() + index);
    return true;
}

Item Inventory::getItem(int index) const {
    if (index < 0 || index >= static_cast<int>(items.size())) return Item("", ItemType::HealingPotion, 0);
    return items[index];
}

void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i+1 << ". " << items[i].name;
        if (items[i].type == ItemType::HealingPotion)
            std::cout << " (restores " << items[i].value << "% HP)";
        std::cout << "\n";
    }
}

void Inventory::listItemsShort() const {
    if (items.empty()) {
        std::cout << "empty\n";
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << items[i].name;
        if (i != items.size()-1) std::cout << ", ";
    }
    std::cout << "\n";
}