#include "TanksGame.h"
#include "Player.h"
#include "Drow.h"
#include "Enemy.h"


int main()
{
	const int width = 1600, height = 950;
	RenderWindow window(VideoMode(width, height), "Tanks", Style::Close);
	window.setPosition(Vector2i(150, 20));

	Player player = Player("PlayerTankTop.png", 1150, 850);
	
	Enemy Enemy1 = Enemy("EnemyTankBottom.png", 153, 50);
	Enemy Enemy2 = Enemy("EnemyTankBottom.png", 653, 350);
	Enemy Enemy3 = Enemy("EnemyTankBottom.png", 353, 750);
	Enemy Enemy4 = Enemy("EnemyTankBottom.png", 53, 850);
	
	SetMap();

	Font font;
	font.loadFromFile("BRLNSR.ttf");
	Text Label("TANKS", font, 60);
	Label.setStyle(Text::Bold);
	Label.setPosition(1325, 20);
	Text Score("SCORE:", font, 60);
	Score.setStyle(Text::Bold);
	Score.setPosition(1270, 120);
	Text TextScore("0", font, 55);
	TextScore.setStyle(Text::Bold);
	TextScore.setPosition(1475, 120);

	window.setFramerateLimit(120);
	bool isSpacePressed = false;
	int MoveTick = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			else if (event.key.code == Keyboard::A) {
				player.Move(-1, 0, "PlayerTankLeft.png",'L');
			}
			else if (event.key.code == Keyboard::W) {
				player.Move(0, -1, "PlayerTankTop.png", 'T');
			}
			else if (event.key.code == Keyboard::S) {
				player.Move(0, 1, "PlayerTankBottom.png", 'B');
			}
			else if (event.key.code == Keyboard::D) {
				player.Move(1, 0, "PlayerTankRight.png", 'R');
			}
			if (Keyboard::isKeyPressed(Keyboard::Space) && !isSpacePressed) {
				isSpacePressed = true;
				player.Fire();
			}
			if (event.key.code == Keyboard::Space && event.type == Event::KeyReleased) {
				isSpacePressed = false;
			}

		}
		DrowMap(window,player, Label, Score, TextScore, Enemy1, Enemy2, Enemy3, Enemy4);

		if (MoveTick == 1) {
			Enemy1.Move(player);
		}
		if (MoveTick == 2) {
			Enemy3.Move(player);
		}
		if (MoveTick == 3) {
			Enemy2.Move(player);
		}
		if (MoveTick == 4) {
			Enemy4.Move(player);
			MoveTick = 0;
		}
		MoveTick++;
	}
	return 0;
}
