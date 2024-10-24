#include "Weapon.hpp"
#include <iostream>
const std::string&  Weapon::getType(void){
    return type;
}

void Weapon::setType(std::string new_type){
    type = new_type;
}

Weapon::Weapon(std::string  weapon_name){
    std::cout << "new weapon\n";
    type = weapon_name;
}