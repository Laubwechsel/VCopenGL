#include "World.h"
#include "Game/SceneObjects/SceneObject.h"
#include "Game/Physics/RigidBodys/RigidBody.h"

void World::addSceneObjectToWorld(SceneObject* toAdd)
{
	RigidBody* newRB;
	if (toAdd->getRigidBody() == nullptr)
	{
		std::string name = "Default";
		newRB = new RigidBody(name);
		toAdd->setRigidBody(newRB);
	}
	newRB = toAdd->getRigidBody();
	_bodys.push_back(newRB);
}

void World::step(float dt)
{
	for (size_t i = 0; i < _bodys.size(); i++)
	{
		_bodys.at(i)->addForce(_gravity * _bodys.at(i)->getWeight() * dt);
		_bodys.at(i)->step(dt);
	}
	for (size_t i = 0; i < 4; i++)
	{
		collisionCheck();

	}
}

void World::collisionCheck()
{
	for (size_t i = 0; i < _bodys.size(); i++)
	{
		for (size_t o = i + 1; o < _bodys.size(); o++)
		{
			Collision collision = Collision(_bodys.at(i), _bodys.at(o));
			handleCollision(&collision);
			if (collision.colliding())
			{
				collision.bodyA()->notifyCollisionListeners(&collision);
				collision.bodyB()->notifyCollisionListeners(&collision);

			}
		}
	}

}

void World::handleCollision(Collision* collision)
{
	if (!collision->colliding())
	{
		return;
	}
	glm::vec3 overlap = collision->overlap();

	if (abs(overlap.x) < abs(overlap.y) && abs(overlap.x) < abs(overlap.z))
	{
		resolveCollision(collision, 0);
		return;
	}
	if (abs(overlap.y) < abs(overlap.z))
	{
		resolveCollision(collision, 1);
		return;
	}
	resolveCollision(collision, 2);
	return;
}

void World::resolveCollision(Collision* collision, int direction)
{
	RigidBody* bodyA = collision->bodyA();
	RigidBody* bodyB = collision->bodyB();
	float arr[3] = { 0,0,0 };
	arr[direction] = collision->overlap()[direction];
	glm::vec3 minResulutionDistance = glm::vec3(arr[0], arr[1], arr[2]);

	if (bodyA->getWeight() == bodyB->getWeight())
	{
		bodyA->translate((minResulutionDistance * 0.5f));
		bodyA->setSpeed(direction, 0);
		bodyB->translate(minResulutionDistance * -0.5f);
		bodyB->setSpeed(direction, 0);
		return;
	}

	if (bodyA->getWeight() < bodyB->getWeight())
	{
		bodyA->translate(minResulutionDistance * 1.0f);
		bodyA->setSpeed(direction, 0);
		return;
	}

	bodyB->translate(minResulutionDistance * -1.0f);
	bodyB->setSpeed(direction, 0);

	bodyA->notifyCollisionListeners(collision);
	bodyB->notifyCollisionListeners(collision);
}
