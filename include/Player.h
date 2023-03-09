#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Player
{
public:
	Texture texture;
	RectangleShape player;
	int Left_Up_X, Left_Up_Y,Right_Down_X, Right_Down_Y,Left_Down_X, Left_Down_Y,Right_Up_Y, Right_Up_X;
	int StartX, StartY;
	int CenterX, CenterY;
	char Direction = 'T';
	Player(std::string texture, int startX, int startY);
	void Move(int x,int y, std::string texture,char direction);
	void Fire();
	void Restart();
};
