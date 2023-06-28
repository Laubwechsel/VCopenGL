#pragma once
class Collision;
class CollisionEventListener {
public:
	virtual void notify(Collision* collision) = 0;
};