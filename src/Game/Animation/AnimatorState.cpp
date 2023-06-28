#include "AnimatorState.h"
#include "Animation.h"

AnimatorState::AnimatorState(SceneGraph* sceneGraph)
{
	_sceneGraph = sceneGraph;
}

void AnimatorState::addTransition(std::string key, AnimatorState* value)
{
	_transitions.insert(std::pair<std::string,AnimatorState*>(key, value));
}

void AnimatorState::addAnimation(std::string key, Animation* value)
{
	_animations.insert(std::make_pair(key, value));
}

AnimatorState* AnimatorState::transition(std::string key)
{
	auto value = _transitions.find(key);
	if (value!=_transitions.end())
	{
		return value->second;
	}
	return this;
}

void AnimatorState::animate(float dt)
{
	for each (std::pair<std::string,Animation*> animation in _animations)
	{
		animation.second->animate(dt);
	}
}
