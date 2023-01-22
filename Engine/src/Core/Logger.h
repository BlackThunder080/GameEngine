#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace spdlog { class logger; }


namespace Engine {

	class Logger
	{
	public:
		static void Init();
			
		static std::shared_ptr<spdlog::logger>& Console() { return m_Console; }
	private:
		static std::shared_ptr<spdlog::logger> m_Console;
	};

}