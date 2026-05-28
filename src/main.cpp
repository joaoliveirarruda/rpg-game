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

    std::cout << "\n=== Cena 2: agregacao (Combat referencia Characters) ===\n";
    Character knight("Galahad", 80, 18, 8);
    knight.add_weapon(std::make_unique<Weapon>("Mangual", 12, 15));
    Character goblin("Grunk", 50, 10, 3);
    goblin.add_weapon(std::make_unique<Weapon>("Adaga Enferrujada", 6, 5));
    {
        Combat arena(knight, goblin);
        arena.run();
    }
    std::cout << "Combat destruido. Status dos lutadores (preservados):\n";
    knight.print_status();
    goblin.print_status();

    return 0;
}
