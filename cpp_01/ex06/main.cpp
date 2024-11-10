#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int complain_index = -1;
    std::string complain_levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl harl_obj;

    for (int i = 0; i < 4; i++)
    {
        if (complain_levels[i] == av[1]){
            complain_index = i;
            break;
        }
    }
    switch (complain_index)
    {
        case 0:
            std::cout << "[ "<< complain_levels[0] << " ]" << '\n';
            harl_obj.complain(complain_levels[0]);
            std::cout << '\n';
        case 1:
            std::cout << "[ "<< complain_levels[1] << " ]" << '\n';
            harl_obj.complain(complain_levels[1]);
            std::cout << '\n';
        case 2:
            std::cout << "[ "<< complain_levels[2] << " ]" << '\n';
            harl_obj.complain(complain_levels[2]);
            std::cout << '\n';
        case 3:
            std::cout << "[ "<< complain_levels[3] << " ]" << '\n';
            harl_obj.complain(complain_levels[3]);
            std::cout << '\n';
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return (0);
}
