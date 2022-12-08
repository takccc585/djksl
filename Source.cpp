#include <SFML/Graphics.hpp>
#include<ctime>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const string WINDOW_TITLE = "SFML Lesson 3";
const float FPS = 120;
const float batDy = 10.f;
float dx = rand() % 30 - 15;
float dy = rand() % 30 - 15;
float dx1 = 5.f;
float dy1 = 5.f;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	//создание игровых объектов
	const int size = 5;
	float sizew = 20.f;
	float sizeh = 80.f;
	float otstup = 50.f;
	float radius = 10;
	CircleShape arr_circles[size];
	for (int i = 0; i < size;i++) {
		arr_circles[i].setRadius(radius);
		arr_circles[i].setFillColor(Color{(Uint8)(rand()%256),(Uint8)(rand() % 256),(Uint8)(rand() % 256)});
		arr_circles[i].setPosition(rand()% 800, -rand() % 800);
	}
	//правая ракетка
	srand(time(nullptr));
		RectangleShape r;
		r.setSize(Vector2f(sizew, sizeh));
		r.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
		r.setPosition(otstup, WINDOW_HEIGHT / 2 - sizeh / 2);
	//ЛЕВАЯ РАКЕТКА
		RectangleShape r1;
		r1.setSize(Vector2f(sizew, sizeh));
		r1.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
		r1.setPosition(WINDOW_WIDTH - (7 * otstup) / 5, WINDOW_HEIGHT / 2 - sizeh / 2);

	/*CircleShape circl;
	float radius = 25.f;
	circl.setRadius(radius);
	circl.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	circl.setPosition(WINDOW_WIDTH / 2 - radius, WINDOW_HEIGHT / 2 - radius);*/
	CircleShape circl1;
	float radius1 = 50.f;
	circl1.setRadius(radius1);
	circl1.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	circl1.setPosition(WINDOW_WIDTH / 2 - radius1, WINDOW_HEIGHT / 2 - radius1);

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//об
		//старый круг
		/*circl.move(dx1, dy1);
		if ((circl.getPosition().x + 2 * radius >= WINDOW_WIDTH) or (circl.getPosition().x <= 0)) {
			dx = -dx;
		}
		if ((circl.getPosition().y + 2 * radius >= WINDOW_HEIGHT) or (circl.getPosition().y <= 0)) {
			dy = -dy;
		}*/

		//новый круг
		//движение по у
			if (Keyboard::isKeyPressed(Keyboard::W)) {
			circl1.move(0, -dy1);
		}
			else if (Keyboard::isKeyPressed(Keyboard::S)) {
			circl1.move(0, dy1);
		}
		//движение по х
			if (Keyboard::isKeyPressed(Keyboard::D)) {
			circl1.move(dx1, 0);
		}
			else if (Keyboard::isKeyPressed(Keyboard::A)) {
			circl1.move(-dx1, 0);
		}
		//ограничения по границам
			//x
				if (circl1.getPosition().x + 2 * radius1 >= WINDOW_WIDTH)  {
			circl1.move(-dx1,0);
		}
				if (circl1.getPosition().x <= 0) {
			circl1.move(dx1, 0);
		}
			//y
				if (circl1.getPosition().y + 2 * radius1 >= WINDOW_HEIGHT)  {
			circl1.move(0, -dy1);
		}
				if (circl1.getPosition().y <= 0) {
			circl1.move(0, dy1);
		}
		//***************************************************************************

		//падающие шарики
				for (int i = 0; i < size; i++) {
					arr_circles[i].move(0, 10.f);

				if (arr_circles[i].getPosition().y >= WINDOW_HEIGHT) {
					arr_circles[i].setPosition(rand() % 800,- rand() % 800);
					}
				}
		//движение левой ракетки

		/*if (Keyboard::isKeyPressed(Keyboard::W)) {
			r.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			r.move(0, batDy);
		}
		if ((r.getPosition().y + sizeh >= WINDOW_HEIGHT)) {
			r.setPosition(otstup, WINDOW_HEIGHT - sizeh);
		}
		if ((r.getPosition().y <= 0)) {
			r.setPosition(otstup, 0);
		}*/

		//движение правой ракетки

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			r1.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			r1.move(0, batDy);
		}
		if ((r1.getPosition().y + sizeh >= WINDOW_HEIGHT)) {
			r1.setPosition(WINDOW_WIDTH - (7 * otstup) / 5, WINDOW_HEIGHT-sizeh);
		}
		if ((r1.getPosition().y <= 0)) {
			r1.setPosition(WINDOW_WIDTH- (7 * otstup) / 5, 0);
		}

		// Отрисовка окна 
		window.clear();
		for (int i = 0; i < size; i++) {
			window.draw(arr_circles[i]);
		}
		window.draw(r);
		window.draw(r1);
		window.draw(circl1);
		window.display();
	}
	return 0;
}