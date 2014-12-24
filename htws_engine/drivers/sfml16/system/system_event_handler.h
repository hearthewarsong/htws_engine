/*
 * system_event_handler.h
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#ifndef SYSTEM_EVENT_HANDLER_H_
#define SYSTEM_EVENT_HANDLER_H_

class SystemEventHandler: public ISystemEventHandler
{
protected:
	typedef vector<IFunction<bool,const CloseEvent&>*> CloseEventListeners;
	typedef vector<IFunction<bool,const KeyEvent&>*> KeyEventListeners;
	typedef vector<IFunction<bool,const TextKeyEvent&>*> TextKeyEventListeners;
	CloseEventListeners closeEventListeners;
	KeyEventListeners keyEventListeners;
	TextKeyEventListeners textKeyEventListeners;
	sf::Window* window;
public:
	SystemEventHandler(sf::Window* window);
	virtual ~SystemEventHandler();

	void ProcessEvents();
	void AddKeyEventListener(OWNERSHIP IFunction<bool,const KeyEvent&>* listener);
	void AddTextKeyEventListener(OWNERSHIP IFunction<bool,const TextKeyEvent&>* listener);
	void AddCloseEventListener(OWNERSHIP IFunction<bool,const CloseEvent&>* listener);

};

#endif /* SYSTEM_EVENT_HANDLER_H_ */
