/*
 * sfml2_window.h
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#ifndef SFML2_WINDOW_H_
#define SFML2_WINDOW_H_

class Window : IWindow
{
public:
	Window();
	void Render(ICanvas * canvas);
	virtual ~Window();
};

#endif /* SFML2_WINDOW_H_ */
