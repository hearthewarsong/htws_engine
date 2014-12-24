#ifndef I_SYSTEM_EVENT_HANDLER_H_
#define I_SYSTEM_EVENT_HANDLER_H_

class Event
{
public:
	enum EventType
	{
		KEY_EVENT, CLOSE_EVENT
	};
	Event(EventType eventType) :
			eventType(eventType)
	{
	}
	EventType eventType;
};

class KeyEvent: public Event
{
public:
	int keyCode;
	bool isUp;
    bool      alt;
    bool      control;
    bool      shift;
	KeyEvent(int keyCode, bool isUp, bool alt, bool control, bool shift) :
			Event(Event::KEY_EVENT), keyCode(keyCode), isUp(isUp), alt(alt), control(control), shift(shift)
	{
	}
};

class TextKeyEvent: public Event
{
public:
	int keyCode;
	TextKeyEvent(int keyCode) :
			Event(Event::KEY_EVENT), keyCode(keyCode)
	{
	}
};

class CloseEvent: public Event
{
public:
	CloseEvent() :
			Event(Event::CLOSE_EVENT)
	{
	}
	virtual ~CloseEvent()
	{
	}
};

class ISystemEventHandler
{
public:
	virtual void ProcessEvents() pure;
	virtual void AddKeyEventListener(OWNERSHIP IFunction<bool,const KeyEvent&>* listener) pure;
	virtual void AddTextKeyEventListener(OWNERSHIP IFunction<bool,const TextKeyEvent&>* listener) pure;
	virtual void AddCloseEventListener(OWNERSHIP IFunction<bool,const CloseEvent&>* listener) pure;
	virtual ~ISystemEventHandler()
	{
	}
};

#endif /* I_SYSTEM_EVENT_HANDLER_H_ */
