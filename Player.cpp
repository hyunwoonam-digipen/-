#include "Player.h"
#include "Ladder.h"
#include "Torch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>


using namespace doodle;

void seongryul::Player::MovePlayer(int Map[10][10])
{
	const int Map_size{ Height / 10 };

	for (int my = 0; my < 10; my++)
	{
		for (int mx = 0; mx < 10; mx++)        //  make maps
		{
			if (Map[my][mx] == 1)
			{
				if (y <= ((my - 5.0) * Map_size + Map_size) && (y >= (my - 5.0) * Map_size))
				{
					if (x <= ((mx - 5.0) * Map_size + Map_size / 2) && (x >= (mx - 5.0) * Map_size - Map_size / 2))
					{
						IsMoving = false;
						if (Key == KeyboardButtons::W)
						{
							this->x = x - dx * 2;
							this->y = y - dy * 2;
						}
						if (Key == KeyboardButtons::S)
						{
							this->x = x + dx * 2;
							this->y = y + dy * 2;
						}
						break;
					}
				}
			}
		}
	}

	if (IsMoving == true && Key == KeyboardButtons::W)
	{
		this->x = x + dx;
		this->y = y + dy;
	}
	if (IsMoving == true && Key == KeyboardButtons::S)
	{
		this->x = x - dx;
		this->y = y - dy;
	}
	if (IsMoving == true && Key == KeyboardButtons::A)
	{
		this->a = a - 0.03 * PI;

		if (a < 0)
		{
			this->a = a + 2 * PI;
		}

		this->dy = cos(a) * 5;
		this->dx = -sin(a) * 5;
	}
	if (IsMoving == true && Key == KeyboardButtons::D)
	{
		this->a = a + 0.03 * PI;

		if (a > 2 * PI)
		{
			this->a -= 2 * PI;
		}

		this->dy = cos(a) * 5;
		this->dx = -sin(a) * 5;
	}
}



std::vector<seongryul::Drawing_map> seongryul::Player::Calculate_Distance(int Map[10][10])
{
	std::vector<Drawing_map> vec;
	const int Map_size{ Height / 10 };
	int       rec_x{ 1 };
	int       begin_X = 0;
	int       begin_Y = 0;
	int       end_X = 10;
	int       end_Y = 10;
	int       px = 0;
	int       py = 0;

	for (int my = 0; my < 10; my++)
	{
		for (int mx = 0; mx < 10; mx++) //  make maps
		{
			if (y <= ((my - 5.0) * Map_size + Map_size) && (y >= (my - 5.0) * Map_size))
			{
				if (x <= ((mx - 5.0) * Map_size + Map_size / 2) && (x >= (mx - 5.0) * Map_size - Map_size / 2))
				{
					px = mx;
					py = my;
				}
			}
		}
	}


	if (a <= PI / 4 || a >= 7 * PI / 4)
	{
		begin_Y = py - 1;
		end_Y = 10;
	}
	else if (a >= PI / 4 && a <= 3 * PI / 4)
	{
		end_X = px + 1;
		begin_X = 0;
	}
	else if (a >= 3 * PI / 4 && a <= 5 * PI / 4)
	{
		end_Y = py + 1;
		begin_Y = 0;
	}
	else if (a >= 5 * PI / 4 && a <= 7 * PI / 4)
	{
		begin_X = px - 1;
		end_X = 10;
	}

	for (double ang = -PI / 4; ang < PI / 4; ang += PI / 100)
	{
		Distance = Height;
		Drawing_map dm;

		dm.number = rec_x;
		dm.Ladder = false;
		dm.Torch = false;

		for (int my = begin_Y; my < end_Y; my++)
		{
			for (int mx = begin_X; mx < end_X; mx++)        //  make maps
			{
				if (Map[my][mx] == 1)
				{
					for (double d = 0; d < Height; d += 0.5)
					{
						if ((y + d * cos(a + ang)) <= ((my - 5.0) * Map_size + Map_size) && (y + d * cos(a + ang)) >= ((my - 5.0) * Map_size))
						{
							if ((x - d * sin(a + ang)) <= ((mx - 5.0) * Map_size + Map_size / 2) && (x - d * sin(a + ang)) >= ((mx - 5.0) * Map_size - Map_size / 2))
							{
								if (Distance > d)
								{
									Distance = d;
								}
							}
						}
					}
				}
			}
		}

		dm.distance = Distance;
		vec.push_back(dm);

		rec_x++;
	}

	return vec;
}

