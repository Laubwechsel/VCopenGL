#include "RobotAI.h"
#include "Physics/Collision.h"
#include "SceneObjects/SceneObject.h"
#include "Physics/RigidBodys/RigidBody.h"
#include "Consts.h"
#include <iostream>

RobotAI::RobotAI(SceneObject* sceneObject)
{
	_sceneObject = sceneObject;
	_currentSpeed = _baseSpeed;
	_sceneObject->getRigidBody()->addCollisionEventListener(this);
	randomRotation();
}

void RobotAI::notify(Collision* collision)
{
	std::string otherName;
	if (collision->bodyA()->getName() != _sceneObject->_objectName)
	{
		otherName = collision->bodyA()->getName();
	}
	else
	{
		otherName = collision->bodyB()->getName();
	}

	if (otherName.find("Plane") != std::string::npos)
	{
		return;
	}
	if (otherName.find("Robot") != std::string::npos)
	{
		if (_waveCdTimer < _waveCoolDown)
		{
			return;
		}
		_sceneObject->animationTransition("wave");
		_waveTimer = 0.0f;
		_moveDirection *= -1.0f;
		_currentSpeed = 0;
		_waveCdTimer = 0;
		return;
	}
	if (otherName.find("Wall") != std::string::npos) {
		randomRotation();
	}
}

void RobotAI::update(float dt)
{
	if (_waveTimer < _waveDuration)
	{
		_waveTimer += dt;

	}
	else
	{
		if (_waveCdTimer < _waveCoolDown)
		{
			_waveCdTimer += dt;
		}
		_currentSpeed = _baseSpeed;
		_sceneObject->animationTransition("walk");

	}
	_sceneObject->getRigidBody()->setSpeed(0, _moveDirection.x * _currentSpeed);
	_sceneObject->getRigidBody()->setSpeed(2, _moveDirection.z * _currentSpeed);

}

void RobotAI::randomRotation()
{
	//float randomX = std::rand() % 10;
	//float randomZ = std::rand() % 10;

	//randomX -= 8;
	//randomZ -= 8;

	//_moveDirection.x = randomX / 32.0;
	//_moveDirection.z = randomZ / 32.0;
	//return;
	float angle = std::rand() % 24;
	angle *= (360.0 / 24.0);
	//std::cout << angle << std::endl;
	angle *= deg2rad;
	glm::mat3 rotation = { std::cosf(angle),0.0,std::sinf(angle),0.0,1.0,0.0,-std::sinf(angle),0.0,-std::cosf(angle) };
	_moveDirection = rotation * _baseDirection;

}
