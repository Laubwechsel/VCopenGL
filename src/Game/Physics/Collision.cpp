#include "Collision.h"
#include "Physics/RigidBodys/RigidBody.h"
Collision::Collision(RigidBody* bodyA, RigidBody* bodyB)
{
	_bodyA = bodyA;
	_bodyB = bodyB;
	if (_bodyA->mode == RigidBody::Static && _bodyB->mode == RigidBody::Static)
	{
		_colliding = false;
		return;
	}

	_colliding = _bodyA->minX() <= _bodyB->maxX() &&
		_bodyA->maxX() >= _bodyB->minX() &&
		_bodyA->minY() <= _bodyB->maxY() &&
		_bodyA->maxY() >= _bodyB->minY() &&
		_bodyA->minZ() <= _bodyB->maxZ() &&
		_bodyA->maxZ() >= _bodyB->minZ();
	if (!_colliding)
	{
		return;
	}
	if (_bodyA->getName().find("Wall") != std::string::npos) {
		int i = 0;
	}
	if (_bodyB->getName().find("Wall") != std::string::npos) {
		int i = 0;
	}

	float minAdistanceX = bodyB->maxX() - bodyA->minX();

	float maxAdistanceX = bodyB->minX() - bodyA->maxX();

	if (std::abs(maxAdistanceX) < std::abs(minAdistanceX))
	{
		_minimunResolutionDistance.x = maxAdistanceX;

	}
	else
	{
		_minimunResolutionDistance.x = minAdistanceX;
	}

	float minAdistanceY = bodyB->maxY() - bodyA->minY();

	float maxAdistanceY = bodyB->minY() - bodyA->maxY();

	if (std::abs(maxAdistanceY) < std::abs(minAdistanceY))
	{
		_minimunResolutionDistance.y = maxAdistanceY;

	}
	else
	{
		_minimunResolutionDistance.y = minAdistanceY;
	}
	float minAdistanceZ = bodyB->maxZ() - bodyA->minZ();

	float maxAdistanceZ = bodyB->minZ() - bodyA->maxZ();

	if (std::abs(maxAdistanceZ) < std::abs(minAdistanceZ))
	{
		_minimunResolutionDistance.z = maxAdistanceZ;

	}
	else
	{
		_minimunResolutionDistance.z = minAdistanceZ;
	}

}

RigidBody* Collision::bodyA()
{
	return _bodyA;
}

RigidBody* Collision::bodyB()
{
	return _bodyB;
}

bool Collision::colliding()
{
	return _colliding;
}

glm::vec3 Collision::overlap()
{
	return _minimunResolutionDistance;
}