seongryul::Drawing_map seongryul::Player::Calculate_Torch(int Map[10][10])
{
	const int Map_size{ Height / 10 };
	unsigned int tx = 0;
	unsigned int ty = 0;
	int		  ta = 0;
	int		  distance;

	//	calculate torch's location
	//  Compare cos to sin to find angle between player's1 and torch's
	//	Calculate number
	//  Calculate distance - sqrt(pow(lx - px) + pow(ly - px));

	for (int my = 0; my < 10; my++)
	{
		for (int mx = 0; mx < 10; mx++) //  calculate torch's location
		{
			if (Map[my][mx] == 2)
			{
				ty = (my - 5.0) * Map_size + (Map_size / 2);
				tx = (mx - 5.0) * Map_size;
			}
		}
	}


	ta = (atan2(tx - x, ty - y) - a + PI / 2);

	if (ta >= 2 * PI)
	{
		ta = ta - 2 * PI;
	}
	else if (ta <= 0)
	{
		ta = ta + 2 * PI;
	}

	if (ta <= PI / 4)
	{
		Drawing_map m;
		m.number = Width / 2 * (-cos(ta));
		m.distance = sqrt(pow(x - tx, 2) + pow(y - ty, 2));
		m.Ladder = true;
		m.Torch = false;

		return m;
	}
	else if (ta >= PI / 4 * 7)
	{
		Drawing_map m;
		m.number = Width / 2 * (-cos(ta));
		m.distance = sqrt(pow(x - tx, 2) + pow(y - ty, 2));
		m.Ladder = true;
		m.Torch = false;

		return m;
	}
	else
	{
		Drawing_map m;
		m.number = 51;
		m.distance = sqrt(pow(tx - x, 2) + pow(ty - x, 2));
		m.Ladder = false;
		m.Torch = false;

		return m;
	}
}


seongryul::Drawing_map seongryul::Player::Calculate_Ladder(int Map[10][10])
{
	Drawing_map m;

	m.number = 51;
	m.distance = Width;
	m.Ladder = false;
	m.Torch = false;

	return m;
}

void seongryul::Player::Draw3D(std::vector<seongryul::Drawing_map> m, seongryul::Drawing_map Torchs, seongryul::Drawing_map Ladders)
{
	m.push_back(Torchs);
	m.push_back(Ladders);

	std::sort(m.begin(), m.end(), [](Drawing_map ma, Drawing_map mb)
		{
			return ma.distance > mb.distance;
		});

	for (auto& [num, dis, Lad, Tor] : m)
	{

		if (Lad == true)
		{
			Ladder l(-Width / 2 + (Width * num / 50), ((Height - dis) / Height));

			l.create_Latter();
		}
		else if (Tor == true)
		{
			Torch t(num, (Height - dis) / Height);

			draw_text(std::to_string(dis), -Width / 2, -Height / 3);
			t.create_Torch();
		}

		else if (Lad == false && Tor == false)
		{
			push_settings();
			set_rectangle_mode(RectMode::Center);
			set_fill_color(255 / dis * 40, 150 / dis * 40, 0 / dis * 40);
			no_outline();
			draw_rectangle(-Width / 2 + (Width * num / 50), 0, (Width / 50 + 1), (Height - dis) / 3);
			pop_settings();
		}

	}
}

void seongryul::Player::DrawPlayer()
{
	push_settings();
	apply_translate(x, y);
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(Color(255, 0, 0));
	apply_rotate(a);
	draw_rectangle(0, 0, Height / 25, Height / 25);
	pop_settings();
	pop_settings();
}