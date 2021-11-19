#pragma once

#include "col.h"
#include "doodle/doodle.hpp"
#include <iostream>
#include <cmath>

using namespace doodle;
using namespace std;

namespace hyunwoo
{
    class Monster;
}

class hyunwoo::Monster
{
private:

    double msx{ 100 };
    double msy{ 100 };
    double a{ 0 };
    double dx{ cos(a) * 5 };
    double dy{ sin(a) * 5 };

public:
    pair<double, double> mxy = make_pair(getmx(), getmy());
    
    double getmx() { return msx; };
    double getmy() { return msy; };


    bool IsMoving = true;
    void Movemonster(int Map[10][10]);
    void Drawmonster();
    void astar(int Map[10][10],double mx, double my, double px, double py);

};