#include "Plane.h"

const std::string Plane::body = "Body";
const std::string Plane::bodyMesh = "BodyMesh";
const std::string Plane::cube = "Cube";


Plane::Plane(std::string& objectName, GLuint cubeVAOid) :SceneObject(objectName)
{
	_rigidBody = new RigidBody(objectName);
	buildSceneGraph(cubeVAOid);

	_rigidBody->mode = RigidBody::Static;
	_rigidBody->setColliderSize(_sceneGraph.getNodeByName(body)->getDefaultScale());
	_rigidBody->setPosition(_sceneGraph.getNodeByName(body)->getDefaultPosition());
	_rigidBody->setWeight(100);

}

SceneGraph* Plane::getLinkedSceneGraph()
{
	return &_sceneGraph;
}

void Plane::animate(float dt)
{
}

void Plane::update(float dt)
{
	_sceneGraph.getNodeByName(body)->setPosition(_rigidBody->getPosition());
}

void Plane::animationTransition(std::string transition)
{
}

void Plane::translate(glm::vec3& amount)
{
	_rigidBody->translate(amount);
}

void Plane::setScale(glm::vec3& scale)
{
	_rigidBody->setColliderSize(scale);
	_sceneGraph.getNodeByName(body)->setDefaultScale(scale);
}

void Plane::lookAt(glm::vec3& point)
{
}

void Plane::setRigidBody(RigidBody* rb)
{
	_rigidBody = rb;
}

RigidBody* Plane::getRigidBody()
{
	return _rigidBody;
}

void Plane::buildSceneGraph(GLuint cubeVAOid)
{
	_sceneGraph.addNode(new SceneGraphNode(body));
	_sceneGraph.addNode(new SceneGraphNode(bodyMesh));
	_sceneGraph.addNode(new SceneGraphNode(cube));


	_sceneGraph.addConnection(body, bodyMesh);
	_sceneGraph.addConnection(bodyMesh, cube);

	_sceneGraph.getNodeByName(body)->setDefaultScale(glm::vec3(10, 1, 10));
	_sceneGraph.getNodeByName(bodyMesh)->setDefaultScale(glm::vec3(1, 1, 1));

	_sceneGraph.getNodeByName(cube)->setVAOid(cubeVAOid);

}
