#pragma once
#include <iostream>
#include "doodle/doodle.hpp"

namespace seongryul
{
	class Ladder;
}

class seongryul::Ladder
{
private:
	int x = 0;
	int y = 0;
	double size = 0;

public:
	Ladder(int X, double Size)
		: x(X), size(Size)
	{}

	void create_Latter();
};