#pragma once
#include "libheaders.h"
class Collider {
public:
	void setSize(glm::vec3& size);
	glm::vec3 getSize();

	void setOffset(glm::vec3& offset);
	glm::vec3 getOffset();
private:
	glm::vec3 _size = glm::vec3(1, 1, 1);
	glm::vec3 _offset = glm::vec3(0, 0, 0);
};