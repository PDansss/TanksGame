#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"


using namespace sf;
class Enemy
{
public:
	Texture texture;
	RectangleShape enemy;
	int Left_Up_X, Left_Up_Y, Right_Down_X, Right_Down_Y, Left_Down_X, Left_Down_Y, Right_Up_Y, Right_Up_X;
	int DX, DY;
	int RestartX, RestartY;
	bool IsStopped = false;
	bool MakeFire = false;
	char Direction = 'T';
	int turn = 0;
	bool IsReady = true;

	int MissileLimit = 0;

	Enemy(std::string texture, int startX, int startY);
	void Move(Player& player);
	void Fire();
	void Restart();
	void Analyze(Player& player);
};
