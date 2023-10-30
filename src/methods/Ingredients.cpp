/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Ingredients.cpp
*/

#include "Ingredients.hpp"
#include <algorithm>
#include <sstream>
#include "Plazza.hpp"

Ingredients::Ingredients()
{
    initialize_stock();
}

void Ingredients::initialize_stock()
{
    _stock["doe"] = 5;
    _stock["tomato"] = 5;
    _stock["gruyere"] = 5;
    _stock["ham"] = 5;
    _stock["mushrooms"] = 5;
    _stock["steak"] = 5;
    _stock["eggplant"] = 5;
    _stock["goat_cheese"] = 5;
    _stock["chief_love"] = 5;
}

std::string Ingredients::getTotalStock() const
{
    size_t stock = 0;

    for (const auto& [ingredient, count] : _stock) {
        stock += count;
    }

    std::stringstream ss;
    ss << stock;

    return ss.str();
}

void Ingredients::addIngredient(const std::string& ingredient, int amount)
{
    _stock[ingredient] = std::min(_stock[ingredient] + amount, 5);
}

bool Ingredients::removeIngredient(const std::string& ingredient, int amount)
{
    if (_stock[ingredient] >= amount) {
        _stock[ingredient] -= amount;
        return true;
    }
    return false;
}

void Ingredients::printStock()
{
    for (const auto& [ingredient, count] : _stock) {
        std::stringstream ss;
        ss << ingredient << "=" << count << "\n";
        std::cout << ss.str();
    }
}

bool Ingredients::isStockEmpty() const
{
    return std::ranges::all_of(_stock, [](const auto& pair) { return pair.second == 0; });
}
