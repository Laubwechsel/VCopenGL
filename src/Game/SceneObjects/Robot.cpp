#include "Robot.h"
#include "Animation/Animation.h"
#include "Animation/AnimatorState.h"
#include "Animation/Animator.h"
#include "Consts.h"
#include "AI/RobotAI.h"


const std::string Robot::body = "Body";
const std::string Robot::bodyMesh = "BodyMesh";
const std::string Robot::head = "Head";
const std::string Robot::headMesh = "HeadMesh";
const std::string Robot::rightArm = "RightArm";
const std::string Robot::rightArmMesh = "RightArmMesh";
const std::string Robot::rightLowerArm = "RightLowerArm";
const std::string Robot::rightLowerArmMesh = "RightLowerArmMesh";
const std::string Robot::leftArm = "LeftArm";
const std::string Robot::leftArmMesh = "LeftArmMesh";
const std::string Robot::leftLowerArm = "LeftLowerArm";
const std::string Robot::leftLowerArmMesh = "LeftLowerArmMesh";
const std::string Robot::rightLeg = "RightLeg";
const std::string Robot::rightLegMesh = "RightLegMesh";
const std::string Robot::leftLeg = "LeftLeg";
const std::string Robot::leftLegMesh = "LeftLegMesh";
const std::string Robot::cube = "Cube";

Robot::Robot(std::string& objectName, GLuint cubeVAOid): SceneObject(objectName)
{
	_rigidBody = new RigidBody(objectName);
	buildSceneGraph(cubeVAOid);
	buildAnimator();

	_rigidBody->setColliderSize(_sceneGraph.getNodeByName(body)->getDefaultScale()* _sceneGraph.getNodeByName(bodyMesh)->getDefaultScale());
	_rigidBody->setPosition(_sceneGraph.getNodeByName(body)->getDefaultPosition());
	_rigidBody->setWeight(1);

	_robotAI = new RobotAI(this);
}

SceneGraph* Robot::getLinkedSceneGraph()
{
	return &_sceneGraph;
}

void Robot::animate(float dt)
{
	_animator->animate(dt);
}

void Robot::update(float dt)
{
	_robotAI->update(dt);
	_sceneGraph.getNodeByName(body)->setPosition(_rigidBody->getPosition());
}

void Robot::animationTransition(std::string transition)
{
	_animator->transition(transition);
}

void Robot::translate(glm::vec3 &amount)
{
	_rigidBody->translate(amount);
}

void Robot::setScale(glm::vec3& scale)
{
	_rigidBody->setColliderSize(scale);
	_sceneGraph.getNodeByName(body)->setDefaultScale(_rigidBody->getPosition());
}

void Robot::lookAt(glm::vec3 &point)
{
}

void Robot::setRigidBody(RigidBody* rb)
{
	_rigidBody = rb;
}

RigidBody* Robot::getRigidBody()
{
	return _rigidBody;
}

