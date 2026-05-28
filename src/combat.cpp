// combat.cpp — implementacao de Combat
#include "combat.hpp"

#include <iostream>

Combat::Combat(Character& fighter_a, Character& fighter_b)
    : fighter_a_(fighter_a), fighter_b_(fighter_b), turn_(0) {
    std::cout << "Combat iniciado: " << fighter_a_.name()
              << " vs " << fighter_b_.name() << "\n";
}

Combat::~Combat() {
    // Agregacao: NAO destroi os Characters — eles existem fora do Combat
    std::cout << "~Combat destruido (lutadores preservados)\n";
}

int Combat::turn() const { return turn_; }

void Combat::run() {
    while (fighter_a_.is_alive() && fighter_b_.is_alive()) {
        ++turn_;
        std::cout << "-- Turno " << turn_ << " --\n";
        fighter_a_.attack_with_weapon(fighter_b_);
        if (!fighter_b_.is_alive()) break;
        fighter_b_.attack_with_weapon(fighter_a_);
    }

    if (!fighter_a_.is_alive() && !fighter_b_.is_alive()) {
        std::cout << "Resultado: empate.\n";
    } else if (fighter_a_.is_alive()) {
        std::cout << "Vencedor: " << fighter_a_.name() << "\n";
    } else {
        std::cout << "Vencedor: " << fighter_b_.name() << "\n";
    }
}
