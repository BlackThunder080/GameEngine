#pragma once
#include "Event.h"

namespace Engine {

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(const int keycode, bool IsRepeat = false)
			: scancode(keycode), isRepeat(IsRepeat) {
			type = EventType::KeyPressed;
		}
		int scancode;
		bool isRepeat;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(const int keycode)
			: scancode(keycode) {
			type = EventType::KeyReleased;
		}
		int scancode;
	};

}