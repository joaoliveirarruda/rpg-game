// ability.hpp — habilidade especial usada por um Character
#pragma once

#include <string>

class Character;  // forward declaration: ability.cpp incluira o header completo

class Ability {
public:
    Ability(std::string name, int mana_cost, int power);
    ~Ability();

    // Getters const
    const std::string& name() const;
    int mana_cost() const;
    int power() const;

    // Aplica a habilidade no alvo (causa power_ de dano).
    void execute(Character& target) const;

private:
    std::string name_;
    int mana_cost_;
    int power_;
};
