#include <iostream>
#include "PetShop.h"
#include <vector>

int main()
{
	PetShop*petShop = new PetShop(1,0.0);

	Animal* animal = petShop->buyAnimal(CAT, "Randal", "boy", "black");
	Animal* animal2 = new Cat("Randal", "boy", "black");
	cout << endl;

	system("pause");
	return 0;
}