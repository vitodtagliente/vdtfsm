/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <string>
#include <vector>

#include "common.h"

namespace vdtfsm
{
	class Node
	{
	public:
		friend class Fsm;
		
		enum class State
		{

		};

		class Behaviour
		{

		};

		Node(state_t state);
		Node(state_t state, const std::string& name);
		Node(state_t state, const std::string& name, const std::string& description);

		state_t getState() const { return m_state; }

		std::string name;
		std::string description;

	private:
		state_t m_state;
		std::vector<Behaviour> m_behaviours;
	};
}