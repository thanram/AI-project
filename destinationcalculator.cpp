std::vector DestinationCalculator::destinationCities = std::vector<City*>();

void DestinationCalculator::addCity(City *city)
{
	destinationCities.push_back(city);
}

City *DestinationCalculator::getCity(int index)
{
	return static_cast<City*>(destinationCities[index]);
}

int DestinationCalculator::numberOfCities()
{
	return destinationCities.size();
}


