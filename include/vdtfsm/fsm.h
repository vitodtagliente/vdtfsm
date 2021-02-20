/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <map>
#include <string>
#include <vector>

#include "common.h"
#include "node.h"

namespace vdtfsm
{
	class Fsm
	{
	public:
		
		Node& addNode(state_t state, const std::string& name);
		Node& addNode(state_t state, const std::string& name, const std::string& description);
		template <typename T>
		Node& addNode(T state, const std::string& name)
		{
			return addNode(static_cast<state_t>(state), name);
		}
		template <typename T>
		Node& addNode(T state, const std::string& name, const std::string& description)
		{
			return addNode(static_cast<state_t>(state), name, description);
		}

	private:
		std::map<state_t, Node> m_nodes;
	};
}