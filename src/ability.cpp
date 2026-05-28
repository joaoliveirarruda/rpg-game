// ability.cpp — implementacao de Ability
#include "ability.hpp"

#include <iostream>
#include <utility>

#include "character.hpp"  // necessario para chamar Character::take_damage

Ability::Ability(std::string name, int mana_cost, int power)
    : name_(std::move(name)), mana_cost_(mana_cost), power_(power) {
    std::cout << "Ability(" << name_ << ") criada\n";
}

Ability::~Ability() {
    std::cout << "~Ability(" << name_ << ") destruido\n";
}

const std::string& Ability::name() const { return name_; }
int Ability::mana_cost() const { return mana_cost_; }
int Ability::power() const { return power_; }

void Ability::execute(Character& target) const {
    std::cout << "habilidade " << name_ << " (poder=" << power_ << ") ";
    target.take_damage(power_);
}
