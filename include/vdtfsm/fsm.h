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

		bool exists(state_t state) const;
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		bool exists(T state) const 
		{
			return exists(static_cast<state_t>(state));
		}

		void start(state_t state);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		void start(const T state)
		{
			start(static_cast<state_t>(state));
		}

		std::string name;

	private:

		void changeState(state_t state);

		std::map<state_t, Node> m_nodes;
		std::vector<Transition> m_transitions;
		state_t m_state;
	};
}