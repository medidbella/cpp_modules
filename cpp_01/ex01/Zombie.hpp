#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;

	public:
		void set_name(std::string zombie_name);
		void announce(void);
		~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);
