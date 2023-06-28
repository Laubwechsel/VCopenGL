#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
}

int SceneGraph::addNode(SceneGraphNode* toAdd)
{
	_allNodes.push_back(toAdd);
	return _allNodes.size() - 1;
}

bool SceneGraph::addConnection(int parent, int child)
{
	bool parentBoundsCheck = (parent) >= _allNodes.size() || parent < 0;
	bool childBoundsCheck = child >= _allNodes.size() || child < 0;
	if (parentBoundsCheck || childBoundsCheck || parent == child)
	{
		return false;
	}

	_allNodes.at(parent)->addChild(_allNodes.at(child));
	return true;
}

bool SceneGraph::addConnection(std::string parent, std::string child)
{
	return addConnection(findNodeByName(parent),findNodeByName(child));
}

std::vector<std::vector<SceneGraphNode*>*>* SceneGraph::getLinkedAllPaths()
{
	if (_allPaths==nullptr)
	{
		_allPaths = _allNodes.at(_rootNode)->buildSceneGraph(new std::vector<std::vector<SceneGraphNode*>*>());
	}
	return _allPaths;
}

void SceneGraph::setRootNode(int rootNode)
{
	_rootNode = rootNode;
}

int SceneGraph::findNodeByName(std::string& name)
{
	for (size_t i = 0; i < _allNodes.size(); i++)
	{
		if (*_allNodes.at(i)->getName() == name)
		{
			return i;
		}
	}
	return -1;
}

SceneGraphNode* SceneGraph::getNodeByName(std::string name)
{
	return _allNodes.at(findNodeByName(name));
}

void SceneGraph::rotateNodeAroundAnchor(const std::string& name, glm::vec3& amount)
{
	SceneGraphNode* node = getNodeByName(name);
	node->rotateAroundAnchor(amount);

}

