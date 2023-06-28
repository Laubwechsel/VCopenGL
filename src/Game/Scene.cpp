#include "Scene.h"
#include <AssetManager.h>
#include <thread>
#include "Mesh/CompositeMesh.h"
#include "Mesh/Cube.h"
#include "Transform/SceneGraph.h"
#include "SceneObjects/Robot.h"
#include "SceneObjects/Plane.h"


Scene::Scene(OpenGLWindow* window) :
	m_window(window)
{
	assert(window != nullptr);
}

Scene::~Scene()
{}


bool Scene::init()
{
	try
	{
		glSetup();

		uploadCube(rainbow, nullptr);
		uploadCube(greyString, &grey);
		uploadCube(greenString, &green);
		uploadCube(brownString, &brown);
		//uploadCube(greyString, grey);
		float stageSize = 14.0f;
		createRobotsInScene();
		std::string name = "Plane";
		int vaoID = vaoIDs.find(Cube::name + greenString)->second;
		_allSceneObjects.push_back(new Plane(name, vaoID));
		_allSceneObjects.back()->setScale(glm::vec3(stageSize, 1, stageSize));
		_allSceneObjects.back()->translate(glm::vec3(0, -4.5, 0));

		float wallHeight = 4;
		name = "Wall1";
		vaoID = vaoIDs.find(Cube::name + brownString)->second;
		_allSceneObjects.push_back(new Plane(name, vaoID));
		_allSceneObjects.back()->setScale(glm::vec3(stageSize, wallHeight, 2));
		_allSceneObjects.back()->translate(glm::vec3(0, -2.5, stageSize / 2.0));
		name = "Wall2";
		vaoID = vaoIDs.find(Cube::name + brownString)->second;
		_allSceneObjects.push_back(new Plane(name, vaoID));
		_allSceneObjects.back()->setScale(glm::vec3(stageSize, wallHeight, 3));
		_allSceneObjects.back()->translate(glm::vec3(0, -2.5, -stageSize / 2.0));
		name = "Wall3";
		vaoID = vaoIDs.find(Cube::name + brownString)->second;
		_allSceneObjects.push_back(new Plane(name, vaoID));
		_allSceneObjects.back()->setScale(glm::vec3(3, wallHeight, stageSize));
		_allSceneObjects.back()->translate(glm::vec3(stageSize / 2.0, -2.5, 0));
		name = "Wall4";
		vaoID = vaoIDs.find(Cube::name + brownString)->second;
		_allSceneObjects.push_back(new Plane(name, vaoID));
		_allSceneObjects.back()->setScale(glm::vec3(3, wallHeight, stageSize));
		_allSceneObjects.back()->translate(glm::vec3(-stageSize / 2.0, -2.5, 0));

		for each (SceneObject * var in _allSceneObjects)
		{
			_physicsWorld.addSceneObjectToWorld(var);
		}

		GLERR
			std::cout << "Scene initialization done\n";
		return true;
	}
	catch (std::exception& ex)
	{
		throw std::logic_error("Scene initialization failed:\n" + std::string(ex.what()) + "\n");
	}
}

void Scene::render(float dt)
{
	int a = 0;
	GLERR;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (size_t i = 0; i < _allSceneObjects.size(); i++)
	{
		drawSceneGraph(_allSceneObjects.at(i)->getLinkedSceneGraph());
	}
	using namespace std::chrono;
	//std::this_thread::sleep_for((milliseconds)20);
}

void Scene::update(float dt)
{
	_cameraTransform.translate(_cameraMoveDirection * dt);
	_cameraTransform.rotateAroundPoint(_cameraTarget, _cameraRotationDirection * dt);
	_view = glm::lookAt(_cameraTransform.getPosition(), _cameraTarget, _cameraUp);
	m_shader->setUniform("view", _view, false);


	for each (auto var in _allSceneObjects)
	{
		var->animate(dt);
	}
	if (!_pausePhysics)
	{
		_physicsWorld.step(dt);

	}

	for each (auto var in _allSceneObjects)
	{
		var->update(dt);
	}

}

OpenGLWindow* Scene::getWindow()
{
	return m_window;
}

void Scene::myInit()
{

}

