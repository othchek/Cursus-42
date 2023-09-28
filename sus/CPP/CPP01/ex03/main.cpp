#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    Weapon weaponA = Weapon("Sword");
    HumanA humanA("othman", weaponA);
    humanA.attack();
    weaponA.setType("Some other Weapon");
    humanA.attack();

    HumanB humanB("Alice");
    Weapon weaponB("bow");
    humanB.setWeapon(weaponB);
    humanB.attack();
}