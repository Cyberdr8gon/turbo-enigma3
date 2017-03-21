#include <iostream>
#include <string>

#include "slime.h"

using namespace std;

int main(void)
{
	slime s = slime("Slime");  // tests if enemy class is working

	cout << s.getName() << ": " << s.getHealth();

	cin.get();

	
	return 0;
};