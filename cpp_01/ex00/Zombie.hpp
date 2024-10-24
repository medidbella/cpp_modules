#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		Zombie(std::string zombie_name);
		void announce(void);
		~Zombie(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
