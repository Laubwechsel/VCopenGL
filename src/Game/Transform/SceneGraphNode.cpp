#include "SceneGraphNode.h"
#include <algorithm>
#include "Mesh/CompositeMesh.h";


SceneGraphNode::SceneGraphNode()
{
}

SceneGraphNode::SceneGraphNode(std::string name)
{
	_name = name;
}

SceneGraphNode::SceneGraphNode(SceneGraphNode* toCopy)
{
}

std::vector<std::vector<SceneGraphNode*>*>* SceneGraphNode::buildSceneGraph(std::vector<std::vector<SceneGraphNode*>*>* toBuild)
{
	
	if (_children.empty())
	{
		toBuild->push_back(new std::vector<SceneGraphNode*>());
		toBuild->back()->push_back(this);
	}
	else
	{
		int begin = toBuild->size();
		for (size_t i = 0; i < _children.size(); i++)
		{
			toBuild = _children.at(i)->buildSceneGraph(toBuild);
		}
		int end = toBuild->size();
		for (size_t i = begin; i < end; i++)
		{
			toBuild->at(i)->push_back(this);
		}
	}
	return toBuild;
}

void SceneGraphNode::addChild(SceneGraphNode* toAdd)
{
	if (std::find(_children.begin(),_children.end(),toAdd) == _children.end())
	{
		_children.push_back(toAdd);
	}
}

std::string* SceneGraphNode::getName()
{
	return new std::string(_name);
}

Transform* SceneGraphNode::getTransform()
{
	return new Transform(_transform);
}

GLuint SceneGraphNode::getVAOid()
{
	return _vaoID;
}

CompositeMesh* SceneGraphNode::getLinkedCompositeMesh()
{
	return _linkedCompositeMesh;
}

Transform* SceneGraphNode::getLinkedTransform()
{
	return &_transform;
}

void SceneGraphNode::setName(std::string* newName)
{
	_name = std::string(*newName);
}

void SceneGraphNode::setTransform(Transform* newTransform)
{
	_transform = Transform(*newTransform);
	_defaultPosition = Transform(*newTransform);
}

void SceneGraphNode::setVAOid(GLuint newVAOid)
{
	_vaoID = newVAOid;
}

void SceneGraphNode::setDefaultScale(glm::vec3& scale)
{
	_defaultPosition.setScale(scale);
	resetPosition();
}

glm::vec3 SceneGraphNode::getDefaultScale()
{
	return _defaultPosition.getScale();
}

void SceneGraphNode::setDefaultPosition(glm::vec3& position)
{
	_defaultPosition.setPosition(position);
	resetPosition();
}

glm::vec3 SceneGraphNode::getDefaultPosition()
{
	return _defaultPosition.getPosition();
}

void SceneGraphNode::setPosition(glm::vec3& position)
{
	_transform.setPosition(position);
}

glm::mat4 SceneGraphNode::getMatrix()
{
	return _transform.getMatrix();
}


void SceneGraphNode::setLinkedCompositeMesh(CompositeMesh* newCompositeMesh)
{
	_linkedCompositeMesh = newCompositeMesh;
}

void SceneGraphNode::translate(glm::vec3 amount)
{
	_transform.translate(amount);
}

void SceneGraphNode::lookAt(glm::vec3 point)
{
}

void SceneGraphNode::rotateAroundAnchor(glm::vec3& amount)
{
	_transform.rotateAroundPoint(rotationAnchorPoint, amount);
}

void SceneGraphNode::resetPosition()
{
	_transform.setMatrix(_defaultPosition.getMatrix());
}

