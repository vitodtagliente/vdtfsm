/// Copyright (c) Vito Domenico Tagliente
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "common.h"

namespace vdtfsm
{
	class Node
	{
	public:	
		friend class Fsm;

		class Behaviour
		{
		public:
			virtual void onEnter() {}
			virtual void onExit() {}
		};

		Node(state_t state);
		Node(state_t state, const std::string& name);
		Node(state_t state, const std::string& name, const std::string& description);

		bool operator== (const Node& node) const;
		bool operator!= (const Node& node) const;

		state_t getState() const { return m_state; }

		// template <typename T, typename TEnabled = std::enable_if<std::is_base_of<Behaviour, T>::value>>
		// T* const addBehaviour()
		// {
		// 	m_behaviours.push_back(std::make_unique<T>());
		// }

		std::string name;
		std::string description;

	private:
		void enter();
		void exit();

		state_t m_state;
		// std::vector<std::unique_ptr<Behaviour>> m_behaviours;
	};
}