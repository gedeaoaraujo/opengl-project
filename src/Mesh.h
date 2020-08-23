#ifndef MESH_H_
#define MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "obj_loader.h"

typedef unsigned int uint;
using namespace glm;

class Vertex {
private:
	vec3 pos;
	vec2 texCoord;
	vec3 normal;

public:
	Vertex(const vec3& pos, const vec2& textCoord, vec3 normal = vec3(0,0,0)) {
		this->pos = pos;
		this->texCoord = textCoord;
		this->normal = normal;
	}

	inline vec3* getPos(){ return &pos; }
	inline vec2* getTexCoord(){ return &texCoord; }
	inline vec3* getNormal(){ return &normal; }
};

class Mesh {

public:
	Mesh(Vertex *vertices, uint numVertices, uint* indices, uint numIndices);
	Mesh(const std::string& fileName);
	void draw();
	virtual ~Mesh();

private:
	Mesh(const Mesh &other);
	void operator=(const Mesh &other);

	void initMesh(const IndexedModel& model);

	enum { POSITION_VB, TEXCOORD_VB, NORMAL_VB,INDEX_VB, NUM_BUFFERS };

	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	uint drawCount;
};

#endif /* MESH_H_ */
