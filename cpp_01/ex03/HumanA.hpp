#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA{
    private:
        Weapon      &used_weapon;
        std::string name;
    public:
        HumanA(std::string new_name, Weapon &new_weapon);
        void attack(void);
};

#endif