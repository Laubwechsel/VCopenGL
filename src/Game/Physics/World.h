#pragma once
#include <vector>
#include <libheaders.h>

class RigidBody;
class SceneObject;
class Collision;
class World {
public:
	void addSceneObjectToWorld(SceneObject* toAdd);
	void step(float dt);
private:
	std::vector<RigidBody*> _bodys = std::vector<RigidBody*>();
	glm::vec3 _gravity = glm::vec3(0, -10, 0);

	void collisionCheck();
	void handleCollision(Collision* collision);
	void resolveCollision(Collision* collision, int direction);

};