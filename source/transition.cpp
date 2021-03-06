#include <vdtfsm/transition.h>

namespace vdtfsm
{
	Transition::Transition(state_t origin, state_t destination)
		: name(std::to_string(origin) + std::to_string(destination))
		, description()
		, m_origin(origin)
		, m_destination(destination)
	{
	}

	Transition::Transition(state_t origin, state_t destination, const std::string& name)
		: name(name)
		, description()
		, m_origin(origin)
		, m_destination(destination)
	{
	}

	Transition::Transition(state_t origin, state_t destination, const std::string& name, const std::string& description)
		: name(name)
		, description(description)
		, m_origin(origin)
		, m_destination(destination)
	{
	}
	
	bool Transition::operator==(const Transition& transition) const
	{
		return m_origin == transition.m_origin && m_destination == transition.m_destination;
	}

	bool Transition::operator!=(const Transition& transition) const
	{
		return m_origin != transition.m_origin || m_destination != transition.m_destination;
	}
}