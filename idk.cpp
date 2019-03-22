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
