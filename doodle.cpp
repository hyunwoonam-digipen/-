#include "screen.h"
#include "displays.h"
#include "Player.h"
#include "monster.h"
#include "col.h"

#include <doodle/doodle.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <exception>
#include <SFML/Audio.hpp>


using namespace doodle;
using namespace std;

double mousex{ 0.0 };
double mousey{ 0.0 };

hyunwoo::screenType sckey{ hyunwoo::screenType::play };
hyunwoo::col colch{ hyunwoo::col::catchfalse };
hyunwoo::Display dis;

int main(void) {

	create_window("Gam 100", Width, Height);

	while(!is_window_closed())
	{
		update_window();
		clear_background(220);

        mousex = get_mouse_x();
        mousey = get_mouse_y();

		switch (sckey)
		{
		case hyunwoo::screenType::logo:
            push_settings();

            set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

			dis.logo();
			if (dis.l_to_s == 1) {
				sckey = hyunwoo::screenType::start;
			}

            pop_settings();

			break;

		case hyunwoo::screenType::start:
            push_settings();

            set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

			dis.start();

            pop_settings();

			break;

		case hyunwoo::screenType::play:
			dis.play();

            if (dis.colision() == true) {
                sckey = hyunwoo::screenType::anime;
            }

			break;

        case hyunwoo::screenType::anime:
            push_settings();

            set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

            dis.anime();

            break;

		case hyunwoo::screenType::end:
            push_settings();

            set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

			dis.end();

            pop_settings();
			break;
		}


	}

	return 0;
}

void on_key_pressed(KeyboardButtons button)
{
    //플레이
    if (sckey == hyunwoo::screenType::play) {
        dis.player.IsMoving = true;
        dis.monster.IsMoving = true;
    }
}

void on_key_released([[maybe_unused]] KeyboardButtons button)
{
    //언제나 작동
    if (button == KeyboardButtons::Escape)
    {
        //화면 닫기
        close_window();
    }

    //로고
    
    if (sckey == hyunwoo::screenType::logo)
    {
        if (button == KeyboardButtons::Space)
        {
            //로고 스킵
            sckey = hyunwoo::screenType::start;
        }
    }

    //플레이

    if (sckey == hyunwoo::screenType::play) {
        dis.player.IsMoving = false;
        dis.monster.IsMoving = true;
    }
    
    //애니메이션

    if (sckey == hyunwoo::screenType::anime) {

    }

    //엔드

    if (sckey == hyunwoo::screenType::end)
    {
        if (button == KeyboardButtons::Enter)
        {
            //스타트 돌아가기
            sckey = hyunwoo::screenType::start;
        }
    }
}

void on_mouse_released([[maybe_unused]] MouseButtons button)
{
    if (sckey == hyunwoo::screenType::start) {

        if (mousex > (Width / 2) && mousex < ((Width / 2) + dis.box_w)) {
            if (mousey > (Height / 2) && mousey < ((Height / 2) + dis.box_h))
            {
                sckey = hyunwoo::screenType::play;
            }
            if (mousey > (Height / 3) && mousey < ((Height / 3) + dis.box_h)) {
                close_window();
            }
        }
    }
}