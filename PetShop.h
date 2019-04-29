#pragma once
#include"Animal.h"
#include <string>

enum AnimalType { CAT, DOG };

class PetShop
{
private:
	int countAnimal;
	double totalPrice;
	const double catPrice;
	const double dogPrice;
public:
	PetShop(int _countAnimal, double _totalPrice) : countAnimal(_countAnimal), totalPrice(_totalPrice), catPrice(10000), dogPrice(10000) { }

	PetShop():catPrice(10000),dogPrice(20000)
	{
		countAnimal = 0;
		totalPrice = 0.0;
	}
	PetShop(const PetShop &a): catPrice(a.catPrice), dogPrice(a.dogPrice)
	{
		
		countAnimal = a.countAnimal;
		totalPrice = a.totalPrice;
	}
private:
	bool isEmpty()
	{
		if (countAnimal == 0) { return true; }
		return false;
	}
public:
	Animal* buyAnimal(AnimalType type, string name, string sex, string colour)
	{
		try
		{
			if (isEmpty())
			{
				throw 1;
			}
			if (type == CAT)
			{
				addCash(type);
				countAnimal--;
				return makeAnimal(type, name, sex, colour);
			}
			if (type == DOG)
			{
				addCash(type);
				countAnimal--;
				return makeAnimal(type, name, sex, colour);
			}
		}
		catch (int i)
		{
			cout << "Error # [ " << i << " ] Stock is empty! Do you want to make order?" << endl;
			cout << "Enter [yes] to 'yes'\nPress [no] to 'exit'\n" << endl;
			string str;
			cin >> str;

			if (str == "yes")
			{
				makeOrder();
				countAnimal--;
				addCash(type);
				return makeAnimal(type, name, sex, colour);
			}
			else if (str == "no")
			{
				cout << "Good bye!" << endl;
			}
		}
	}
	double getTotalPrice()
	{
		return totalPrice;
	}
private:
	Animal*makeAnimal(AnimalType type, string name, string sex, string colour)
	{
		if (type == CAT)
		{
			Animal* animal = new Cat(name, sex, colour);
			return animal;
		}
		if (type == DOG)
		{
			Animal* animal = new Dog(name, sex, colour);
			return animal;
		}
	}
	void makeOrder()
	{
		countAnimal++;
	}
	void addCash(AnimalType type)
	{
		if (type == CAT) { totalPrice += catPrice; }
		else if (type == DOG) { totalPrice += dogPrice; }
	}
};
