City::City()
{
	this->x = static_cast<int>(Math::random()*200);
	this->y = static_cast<int>(Math::random()*200);
}

City::City(int x, int y)
{
	this->x = x;
	this->y = y;
}

int City::getX()
{
	return this->x;
}

int City::getY()
{
	return this->y;
}

double City::distanceTo(City *city)
{
	int xDistance = std::abs(getX() - city->getX());
	int yDistance = std::abs(getY() - city->getY());
	double distance = std::sqrt((xDistance*xDistance) + (yDistance*yDistance));

	return distance;
}

std::wstring City::toString()
{
	return std::to_wstring(getX()) + L", " + std::to_wstring(getY());
}
