#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string>
#include <GL/glew.h>

class Texture {

public:
	Texture(const std::string& fileName);

	void bind(unsigned int unit);

	virtual ~Texture();
	
private:
	Texture(const Texture &other);
	void operator=(const Texture &other);

	GLuint texture;
};

#endif /* TEXTURE_H_ */
