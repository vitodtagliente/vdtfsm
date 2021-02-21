/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <map>
#include <string>
#include <vector>

#include "common.h"
#include "fsm.h"
#include "node.h"

namespace vdtfsm
{
	class Fsm;

	class Builder
	{
	public:
		Builder(Fsm& fsm);

		Node& addNode(state_t state, const std::string& name);
		Node& addNode(state_t state, const std::string& name, const std::string& description);
		//template <typename T, typename TEnabled = std::enable_if<is_state_compatible<T>>>
		template <typename T>
		Node& addNode(const T state, const std::string& name)
		{
			return addNode(static_cast<state_t>(state), name);
		}
		//template <typename T, typename TEnabled = std::enable_if<is_state_compatible<T>>>
		template <typename T>
		Node& addNode(const T state, const std::string& name, const std::string& description)
		{
			return addNode(static_cast<state_t>(state), name, description);
		}

		Transition& addTransition(state_t origin, state_t destination, const std::string& name);
		template <typename T>
		Transition& addTransition(const T origin, const T destination, const std::string& name)
		{
			return addTransition(origin, destination, name);
		}
		Transition& addTransition(state_t origin, state_t destination, const std::string& name, const std::string& description);
		template <typename T>
		Transition& addTransition(const T origin, const T destination, const std::string& name, const std::string& description)
		{
			return addTransition(origin, destination, name, description);
		}

	private:
		Fsm m_fsm;
	};
}