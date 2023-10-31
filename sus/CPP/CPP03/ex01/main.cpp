#include "ScavTrap.hpp"

int main()
{
	ScavTrap	me("mohammed");
	ClapTrap	me_("othmane");
	me.attack("talal");
	me_.attack("NULL");
	me.takeDamage(0);
}