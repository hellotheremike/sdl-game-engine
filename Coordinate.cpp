#include "Coordinate.h"

namespace Engine
{
	Coordinate::Coordinate()
	{
		this->X = 0;
		this->Y = 0;
	}

	Coordinate::Coordinate(double x, double y)
	{
		this->X = x;
		this->Y = y;
	}

	Coordinate::Coordinate(const Coordinate& other)
	{
		this->X = other.X;
		this->Y = other.Y;
	}

	void Coordinate::SetCoordinate(double x, double y)
	{
		this->X = x;
		this->Y = y;
	}

	const Coordinate Coordinate::operator+(const Coordinate& other)
	{
		Coordinate result(*this);
		result.X += other.X;
		result.Y += other.Y;

		return result;
	}

	const Coordinate Coordinate::operator-(const Coordinate& other)
	{
		Coordinate result(*this);
		result.X -= other.X;
		result.Y -= other.Y;

		return result;
	}
	const Coordinate Coordinate::operator*(const Coordinate& other)
	{
		Coordinate result(*this);
		result.X *= other.X;
		result.Y *= other.Y;

		return result;
	}

	const Coordinate Coordinate::operator*(double other)
	{
		Coordinate result(*this);
		result.X *= other;
		result.Y *= other;

		return result;

		return *this;
	}

	const Coordinate Coordinate::operator/(const Coordinate& other)
	{
		Coordinate result(*this);
		result.X /= other.X;
		result.Y /= other.Y;

		return result;
	}

	const Coordinate Coordinate::operator/(double other)
	{
		Coordinate result(*this);
		result.X /= other;
		result.Y /= other;

		return result;
	}
}
