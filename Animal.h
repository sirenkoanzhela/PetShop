#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string name;
	string sex;
	string colour;
public:
	Animal(string _name, string _sex, string  _colour) :name(_name = ' '), sex(_sex = ' '), colour(_colour = ' ') { cout << "test: Constructor with Params- ANIMAL" << endl; }
	Animal()
	{
		cout << "test: Constructor Default - ANIMAL" << endl;
		name = ' ';
		sex = ' ';
		colour = ' ';
	}
	Animal(const Animal &a)
	{
		cout << "test: Copy Constructor for Animal";
		name = a.name;
		sex = a.name;
		colour = a.colour;
	}
	Animal&operator = (const Animal&a) //перегрузка оператора =
	{

	}
	void printAnimalType()
	{
		cout << "Name: " << name << endl;
		cout << "Sex: " << sex << endl;
		cout << "Colour: " << colour << endl;
	}
	void testChangeName(string newName)
	{
		name = newName;
	}
	virtual string voice() = 0;
};
class Cat :public Animal
{

public:
	Cat(string _name, string _sex, string  _colour)
	{
		cout << "test: Constructor with Params- CAT" << endl;
		name = _name;
		sex = _sex;
		colour = _colour;
	}
	Cat(const Cat &a):Animal (a)
	{
		cout << "test: Copy Constructor - CAT" << endl;
		name = a.name;
		sex = a.name;
		colour = a.colour;
	}
	Cat()
	{
		cout << "test: Constructor Default - CAT" << endl;
		name = ' ';
		sex = ' ';
		colour = ' ';
	}
	string voice()override
	{
		return "myau";
	}
};
class Dog :public Animal
{
public:
	Dog(string _name, string _sex, string  _colour)
	{
		name = _name;
		sex = _sex;
		colour = _colour;
	}
	Dog(const Dog &a)
	{
		cout << "test: Copy Constructor - DOG";
		name = a.name;
		sex = a.name;
		colour = a.colour;
	}
	Dog()
	{
		name = ' ';
		sex = ' ';
		colour = ' ';
	}
	string voice()override
	{
		return "woff";
	}
};
