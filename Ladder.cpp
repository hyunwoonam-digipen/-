#include "Ladder.h"
#include "doodle/doodle.hpp"
using namespace doodle;

void seongryul::Ladder::create_Latter()
{
	push_settings();
	apply_translate(x, 0);
	push_settings();
	apply_scale(size * 1.5);
	no_outline();
	set_fill_color(Color(164, 116, 73));
	set_rectangle_mode(RectMode::Center);
	draw_rectangle(-Height / 10, 0, Height / 50, Height / 2);
	draw_rectangle(Height / 10, 0, Height / 50, Height / 2);

	draw_rectangle(0, -Height / 10, Height / 5, Height / 50);
	draw_rectangle(0, -Height / 5, Height / 5, Height / 50);
	draw_rectangle(0, 0, Height / 5, Height / 50);
	draw_rectangle(0, Height / 5, Height / 5, Height / 50);
	draw_rectangle(0, Height / 10, Height / 5, Height / 50);

	draw_ellipse(-Height / 10, -Height / 4, Height / 50, Height / 50);
	draw_ellipse(-Height / 10, Height / 4, Height / 50, Height / 50);
	draw_ellipse(Height / 10, -Height / 4, Height / 50, Height / 50);
	draw_ellipse(Height / 10, Height / 4, Height / 50, Height / 50);
	pop_settings();
	pop_settings();
}