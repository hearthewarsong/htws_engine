/*
 * SystemEventHandler.cpp
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#include "../../drivers_all.h"

#ifdef _3RD_SFML16

CREATE_STATIC_INSTANCE(SystemEventHandler);

SystemEventHandler ::SystemEventHandler()
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

#endif /* _3RD_SFML2 */

