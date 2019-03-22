Route::Route()
{
	for (int i = 0; i < RouteManager::numberOfCities(); i++)
	{
		Route_Renamed.push_back(nullptr);
	}
}

Route::Route(std::vector Route)
{
	this->Route_Renamed = Route;
}

void Route::generateIndividual()
{
	// Loop through all our destination cities and add them to our Route
	for (int cityIndex = 0; cityIndex < RouteManager::numberOfCities(); cityIndex++)
	{
		setCity(cityIndex, RouteManager::getCity(cityIndex));
	}
	// Randomly reorder the Route
	Collections::shuffle(Route_Renamed);
}

City *Route::getCity(int RoutePosition)
{
	return static_cast<City*>(Route_Renamed[RoutePosition]);
}

void Route::setCity(int RoutePosition, City *city)
{
	Route_Renamed[RoutePosition] = city;
	// If the Routes been altered we need to reset the fitness and distance
	fitness = 0;
	distance = 0;
}

double Route::getFitness()
{
	if (fitness == 0)
	{
		fitness = 1 / static_cast<double>(getDistance());
	}
	return fitness;
}

int Route::getDistance()
{
	if (distance == 0)
	{
		int RouteDistance = 0;
		// Loop through our Route's cities
		for (int cityIndex = 0; cityIndex < RouteSize(); cityIndex++)
		{
			// Get city we're travelling from
			City *fromCity = getCity(cityIndex);
			// City we're travelling to
			City *destinationCity;
			// Check we're not on our Route's last city, if we are set our
			// Route's final destination city to our starting city
			if (cityIndex + 1 < RouteSize())
			{
				destinationCity = getCity(cityIndex + 1);
			}
			else
			{
				destinationCity = getCity(0);
			}
			// Get the distance between the two cities
			RouteDistance += fromCity->distanceTo(destinationCity);
		}
		distance = RouteDistance;
	}
	return distance;
}

int Route::RouteSize()
{
	return Route_Renamed.size();
}

bool Route::containsCity(City *city)
{
	return std::find(Route.begin(), Route.end(), city) != Route.end();
}

std::wstring Route::toString()
{
	std::wstring geneString = L"|";
	for (int i = 0; i < RouteSize(); i++)
	{
		geneString += getCity(i) + L"|";
	}
	return geneString;
}
