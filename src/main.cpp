// main.cpp — demonstracao do sistema de combate RPG
#include <iostream>
#include <memory>

#include "ability.hpp"
#include "character.hpp"
#include "combat.hpp"
#include "weapon.hpp"

int main() {
    std::cout << "=== Cena 1: composicao (ciclo de vida em bloco) ===\n";
    {
        Character hero("Aria", 100, 20, 5);
        hero.add_weapon(std::make_unique<Weapon>("Espada Longa", 15, 10));
        hero.add_weapon(std::make_unique<Weapon>("Adaga", 8, 20));
        hero.add_ability(std::make_unique<Ability>("Golpe Flamejante", 10, 25));
        hero.print_status();
    }
    std::cout << "Fora do bloco — todos os recursos foram liberados.\n";

    return 0;
}
