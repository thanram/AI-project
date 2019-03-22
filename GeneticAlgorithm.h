
class GeneticAlgorithm
{

	/* GeneticAlgorithm parameters */
private:
	static constexpr double mutationRate = 0.015;
	static constexpr int RoutenamentSize = 5;
	static constexpr bool elitism = true;

	// Evolves a population over one generation
public:
	static Population *evolvePopulation(Population *pop);

	// Applies crossover to a set of parents and creates offspring
	static Route *crossover(Route *parent1, Route *parent2);

	// Mutate a Route using swap mutation
private:
	static void mutate(Route *Route);

	// Selects candidate Route for crossover
	static Route *RoutenamentSelection(Population *pop);
};

