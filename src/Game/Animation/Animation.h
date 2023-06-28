#pragma once
#include <vector>
#include"glm/vec3.hpp"
#include <string>

class SceneGraphNode;
class Transform;
class Animation {
public:
	Animation(SceneGraphNode* toAnimate);
	void addKeyFrame(glm::vec3& toAdd, float duration);
	void animate(float dt);
	void reset();
	void setToAnimate(SceneGraphNode* toAnimate);
private:
	float _timer = 0.0;
	int _currentKeyframeIndex = 0;
	glm::vec3 _currentKeyframe = glm::vec3();
	std::pair<glm::vec3, float> * _lastKeyframe= nullptr;
	std::vector<std::pair<glm::vec3, float>> _keyFrames = std::vector<std::pair<glm::vec3, float>>();
	SceneGraphNode* _toAnimate = nullptr;

	void nextKeyframeCheck();
};