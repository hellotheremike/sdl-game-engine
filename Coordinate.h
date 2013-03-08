/*
	Coordinate class that is used as an interface for placing 
	GameObjects and Sprites at specific coordinates in the game

	Author: Mikael Hallgren, 2013 
*/

#ifndef Coordinate_H
#define Coordinate_H

namespace Engine
{
	struct Coordinate
	{
		double X;	// X cordinate
		double Y;	// Y Cordinate

		Coordinate();		// Constructor sets X & Y to 0
		Coordinate(double in_X, double in_Y);	// Sets X & Y to inparameters
		Coordinate(const Coordinate& other);	// Sets X & Y to other's X & Y

		// Opertaors to make it quick and easy to set cordinates
		void	SetCoordinate(double in_X, double in_Y);
		const Coordinate operator+(const Coordinate& other);
		const Coordinate operator-(const Coordinate& other);
		const Coordinate operator*(const Coordinate& other);
		const Coordinate operator*(const double value);
		const Coordinate operator/(const Coordinate& other);
		const Coordinate operator/(const double value);
	};
}

#endif