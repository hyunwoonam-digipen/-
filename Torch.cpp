#include "Torch.h"
#include "doodle/doodle.hpp"

using namespace doodle;


void seongryul::Particle::draw_particle()
{
	dx = random(-2, 3);
	dy = random(0, 3);

	x += dx;
	y += dy;
	push_settings();
	if (y <= (Height / 10))
	{
		set_fill_color(Color(184, 43, 24));
	}
	else if (y > (Height / 10))
	{
		set_fill_color(Color(150));
	}
	no_outline();
	draw_ellipse(x, y, Height / 80, Height / 80);
	pop_settings();
}


void seongryul::Torch::Torch_Particle()
{
	P.push_back(par);
	
	
	for (unsigned int i = 0; i < P.size(); i++)
	{
		P[i].draw_particle();
	
		if (P[i].Particle_y() > (Height / 5))
		{
			P.erase(P.begin() + i);
		}
	}
}

void seongryul::Torch::create_Torch()
{
	push_settings();
	apply_translate(x, 0);
	push_settings();
	apply_scale(size);
	no_outline();

	set_fill_color(Color(184, 43, 24));
	draw_quad(-Height / 60, Height / 10 - Height / 30, Height / 60, Height / 10 - Height / 30, Height / 40, 0, -Height / 40, 0);

	set_fill_color(Color(210, 176, 76));
	draw_quad(-Height / 40, 0, Height / 40, 0, Height / 60, -Height / 3, -Height / 60, -Height / 3);

	push_settings();
	set_fill_color(Color(171, 120, 78));
	draw_triangle(-Height / 60 + Height / 180, -Height / 30, 0 - Height / 60, -Height / 30, -Height / 40 + Height / 60, -Height / 3 + Height / 30);
	draw_triangle(Height / 60 - Height / 180, -Height / 30, 0 + Height / 60, -Height / 30, Height / 40 - Height / 60, -Height / 3 + Height / 30);
	draw_quad(-Height / 60 - Height / 60, Height / 30, Height / 60 + Height / 60, Height / 30, Height / 40, 0, -Height / 40, 0);
	pop_settings();
	pop_settings();
	pop_settings();
}