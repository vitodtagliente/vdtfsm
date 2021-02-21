/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <map>
#include <string>
#include <vector>

#include "common.h"
#include "node.h"

namespace vdtfsm
{
	struct Transition
	{
	public:
		Transition(state_t origin, state_t destination);
		Transition(state_t origin, state_t destination, const std::string& name);
		Transition(state_t origin, state_t destination, const std::string& name, const std::string& description);

		bool operator== (const Transition& transition) const;
		bool operator!= (const Transition& transition) const;

		state_t getOrigin() const { return m_origin; }
		state_t getDestination() const { return m_destination; }

		std::string name;
		std::string description;

		class Behaviour
		{

		};

	private:
		state_t m_origin;
		state_t m_destination;
		std::vector<Behaviour> m_behaviours;
	};
}