#include "Player.h"
#include "monster.h"

using namespace std;
using namespace doodle;

void hyunwoo::Monster::Movemonster(int Map[10][10])
{
	const int Map_size{ Height / 10 };

	for (int my = 0; my < 10; my++)
	{
		for (int mx = 0; mx < 10; mx++)        //  make maps
		{
			if (Map[my][mx] == 1)
			{
				if (msy <= ((my - 5.0) * Map_size + Map_size) && (msy >= (my - 5.0) * Map_size))
				{
					if (msx <= ((mx - 5.0) * Map_size + Map_size / 2) && (msx >= (mx - 5.0) * Map_size - Map_size / 2))
					{
						IsMoving = false;
						if (Key == KeyboardButtons::U)
						{
							this->msx = msx - dx * 2;
							this->msy = msy - dy * 2;
						}
						if (Key == KeyboardButtons::J)
						{
							this->msx = msx + dx * 2;
							this->msy = msy + dy * 2;
						}
						break;
					}
				}
			}
		}
	}

	if (IsMoving == true && Key == KeyboardButtons::U)
	{
		this->msx = msx + dx;
		this->msy = msy + dy;
	}
	if (IsMoving == true && Key == KeyboardButtons::J)
	{
		this->msx = msx - dx;
		this->msy = msy - dy;
	}
	if (IsMoving == true && Key == KeyboardButtons::H)
	{
		this->a = a - 0.03 * PI;

		if (a < 0)
		{
			this->a = a + 2 * PI;
		}

		this->dy = cos(a) * 5;
		this->dx = -sin(a) * 5;
	}
	if (IsMoving == true && Key == KeyboardButtons::K)
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


void hyunwoo::Monster::Drawmonster()
{
	push_settings();
	apply_translate(msx, msy);
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(Color(255, 0, 0));
	apply_rotate(a);
	draw_rectangle(0, 0, Height / 25, Height / 25);
	pop_settings();
	pop_settings();
}

void hyunwoo::Monster::astar(int Map[10][10], double mx, double my, double px, double py)
{

}