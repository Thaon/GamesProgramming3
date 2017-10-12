/*
==========================================================================
cCube.h
==========================================================================
*/

#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "windowOGL.h"
#include "glm\glm.hpp"
#include "glx\glext.h"
#include "wglext.h"
#include <vector>
#include "cColours.h"
#include "cShapes.h"

class Pyramid : public cShapes
{
public:
	Pyramid();
	virtual void render(float rotAngle);
	virtual void initialise();

private:

	glm::vec3 m_bottomLeft;
	glm::vec3 m_topLeft;
	glm::vec3 m_bottomRight;
	glm::vec3 m_topRight;
	glm::vec3 m_top;

	glm::vec3 m_Faces[6];
	GLuint m_Indices[18];

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_colourList;
	GLuint m_VertexBufferObjects[3];
};

#endif