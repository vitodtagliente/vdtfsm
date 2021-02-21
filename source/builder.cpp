#include <vdtfsm/builder.h>

#include <cassert>

namespace vdtfsm
{
	Builder::Builder(Fsm& fsm)
		: m_fsm(fsm)
	{

	}

	Node& Builder::addNode(state_t state)
	{
		return addNode(state, std::to_string(state), "");
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

	Transition& Builder::addTransition(state_t origin, state_t destination)
	{
		return addTransition(origin, destination, std::to_string(origin) + std::to_string(destination));
	}

	Transition& Builder::addTransition(const state_t origin, const state_t destination, const std::string& name)
	{
		return addTransition(origin, destination, name, "");
	}

	Transition& Builder::addTransition(const state_t origin, const state_t destination, const std::string& name, const std::string& description)
	{
		std::vector<Transition>& transitions = m_fsm.m_transitions;
		Transition transition(origin, destination, name, description);
		const auto& it = std::find(transitions.begin(), transitions.end(), transition);
		assert(it == transitions.end());
		return *transitions.emplace(transitions.end(), origin, destination, name, description);
	}
}