#include "Controller.h"

Controller::Controller()
{
}

void Controller::run(sf::RenderWindow& window, std::string level)
{

	ToolBar toolbar;
	while (window.isOpen())
	{
		//Clear window
		window.clear();

		//draw the toolbar:
		//Toolbar.draw(window);
		toolbar.draw(window);
		//Display on the window:
		window.display();



		if (auto event = sf::Event{}; window.pollEvent(event))
		{

			switch (event.type)
			{
				//closing window:
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				//// HERE we check if we click on color and sent the clolr to the function that do the algoretem

				break;
			}

		
		}
	}

}



Controller::~Controller()
{
}
