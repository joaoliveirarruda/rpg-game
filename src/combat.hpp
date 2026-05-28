// combat.hpp — arena de combate por turnos (agregacao de Characters)
#pragma once

#include "character.hpp"

class Combat {
public:
    // Recebe referencias: agregacao — Combat NAO possui os Characters.
    Combat(Character& fighter_a, Character& fighter_b);
    ~Combat();

    int turn() const;

    // Executa o combate ate alguem cair; imprime o vencedor.
    void run();

private:
    Character& fighter_a_;
    Character& fighter_b_;
    int turn_;
};
