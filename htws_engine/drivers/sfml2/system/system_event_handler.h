/*
 * system_event_handler.h
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#ifndef SYSTEM_EVENT_HANDLER_H_
#define SYSTEM_EVENT_HANDLER_H_

class SystemEventHandler: public ISystemEventHandler, public Singleton<SystemEventHandler>
{
public:
	SystemEventHandler();
	virtual ~SystemEventHandler();

	void ProcessEvents();
	void AddKeyEventListener(OWNERSHIP IFunction<bool,const KeyEvent&>* listener);
	void AddCloseEventListener(OWNERSHIP IFunction<bool,const CloseEvent&>* listener);

};

#endif /* SYSTEM_EVENT_HANDLER_H_ */
