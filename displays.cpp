#include "displays.h"
#include "Map.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <doodle/doodle.hpp>


using namespace doodle;
using namespace std;

const Image white_logo{ "assets/DigiPen_WHITE.png" };

bool hyunwoo::Display::colision() {
	pair<double, double> pxy1 = make_pair(player.getpx() + Height / 50, player.getpy() + Height / 50);
	pair<double, double> pxy2 = make_pair(player.getpx() - Height / 50, player.getpy() - Height / 50);
	if (pxy1.first > monster.mxy.first && pxy2.first < monster.mxy.first) {
		if (pxy1.second > monster.mxy.second && pxy2.second < monster.mxy.second)
		{
			return true;
		}
		else {
			return false;
		}
	}
}

void hyunwoo::Display::logo() {

	if (ElapsedTime > 2.0)
	{
		R--;
	}

	push_settings();
	clear_background(HexColor(0x000000FF));
	set_tint_color(Color(R));
	set_image_mode(RectMode::Center);
	draw_image(white_logo, Width / 2, Height / 2);
	pop_settings();

	if (ElapsedTime > 6.0) 
	{
		l_to_s = 1;
	}
}

void hyunwoo::Display::start() {
	push_settings();
	clear_background(HexColor(0x000000FF));
	set_font_size(100);
	set_fill_color(255);
	draw_text("Sweet Dream", Width / 3, Height / 1.5);

	set_image_mode(RectMode::Corner);
	set_fill_color(255);
	set_outline_color(0);

	set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);

	draw_rectangle(Width / 2, Height / 2, box_w, box_h);
	draw_rectangle(Width / 2, Height / 3, box_w, box_h);

	set_font_size(50);
	set_fill_color(HexColor{ 0x2B61D5FF });

	int st = (Width / 2) + 20;
	int ex = (Width / 2) + 30;

	draw_text("start", st, Height / 2);
	draw_text("exit", ex, Height / 3);
	pop_settings();
}

void hyunwoo::Display::play() {
	player.Draw3D(player.Calculate_Distance(seongryul::Map1), player.Calculate_Torch(seongryul::Map1), player.Calculate_Ladder(seongryul::Map1));

	//player.DrawMap(Map1);

	player.MovePlayer(seongryul::Map1);

	monster.Movemonster(seongryul::Map1);
	monster.Drawmonster();

	player.DrawPlayer();

	//player.DrawRay(Map1);

}

void hyunwoo::Display::anime() {

}

void hyunwoo::Display::end() {
	push_settings();
	clear_background(HexColor(0x000000FF));

	set_font_size(50);
	set_fill_color(255);

	int ed = (Width / 2) - 20;
	int cl = (Width / 4);

	draw_text("end game", ed, Height / 2);
	draw_text("click enter to restart or esc to exit", cl, Height / 3);
	pop_settings();
}