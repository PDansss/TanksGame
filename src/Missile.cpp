#include "Missile.h"
#include "Enemy.h"
#include "Drow.h"

void Missile::Move()
{
	missile.setPosition(Vector2f(X + DX, Y + DY));
	X += DX;
	Y += DY;
	if (Map[Center_Y / 50][Center_X / 50] == 2 || Map[Center_Y / 50][Center_X / 50] == 1) {
		Map[Center_Y / 50][Center_X / 50] -= 1;
		Active = true;
		Use = false;
	}
	else if (X > 1150 || X < 50 || Y > 850 || Y < 50) {
		Active = true;
		Use = false;
	}
	Center_X = X + 25;
	Center_Y = Y + 25;
}

void Missile::Set(int x, int y, char direction)
{
	missile.setSize(Vector2f(45, 45));
	Use = true;
	Active = false;
	X = x;
	Y = y;
	Center_X = X + 25;
	Center_Y = Y + 25;
	missile.setPosition(Vector2f(X, Y));
	Direction = direction;
	if (Direction == 'L') {
		DX = -1;
		DY = 0;
		texture.loadFromFile("mslL.png");
	}
	if (Direction == 'R') {
		DX = 1;
		DY = 0;
		texture.loadFromFile("mslR.png");
	}
	if (Direction == 'T') {
		DX = 0;
		DY = -1;
		texture.loadFromFile("mslT.png");
	}
	if (Direction == 'B') {
		DX = 0;
		DY = 1;
		texture.loadFromFile("mslB.png");
	}
	missile.setTexture(&texture);
}

bool FindActive(int i) {
	return MissileArray[i].Active;
}

bool FindUse(int i) {
	return MissileArray[i].Use;
}

void MissileCollision(Enemy& enemy, Missile& missile) {
	if (missile.Center_X < enemy.Right_Down_X && missile.Center_X > enemy.Left_Down_X) {
		if (missile.Center_Y < enemy.Right_Down_Y && missile.Center_Y > enemy.Right_Up_Y) {
			missile.Active = true;
			missile.Use = false;
			if (enemy.IsStopped) {
				enemy.Restart();
				SCORE += 20;
			}
			else {
				enemy.IsStopped = true;
				SCORE += 50;
			}
		}
	}
}
void MissileCollision(Player& player, Missile& missile) {
	if (missile.Center_X < player.Right_Down_X && missile.Center_X > player.Left_Down_X) {
		if (missile.Center_Y < player.Right_Down_Y && missile.Center_Y > player.Right_Up_Y) {
			missile.Active = true;
			missile.Use = false;
			player.Restart();
			SCORE = 0;
		}
	}
}


