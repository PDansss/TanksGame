#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Drow.h"

class Missile {
public:
	bool Active = true;
	bool Use = false;
	Texture texture;
	RectangleShape missile;
	Texture Ex_texture;
	RectangleShape Explosion;

	int X, Y,DX, DY;
	int Center_X, Center_Y;
	char Direction;
	void Move();
	void Set(int x, int y, char direction);
};
extern Missile MissileArray[3];
extern Missile MissileEnemyArray[12];

extern Enemy& Enem1;
extern Enemy& Enem2;
extern Enemy& Enem3;
extern Enemy& Enem4;

bool FindActive(int i);
bool FindUse(int i);
void MissileCollision(Enemy& enemy, Missile& missile);
void MissileCollision(Player& enemy, Missile& missile);
