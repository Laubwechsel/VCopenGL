#pragma once

#include "OpenGLWindow.h"
#include <ShaderProgram.h>
#include <memory>
#include <AssetManager.h>
#include "Mesh/CompositeMesh.h"
#include "Transform.h"
#include <map>
#include <string>
#include "Consts.h"
#include "Physics/World.h"

class SceneObject;
class SceneGraph;
class SceneGraphNode;
class Scene
{
public:
	Scene(OpenGLWindow* window);
	~Scene();

	bool init();
	void unbindVertexAndArrayBuffers();
	void shutdown();
	void render(float dt);
	void update(float dt);
	OpenGLWindow* getWindow();

	void myInit();

	void onKey(Key key, Action action, Modifier modifier);
	void onMouseMove(MousePosition mouseposition);
	void onMouseButton(MouseButton button, Action action, Modifier modifier);
	void onMouseScroll(double xscroll, double yscroll);
	void onFrameBufferResize(int width, int height);

private:
	OpenGLWindow* m_window = nullptr;
	AssetManager m_assets;
	ShaderProgram* m_shader = nullptr;

	glm::mat4 _projection = glm::mat4();
	glm::mat4 _view = glm::mat4();

	glm::vec3 _cameraPosition = glm::vec3();
	glm::vec3 _cameraTarget = glm::vec3();
	glm::vec3 _cameraUp = glm::vec3();

	Transform _cameraTransform = Transform();
	glm::vec3 _cameraMoveDirection = glm::vec3();
	glm::vec3 _cameraRotationDirection = glm::vec3();
	void buildCompositePolygonBW();

	int buildCompositePolygonCube(Color* color);

	std::vector<CompositeMesh*> compositeMeshs = std::vector<CompositeMesh*>();

	std::map<std::string, GLuint> vboIDs = std::map<std::string, GLuint>();
	std::map<std::string, GLuint> vaoIDs = std::map<std::string, GLuint>();
	std::map<GLuint, GLuint> _indiciesFromVaoID = std::map<GLuint, GLuint>();

	Transform* globalTransform = new Transform();

	std::vector<SceneObject*> _allSceneObjects = std::vector<SceneObject*>();

	World _physicsWorld = World();
	bool _pausePhysics = true;

	std::string rainbow = "Rainbow";

	void strikePoseRobot(SceneGraph* robotSceneGraph);
	void animateRobot(SceneGraph* robotSceneGraph, float dt);
	void swapWavingRobot(int willWave);

	void drawSceneGraph(SceneGraph* sceneGraph);
	void drawAtPath(std::vector<SceneGraphNode*>* path);
	GLuint calculatePathTransform(std::vector<SceneGraphNode*>* path, Transform* transform);

	void glSetup();
	void uploadCube(std::string& colorName, Color* color);
	void createRobotsInScene();

	void addSceneToPhysicsWorld();

};

