#pragma once
#include "Physics/CollisionEventListener.h"
#include "libheaders.h"
#include "Transform.h"

class SceneObject;
class RobotAI : CollisionEventListener {
public:
	RobotAI(SceneObject* sceneObject);
	void notify(Collision* collision);
	void update(float dt);
private:
	glm::vec3 _moveDirection = glm::vec3(1, 0, 0);
	glm::vec3 _baseDirection = glm::vec3(1, 0, 0);
	float _baseSpeed = 1.8f;
	float _currentSpeed = 0.0f;
	float _waveDuration = 1.0f;
	float _waveTimer = 0.0f;
	float _waveCoolDown = 0.5f;
	float _waveCdTimer = 0.0f;

	SceneObject* _sceneObject;

	void randomRotation();
};