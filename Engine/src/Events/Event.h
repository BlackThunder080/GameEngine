#pragma once

namespace Engine {

	enum EventType
	{
		KeyPressed,
		KeyReleased,
	};

	class Event
	{
	public:
		EventType type;
	private:
	};

}