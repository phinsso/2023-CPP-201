﻿#include <SFML/Graphics.hpp>
#include<stdlib.h>
#include<time.h>

using namespace sf;

class Entity {
public:
	// 거의 대부분이 클래스를 매개변수로 할 때는 주소값으로 받는다
	// 메모리 용량 및 call by value 이슈 때문에 사용함
	Entity(int life, int speed, RectangleShape* sprite)
		:life_(life), sprite_(sprite), speed_(speed)
	{
	}

	 ~Entity() {}

	 // sprite_의 위치를 x, y만큼 변경
	 void move(float x, float y)
	 {
		 sprite_->move(x, y);
	 }

	 // getter
	 int get_life() { return life_; }
	 RectangleShape get_sprite() { return *sprite_; }
	 int get_speed() { return speed_; }

	 // setter
	 void set_life(int val) { life_ = val; }
	 void set_speed(int val) { speed_ = val; }
	 void set_sprite(RectangleShape* val) { sprite_ = val; }

private:
	int life_;
	int speed_;
	RectangleShape* sprite_;
};

int main(void)
{
	srand((unsigned int)time(NULL));

	RenderWindow window(VideoMode(1000, 800), "Sangsok");
	window.setFramerateLimit(60);

	RectangleShape sp1;
	sp1.setPosition(400, 300);
	sp1.setSize(Vector2f(50, 50));
	sp1.setFillColor(Color::Blue);

	RectangleShape se1;
	se1.setPosition(rand() % 800, rand() % 600);
	se1.setSize(Vector2f(40, 40));
	se1.setFillColor(Color::Yellow);

	Entity* player = new Entity(3, 5, &sp1);
	Entity* enemy1 = new Entity(1, 5, &se1);

	while (window.isOpen()) {
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		// Input
		// 방향키 이동
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player->move(0, -player->get_speed());
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player->move(0, player->get_speed());
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player->move(-player->get_speed(), 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player->move(player->get_speed(), 0);
		}
		

		// Update

		// Render

		window.clear();

		window.draw(enemy1->get_sprite());
		window.draw(player->get_sprite());
		window.display();
	}

	return 0;
}