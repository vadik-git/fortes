#pragma once


#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class Shooter abstract
{
	string ammunition;
	size_t size;
public:
	Shooter(const string& ammunition = "NoAmmunition", size_t size = 0)
		:ammunition(ammunition), size(size) {}
	void shot()
	{
		if (size != 0)
		{
			cout << ammunition << "\tsize = " << size-- << endl;
		}
	}
	void giveAmmunition(const string& ammunition = "NoAmmunition", size_t size = 0)
	{
		this->ammunition = ammunition;
		this->size = size;
	}
};
class Archer abstract :virtual protected Shooter
{
public:
	Archer(size_t size = 0)
	{
		giveAmmunition(size);
	}
	void shot()
	{
		Shooter::shot();
		cout << "Archer" << endl;
	}
	void giveAmmunition(size_t size = 0)
	{
		Shooter::giveAmmunition("Arrow", size);
	}
};
class Range abstract :virtual protected Shooter
{
public:
	Range(size_t size = 0)
	{
		giveAmmunition(size);
	}
	void shot()
	{
		Shooter::shot();
		cout << "Range" << endl;
	}
	void giveAmmunition(size_t size = 0)
	{
		Shooter::giveAmmunition("Arrow", size);
	}
};
class Catapult abstract :protected Shooter
{
public:
	Catapult(size_t size = 0)
	{
		giveAmmunition(size);
	}
	void shot()
	{
		Shooter::shot();
		cout << "Catapult" << endl;
	}
	void giveAmmunition(size_t size = 0)
	{
		Shooter::giveAmmunition("stone", size);
	}
};
class ArcherTower abstract :public Archer, public Range
{
public:
	ArcherTower(size_t size = 0)
	{
		Archer::giveAmmunition(size);
	}
	void giveAmmunition(size_t size = 0)
	{
		Archer::giveAmmunition(size);
	}
};
class Fortess :public ArcherTower, public Catapult
{
	size_t wall_thickness = 50;
	size_t condition_of_the_gate : 7;
public:
	Fortess(size_t size_arrow = 0, size_t size_stone = 0)
	{
		ArcherTower::Archer::giveAmmunition(size_arrow);
		Catapult::giveAmmunition(size_stone);
	}
	void giveAmmunitionArcherTower(size_t size = 0)
	{
		ArcherTower::giveAmmunition(size);
	}
	void giveAmmunitionCatapult(size_t size = 0)
	{
		Catapult::giveAmmunition(size);
	}
	void shotArcher()
	{
		Archer::shot();
	}
	void shotRange()
	{
		Range::shot();
	}
	void shotCatapult()
	{
		Catapult::shot();
	}
	void shot()// all
	{
		Archer::shot();
		Range::shot();
		Catapult::shot();
	}
};


