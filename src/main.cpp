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

    std::cout << "\n=== Cena 3: casos limite ===\n";

    // Dano cru menor que defesa: dano efetivo deve ser 1 (nao zero, nao negativo)
    Character armored("Fortaleza", 50, 5, 100);
    armored.take_damage(3);

    // Personagem sem armas: ataque usa attack_ base
    Character bare("Mendigo", 40, 7, 1);
    Character dummy("Alvo", 20, 0, 0);
    bare.attack_with_weapon(dummy);

    // Atacar alvo ja caido: take_damage retorna sem efeito
    dummy.take_damage(1000);  // mata o alvo
    bare.attack_with_weapon(dummy);

    // Habilidade com indice invalido: cast_ability ignora
    bare.cast_ability(99, dummy);

    return 0;
}
