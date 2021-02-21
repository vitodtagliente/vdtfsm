#include <vdtfsm/builder.h>

#include <cassert>

namespace vdtfsm
{
	Builder::Builder(Fsm& fsm)
		: m_fsm(fsm)
	{

	}

	Node& Builder::addNode(const state_t state, const std::string& name)
	{
		return addNode(state, name, "");
	}

	Node& Builder::addNode(const state_t state, const std::string& name, const std::string& description)
	{
		const auto& it = m_fsm.m_nodes.find(state);
		if (it == m_fsm.m_nodes.end())
		{
			const auto& pair = m_fsm.m_nodes.insert(std::make_pair(state, Node(state, name, description)));
			assert(pair.second);
			return pair.first->second;
		}
		else
		{
			return it->second;
		}
	}

	Transition& Builder::addTransition(state_t origin, state_t destination, const std::string& name)
	{
		return addTransition(origin, destination, name, "");
	}

	Transition& Builder::addTransition(state_t origin, state_t destination, const std::string& name, const std::string& description)
	{

	}
}