void Scene::onKey(Key key, Action action, Modifier modifier)
{
	switch (key)
	{
	case Key::Unknown:
		break;
	case Key::Space:
		_cameraMoveDirection = glm::vec3(0, 0, 0);
		_cameraRotationDirection = glm::vec3(0, 0, 0);
		break;
	case Key::Apostrophe:
		break;
	case Key::Comma:
		break;
	case Key::Minus:
		break;
	case Key::Period:
		break;
	case Key::Slash:
		break;
	case Key::K0:
		//swapWavingRobot(0);
		break;
	case Key::K1:
		//swapWavingRobot(1);
		break;
	case Key::K2:
		//swapWavingRobot(2);
		break;
	case Key::K3:
		//swapWavingRobot(3);
		break;
	case Key::K4:
		//swapWavingRobot(4);
		break;
	case Key::K5:
		//swapWavingRobot(5);
		break;
	case Key::K6:
		//swapWavingRobot(6);
		break;
	case Key::K7:
		//swapWavingRobot(7);
		break;
	case Key::K8:
		//swapWavingRobot(8);
		break;
	case Key::K9:
		//swapWavingRobot(9);
		break;
	case Key::Semicolon:
		break;
	case Key::Equal:
		break;
	case Key::A:
		break;
	case Key::B:
		break;
	case Key::C:
		break;
	case Key::D:
		break;
	case Key::E:
		break;
	case Key::F:
		break;
	case Key::G:
		break;
	case Key::H:
		break;
	case Key::I:
		break;
	case Key::J:
		break;
	case Key::K:
		break;
	case Key::L:
		break;
	case Key::M:
		break;
	case Key::N:
		break;
	case Key::O:
		_pausePhysics = true;
		break;
	case Key::P:
		_pausePhysics = false;
		break;
	case Key::Q:
		break;
	case Key::R:
		break;
	case Key::S:
		break;
	case Key::T:
		break;
	case Key::U:
		break;
	case Key::V:
		break;
	case Key::W:
		break;
	case Key::X:
		break;
	case Key::Y:
		break;
	case Key::Z:
		break;
	case Key::LeftBracket:
		break;
	case Key::Backslash:
		break;
	case Key::RightBracket:
		break;
	case Key::GraveAccent:
		break;
	case Key::World1:
		break;
	case Key::World2:
		break;
	case Key::Escape:
		break;
	case Key::Enter:
		break;
	case Key::Tab:
		break;
	case Key::Backspace:
		break;
	case Key::Insert:
		break;
	case Key::Delete:
		break;
	case Key::Right:
		_cameraMoveDirection = glm::vec3(0, 0, 0);
		_cameraRotationDirection = glm::vec3(0, 1, 0);
		break;
	case Key::Left:
		_cameraMoveDirection = glm::vec3(0, 0, 0);
		_cameraRotationDirection = glm::vec3(0, -1, 0);
		break;
	case Key::Down:
		_cameraRotationDirection = glm::vec3(0, 0, 0);
		_cameraMoveDirection = glm::vec3(0, 5, 0);
		break;
	case Key::Up:
		_cameraRotationDirection = glm::vec3(0, 0, 0);
		_cameraMoveDirection = glm::vec3(0, -5, 0);
		break;
	case Key::PageUp:
		break;
	case Key::PageDown:
		break;
	case Key::Home:
		break;
	case Key::End:
		break;
	case Key::CapsLock:
		break;
	case Key::ScrollLock:
		break;
	case Key::NumLock:
		break;
	case Key::PrintScreen:
		break;
	case Key::Pause:
		break;
	case Key::F1:
		break;
	case Key::F2:
		break;
	case Key::F3:
		break;
	case Key::F4:
		break;
	case Key::F5:
		break;
	case Key::F6:
		break;
	case Key::F7:
		break;
	case Key::F8:
		break;
	case Key::F9:
		break;
	case Key::F10:
		break;
	case Key::F11:
		break;
	case Key::F12:
		break;
	case Key::F13:
		break;
	case Key::F14:
		break;
	case Key::F15:
		break;
	case Key::F16:
		break;
	case Key::F17:
		break;
	case Key::F18:
		break;
	case Key::F19:
		break;
	case Key::F20:
		break;
	case Key::F21:
		break;
	case Key::F22:
		break;
	case Key::F23:
		break;
	case Key::F24:
		break;
	case Key::F25:
		break;
	case Key::NumPad0:
		break;
	case Key::NumPad1:
		break;
	case Key::NumPad2:
		break;
	case Key::NumPad3:
		break;
	case Key::NumPad4:
		break;
	case Key::NumPad5:
		break;
	case Key::NumPad6:
		break;
	case Key::NumPad7:
		break;
	case Key::NumPad8:
		break;
	case Key::NumPad9:
		break;
	case Key::NumPadDecimal:
		break;
	case Key::NumPadDivide:
		break;
	case Key::NumPadMultiply:
		break;
	case Key::NumPadSubtract:
		break;
	case Key::NumPadAdd:
		break;
	case Key::NumPadEnter:
		break;
	case Key::NumPadEqual:
		break;
	case Key::LeftShift:
		break;
	case Key::LeftCtrl:
		break;
	case Key::LeftAlt:
		break;
	case Key::LeftSuper:
		break;
	case Key::RightShift:
		break;
	case Key::RightCtrl:
		break;
	case Key::RightAlt:
		break;
	case Key::RightSuper:
		break;
	case Key::Menu:
		break;
	default:
		break;
	}
}

