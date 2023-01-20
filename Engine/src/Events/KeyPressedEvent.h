#pragma once

namespace Engine {

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(const int keycode, bool isRepeat = false)
			: m_IsRepeat(isRepeat) {}
	private:
		bool m_IsRepeat;
	};

}