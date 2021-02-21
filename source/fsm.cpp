#include <vdtfsm/fsm.h>

#include <cassert>

namespace vdtfsm
{
	Fsm::Fsm()
		: name()
		, m_nodes()
		, m_state()
	{}

	Fsm::Fsm(const std::string& name)
		: name(name)
		, m_nodes()
		, m_state()
	{}

	bool Fsm::exists(const state_t state) const
	{
		return m_nodes.find(state) != m_nodes.end();
	}

	void Fsm::start(const state_t state)
	{
		const auto& it = m_nodes.find(state);
		assert(it != m_nodes.end());
		Node& node = it->second;
		m_state = state;
		node.enter();
	}

	void Fsm::changeState(const state_t state)
	{
		const auto& it = m_nodes.find(state);
		assert(it != m_nodes.end());
		Node& node = it->second;
		m_state = state;
		node.enter();
	}
}