#pragma once
#include "libheaders.h"

class RigidBody;
class Collision {
public:
	Collision(RigidBody* bodyA, RigidBody* bodyB);

	RigidBody * bodyA();
	RigidBody* bodyB();

	bool colliding();
	glm::vec3 overlap();
private:
	RigidBody* _bodyA;
	RigidBody* _bodyB;
	bool _colliding;

	glm::vec3 _minimunResolutionDistance = glm::vec3(0, 0, 0);
};