void Scene::onMouseMove(MousePosition mouseposition)
{

}

void Scene::onMouseButton(MouseButton button, Action action, Modifier modifier)
{

}

void Scene::onMouseScroll(double xscroll, double yscroll)
{

}

void Scene::onFrameBufferResize(int width, int height)
{

}

void Scene::buildCompositePolygonBW()
{
	CompositeMesh* BW = new CompositeMesh("BW");
	Mesh B = Mesh();

	B.addPoint(new Point(-7.0 / 8.0, 5.0 / 8.0, &red));
	B.addPoint(new Point(-6.0 / 8.0, 5.0 / 8.0, &green));
	B.addPoint(new Point(-5.0 / 8.0, 5.0 / 8.0, &blue));
	B.addPoint(new Point(-6.0 / 8.0, 4.0 / 8.0, &white));
	B.addPoint(new Point(-5.0 / 8.0, 4.0 / 8.0, &red));
	B.addPoint(new Point(-4.0 / 8.0, 7.0 / 16.0, &green));
	B.addPoint(new Point(-6.0 / 8.0, 3.0 / 8.0, &blue));
	B.addPoint(new Point(-5.0 / 8.0, 3.0 / 8.0, &white));
	B.addPoint(new Point(-5.0 / 8.0, 5.0 / 16.0, &red));
	B.addPoint(new Point(-6.0 / 8.0, 2.0 / 8.0, &green));
	B.addPoint(new Point(-5.0 / 8.0, 2.0 / 8.0, &blue));
	B.addPoint(new Point(-4.0 / 8.0, 3.0 / 16.0, &white));
	B.addPoint(new Point(-6.0 / 8.0, 1.0 / 8.0, &red));
	B.addPoint(new Point(-5.0 / 8.0, 1.0 / 8.0, &green));
	B.addPoint(new Point(-7.0 / 8.0, 0.0 / 8.0, &blue));
	B.addPoint(new Point(-6.0 / 8.0, 0.0 / 8.0, &white));
	B.addPoint(new Point(-5.0 / 8.0, 0.0 / 8.0, &white));

	B.addConnection(0, 14, 1);
	B.addConnection(1, 14, 15);
	B.addConnection(1, 3, 2);
	B.addConnection(2, 3, 4);
	B.addConnection(2, 8, 5);
	B.addConnection(8, 16, 11);
	B.addConnection(6, 9, 7);
	B.addConnection(7, 9, 10);
	B.addConnection(12, 15, 13);
	B.addConnection(13, 15, 16);

	B.translate2d(0.2, -0.3);

	BW->addMesh(&B);

	//B.translate2d(0.5, 0);
	//BW->addPolygon(&B);

	Mesh W = Mesh();

	W.addPoint(new Point(-1.0 / 16.0, 10.0 / 16.0, &red));
	W.addPoint(new Point(5.0 / 16.0, 10.0 / 16.0, &green));
	W.addPoint(new Point(11.0 / 16.0, 10.0 / 16.0, &blue));
	W.addPoint(new Point(-1.0 / 16.0, 6.5 / 16.0, &white));
	W.addPoint(new Point(5.0 / 16.0, 6.5 / 16.0, &red));
	W.addPoint(new Point(11.0 / 16.0, 6.5 / 16.0, &green));
	W.addPoint(new Point(2.0 / 16.0, 3.5 / 16.0, &blue));
	W.addPoint(new Point(8.0 / 16.0, 3.5 / 16.0, &white));
	W.addPoint(new Point(2.0 / 16.0, 0.0 / 16.0, &red));
	W.addPoint(new Point(8.0 / 16.0, 0.0 / 16.0, &green));

	W.addConnection(0, 3, 8);
	W.addConnection(0, 8, 6);
	W.addConnection(6, 8, 1);
	W.addConnection(8, 4, 1);
	W.addConnection(7, 1, 9);
	W.addConnection(9, 1, 4);
	W.addConnection(2, 9, 5);
	W.addConnection(2, 7, 9);

	W.translate2d(0, -0.3);
	BW->addMesh(&W);

	compositeMeshs.push_back(BW);

}

