/*
 * SystemEventHandler.cpp
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#include "../../drivers_all.h"

#ifdef _3RD_SFML16

SystemEventHandler ::SystemEventHandler(sf::Window* window) :window(window)
{

}

SystemEventHandler::~SystemEventHandler()
{
	foreach(KeyEventListeners,keyEventListeners, it){
	delete *it;
}
foreach(CloseEventListeners,closeEventListeners, it)
{
	delete *it;
}
}

void SystemEventHandler::ProcessEvents()
{
	sf::Event event;
	while(window->GetEvent(event))
	{
		switch(event.Type)
		{
		case sf::Event::KeyPressed:
			{
				KeyEvent keyEvent(event.Key.Code, false, event.Key.Alt, event.Key.Control, event.Key.Shift);
				foreach(KeyEventListeners,keyEventListeners,it)
				{
					(**it)(keyEvent);
				}
			}
			break;
		case sf::Event::TextEntered:
			{
				TextKeyEvent textKeyEvent(event.Key.Code);
				foreach(TextKeyEventListeners,textKeyEventListeners,it)
				{
					(**it)(textKeyEvent);
				}
			}
			break;
		case sf::Event::Closed:
			{
				CloseEvent closedEvent;
				foreach(CloseEventListeners,closeEventListeners,it)
				{
					(**it)(closedEvent);
				}
			}
			break;
		default:
			break;
		}
	}
}

void SystemEventHandler::AddKeyEventListener(
		IFunction<bool, const KeyEvent&>* listener)
{
	keyEventListeners.push_back(listener);
}

void SystemEventHandler::AddCloseEventListener(
		IFunction<bool, const CloseEvent&>* listener)
{
	closeEventListeners.push_back(listener);
}

void SystemEventHandler::AddTextKeyEventListener(
		IFunction<bool, const TextKeyEvent&>* listener)
{
	textKeyEventListeners.push_back(listener);
}

#endif /* _3RD_SFML2 */

