#pragma once
#include "Logger.h"

namespace Engine {

	enum class DataType : uint8_t
	{
		Float,
		Float2,
		Float3,
		Float4,
	};

	static uint32_t DataTypeSize(DataType datatype)
	{
		switch (datatype)
		{
		case DataType::Float  : return 4;
		case DataType::Float2 : return 4 * 2;
		case DataType::Float3 : return 4 * 3;
		case DataType::Float4 : return 4 * 4;
		}

		Logger::Console()->error("Unknown Data Type");
		return 0;
	}

}