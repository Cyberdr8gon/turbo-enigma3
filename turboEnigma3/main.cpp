#include <iostream>
#include <string>

#include "slime.h"
#include "hero.h"

using namespace std;

int main(void)
{
	slime s = slime("Slime");  // tests if enemy class is working
	int health = s.getHealth();
	int newHealth = adjustHealth();
	cout << s.getName() << ": " << s.getHealth();
	
	
	cout << s.getName() << ": " << s.adjustHealth();
	cin.get();

	
	return 0;
};