#include "FragTrap.hpp"

int main() {
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ScavTrap bok("hihi");
	ScavTrap tok;
	FragTrap johny;
	FragTrap hoho("haha");

	john.attack("Bart");
	john.attack("Homer");
	john.takeDamage(5);
	jim.takeDamage(9);
	jim.takeDamage(10);
	bok.attack("hoe");
	bok.guardGate();
	hoho.attack("moraw");
	hoho.takeDamage(5);
	hoho.highFivesGuys();
	johny.attack("hamid");
	johny.highFivesGuys();
}