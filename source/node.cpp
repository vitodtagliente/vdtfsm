#include <vdtfsm/node.h>

namespace vdtfsm
{
	Node::Node(state_t state)
		: name(std::to_string(state))
		, m_state(state)
	{
	}

	Node::Node(state_t state, const std::string& name)
		: name(name)
		, m_state(state)
	{
	}

	Node::Node(state_t state, const std::string& name, const std::string& description)
		: name(name)
		, description(description)
		, m_state(state)
	{
	}

	bool Node::operator==(const Node& node) const
	{
		return m_state == node.m_state;
	}

	bool Node::operator!=(const Node& node) const
	{
		return m_state != node.m_state;
	}
}