int Scene::buildCompositePolygonCube(Color* color)
{
	CompositeMesh* compositeCube = new CompositeMesh(Cube::name);
	Cube cube = Cube();
	if (color != nullptr)
	{
		cube = Cube(*color);
	}
	compositeCube->addMesh(&cube);

	compositeMeshs.push_back(compositeCube);
	return compositeMeshs.size() - 1;
}

void Scene::strikePoseRobot(SceneGraph* robotSceneGraph)
{
	robotSceneGraph->rotateNodeAroundAnchor(Robot::rightArm, glm::vec3(-10.0 * deg2rad, 0, 0));
	robotSceneGraph->rotateNodeAroundAnchor(Robot::rightLowerArm, glm::vec3(-10.0 * deg2rad, 0, 0));

}

void Scene::drawAtPath(std::vector<SceneGraphNode*>* path)
{
	Transform transformForPath = Transform(*globalTransform);

	GLuint vaoIDtoUse = calculatePathTransform(path, &transformForPath);

	if (vaoIDtoUse == 0)
	{
		std::cout << "Error vaoID is 0" << "\n";
		return;
	}

	m_shader->setUniform("model", transformForPath.getMatrix(), false);

	glBindVertexArray(vaoIDtoUse);

	glDrawElements(GL_TRIANGLES, _indiciesFromVaoID.find(vaoIDtoUse)->second, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Scene::drawSceneGraph(SceneGraph* sceneGraph)
{
	std::vector<std::vector<SceneGraphNode*>*>* allPaths = sceneGraph->getLinkedAllPaths();

	for (size_t o = 0; o < allPaths->size(); o++)
	{
		drawAtPath(allPaths->at(o));
	}

}

GLuint Scene::calculatePathTransform(std::vector<SceneGraphNode*>* path, Transform* transform)
{
	GLuint vaoIDtoUse = 0;
	for (int p = path->size() - 1; p >= 0; p--)
	{
		SceneGraphNode* currentNode = path->at(p);
		if (currentNode->getVAOid() != 0)
		{
			vaoIDtoUse = currentNode->getVAOid();
		}

		transform->setMatrix(transform->getMatrix() * currentNode->getMatrix());
	}
	return vaoIDtoUse;
}

void Scene::glSetup()
{
	//Load shader
	m_assets.addShaderProgram("shader", AssetManager::createShaderProgram("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl"));
	m_shader = m_assets.getShaderProgram("shader");
	m_shader->use();


	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.0f);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	_projection = glm::perspective(45.0, 16.0 / 9.0, 0.10, 30.0);
	m_shader->setUniform("projection", _projection, false);
	_cameraPosition = glm::vec3(6, 5, 6);
	_cameraTransform.setPosition(_cameraPosition);
	_cameraTarget = glm::vec3(0, -4, 0);
	_cameraUp = glm::vec3(0, 1, 0);
	_view = glm::lookAt(_cameraPosition, _cameraTarget, _cameraUp);
	m_shader->setUniform("view", _view, false);

}

void Scene::uploadCube(std::string& colorName, Color* color)
{
	//buildCompositePolygonBW();

	int compositePolygonToRender = buildCompositePolygonCube(color);
	GLuint vaoID = 0;
	GLuint vboID = 0;

	std::vector<float>* bVertexes = compositeMeshs.at(compositePolygonToRender)->getVerticies3dWithColor();
	std::vector<unsigned int>* bIndicies = compositeMeshs.at(compositePolygonToRender)->getIndicies();
	std::string bufferName = Cube::name + colorName;
	GLuint indiciesAmount = (GLuint)compositeMeshs.back()->getIndiciesAmount();

	GLERR;

	GLuint VertexBufferObjectID;
	glGenVertexArrays(1, &vaoID);
	glGenBuffers(1, &VertexBufferObjectID);

	_indiciesFromVaoID.insert(std::pair<GLuint, GLuint>(vaoID, indiciesAmount));
	glBindVertexArray(vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObjectID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * bVertexes->size(), bVertexes->data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float) * 0));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	GLuint indexBufferObject;
	glGenBuffers(1, &indexBufferObject);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * bIndicies->size(), bIndicies->data(), GL_STATIC_DRAW);

	vboIDs.insert(std::pair<std::string, GLuint>(bufferName, vboID));
	vaoIDs.insert(std::pair<std::string, GLuint>(bufferName, vaoID));
	unbindVertexAndArrayBuffers();
}

