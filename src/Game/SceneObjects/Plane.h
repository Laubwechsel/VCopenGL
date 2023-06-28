#pragma once
#include "SceneObject.h"
#include "Transform/SceneGraph.h"
#include "Physics/RigidBodys/RigidBody.h"

class Plane : public SceneObject {
public:
	Plane(std::string& objectName, GLuint cubeVAOid);
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
	static const std::string cube;


private:
	void buildSceneGraph(GLuint cubeVAOid);
	//void buildAnimator();
	//void buildWalkingAnimation(AnimatorState* walkingAnimState);
	//void buildWavingAnimation(AnimatorState* wavingAnimState);

	SceneGraph _sceneGraph = SceneGraph();
	//Animator* _animator;
	RigidBody* _rigidBody;

};