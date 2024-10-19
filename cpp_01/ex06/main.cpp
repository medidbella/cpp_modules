#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int complain_index = -1;
    std::string complains_levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl_obj;

    for (int i = 0; i < 4; i++)
    {
        if (complains_levels[i] == av[1]){
            complain_index = i;
            break;
        }
    }
    switch (complain_index)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            for (;complain_index < 4; complain_index++)
                harl_obj.complain(complains_levels[complain_index]);
            return (0);
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return (0);
}