void Scene::createRobotsInScene()
{
	int roboDimesions = 8;
	for (size_t x = 0; x < roboDimesions; x++)
	{
		for (size_t y = 0; y < roboDimesions; y++)
		{
			std::string objectName = "Robot " + std::to_string(x) + " " + std::to_string(y);
			int vaoid = vaoIDs.find(Cube::name + rainbow)->second;
			_allSceneObjects.push_back(new Robot(objectName, vaoid));
			_allSceneObjects.back()->translate(glm::vec3((double)(x - ((double) roboDimesions / 2.0)) * 1.2, 0, (double)(y - ((double)roboDimesions / 2.0)) * 1.2));
			//_allSceneObjects.back()->translate(glm::vec3((double)(x) * 1.2, 0, (double)(y) * 1.2));
		}
	}
}

void Scene::addSceneToPhysicsWorld()
{
	for (size_t i = 0; i < _allSceneObjects.size(); i++)
	{
		_physicsWorld.addSceneObjectToWorld(_allSceneObjects.at(i));
	}
}

void Scene::animateRobot(SceneGraph* robotSceneGraph, float dt)
{
	float degrees = 30.0;
	robotSceneGraph->rotateNodeAroundAnchor(Robot::rightArm, glm::vec3(-degrees * deg2rad * dt, degrees * deg2rad * dt, 0));
	robotSceneGraph->rotateNodeAroundAnchor(Robot::rightLowerArm, glm::vec3(0, 0, degrees * deg2rad * dt));

	robotSceneGraph->rotateNodeAroundAnchor(Robot::leftArm, glm::vec3(0, -degrees * deg2rad * dt, 0));
	robotSceneGraph->rotateNodeAroundAnchor(Robot::leftLowerArm, glm::vec3(degrees * deg2rad * dt, -degrees * deg2rad * dt, 0));

	robotSceneGraph->rotateNodeAroundAnchor(Robot::rightLeg, glm::vec3(-degrees * deg2rad * dt, 0, 0));
	robotSceneGraph->rotateNodeAroundAnchor(Robot::leftLeg, glm::vec3(degrees * deg2rad * dt, degrees * deg2rad * dt, 0));

	robotSceneGraph->rotateNodeAroundAnchor(Robot::body, glm::vec3(5.0 * deg2rad * dt, 9.0 * deg2rad * dt, 17.0 * deg2rad * dt));


}

void Scene::swapWavingRobot(int willWave)
{
	for (size_t i = 0; i < _allSceneObjects.size(); i++)
	{
		if (i == willWave)
		{
			_allSceneObjects.at(i)->animationTransition("wave");
		}
		else
		{
			_allSceneObjects.at(i)->animationTransition("walk");
		}
	}
}

void Scene::unbindVertexAndArrayBuffers()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Scene::shutdown()
{

}
