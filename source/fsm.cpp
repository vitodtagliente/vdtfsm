#include <vdtfsm/fsm.h>

#include <cassert>

namespace vdtfsm
{
	Node& Fsm::addNode(const state_t state, const std::string& name)
	{
		return addNode(state, name, "");
	}

	Node& Fsm::addNode(const state_t state, const std::string& name, const std::string& description)
	{
		const auto& it = m_nodes.find(state);
		if (it == m_nodes.end())
		{
			const auto& pair = m_nodes.insert(std::make_pair(state, Node(state, name, description)));
			assert(pair.second);
			return pair.first->second;
		}
		else
		{
			return it->second;
		}
	}
}