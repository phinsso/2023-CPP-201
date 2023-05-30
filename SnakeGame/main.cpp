#include <SFML/Graphics.hpp>
#include <stdlib.h> // srand(), rand()
#include <time.h> // time()

#define DIR_UP       0
#define DIR_DOWN     1
#define DIR_RIGHT    2
#define DIR_LEFT     3

using namespace sf;

class Snake {
public:
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;   // 그래픽
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
	snake.dir_ = DIR_DOWN;
	snake.x_ = 3;
	snake.y_ = 3;
	snake.sprite_.setPosition(snake.x_ * block, snake.y_ * block);
	snake.sprite_.setSize(Vector2f(block, block));
	snake.sprite_.setFillColor(Color::Green);

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

		// 경계범위 안에 있을 때, 뱀 이동
		if (snake.dir_ == DIR_UP) {
			snake.y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.y_++;
		}
		else if (snake.dir_ == DIR_LEFT) {
			snake.x_--;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.x_++;
		}

		// 경계범위를 넘었을 때
		if (snake.x_ < 0)
			snake.x_ = 0;
		if (snake.x_ >= w)
			snake.x_ = w - 1;
		if (snake.y_ < 0)
			snake.y_ = 0;
		if (snake.y_ >= h)
			snake.y_ = h - 1;

		snake.sprite_.setPosition(snake.x_ * block, snake.y_ * block);

		// 뱀이 사과를 먹었을 때
		if (snake.x_ == apple.x_ && snake.y_ == apple.y_)
		{
			apple.x_ = rand() % w;
			apple.y_ = rand() % h;
			apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
		}


		// render

		window.clear();

		window.draw(apple.sprite_); // 뱀과 사과가 겹칠 경우 사과가 위에 나옴 (먼저 draw 해서)
		window.draw(snake.sprite_);

		window.display();

	}

	return 0;
}