void Robot::buildSceneGraph(GLuint cubeVAOid)
{


	_sceneGraph.addNode(new SceneGraphNode(body));
	_sceneGraph.addNode(new SceneGraphNode(bodyMesh));
	_sceneGraph.addNode(new SceneGraphNode(leftLeg));
	_sceneGraph.addNode(new SceneGraphNode(leftLegMesh));
	_sceneGraph.addNode(new SceneGraphNode(rightLeg));
	_sceneGraph.addNode(new SceneGraphNode(rightLegMesh));
	_sceneGraph.addNode(new SceneGraphNode(leftArm));
	_sceneGraph.addNode(new SceneGraphNode(leftArmMesh));
	_sceneGraph.addNode(new SceneGraphNode(leftLowerArm));
	_sceneGraph.addNode(new SceneGraphNode(leftLowerArmMesh));
	_sceneGraph.addNode(new SceneGraphNode(rightArm));
	_sceneGraph.addNode(new SceneGraphNode(rightArmMesh));
	_sceneGraph.addNode(new SceneGraphNode(rightLowerArm));
	_sceneGraph.addNode(new SceneGraphNode(rightLowerArmMesh));
	_sceneGraph.addNode(new SceneGraphNode(head));
	_sceneGraph.addNode(new SceneGraphNode(headMesh));
	_sceneGraph.addNode(new SceneGraphNode(cube));

	_sceneGraph.addConnection(body, bodyMesh);
	_sceneGraph.addConnection(body, leftLeg);
	_sceneGraph.addConnection(body, rightLeg);
	_sceneGraph.addConnection(body, leftArm);
	_sceneGraph.addConnection(body, rightArm);
	_sceneGraph.addConnection(body, head);
	_sceneGraph.addConnection(rightArm, rightLowerArm);
	_sceneGraph.addConnection(rightArm, rightArmMesh);
	_sceneGraph.addConnection(rightLowerArm, rightLowerArmMesh);
	_sceneGraph.addConnection(leftArm, leftLowerArm);
	_sceneGraph.addConnection(leftArm, leftArmMesh);
	_sceneGraph.addConnection(leftLowerArm, leftLowerArmMesh);
	_sceneGraph.addConnection(leftLeg, leftLegMesh);
	_sceneGraph.addConnection(rightLeg, rightLegMesh);
	_sceneGraph.addConnection(head, headMesh);
	_sceneGraph.addConnection(headMesh, cube);
	_sceneGraph.addConnection(bodyMesh, cube);
	_sceneGraph.addConnection(rightArmMesh, cube);
	_sceneGraph.addConnection(rightLowerArmMesh, cube);
	_sceneGraph.addConnection(leftArmMesh, cube);
	_sceneGraph.addConnection(leftLowerArmMesh, cube);
	_sceneGraph.addConnection(rightLegMesh, cube);
	_sceneGraph.addConnection(leftLegMesh, cube);

	float headDimension = 0.25;
	float bodyHeight = 0.75;
	float bodyWidth = 0.5;
	float armHeight = 0.4;
	float armWidth = 0.25;
	float legHeight = 0.5;
	float legWidth = 0.25;

	float headVerticalOffset = ((bodyHeight / 2.0) + (headDimension / 2.0)) * 1.0;

	float armHorizontalOffset = ((bodyWidth / 2.0) + (armWidth / 2.0)) * 1.05;
	float armVerticalOffset = ((bodyHeight / 2.0) - (armHeight / 2.0));

	float lowerArmVerticalOffset = -armHeight * 1.05;

	float legHorizontalOffset = ((bodyWidth / 2.0) * 1.05) - (legWidth / 2.0);
	float leggVertivalOffset = -((bodyHeight / 2.0) + (legHeight / 2.0)) * 1.05;

	_sceneGraph.getNodeByName(body)->setDefaultScale(glm::vec3(0.5, 0.5, 0.5));
	_sceneGraph.getNodeByName(bodyMesh)->setDefaultScale(glm::vec3(bodyWidth, bodyHeight, bodyWidth));

	_sceneGraph.getNodeByName(head)->setDefaultPosition(glm::vec3(0, headVerticalOffset, 0));
	_sceneGraph.getNodeByName(headMesh)->setDefaultScale(glm::vec3(headDimension, headDimension, headDimension));

	_sceneGraph.getNodeByName(leftArm)->setDefaultPosition(glm::vec3(-armHorizontalOffset, armVerticalOffset, 0));
	_sceneGraph.getNodeByName(leftArm)->rotationAnchorPoint = glm::vec3(-armHorizontalOffset, (armVerticalOffset + (armHeight / 2.0)) * 0.95, 0);
	_sceneGraph.getNodeByName(leftArmMesh)->setDefaultScale(glm::vec3(armWidth, armHeight, armWidth));

	_sceneGraph.getNodeByName(leftLowerArm)->setDefaultPosition(glm::vec3(0, lowerArmVerticalOffset, 0));
	_sceneGraph.getNodeByName(leftLowerArm)->rotationAnchorPoint = glm::vec3(0, (lowerArmVerticalOffset + (armHeight / 2.0)) * 1.05, 0);
	_sceneGraph.getNodeByName(leftLowerArmMesh)->setDefaultScale(glm::vec3(armWidth, armHeight, armWidth));

	_sceneGraph.getNodeByName(rightArm)->setDefaultPosition(glm::vec3(armHorizontalOffset, armVerticalOffset, 0));
	_sceneGraph.getNodeByName(rightArm)->rotationAnchorPoint = glm::vec3(armHorizontalOffset, (armVerticalOffset + (armHeight / 2.0)) * 0.95, 0);
	_sceneGraph.getNodeByName(rightArmMesh)->setDefaultScale(glm::vec3(armWidth, armHeight, armWidth));

	_sceneGraph.getNodeByName(rightLowerArm)->setDefaultPosition(glm::vec3(0, lowerArmVerticalOffset, 0));
	_sceneGraph.getNodeByName(rightLowerArm)->rotationAnchorPoint = glm::vec3(0, (lowerArmVerticalOffset + (armHeight / 2.0)) * 1.05, 0);
	_sceneGraph.getNodeByName(rightLowerArmMesh)->setDefaultScale(glm::vec3(armWidth, armHeight, armWidth));

	_sceneGraph.getNodeByName(leftLeg)->setDefaultPosition(glm::vec3(-legHorizontalOffset, leggVertivalOffset, 0));
	_sceneGraph.getNodeByName(leftLeg)->rotationAnchorPoint = glm::vec3(-legHorizontalOffset, (leggVertivalOffset + (legHeight / 2.0)) * 1.05, 0);
	_sceneGraph.getNodeByName(leftLegMesh)->setDefaultScale(glm::vec3(legWidth, legHeight, legWidth));

	_sceneGraph.getNodeByName(rightLeg)->setDefaultPosition(glm::vec3(legHorizontalOffset, leggVertivalOffset, 0));
	_sceneGraph.getNodeByName(rightLeg)->rotationAnchorPoint = glm::vec3(legHorizontalOffset, (leggVertivalOffset + (legHeight / 2.0)) * 1.05, 0);
	_sceneGraph.getNodeByName(rightLegMesh)->setDefaultScale(glm::vec3(legWidth, legHeight, legWidth));

	_sceneGraph.getNodeByName(cube)->setVAOid(cubeVAOid);
}

