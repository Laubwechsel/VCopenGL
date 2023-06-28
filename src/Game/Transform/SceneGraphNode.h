#pragma once

#include <vector>;
#include <string>;
#include "Transform.h"

class CompositeMesh;
class SceneGraphNode {
public:
	SceneGraphNode();
	SceneGraphNode(std::string name);
	SceneGraphNode(SceneGraphNode * toCopy);
	std::vector<std::vector<SceneGraphNode*>*>* buildSceneGraph(std::vector<std::vector<SceneGraphNode*>*>* toBuild);
	void addChild(SceneGraphNode* toAdd);

	std::string* getName();
	Transform* getTransform();
	GLuint getVAOid();

	CompositeMesh* getLinkedCompositeMesh();

	void setName(std::string* newName);
	void setTransform(Transform* newTransform);
	void setVAOid(GLuint newVAOid);
	void setDefaultScale(glm::vec3& scale);
	glm::vec3 getDefaultScale();
	void setDefaultPosition(glm::vec3& position);
	glm::vec3 getDefaultPosition();
	void setPosition(glm::vec3& position);
	glm::mat4 getMatrix();

	void setLinkedCompositeMesh(CompositeMesh* newCompositeMesh);

	void translate(glm::vec3 amount);
	void lookAt(glm::vec3 point);
	void rotateAroundAnchor(glm::vec3& amount);
	void resetPosition();

	glm::vec3 rotationAnchorPoint = glm::vec3();



private:
	Transform* getLinkedTransform();
	std::vector<SceneGraphNode*> _children = std::vector<SceneGraphNode*>();

	Transform _transform = Transform();
	Transform _defaultPosition = Transform();

	std::string _name = "";

	CompositeMesh* _linkedCompositeMesh= nullptr;
	GLuint _vaoID=0;


};