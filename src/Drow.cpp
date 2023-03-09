#include "Drow.h"
#include "Player.h"
#include "Missile.h"
#include "Enemy.h"

const int scaleparam = 50;
const int Map_Width = 25;
const int Map_Height = 19;

int Map[19][25];

Texture UnbreakableWall;
Texture Wall;

RectangleShape _UnbreakableWall(Vector2f(50, 50));
RectangleShape _Wall(Vector2f(50, 50));

Image MissileIm;
Texture MissileTexture;
Texture MissileGrayTexture;
Sprite MissileSprArr[3];

int SCORE = 0;

int countActiveMissiles = 3;

void SetMap() {
	MissileIm.loadFromFile("Missile.png");
	MissileGrayTexture.loadFromFile("MissileGray.png");
	MissileTexture.loadFromImage(MissileIm);
	for (int i = 0; i < 3; i++) {
		MissileSprArr[i].setTexture(MissileTexture);
		MissileSprArr[i].setPosition(1300 + (i * 50), 220);
	}

	UnbreakableWall.loadFromFile("UnbreakableWall.png");
	_UnbreakableWall.setTexture(&UnbreakableWall);
	Wall.loadFromFile("Wall.png");
	_Wall.setTexture(&Wall);
	for (int i = 0; i < Map_Height; i++) {
		for (int j = 0; j < Map_Width; j++) {
			if (i == 0 || i == Map_Height - 1 || j == 0 || j == Map_Width - 1)
				Map[i][j] = 3;
			else if(j % 2 == 0 && i % 2 != 0)
				Map[i][j] = 2;
			else
				Map[i][j] = 0;
		}
	}
}

void DrowMap(RenderWindow& win,Player &player, Text text1, Text text2, Text text3, Enemy &enem1, Enemy &enem2, Enemy &enem3, Enemy &enem4)
{
	win.clear();
	player.player.setPosition(player.Left_Up_X, player.Left_Up_Y);
	win.draw(player.player);

	enem1.enemy.setPosition(enem1.Left_Up_X, enem1.Left_Up_Y);
	win.draw(enem1.enemy);
	enem2.enemy.setPosition(enem2.Left_Up_X, enem2.Left_Up_Y);
	win.draw(enem2.enemy);
	enem3.enemy.setPosition(enem3.Left_Up_X, enem3.Left_Up_Y);
	win.draw(enem3.enemy);
	enem4.enemy.setPosition(enem4.Left_Up_X, enem4.Left_Up_Y);
	win.draw(enem4.enemy);

	for (int i = 0; i < Map_Height; i++) {
		for (int j = 0; j < Map_Width; j++) {
			if (Map[i][j] == 3) {
				_UnbreakableWall.setPosition(Vector2f(j * scaleparam, i * scaleparam));
				win.draw(_UnbreakableWall);
			}
			if (Map[i][j] == 2 || Map[i][j] == 1) {
				_Wall.setPosition(Vector2f(j * scaleparam, i * scaleparam));
				win.draw(_Wall);
			}
		}
	}
	countActiveMissiles = 0;

	for (int i = 0; i < 3; i++) {
		if (MissileArray[i].Use) {
			MissileArray[i].Move();
			win.draw(MissileArray[i].missile);
			countActiveMissiles++;
			MissileCollision(enem1, MissileArray[i]);
			MissileCollision(enem2, MissileArray[i]);
			MissileCollision(enem3, MissileArray[i]);
			MissileCollision(enem4, MissileArray[i]);
		}
	}

	for (int i = 0; i < 12; i++) {
		if (MissileEnemyArray[i].Use) {
			MissileEnemyArray[i].Move();
			MissileCollision(player, MissileEnemyArray[i]);
			win.draw(MissileEnemyArray[i].missile);
		}
	}

	for (int i = 0; i < 3; i++) {
		if (i >= countActiveMissiles) {
			MissileSprArr[i].setTexture(MissileTexture);
		}
		else {
			MissileSprArr[i].setTexture(MissileGrayTexture);
		}
		win.draw(MissileSprArr[i]);
	}
	win.draw(text1);
	win.draw(text2);
	text3.setString(std::to_string(SCORE));
	win.draw(text3);
	win.display();
}

