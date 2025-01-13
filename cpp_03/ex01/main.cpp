#include "ScavTrap.hpp"

void testDestructionOrder(){
	ScavTrap *bot = new ScavTrap("test");
	delete bot;
}

void logStats(ScavTrap &bot){
	std::cout << "name = " << bot.getName() << '\n';
	std::cout << "energy points = " << bot.getEnergypoints() << '\n';
	std::cout << "hit points = " << bot.getHitPoints() << '\n';
	std::cout << "attack damage = " << bot.getAttackDamage() << '\n';
}

void generalTest(){
	ScavTrap robot("bit");

	logStats(robot);
	robot.attack("targetBot");
	std::cout << "energy points after attacking = " << robot.getEnergypoints() << '\n';
	robot.takeDamage(10);
	std::cout << "hit points after taking 10 points of damage = " <<robot.getHitPoints() << '\n';
	robot.guardGate();
}

void TestLimit(){
	ScavTrap bot("frag");
	logStats(bot);
	bot.setEnergyPoints(0);
	std::cout << "bot energy is now = " << bot.getEnergypoints() << '\n';
	bot.attack("target bot");
	bot.beRepaired(10);
}


int main()
{
	TestLimit();
	generalTest();
	testDestructionOrder();
}
