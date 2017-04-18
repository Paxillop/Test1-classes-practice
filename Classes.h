/* ----------------------------------------------------------------------- */
/*                         PAU LLOPART CERVELLO                            */
/* ----------------------------------------------------------------------- */

#ifndef CLASSES_H
#define CLASSES_H



// TO DO: Implement the base class Battalion here

class Battalion
{
public:
	Battalion( char* pname) {

		_name = pname;

	};

	char* getName() {

		return _name;

	};

	virtual int combatValue() = 0;

	~Battalion(){}

protected:

	char* _name;

};

// TO DO: Implement the derived class Infantry here

class Infantry : public Battalion
{
public:
	Infantry( char* pname, int bayonetSoldiers, int musketSoldiers):Battalion(pname) 
	{
	
		_bayonetSoldiers = bayonetSoldiers;
		_musketSoldiers = musketSoldiers;

	};
	
	virtual int combatValue()
	{

		int totalDmg = (_bayonetSoldiers * 1) + (_musketSoldiers * 2);

		return totalDmg;
	};


private:

	int _bayonetSoldiers;
	int _musketSoldiers;

};

// TO DO: Implement the derived class Chivalry here

class Chivalry : public Battalion
{
public:

	Chivalry( char* pname, int lightChivarly, int heavyChivarly):Battalion(pname)
	{
	
		_lightChivarly = lightChivarly;
		_heavyChivarly = heavyChivarly;
	
	};

	virtual int combatValue()
	{

		int totalDmg = _lightChivarly * 3 + _heavyChivarly * 4;

		return totalDmg;
	};

private:

	int _lightChivarly;
	int _heavyChivarly;

};

// TO DO: Implement the derived class Artillery here

class Artillery : public Battalion
{
public:

	Artillery( char* pname, int mortars, int cannons) :Battalion(pname)
	{

		_mortars = mortars;
		_cannons = cannons;

	};

	virtual int combatValue()
	{

		int totalDmg = _mortars * 5 + _cannons * 6;

		return totalDmg;
	};

private:

	int _mortars;
	int _cannons;

};



char* victoryInBattlefield(Battalion* div1, Battalion* div2)
{
	// TO DO: introduce the code of the function here

	if (div1->combatValue() == div2->combatValue()) {

		return "Same combat value";

	}
	else if(div1->combatValue() > div2->combatValue())
	{
		return div1->getName();
	}
	
	else
	{
		return div2->getName();
	}


}


#endif // CLASSES_H