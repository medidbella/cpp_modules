#include "Harl.hpp"

int main()
{
    std::string complains_levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl_obj;

    for (int i = 0; i < 4; i++)
        harl_obj.complain(complains_levels[i]);
    harl_obj.complain("none");
    return (0);
}
