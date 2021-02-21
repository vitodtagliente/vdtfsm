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

		Node& addNode(state_t state);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Node& addNode(const T state)
		{
			return addNode(static_cast<state_t>(state));
		}

		Node& addNode(state_t state, const std::string& name);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Node& addNode(const T state, const std::string& name)
		{
			return addNode(static_cast<state_t>(state), name);
		}

		Node& addNode(state_t state, const std::string& name, const std::string& description);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Node& addNode(const T state, const std::string& name, const std::string& description)
		{
			return addNode(static_cast<state_t>(state), name, description);
		}

		Transition& addTransition(state_t origin, state_t destination);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Transition& addTransition(const T origin, const T destination)
		{
			return addTransition(static_cast<state_t>(origin), static_cast<state_t>(destination));
		}

		Transition& addTransition(state_t origin, state_t destination, const std::string& name);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Transition& addTransition(const T origin, const T destination, const std::string& name)
		{
			return addTransition(static_cast<state_t>(origin), static_cast<state_t>(destination), name);
		}
		
		Transition& addTransition(state_t origin, state_t destination, const std::string& name, const std::string& description);
		template <typename T, typename TEnabled = std::enable_if<std::is_enum<T>::value>>
		Transition& addTransition(const T origin, const T destination, const std::string& name, const std::string& description)
		{
			return addTransition(static_cast<state_t>(origin), static_cast<state_t>(destination), name, description);
		}

	private:
		Fsm m_fsm;
	};
}