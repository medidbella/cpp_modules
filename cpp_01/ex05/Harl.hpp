#include <string>
#include <iostream>

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*ft_ptrs[4])(void);
		std::string levels[4];
	public:
		Harl(void);
		void complain(std::string level);
};
