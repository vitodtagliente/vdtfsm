#include <vdtfsm/fsm.h>

#include <cassert>

namespace vdtfsm
{
	Fsm::Fsm()
		: name()
		, m_nodes()
	{}

	Fsm::Fsm(const std::string& name)
		: name(name)
		, m_nodes()
	{}

	bool Fsm::isValidState(state_t state) const
	{
		return m_nodes.find(state) != m_nodes.end();
	}
}