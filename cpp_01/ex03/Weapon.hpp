#include <string>

class Weapon{
    private:
        std::string type;
    public:
        const std::string&  getType(void) const;
        void setType(std::string new_type);
};
