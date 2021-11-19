#pragma once
#include <iostream>
#include <vector>
#include "doodle/doodle.hpp"

namespace seongryul
{
	class Particle;
	class Torch;
}

class seongryul::Particle
{
private:
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;

public:
	int Particle_x() const { return x; }

	int Particle_y() const { return y; }

	void draw_particle();
};

class seongryul::Torch
{
private:
	int x = 0;
	int y = 0;
	double size = 0;
	Particle par;
	std::vector<Particle> P;

public:
	Torch(int X, double Size)
		: x(X), size(Size)
	{}


	void create_Torch();

	void Torch_Particle();
};