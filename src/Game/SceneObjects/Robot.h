#pragma once

#include <vector>;
#include "Transform/SceneGraph.h";
#include "SceneObject.h"
#include "Physics/RigidBodys/RigidBody.h"

class RobotAI;
class Animator;
class AnimatorState;
class Robot:public SceneObject {
public:
	Robot(std::string &objectName, GLuint cubeVAOid);
	SceneGraph* getLinkedSceneGraph() override;
	void animate(float dt) override;
	void update(float dt) override;
	void animationTransition(std::string transition) override;
	void translate(glm::vec3 &amount) override;
	void setScale(glm::vec3& scale) override;

	void lookAt(glm::vec3 &point) override;

	void setRigidBody(RigidBody* rb) override;
	RigidBody* getRigidBody() override;



	static const std::string body;
	static const std::string bodyMesh;
	static const std::string head;
	static const std::string headMesh;
	static const std::string rightArm;
	static const std::string rightArmMesh;
	static const std::string rightLowerArm;
	static const std::string rightLowerArmMesh;
	static const std::string leftArm;
	static const std::string leftArmMesh;
	static const std::string leftLowerArm;
	static const std::string leftLowerArmMesh;
	static const std::string rightLeg;
	static const std::string rightLegMesh;
	static const std::string leftLeg;
	static const std::string leftLegMesh;
	static const std::string cube;

private:
	void buildSceneGraph(GLuint cubeVAOid);
	void buildAnimator();
	void buildWalkingAnimation(AnimatorState* walkingAnimState);
	void buildWavingAnimation(AnimatorState* wavingAnimState);

	SceneGraph _sceneGraph = SceneGraph();
	Animator* _animator;
	RigidBody * _rigidBody;

	RobotAI * _robotAI;
	
};