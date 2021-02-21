#include <iostream>
#include <vdtfsm/vdtfsm.h>

using namespace vdtfsm;

int main()
{
	enum class AnimationState : int
	{
		Idle,
		Running,
		Attack
	};

	Fsm fsm;
	auto builder = Builder(fsm);
	Node& node = builder.addNode(AnimationState::Idle);
	Transition& transition = builder.addTransition(AnimationState::Idle, AnimationState::Running);

	is_state_compatible(4);
}