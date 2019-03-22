#include <vector>

class DestinationCalculator
{

	// Holds our cities
private:
	static std::vector destinationCities;

	// Adds a destination city
public:
	static void addCity(City *city);

	// Get a city
	static City *getCity(int index);

	// Get the number of destination cities
	static int numberOfCities();
};
