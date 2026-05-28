// inventory.hpp — mochila de armas (composicao de Weapon)
#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "weapon.hpp"

class Inventory {
public:
    explicit Inventory(std::string owner_name);
    ~Inventory();

    // Getters const
    const std::string& owner_name() const;
    std::size_t size() const;

    // Recebe posse exclusiva da arma.
    void add_weapon(std::unique_ptr<Weapon> weapon);

    // Retorna ponteiro nao-owning para a arma de maior dano,
    // ou nullptr se o inventario estiver vazio.
    Weapon* strongest_weapon() const;

private:
    std::string owner_name_;
    std::vector<std::unique_ptr<Weapon>> weapons_;
};
