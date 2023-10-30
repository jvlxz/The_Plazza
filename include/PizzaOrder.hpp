/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** PizzaOrder.hpp
*/

#pragma once

#include <iostream>
#include <map>
#include <vector>

enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};

const std::map<std::string, PizzaType> PIZZA_TYPES = {{"regina", PizzaType::Regina},
                                                      {"margarita", PizzaType::Margarita},
                                                      {"americana", PizzaType::Americana},
                                                      {"fantasia", PizzaType::Fantasia}};

const std::map<std::string, PizzaSize> PIZZA_SIZES = {{"S", PizzaSize::S},
                                                      {"M", PizzaSize::M},
                                                      {"L", PizzaSize::L},
                                                      {"XL", PizzaSize::XL},
                                                      {"XXL", PizzaSize::XXL}};

using std::size_t;

class PizzaOrder {
  private:
    size_t _orderId{};
    size_t _clientId{};
    size_t _totalPizzasOrdered{};
    size_t _pizzaOrderIndex{};
    PizzaType _type;
    PizzaSize _size;

    std::map<std::string, int> _ingredients;
    float _bakingTime = 0;
    float _timeMultiplier = 0;

  public:
    // ! Constructors:

    PizzaOrder() = default;

    /**
    ** @brief Construct a new Pizza Order object
    ** @param orderId
    ** @param clientId
    ** @param totalPizzasOrdered : total number of pizzas ordered by the client
    ** @param pizzaOrderIndex : index of the pizza in the order
    ** @param type : type of the pizza (Regina, Margarita, Americana, Fantasia)
    ** @param size : size of the pizza (S, M, L, XL, XXL)
    ** @param timeMultiplier
    **/
    PizzaOrder(size_t orderId, size_t clientId, size_t totalPizzasOrdered, size_t pizzaOrderIndex,
               PizzaType type, PizzaSize size, float timeMultiplier);

    virtual ~PizzaOrder() = default;

    // ! Getters:

    [[nodiscard]] size_t getOrderId() const;
    [[nodiscard]] size_t getClientId() const;
    [[nodiscard]] size_t getTotalPizzasOrdered() const;
    [[nodiscard]] size_t getPizzaOrderIndex() const;
    [[nodiscard]] PizzaType getType() const;
    [[nodiscard]] std::string getTypeString() const;
    [[nodiscard]] PizzaSize getSize() const;
    [[nodiscard]] std::string getSizeString() const;
    [[nodiscard]] float getBakingTime() const;

    // ! Set ingredients based on pizza type

    void setIngredients();
    void setBakingTime();
    std::map<std::string, int> getIngredients();
    [[nodiscard]] float getTimeMultiplier() const;

    // ! Overloads for stream operators:

    /**
    ** @brief Overload of the << operator (pack)
    ** @param os The output stream
    ** @param order The order to display
    ** @return The output stream : PizzaOrderRequest orderId clientId totalPizzasOrdered pizzaOrderIndex type size timeMultiplier
    **/
    friend std::ostream& operator<<(std::ostream& os, const PizzaOrder& order);

    /**
    ** @brief Overload of the >> operator (unpack)
    ** @param is The input stream
    ** @param order The order to fill
    ** @return The input stream
    **/
    friend std::istream& operator>>(std::istream& is, PizzaOrder& order);
};

PizzaSize getPizzaSizeFromString(const std::string& pizzaSizeStr);
PizzaType getPizzaTypeFromString(const std::string& pizzaTypeStr);
