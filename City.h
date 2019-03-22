#include <string>
#include <cmath>

class City
{
public:
	int x = 0;
	int y = 0;

	// Constructs a randomly placed city
	City();

	// Constructs a city at chosen x, y location
	City(int x, int y);

	// Gets city's x coordinate
	virtual int getX();

	// Gets city's y coordinate
	virtual int getY();

	// Gets the distance to given city
	virtual double distanceTo(City *city);

	std::wstring toString() override;
};
