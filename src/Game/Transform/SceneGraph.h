#pragma once

#include "SceneGraphNode.h";
#include <vector>;
#include <string>;
class SceneGraph {
public:
	SceneGraph();
	int addNode(SceneGraphNode *);
	bool addConnection(int parent, int child);
	bool addConnection(std::string parent, std::string child);
	std::vector<std::vector<SceneGraphNode*>*> * getLinkedAllPaths();
	void setRootNode(int rootNode);

	int findNodeByName(std::string& name);

	SceneGraphNode* getNodeByName(std::string name);

	void rotateNodeAroundAnchor(const std::string& name, glm::vec3& amount);

private:
	std::vector<SceneGraphNode *> _allNodes = std::vector<SceneGraphNode*>();
	std::vector<SceneGraphNode *> _bottomNodes = std::vector<SceneGraphNode*>();
	int _rootNode = 0;

	std::vector<std::vector<SceneGraphNode*>*>* _allPaths = nullptr;
};