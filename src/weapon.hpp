// weapon.hpp — arma equipavel com dano e durabilidade
#pragma once

#include <string>

class Weapon {
public:
    Weapon(std::string name, int damage, int durability);
    ~Weapon();

    // Getters const
    const std::string& name() const;
    int damage() const;
    int durability() const;

    // Retorna o dano corrente e consome 1 ponto de durabilidade.
    // Se a arma estiver quebrada (durabilidade 0), retorna metade do dano.
    int roll_damage();

private:
    std::string name_;
    int damage_;
    int durability_;
};
