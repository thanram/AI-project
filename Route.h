//.h file code:

#include <string>
#include <vector>
#include <algorithm>

class Route
{

	// Holds our Route of cities
private:
	std::vector Route_Renamed = std::vector<City*>();
	// Cache
	double fitness = 0;
	int distance = 0;

	// Constructs a blank Route
public:
	Route();

	Route(std::vector Route);

	// Creates a random individual
	virtual void generateIndividual();

	// Gets a city from the Route
	virtual City *getCity(int RoutePosition);

	// Sets a city in a certain position within a Route
	virtual void setCity(int RoutePosition, City *city);

	// Gets the Routes fitness
	virtual double getFitness();

	// Gets the total distance of the Route
	virtual int getDistance();

	// Get number of cities on our Route
	virtual int RouteSize();

	// Check if the Route contains a city
	virtual bool containsCity(City *city);

	std::wstring toString() override;
};
