// character.hpp — personagem com HP, atributos, inventario e habilidades
#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "ability.hpp"
#include "inventory.hpp"
#include "weapon.hpp"

class Character {
public:
    Character(std::string name, int hp, int attack, int defense);
    ~Character();

    // Getters const
    const std::string& name() const;
    int hp() const;
    int max_hp() const;
    int attack() const;
    int defense() const;
    bool is_alive() const;

    // Aplica dano: dano efetivo = max(raw_damage - defense_, 1).
    // Caso limite: se ja estiver morto, ignora.
    void take_damage(int raw_damage);

    // Ataca o alvo usando a arma mais forte; sem arma, usa attack_ base.
    void attack_with_weapon(Character& target);

    // Conjura a habilidade de indice idx no alvo. Indice invalido: ignora.
    void cast_ability(std::size_t idx, Character& target);

    // Helpers para popular o personagem
    void add_weapon(std::unique_ptr<Weapon> weapon);
    void add_ability(std::unique_ptr<Ability> ability);

    // Imprime status no terminal
    void print_status() const;

private:
    std::string name_;
    int hp_;
    int max_hp_;
    int attack_;
    int defense_;
    std::unique_ptr<Inventory> inventory_;
    std::vector<std::unique_ptr<Ability>> abilities_;
};
