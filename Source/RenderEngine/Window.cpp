#include "../../RenderEngine/Window.h"



Window::Window()
{

}

Window::Window(int width, int height, std::string windowName)
{
	initialise(width, height, "Default Window");
	circleShape.setFillColor(sf::Color::Red);
	circleShape.setRadius(40);
	circleShape.setPosition(0, 0);
}

void Window::initialise(int width, int height, std::string windowName)
{
}

Window::~Window()
{

}

void Window::clear()
{

}


void Window::display()
{

}
