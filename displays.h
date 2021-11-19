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

    //�÷��̾�
    seongryul::Player player;
    //����
    hyunwoo::Monster monster;

    //�浹�˻�

    bool colision();

    // �ΰ�----------------------
    int l_to_s = 0;//�ΰ� �ð� üũ �� start�� �ѱ�

    // �ڽ�--------------------------
    int box_w = 200;
    int box_h = 100;


    //-�Լ�--------------------------------
    void logo();

    void start();

    void play();

    void anime();


    void end();

};