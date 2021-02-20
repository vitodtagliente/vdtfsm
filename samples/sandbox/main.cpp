#include <iostream>
#include <vdtfsm/fsm.h>

using namespace vdtfsm;

int main()
{
	enum class AnimationState
	{
		Idle,
		Running,
		Attack
	};

	Fsm fsm;
	Node& node = fsm.addNode(AnimationState::Idle, "idle");
}