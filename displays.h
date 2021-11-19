#pragma once

#include "Player.h"
#include "monster.h"
#include "Ladder.h"
#include "Torch.h"

#include <doodle/doodle.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace doodle;

namespace hyunwoo
{
    class Display;
}

class hyunwoo::Display
{
    int R = 255;

public:

    //플레이어
    seongryul::Player player;
    //몬스터
    hyunwoo::Monster monster;

    //충돌검사

    bool colision();

    // 로고----------------------
    int l_to_s = 0;//로고 시간 체크 후 start로 넘김

    // 박스--------------------------
    int box_w = 200;
    int box_h = 100;


    //-함수--------------------------------
    void logo();

    void start();

    void play();

    void anime();


    void end();

};