// character.cpp — implementacao de Character
#include "character.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

Character::Character(std::string name, int hp, int attack, int defense)
    : name_(std::move(name)),
      hp_(hp),
      max_hp_(hp),
      attack_(attack),
      defense_(defense),
      inventory_(std::make_unique<Inventory>(name_)) {
    std::cout << "Character(" << name_ << ") criado\n";
}

Character::~Character() {
    // Inventory e abilities serao destruidos automaticamente em seguida
    std::cout << "~Character(" << name_ << ") destruido\n";
}

const std::string& Character::name() const { return name_; }
int Character::hp() const { return hp_; }
int Character::max_hp() const { return max_hp_; }
int Character::attack() const { return attack_; }
int Character::defense() const { return defense_; }
bool Character::is_alive() const { return hp_ > 0; }

void Character::take_damage(int raw_damage) {
    // Personagem morto nao sofre mais dano
    if (!is_alive()) {
        std::cout << name_ << " ja esta caido — ignora dano\n";
        return;
    }
    // Defesa nunca anula completamente: minimo 1 de dano
    int effective = std::max(raw_damage - defense_, 1);
    hp_ = std::max(hp_ - effective, 0);
    std::cout << name_ << " sofreu " << effective
              << " de dano (HP=" << hp_ << "/" << max_hp_ << ")\n";
}

void Character::attack_with_weapon(Character& target) {
    Weapon* w = inventory_->strongest_weapon();
    int dmg = w ? w->roll_damage() : attack_;
    std::cout << name_ << " ataca " << target.name()
              << " com " << (w ? w->name() : std::string("punhos"))
              << " (dano=" << dmg << ")\n";
    target.take_damage(dmg);
}

void Character::cast_ability(std::size_t idx, Character& target) {
    if (idx >= abilities_.size()) {
        std::cout << name_ << " nao tem habilidade no indice " << idx << "\n";
        return;
    }
    std::cout << name_ << " conjura ";
    abilities_[idx]->execute(target);
}

void Character::add_weapon(std::unique_ptr<Weapon> weapon) {
    inventory_->add_weapon(std::move(weapon));
}

void Character::add_ability(std::unique_ptr<Ability> ability) {
    abilities_.push_back(std::move(ability));
}

void Character::print_status() const {
    std::cout << "[" << name_ << "] HP=" << hp_ << "/" << max_hp_
              << " ATK=" << attack_ << " DEF=" << defense_
              << " armas=" << inventory_->size()
              << " habilidades=" << abilities_.size() << "\n";
}
