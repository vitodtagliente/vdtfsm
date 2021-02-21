/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <map>
#include <string>
#include <vector>

#include "common.h"
#include "node.h"
#include "transition.h"

namespace vdtfsm
{
	class Fsm
	{
	public:
		friend class Builder;

		Fsm();
		Fsm(const std::string& name);

		bool isValidState(state_t state) const;
		template <typename T>
		bool isValidState(T state) const 
		{
			return isValidState(static_cast<state_t>(state));
		}

		std::string name;

	private:
		std::map<state_t, Node> m_nodes;
		std::vector<Transition> m_transitions;
	};
}