#include <SFML/Graphics.hpp>

using namespace sf;

int main(void) {

	RenderWindow window(VideoMode(640, 480), "Snake Game");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 창 닫기를 눌렀을 때 (윈도우 창의 X 표시) 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.display();

	}

	return 0;
}