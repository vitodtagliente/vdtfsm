/// Copyright (c) Vito Domenico Tagliente
#pragma once

namespace vdtfsm
{
	using state_t = unsigned int;

	template <typename T>
	constexpr bool is_state_compatible(const T type_value)
	{
		return std::is_enum<type_value>::value || std::is_integral<type_value>::value;
	}
}