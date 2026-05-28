// inventory.cpp — implementacao de Inventory
#include "inventory.hpp"

#include <iostream>
#include <utility>

Inventory::Inventory(std::string owner_name)
    : owner_name_(std::move(owner_name)) {
    std::cout << "Inventory(" << owner_name_ << ") criado\n";
}

Inventory::~Inventory() {
    // As armas (unique_ptr) serao destruidas automaticamente em seguida
    std::cout << "~Inventory(" << owner_name_ << ") destruido\n";
}

const std::string& Inventory::owner_name() const { return owner_name_; }
std::size_t Inventory::size() const { return weapons_.size(); }

void Inventory::add_weapon(std::unique_ptr<Weapon> weapon) {
    weapons_.push_back(std::move(weapon));
}

Weapon* Inventory::strongest_weapon() const {
    if (weapons_.empty()) {
        return nullptr;
    }
    Weapon* best = weapons_.front().get();
    for (const auto& w : weapons_) {
        if (w->damage() > best->damage()) {
            best = w.get();
        }
    }
    return best;
}
