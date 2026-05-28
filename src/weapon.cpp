// weapon.cpp — implementacao de Weapon
#include "weapon.hpp"

#include <iostream>
#include <utility>

Weapon::Weapon(std::string name, int damage, int durability)
    : name_(std::move(name)), damage_(damage), durability_(durability) {
    std::cout << "Weapon(" << name_ << ") criada\n";
}

Weapon::~Weapon() {
    std::cout << "~Weapon(" << name_ << ") destruido\n";
}

const std::string& Weapon::name() const { return name_; }
int Weapon::damage() const { return damage_; }
int Weapon::durability() const { return durability_; }

int Weapon::roll_damage() {
    // Arma quebrada: rende metade do dano nominal
    if (durability_ <= 0) {
        return damage_ / 2;
    }
    --durability_;
    return damage_;
}
