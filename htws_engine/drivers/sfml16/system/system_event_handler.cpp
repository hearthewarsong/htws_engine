/*
 * SystemEventHandler.cpp
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#include "../../drivers_all.h"

#ifdef _3RD_SFML2

CREATE_STATIC_INSTANCE(SystemEventHandler);

SystemEventHandler::SystemEventHandler()
{
	// TODO Auto-generated constructor stub

}

SystemEventHandler::~SystemEventHandler()
{
	// TODO Auto-generated destructor stub
}

void SystemEventHandler::ProcessEvents()
{

}

void SystemEventHandler::AddKeyEventListener(
		IFunction<bool, const KeyEvent&>* listener)
{
}

void SystemEventHandler::AddCloseEventListener(
		IFunction<bool, const CloseEvent&>* listener)
{
}

#endif /* _3RD_SFML2 */

