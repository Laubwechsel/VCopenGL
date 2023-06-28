#include "Animation.h"
#include "Transform.h"
#include "Transform/SceneGraphNode.h"

Animation::Animation(SceneGraphNode* toAnimate)
{
	_toAnimate = toAnimate;
}

void Animation::addKeyFrame(glm::vec3 &toAdd,float duration)
{
	_keyFrames.push_back(std::make_pair(glm::vec3(toAdd),duration));
	_lastKeyframe = &_keyFrames.back();
}

void Animation::animate(float dt)
{
	_timer += dt;

	nextKeyframeCheck();

	std::pair<glm::vec3,float> &keyFrame = _keyFrames.at(_currentKeyframeIndex);
	float fraction = _timer / keyFrame.second;
	glm::vec3 targetRotation = _lastKeyframe->first + ((keyFrame.first-_lastKeyframe->first) * fraction);
	//glm::vec3 sourceRotation = glm::eulerAngles(_lastKeyframeTransform->getRotation());
	//glm::vec3 diffRotation = (targetRotation - sourceRotation)*fraction;
	_toAnimate->resetPosition();
	_toAnimate->rotateAroundAnchor(targetRotation);
}

void Animation::reset()
{
	_timer = 0.0;
	_currentKeyframeIndex = 0;
}


void Animation::setToAnimate(SceneGraphNode* toAnimate)
{
	_toAnimate = toAnimate;
}

void Animation::nextKeyframeCheck()
{
	std::pair<glm::vec3, float> &keyFrame = _keyFrames.at(_currentKeyframeIndex);

	if (_timer > keyFrame.second)
	{
		_lastKeyframe = &keyFrame;
		_timer = 0.0;
		_currentKeyframeIndex++;
		if (_currentKeyframeIndex >= _keyFrames.size())
		{
			_currentKeyframeIndex = 0;
		}
	}

}
