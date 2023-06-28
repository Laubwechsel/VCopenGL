#pragma once
#include <string>;
#include <libheaders.h>
class SceneGraph;
class RigidBody;
class SceneObject {
public:
	SceneObject(std::string& objectName);
	virtual SceneGraph* getLinkedSceneGraph()=0;
	virtual void update(float dt) = 0;
	virtual void animate(float dt)=0;
	virtual void animationTransition(std::string transition)=0;
	virtual void translate(glm::vec3 &amount)=0;
	virtual void setScale(glm::vec3 &scale)=0;
	virtual void lookAt(glm::vec3 &point)=0;
	virtual void setRigidBody(RigidBody * rb) = 0;
	virtual RigidBody * getRigidBody() = 0;

	std::string _objectName;
};