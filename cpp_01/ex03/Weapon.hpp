#include <string>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(std::string new_type);
        const std::string&  getType(void);
        void setType(std::string  weapon_name);
};
