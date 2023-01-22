#include <spdlog/sinks/stdout_color_sinks.h>
#include "Logger.h"

namespace Engine {

	std::shared_ptr<spdlog::logger> Logger::m_Console;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[ %l : %T ] %v %$");
		spdlog::set_level(spdlog::level::trace);

		m_Console = spdlog::stdout_color_mt("CONSOLE");
	}

}