#include <iostream>
#include "Object.h"
#include <math.h>
#include <SFML\Graphics.hpp>
#include <random>
#include <ctime>

using namespace std;
using namespace sf;

int main()
{	
	srand((unsigned int)time(NULL));

	RenderWindow window(VideoMode(720, 480), "SFML", Style::Close);

	Object obj = Object();
	Object objT = Object(540, 360, 40);
	Object objC = obj + objT;

	obj.render(&window);
	objT.render(&window);
	objC.render(&window);
	window.display();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}

	return 0;
}
