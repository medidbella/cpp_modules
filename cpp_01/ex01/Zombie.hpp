#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		Zombie(void);
		void set_name(std::string zombie_name);
		void announce(void);
		~Zombie(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );
