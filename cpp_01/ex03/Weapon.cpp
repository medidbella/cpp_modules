#include "Weapon.hpp"

const std::string&  Weapon::getType(void){
    return (const std::string)type;
}

void Weapon::setType(std::string new_type){
    type = new_type;
}
Weapon::Weapon(std::string  weapon_name){
    type = weapon_name;
}