void Robot::buildAnimator()
{
	AnimatorState* idle = new AnimatorState(&_sceneGraph);

	AnimatorState* walking = new AnimatorState(&_sceneGraph);
	AnimatorState* waving = new AnimatorState(&_sceneGraph);

	buildWalkingAnimation(walking);
	buildWavingAnimation(waving);


	_animator = new Animator("idle", idle);
	_animator->addState("walking", walking);
	_animator->addState("waving", waving);
	_animator->addTransition("idle", "walking", "walk");
	_animator->addTransition("walking", "waving", "wave");
	_animator->addTransition("waving", "walking", "walk");
	_animator->transition("walk");

}

void Robot::buildWalkingAnimation(AnimatorState* walkingAnimState)
{
#pragma region LeftLegAnimation
	Animation* walkingLeftLeg = new Animation(_sceneGraph.getNodeByName(leftLeg));
	glm::vec3 wllK0 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingLeftLeg->addKeyFrame(wllK0, 0.5f);
	glm::vec3 wllK1 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftLeg->addKeyFrame(wllK1, 0.5f);
	glm::vec3 wllK2 = glm::vec3(-30.0 * deg2rad, 0, 0);
	walkingLeftLeg->addKeyFrame(wllK2, 0.5f);
	glm::vec3 wllK3 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftLeg->addKeyFrame(wllK3, 0.5f);
	walkingAnimState->addAnimation(leftLeg, walkingLeftLeg);

#pragma endregion


#pragma region RightLegAnimation
	Animation* walkingRightLeg = new Animation(_sceneGraph.getNodeByName(rightLeg));
	glm::vec3 wrlK0 = glm::vec3(-30.0 * deg2rad, 0, 0);
	walkingRightLeg->addKeyFrame(wrlK0, 0.5f);
	glm::vec3 wrlK1 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingRightLeg->addKeyFrame(wrlK1, 0.5f);
	glm::vec3 wrlK2 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingRightLeg->addKeyFrame(wrlK2, 0.5f);
	glm::vec3 wrlK3 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingRightLeg->addKeyFrame(wrlK3, 0.5f);
	walkingAnimState->addAnimation(rightLeg, walkingRightLeg);

#pragma endregion

#pragma region LeftArmAnimation

	Animation* walkingLeftArm = new Animation(_sceneGraph.getNodeByName(leftArm));
	glm::vec3 wlaK0 = glm::vec3(-30.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK0, 0.5f);
	glm::vec3 wlaK1 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK1, 0.5f);
	glm::vec3 wlaK2 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK2, 0.5f);
	glm::vec3 wlaK3 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK3, 0.5f);
	walkingAnimState->addAnimation(leftArm, walkingLeftArm);

