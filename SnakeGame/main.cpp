﻿#include <SFML/Graphics.hpp>
#include <stdlib.h> // srand(), rand()
#include <time.h> // time()

#define DIR_UP       0
#define DIR_DOWN     1
#define DIR_RIGHT    2
#define DIR_LEFT     3

#define BODY_MAX     20

using namespace sf;

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Snake {
public:
	int dir_;
	int length_;
	float thickness; // 외피 두께
	Object body_[BODY_MAX];
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main(void) {

	const int WIDTH = 1000;
	const int HEIGHT = 800;

	int block = 40; // 한 칸을 40으로
	const int w = WIDTH / block;
	const int h = HEIGHT / block;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	window.setFramerateLimit(10); // snake 움직이는 속도 조절 (1초에 n번의 작업이 이루어지도록 프레임을 조절) -> 사양에 관계없이 똑같은 속도로 처리됨 

	srand(time(NULL));

	Snake snake;
	snake.length_ = 1;
	snake.dir_ = DIR_DOWN;
	snake.thickness = 5.f;
	float snake_inner = block - snake.thickness;

	// TODO: 뱀과 사과가 걸치지 않도록 수정하기
	for (int i = 0; i < BODY_MAX; i++) {
		snake.body_[i].x_ = -100;
		snake.body_[i].y_ = -100;
		snake.body_[i].sprite_.setPosition(snake.body_[i].x_ * block, snake.body_[i].y_ * block);
		snake.body_[i].sprite_.setSize(Vector2f(snake_inner, snake_inner));
		snake.body_[i].sprite_.setFillColor(Color::Green);

		// 뱀의 테두리
		snake.body_[i].sprite_.setOutlineColor(Color::Color(0, 128, 0));
		snake.body_[i].sprite_.setOutlineThickness(5);
	}
	snake.body_[0].x_ = 3;
	snake.body_[0].y_ = 3;

	Apple apple;
	apple.x_ = rand() % w;
	apple.y_ = rand() % h;
	apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
	apple.sprite_.setSize(Vector2f(block, block));
	apple.sprite_.setFillColor(Color::Red);


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 창 닫기를 눌렀을 때 (윈도우 창의 X 표시) 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			snake.dir_ = DIR_UP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			snake.dir_ = DIR_DOWN;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			snake.dir_ = DIR_LEFT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			snake.dir_ = DIR_RIGHT;
		}

		// update

		// 뱀의 몸통에 대한 이동
		for (int i = snake.length_ - 1; i > 0; i--) {
			snake.body_[i].x_ = snake.body_[i - 1].x_;
			snake.body_[i].y_ = snake.body_[i - 1].y_;
		}

		// 뱀의 머리에 대한 이동
		if (snake.dir_ == DIR_UP) {
			snake.body_[0].y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.body_[0].y_++;
		}
		else if (snake.dir_ == DIR_LEFT) {
			snake.body_[0].x_--;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.body_[0].x_++;
		}

		// 뱀이 사과를 먹었을 때 길이가 늘어남
		if (snake.body_[0].x_ == apple.x_ && snake.body_[0].y_ == apple.y_)
		{
			apple.x_ = rand() % w;
			apple.y_ = rand() % h;
			apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
			if(snake.length_ < BODY_MAX)
				snake.length_++;
		}


		// 경계범위를 넘었을 때
		if (snake.body_[0].x_ < 0)
			snake.body_[0].x_ = 0;
		if (snake.body_[0].x_ >= w)
			snake.body_[0].x_ = w - 1;
		if (snake.body_[0].y_ < 0)
			snake.body_[0].y_ = 0;
		if (snake.body_[0].y_ >= h)
			snake.body_[0].y_ = h - 1;

		for (int i = 0; i < snake.length_; i++) {
			snake.body_[i].sprite_.setPosition(snake.body_[i].x_ * block, snake.body_[i].y_ * block);
		}


		// render

		window.clear();

		for (int i = 0; i < BODY_MAX; i++) {
			window.draw(snake.body_[i].sprite_);
		}
		window.draw(apple.sprite_); // 뱀과 사과가 겹칠 경우 사과가 위에 나옴 (먼저 draw 해서)

		window.display();

	}

	return 0;
}