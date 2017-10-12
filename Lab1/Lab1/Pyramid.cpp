/*
==================================================================================
cCube.cpp
==================================================================================
*/

#include "Pyramid.h"

Pyramid::Pyramid()
{
	setRotAngle(0.0f);
}

void Pyramid::render(float rotAngle)
{
	glRotatef(rotAngle, 0.0f, 1.0f, 0.0f); 
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
}

void Pyramid::initialise()
{
	m_topLeft = glm::vec3(-1.0f, 0.0f, -1.0f);
	m_bottomLeft = glm::vec3(-1.0f, 0.0f, 1.0f);
	m_topRight= glm::vec3(1.0f, 0.0f, -1.0f);
	m_bottomRight= glm::vec3(1.0f, 0.0f, 1.0f);
	m_top = glm::vec3(0.0f, 1.0f, 0.0f);

	//Push back 8 vertices that make up a cube 
	m_vertices.push_back(m_bottomLeft);
	m_vertices.push_back(m_topLeft);
	m_vertices.push_back(m_bottomRight);
	m_vertices.push_back(m_topRight);
	m_vertices.push_back(m_top);



	m_Indices[0] = 0; // left face
	m_Indices[1] = 1;
	m_Indices[2] = 4;

	m_Indices[3] = 0; // front face 
	m_Indices[4] = 2;
	m_Indices[5] = 4;

	m_Indices[6] = 2; // right face 
	m_Indices[7] = 3;
	m_Indices[8] = 4;

	m_Indices[9] = 1; // back face 
	m_Indices[10] = 3;
	m_Indices[11] = 4;

	m_Indices[12] = 1; // bottom face 
	m_Indices[13] = 0;
	m_Indices[14] = 2;
	m_Indices[15] = 2;
	m_Indices[16] = 3;
	m_Indices[17] = 1;

	// Create Colour list 
	cColours theColour;

	for (int Colour = 0; Colour < 6; Colour++)
	{
		m_colourList.push_back(theColour.getColour(static_cast<cColours::colours>(Colour)));
	}

	// Assign variables that will be used to store the unique object ID’s that will be used to refer to the two buffers. 

	glGenBuffers = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glGenBuffers(2, &m_VertexBufferObjects[0]);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]); //Bind the vertex buffer 
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VertexBufferObjects[1]); //Bind the vertex buffer 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeof(m_Indices), &m_Indices[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * m_colourList.size(), &m_colourList[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	//Bind the colour array, and set the color pointer to point at it 
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glColorPointer(3, GL_FLOAT, sizeof(GLfloat) * 3 * 3, 0);

	//Bind the vertex array and set the vertex pointer to point at it 
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
}
