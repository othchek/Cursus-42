#include "ClapTrap.hpp"

int main() {
  	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe;

	john.attack("zac");
	john.attack("james");
	john.attack("simo");
	john.takeDamage(5);
	jim.takeDamage(9);
	jim.takeDamage(10);
	joe.beRepaired(10);
	joe.takeDamage(19);
	joe.attack("mohammed");
}