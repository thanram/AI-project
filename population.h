#include <vector>

class Population
{

	// Holds population of Routes
public:
	std::vector<Route*> Routes;

	// Construct a population
	Population(int populationSize, bool initialise);

	// Saves a Route
	virtual void saveRoute(int index, Route *Route);

	// Gets a Route from population
	virtual Route *getRoute(int index);

	// Gets the best Route in the population
	virtual Route *getFittest();

	// Gets population size
	virtual int populationSize();
};
