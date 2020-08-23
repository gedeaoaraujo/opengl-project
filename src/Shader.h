#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader {

private:
	static const unsigned int NUM_SHADERS = 2;
	enum { TRANSFORM_U, NUM_UNIFORMS};

	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];

	Shader(const Shader &other);
	Shader& operator=(const Shader &other);

public:
	Shader(const std::string& fileName);

	void bind();
	void update(const Transform& transform, const Camera& camera);

	virtual ~Shader();

};

#endif /* SHADER_H_ */
