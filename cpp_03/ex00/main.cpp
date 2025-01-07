#include "ClapTrap.hpp"

void logStats(ClapTrap &obj)
{
	std::cout << "____" + obj.getName() + " data___\n\n";
	// std::cout << "name = " << obj.getName() << '\n';
	std::cout << "hit points = " << obj.getHitPoints() << '\n';
	std::cout << "energy points = " << obj.getEnergypoints() << '\n';
	std::cout << "attack damage = " << obj.getAttackDamage() << '\n';
	std::cout << "__________________\n\n";
}

void attackLimitTest()
{
	ClapTrap robot1("clap1");
	ClapTrap robot2("clap2");
	for(int i = 0; i < 10;i++)
		robot1.attack("clap2");
	robot1.attack("clap2");
	logStats(robot1);
	logStats(robot2);
}

void repairLimitTest()
{
	ClapTrap robot1("bot");
	for(int i = 0; i < 10;i++)
		robot1.beRepaired(1);
	robot1.beRepaired(1);
	logStats(robot1);
}

int main()
{
	attackLimitTest();
	repairLimitTest();
}