#pragma endregion

#pragma region LeftLowerArmAnimation

	Animation* walkingLeftLowerArmq = new Animation(_sceneGraph.getNodeByName(leftLowerArm));
	glm::vec3 wllaK0 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK0, 0.5f);
	glm::vec3 wllaK1 = glm::vec3(15.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK1, 0.5f);
	glm::vec3 wllaK2 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK2, 0.5f);
	glm::vec3 wllaK3 = glm::vec3(15.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK3, 0.5f);
	walkingAnimState->addAnimation(leftLowerArm, walkingLeftLowerArmq);

#pragma endregion

#pragma region RigthArmAnimation

	Animation* walkingRightArm = new Animation(_sceneGraph.getNodeByName(rightArm));
	glm::vec3 wraK0 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingRightArm->addKeyFrame(wraK0, 0.5f);
	glm::vec3 wraK1 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingRightArm->addKeyFrame(wraK1, 0.5f);
	glm::vec3 wraK2 = glm::vec3(-30.0 * deg2rad, 0, 0);
	walkingRightArm->addKeyFrame(wraK2, 0.5f);
	glm::vec3 wraK3 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingRightArm->addKeyFrame(wraK3, 0.5f);
	walkingAnimState->addAnimation(rightArm, walkingRightArm);

#pragma endregion

#pragma region RightLowerArmAnimation

	Animation* walkingRightLowerArmq = new Animation(_sceneGraph.getNodeByName(rightLowerArm));
	glm::vec3 wrlaK0 = glm::vec3(30.0 * deg2rad, 0, 0);
	walkingRightLowerArmq->addKeyFrame(wrlaK0, 0.5f);
	glm::vec3 wrlaK1 = glm::vec3(15.0 * deg2rad, 0, 0);
	walkingRightLowerArmq->addKeyFrame(wrlaK1, 0.5f);
	glm::vec3 wrlaK2 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingRightLowerArmq->addKeyFrame(wrlaK2, 0.5f);
	glm::vec3 wrlaK3 = glm::vec3(15.0 * deg2rad, 0, 0);
	walkingRightLowerArmq->addKeyFrame(wrlaK3, 0.5f);
	walkingAnimState->addAnimation(rightLowerArm, walkingRightLowerArmq);

#pragma endregion


}

void Robot::buildWavingAnimation(AnimatorState* wavingAnimState)
{
#pragma region LeftArmAnimation

	Animation* walkingLeftArm = new Animation(_sceneGraph.getNodeByName(leftArm));
	glm::vec3 wlaK0 = glm::vec3(180.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK0, 0.5f);
	glm::vec3 wlaK1 = glm::vec3(180.0 * deg2rad, 0, 0);
	walkingLeftArm->addKeyFrame(wlaK1, 0.5f);
	glm::vec3 wlaK2 = glm::vec3(180.0 * deg2rad, 0.0 * deg2rad, 0);
	walkingLeftArm->addKeyFrame(wlaK2, 0.5f);
	glm::vec3 wlaK3 = glm::vec3(180.0 * deg2rad, 0.0 * deg2rad, 0);
	walkingLeftArm->addKeyFrame(wlaK3, 0.5f);
	wavingAnimState->addAnimation(leftArm, walkingLeftArm);

#pragma endregion

#pragma region LeftLowerArmAnimation

	Animation* walkingLeftLowerArmq = new Animation(_sceneGraph.getNodeByName(leftLowerArm));
	glm::vec3 wllaK0 = glm::vec3(0.0 * deg2rad, 0, 15.0 * deg2rad);
	walkingLeftLowerArmq->addKeyFrame(wllaK0, 0.5f);
	glm::vec3 wllaK1 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK1, 0.5f);
	glm::vec3 wllaK2 = glm::vec3(0.0 * deg2rad, 0, -15.0 * deg2rad);
	walkingLeftLowerArmq->addKeyFrame(wllaK2, 0.5f);
	glm::vec3 wllaK3 = glm::vec3(0.0 * deg2rad, 0, 0);
	walkingLeftLowerArmq->addKeyFrame(wllaK3, 0.5f);
	wavingAnimState->addAnimation(leftLowerArm, walkingLeftLowerArmq);

#pragma endregion

}
