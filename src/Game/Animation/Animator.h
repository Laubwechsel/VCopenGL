#pragma once
#include <unordered_map>
#include <string>

class Transform;
class AnimatorState;
class Animator {
public:
	Animator(std::string key, AnimatorState* initialState);
	void addState(std::string key,AnimatorState* toAdd);
	void addTransition(std::string from, std::string to, std::string trigger);

	void transition(std::string key);
	void animate(float dt);
private:
	std::unordered_map<std::string, AnimatorState*>_animatorstates = std::unordered_map<std::string, AnimatorState*>();
	AnimatorState* _currentState = nullptr;
};
