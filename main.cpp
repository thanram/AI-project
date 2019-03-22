#include <string>
#include <vector>
#include <iostream>

class Main
{

	static void main(std::vector<std::wstring> &args);
};


void Main::main(std::vector<std::wstring> &args)
{

	// Create and add our cities
	City *city = new City(60, 200);
	DestinationCalculator::addCity(city);
	City *city2 = new City(180, 200);
	DestinationCalculator::addCity(city2);
	City *city3 = new City(80, 180);
	DestinationCalculator::addCity(city3);
	City *city4 = new City(140, 180);
	DestinationCalculator::addCity(city4);
	City *city5 = new City(20, 160);
	DestinationCalculator::addCity(city5);
	City *city6 = new City(100, 160);
	DestinationCalculator::addCity(city6);
	City *city7 = new City(200, 160);
	DestinationCalculator::addCity(city7);
	City *city8 = new City(140, 140);
	DestinationCalculator::addCity(city8);
	City *city9 = new City(40, 120);
	DestinationCalculator::addCity(city9);
	City *city10 = new City(100, 120);
	DestinationCalculator::addCity(city10);
	City *city11 = new City(180, 100);
	DestinationCalculator::addCity(city11);
	City *city12 = new City(60, 80);
	DestinationCalculator::addCity(city12);
	City *city13 = new City(120, 80);
	DestinationCalculator::addCity(city13);
	City *city14 = new City(180, 60);
	DestinationCalculator::addCity(city14);
	City *city15 = new City(20, 40);
	DestinationCalculator::addCity(city15);
	City *city16 = new City(100, 40);
	DestinationCalculator::addCity(city16);
	City *city17 = new City(200, 40);
	DestinationCalculator::addCity(city17);
	City *city18 = new City(20, 20);
	DestinationCalculator::addCity(city18);
	City *city19 = new City(60, 20);
	DestinationCalculator::addCity(city19);
	City *city20 = new City(160, 20);
	DestinationCalculator::addCity(city20);

	// Initialize population
	Population *pop = new Population(50, true);
	std::wcout << L"Initial distance: " << pop->getFittest().getDistance() << std::endl;

	// Evolve population for 100 generations
	pop = GeneticAlgorithm::evolvePopulation(pop);
	for (int i = 0; i < 100; i++)
	{
		pop = GeneticAlgorithm::evolvePopulation(pop);
	}

	// Print final results
	std::wcout << L"Finished" << std::endl;
	std::wcout << L"Final distance: " << pop->getFittest().getDistance() << std::endl;
	std::wcout << L"Solution:" << std::endl;
	std::wcout << pop->getFittest() << std::endl;
}
