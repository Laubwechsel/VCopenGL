#pragma once
#include "Transform.h"
#include "libheaders.h"
#include <memory>
#include "Physics/Collision.h"
#include "Physics/Colliders/Collider.h"
#include <string>
#include <vector>
class CollisionEventListener;
class RigidBody {
public:
	RigidBody(std::string& name);
	void setColliderSize(glm::vec3 &size);
	void setColliderOffset(glm::vec3& offset);
	glm::vec3 getColliderSize();
	void setWeight(float weight);

	void addCollisionEventListener(CollisionEventListener* eventListener);
	void notifyCollisionListeners(Collision * collision );

	void translate(glm::vec3 &translation);
	void rotateEulerDeg(glm::vec3 &rotation);
	void setPosition(glm::vec3 &position);
	glm::vec3 getPosition();
	void addForce(glm::vec3 &force);
	float getWeight();

	void setSpeed(glm::vec3& speed);
	void setSpeed(int axis, float speed);
	glm::vec3 getSpeed();

	std::string getName();

	void step(float dt);

	float minX();
	float maxX();
	float minY();
	float maxY();
	float minZ();
	float maxZ();

	std::unique_ptr<Collision> checkForCollisionWith(RigidBody* other);
	enum Mode
	{
		Dynamic,
		Static
	};
	
	Mode mode = Mode::Dynamic;
private:
	Transform _transform = Transform();
	glm::vec3 _speed = glm::vec3();
	float _weight = 1.0;

	std::string _name;

	Collider _collider = Collider();
	std::vector<CollisionEventListener*> _collisionEventListener = std::vector<CollisionEventListener*>();
};