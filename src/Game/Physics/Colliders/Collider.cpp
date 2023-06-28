#include "Collider.h"

void Collider::setSize(glm::vec3& size)
{
	_size.x = size.x;
	_size.y = size.y;
	_size.z = size.z;
}

glm::vec3 Collider::getSize()
{
	return _size;
}

void Collider::setOffset(glm::vec3 &offset)
{
	_offset.x = offset.x;
	_offset.y = offset.y;
	_offset.z = offset.z;
}

glm::vec3 Collider::getOffset()
{
	return _offset;
}
