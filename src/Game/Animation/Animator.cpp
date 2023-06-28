#include "Animator.h"
#include "AnimatorState.h"

Animator::Animator(std::string key, AnimatorState* initialState)
{
	addState(key, initialState);
	_currentState = initialState;
}

void Animator::addState(std::string key, AnimatorState* toAdd)
{
	_animatorstates.insert(std::pair<std::string, AnimatorState*>(key, toAdd));
}

void Animator::addTransition(std::string from, std::string to, std::string trigger)
{
	_animatorstates.at(from)->addTransition(trigger, _animatorstates.at(to));
}

void Animator::transition(std::string key)
{
	AnimatorState* next = _currentState->transition(key);
	_currentState = next;
}

void Animator::animate(float dt)
{
	_currentState->animate(dt);
}
