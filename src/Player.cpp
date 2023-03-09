#include "Player.h"
#include "Missile.h"
#include "Drow.h"

Missile MissileArray[3];

Player::Player(std::string texture_name,int startX, int startY)
{
	player.setSize(Vector2f(45, 45));
	texture.loadFromFile(texture_name);
	player.setTexture(&texture);

	StartX = startX;
	StartY = startY;

	Left_Up_X = startX;
	Left_Up_Y = startY;

	CenterX = Left_Up_X + 20;
	CenterY = Left_Up_Y + 20;

	Right_Down_X = Left_Up_X + 44;
	Right_Down_Y = Left_Up_Y + 44;
	Left_Down_X = Left_Up_X;
	Left_Down_Y = Left_Up_Y + 44;
	Right_Up_X = Left_Up_X + 44;
	Right_Up_Y = Left_Up_Y;
}

void Player::Move(int x, int y, std::string Texture, char direction)
{
	if (Map[(Left_Up_Y + y) / 50][(Left_Up_X + x) / 50] == 0 && Map[(Right_Down_Y + y) / 50][(Right_Down_X + x) / 50] == 0 && Map[(Left_Down_Y + y) / 50][(Left_Down_X + x) / 50] == 0 && Map[(Right_Up_Y + y) / 50][(Right_Up_X + x) / 50] == 0)
	{
		Left_Up_X += x;
		Left_Up_Y += y;

		CenterX = Left_Up_X + 20;
		CenterY = Left_Up_Y + 20;

		Direction = direction;
		Right_Down_X = Left_Up_X + 44;
		Right_Down_Y = Left_Up_Y + 44;
		Left_Down_X = Left_Up_X;
		Left_Down_Y = Left_Up_Y + 44;
		Right_Up_X = Left_Up_X + 44;
		Right_Up_Y = Left_Up_Y;
		texture.loadFromFile(Texture);
		player.setTexture(&texture);
	}
}

void Player::Fire()
{
	for (int i = 0; i < 3; i++) {
		if (MissileArray[i].Active) {
			MissileArray[i].Set(Left_Up_X, Left_Up_Y, Direction);
			break;
		}
	}
}

void Player::Restart()
{
	Left_Up_X = StartX;
	Left_Up_Y = StartY;

	CenterX = Left_Up_X + 20;
	CenterY = Left_Up_Y + 20;

	Right_Down_X = Left_Up_X + 44;
	Right_Down_Y = Left_Up_Y + 44;
	Left_Down_X = Left_Up_X;
	Left_Down_Y = Left_Up_Y + 44;
	Right_Up_X = Left_Up_X + 44;
	Right_Up_Y = Left_Up_Y;
}
