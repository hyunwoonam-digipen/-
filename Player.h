#pragma once

#include "doodle/doodle.hpp"
#include <iostream>
#include <cmath>
using namespace doodle;
using namespace std;


namespace seongryul {

	struct Drawing_map;
	class Player;
};

struct seongryul::Drawing_map
{
	int number;
	double distance;
	bool Torch;
	bool Ladder;
};

class seongryul::Player
{
private:
	double x{ 0 };
	double y{ 0 };
	double a{ 0 };
	double dx{ cos(a) * 5 };
	double dy{ sin(a) * 5 };

	double Distance{ Height * 1.0 };

public:
	bool IsMoving = true;

	void MovePlayer(int Map[10][10]);

	std::vector<Drawing_map> Calculate_Distance(int Map[10][10]);

	Drawing_map Calculate_Torch(int Map[10][10]);

	Drawing_map Calculate_Ladder(int Map[10][10]);

	void Draw3D(std::vector<Drawing_map> m, Drawing_map Torch, Drawing_map Ladder);

	void DrawPlayer();

	pair<double, double> pxy = make_pair(getpx(), getpy());

	double getpx() { return x; };
	double getpy() { return y; };

};