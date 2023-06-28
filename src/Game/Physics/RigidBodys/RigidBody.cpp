#include "RigidBody.h"
#include "Consts.h"
#include "Physics/CollisionEventListener.h"
#include <iostream>
RigidBody::RigidBody(std::string& name)
{
	_name = name;
}
void RigidBody::setColliderSize(glm::vec3& size)
{
	_collider.setSize(size);
}
void RigidBody::setColliderOffset(glm::vec3& offset)
{
	_collider.setOffset(offset);
}
glm::vec3 RigidBody::getColliderSize()
{
	return _collider.getSize();
}
void RigidBody::setWeight(float weight)
{
	_weight = weight;
}
void RigidBody::addCollisionEventListener(CollisionEventListener* eventListener)
{
	_collisionEventListener.push_back(eventListener);
}
void RigidBody::notifyCollisionListeners(Collision* collision)
{
	for each (CollisionEventListener * var in _collisionEventListener)
	{
		var->notify(collision);
	}
}
void RigidBody::translate(glm::vec3& translation)
{
	_transform.translate(translation);
}

void RigidBody::rotateEulerDeg(glm::vec3& rotation)
{
	_transform.rotate(rotation * deg2rad);
}

void RigidBody::setPosition(glm::vec3& position)
{
	_transform.setPosition(position);
}

glm::vec3 RigidBody::getPosition()
{
	return _transform.getPosition();
}

void RigidBody::addForce(glm::vec3& force)
{
	_speed += force / _weight;
}

float RigidBody::getWeight()
{
	return _weight;
}

void RigidBody::setSpeed(glm::vec3& speed)
{
	_speed.x = speed.x;
	_speed.y = speed.y;
	_speed.z = speed.z;
}

void RigidBody::setSpeed(int axis, float speed)
{
	switch (axis)
	{
	case 0:
		_speed.x = speed;
		break;
	case 1:
		_speed.y = speed;
		break;
	case 2:
		_speed.z = speed;
		break;
	default:
		break;
	}
}

glm::vec3 RigidBody::getSpeed()
{
	return _speed;
}

std::string RigidBody::getName()
{
	return _name;
}

void RigidBody::step(float dt)
{
	if (mode == Static)
	{
		return;
	}
	_transform.translate(_speed * dt);
	//std::cout <<"X "<< _speed.x << " Y " << _speed.y<<" Z " << _speed.z << std::endl;
}

float RigidBody::minX()
{
	return _transform.getPosition().x + _collider.getOffset().x - (_collider.getSize().x / 2.0);
}

float RigidBody::maxX()
{
	return _transform.getPosition().x + _collider.getOffset().x + (_collider.getSize().x / 2.0);
}

float RigidBody::minY()
{
	return _transform.getPosition().y + _collider.getOffset().y - (_collider.getSize().y / 2.0);
}

float RigidBody::maxY()
{
	return _transform.getPosition().y + _collider.getOffset().y + (_collider.getSize().y / 2.0);
}

float RigidBody::minZ()
{
	return _transform.getPosition().z + _collider.getOffset().z - (_collider.getSize().z / 2.0);
}

float RigidBody::maxZ()
{
	return _transform.getPosition().z + _collider.getOffset().z + (_collider.getSize().z / 2.0);
}

std::unique_ptr<Collision> RigidBody::checkForCollisionWith(RigidBody* other)
{
	return std::unique_ptr<Collision>();
}
