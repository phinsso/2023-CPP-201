﻿#include <SFML/Graphics.hpp>

using namespace sf;

int main(void) {

	RenderWindow window(VideoMode(640, 480), "Snake Game");
	window.setFramerateLimit(60); // snake 움직이는 속도 조절 (1초에 60번의 작업이 이루어지도록 프레임을 조절) -> 사양에 관계없이 똑같은 속도로 처리됨 

	RectangleShape snake;
	snake.setPosition(200, 300);
	snake.setSize(Vector2f(30, 30));
	snake.setFillColor(Color::Green);

	RectangleShape apple;
	apple.setPosition(300, 400);
	apple.setSize(Vector2f(30, 30));
	apple.setFillColor(Color::Red);


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
			snake.move(0, -5);
		else if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.move(0, 5);
		else if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.move(-5, 0);
		else if (Keyboard::isKeyPressed(Keyboard::Right))
			snake.move(5,0);

		window.clear();

		window.draw(apple); // 뱀과 사과가 겹칠 경우 사과가 위에 나옴 (먼저 draw 해서)
		window.draw(snake);

		window.display();

	}

	return 0;
}