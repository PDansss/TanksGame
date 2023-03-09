#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

using namespace sf;
extern int Map[19][25];
void SetMap();
void DrowMap(RenderWindow& win,Player &player,Text text, Text text2, Text text3, Enemy &enem1, Enemy &enem2, Enemy &enem3, Enemy &enem4);
extern int SCORE;