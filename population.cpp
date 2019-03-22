
Population *GeneticAlgorithm::evolvePopulation(Population *pop)
{
	Population *newPopulation = new Population(pop->populationSize(), false);

	// Keep our best individual if elitism is enabled
	int elitismOffset = 0;
	if (elitism)
	{
		newPopulation->saveRoute(0, pop->getFittest());
		elitismOffset = 1;
	}

	// Crossover population
	// Loop over the new population's size and create individuals from
	// Current population
	for (int i = elitismOffset; i < newPopulation->populationSize(); i++)
	{
		// Select parents
		Route *parent1 = RoutenamentSelection(pop);
		Route *parent2 = RoutenamentSelection(pop);
		// Crossover parents
		Route *child = crossover(parent1, parent2);
		// Add child to new population
		newPopulation->saveRoute(i, child);
	}

	// Mutate the new population a bit to add some new genetic material
	for (int i = elitismOffset; i < newPopulation->populationSize(); i++)
	{
		mutate(newPopulation->getRoute(i));
	}

	return newPopulation;
}

Route *GeneticAlgorithm::crossover(Route *parent1, Route *parent2)
{
	// Create new child Route
	Route *child = new Route();

	// Get start and end sub Route positions for parent1's Route
	int startPos = static_cast<int>(Math::random() * parent1->RouteSize());
	int endPos = static_cast<int>(Math::random() * parent1->RouteSize());

	// Loop and add the sub Route from parent1 to our child
	for (int i = 0; i < child->RouteSize(); i++)
	{
		// If our start position is less than the end position
		if (startPos < endPos && i > startPos && i < endPos)
		{
			child->setCity(i, parent1->getCity(i));
		} // If our start position is larger
		else if (startPos > endPos)
		{
			if (!(i < startPos && i > endPos))
			{
				child->setCity(i, parent1->getCity(i));
			}
		}
	}

	// Loop through parent2's city Route
	for (int i = 0; i < parent2->RouteSize(); i++)
	{
		// If child doesn't have the city add it
		if (!child->containsCity(parent2->getCity(i)))
		{
			// Loop to find a spare position in the child's Route
			for (int ii = 0; ii < child->RouteSize(); ii++)
			{
				// Spare position found, add city
				if (child->getCity(ii) == nullptr)
				{
					child->setCity(ii, parent2->getCity(i));
					break;
				}
			}
		}
	}
	return child;
}

void GeneticAlgorithm::mutate(Route *Route)
{
	// Loop through Route cities
	for (int RoutePos1 = 0; RoutePos1 < Route->RouteSize(); RoutePos1++)
	{
		// Apply mutation rate
		if (Math::random() < mutationRate)
		{
			// Get a second random position in the Route
			int RoutePos2 = static_cast<int>(Route->RouteSize() * Math::random());

			// Get the cities at target position in Route
			City *city1 = Route->getCity(RoutePos1);
			City *city2 = Route->getCity(RoutePos2);

			// Swap them around
			Route->setCity(RoutePos2, city1);
			Route->setCity(RoutePos1, city2);
		}
	}
}

Route *GeneticAlgorithm::RoutenamentSelection(Population *pop)
{
	// Create a Routenament population
	Population *Routenament = new Population(RoutenamentSize, false);
	// For each place in the Routenament get a random candidate Route and
	// add it
	for (int i = 0; i < RoutenamentSize; i++)
	{
		int randomId = static_cast<int>(Math::random() * pop->populationSize());
		Routenament->saveRoute(i, pop->getRoute(randomId));
	}
	// Get the fittest Route
	Route *fittest = Routenament->getFittest();
	return fittest;
}


Population::Population(int populationSize, bool initialise)
{
	Routes = std::vector<Route*>(populationSize);
	// If we need to initialise a population of Routes do so
	if (initialise)
	{
		// Loop and create individuals
		for (int i = 0; i < this->populationSize(); i++)
		{
			Route *newRoute = new Route();
			newRoute->generateIndividual();
			saveRoute(i, newRoute);
		}
	}
}

void Population::saveRoute(int index, Route *Route)
{
	Routes[index] = Route;
}

Route *Population::getRoute(int index)
{
	return Routes[index];
}

Route *Population::getFittest()
{
	Route *fittest = Routes[0];
	// Loop through individuals to find fittest
	for (int i = 1; i < populationSize(); i++)
	{
		if (fittest->getFitness() <= getRoute(i)->getFitness())
		{
			fittest = getRoute(i);
		}
	}
	return fittest;
}

int Population::populationSize()
{
	return Routes.size();
}
