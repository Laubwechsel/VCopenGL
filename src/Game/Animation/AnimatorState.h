#pragma once
#include <string>
#include <unordered_map>

class Transform;
class Animation;
class SceneGraph;
class AnimatorState {
public:
	AnimatorState(SceneGraph* _sceneGraph);
	void addTransition(std::string key, AnimatorState* value);
	void addAnimation(std::string key, Animation* value);

	AnimatorState* transition(std::string key);
	void animate(float dt);
private:
	std::unordered_map<std::string, Animation*> _animations = std::unordered_map<std::string, Animation*>();
	std::unordered_map<std::string, AnimatorState*> _transitions = std::unordered_map<std::string, AnimatorState*>();
	SceneGraph* _sceneGraph = nullptr;
};