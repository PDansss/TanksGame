#include "Enemy.h"
#include "Drow.h"
#include "Missile.h"
#include "Player.h"

Enemy::Enemy(std::string texture_name, int startX, int startY)
{
	enemy.setSize(Vector2f(45, 45));
	texture.loadFromFile(texture_name);
	enemy.setTexture(&texture);
	Left_Up_X = startX;
	Left_Up_Y = startY;
	Right_Down_X = Left_Up_X + 44;
	Right_Down_Y = Left_Up_Y + 44;
	Left_Down_X = Left_Up_X;
	Left_Down_Y = Left_Up_Y + 44;
	Right_Up_X = Left_Up_X + 44;
	Right_Up_Y = Left_Up_Y;
	RestartX = startX;
	RestartY = startY;
}
int GetDir() {
	return rand() % 4;
}

void Enemy::Move(Player& player)
{
	Analyze(player);
	if(!IsStopped){
		if (IsReady) {
			int Dir = GetDir();
			switch (Dir)
			{
			case 0:
				Direction = 'L';
				DX = -2;
				DY = 0;
				texture.loadFromFile("EnemyTankLeft.png");
				break;
			case 1:
				Direction = 'T';
				DX = 0;
				DY = -2;
				texture.loadFromFile("EnemyTankTop.png");
				break;
			case 2:
				Direction = 'B';
				DX = 0;
				DY = 2;
				texture.loadFromFile("EnemyTankBottom.png");
				break;
			case 3:
				Direction = 'R';
				DX = 2;
				DY = 0;
				texture.loadFromFile("EnemyTankRight.png");
				break;
			}
			IsReady = false;
		}

		if (!IsReady && turn != 25) {
			if (Map[(Left_Up_Y + DY) / 50][(Left_Up_X + DX) / 50] == 0 && Map[(Right_Down_Y + DY) / 50][(Right_Down_X + DX) / 50] == 0 && Map[(Left_Down_Y + DY) / 50][(Left_Down_X + DX) / 50] == 0 && Map[(Right_Up_Y + DY) / 50][(Right_Up_X + DX) / 50] == 0) {
				Left_Up_X += DX;
				Left_Up_Y += DY;
				Right_Down_X = Left_Up_X + 44;
				Right_Down_Y = Left_Up_Y + 44;
				Left_Down_X = Left_Up_X;
				Left_Down_Y = Left_Up_Y + 44;
				Right_Up_X = Left_Up_X + 44;
				Right_Up_Y = Left_Up_Y;
				enemy.setTexture(&texture);
				turn++;
			}
			else {
				Fire();
				IsReady = true;
				turn = 0;
			}
		}
		if (turn == 25) {
			IsReady = true;
			turn = 0;
			MissileLimit = 0;
		}
	}
}

Missile MissileEnemyArray[12];

void Enemy::Fire()
{
	if (MissileLimit != 3) {
		for (int i = 0; i < 12; i++) {
			if (MissileEnemyArray[i].Active) {
				MissileEnemyArray[i].Set(Left_Up_X, Left_Up_Y, Direction);
				break;
			}
		}
		MissileLimit++;
	}
}

void Enemy::Analyze(Player &player) {
	switch (Direction)
	{
	case 'L':
		if (Right_Up_Y < player.CenterY && Right_Down_Y > player.CenterY) {
			MakeFire = true;
			for (int i = Right_Up_X / 50; i >= 0; i--) {
				if (player.CenterX / 50 == i) {
					MakeFire = true;
					break;
				}
				if (Map[player.CenterY / 50][i] != 0) {
					MakeFire = false;
					break;
				}
			}
			if (MakeFire) {
				Fire();
				MakeFire = false;
			}
		}
		break;
	case 'R':			
		if (Right_Up_Y < player.CenterY && Right_Down_Y > player.CenterY) {
			MakeFire = true;
			for (int i = Right_Up_X / 50; i < 24; i++) {
				if (player.CenterX / 50 == i) {
					MakeFire = true;
					break;
				}
				if (Map[player.CenterY / 50][i] != 0) {
					MakeFire = false;
					break;
				}
			}
			if (MakeFire) {
				Fire();
				MakeFire = false;
			}
		}		
		break;
	case 'T':
		if (Left_Up_X < player.CenterX && Right_Up_X > player.CenterX) {
			for (int j = Right_Down_Y / 50; j > 0; j--){
				if (player.CenterY / 50 == j) {
					MakeFire = true;
					break;
				}
				if (Map[j][player.CenterX / 50] != 0) {
					MakeFire = false;
					break;
				}
			}
			if (MakeFire) {
				Fire();
				MakeFire = false;
			}
		}
		break;
	case 'B':
		if (Left_Up_X < player.CenterX && Right_Up_X > player.CenterX) {
			MakeFire = true;
			for (int j = Right_Down_Y / 50; j < 19; j++) {
				if (player.CenterY / 50 == j) {
					MakeFire = true;
					break;
				}
				if (Map[j][player.CenterX / 50] != 0) {
					MakeFire = false;
					break;
				}
			}
			if (MakeFire) {
				Fire();
				MakeFire = false;
			}
		}
		break;
	}
}

void Enemy::Restart()
{
	Left_Up_X = RestartX;
	Left_Up_Y = RestartY;

	Right_Down_X = Left_Up_X + 44;
	Right_Down_Y = Left_Up_Y + 44;
	Left_Down_X = Left_Up_X;
	Left_Down_Y = Left_Up_Y + 44;
	Right_Up_X = Left_Up_X + 44;
	Right_Up_Y = Left_Up_Y;
	IsStopped = false;
	Direction = 'T';
}
