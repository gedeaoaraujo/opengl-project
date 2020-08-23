#include <GL/glew.h>
#include <iostream>

#include "Transform.h"
#include "Display.h"
#include "Texture.h"
#include "Camera.h"
#include "Shader.h"
#include "Mesh.h"

#define WIDTH 800
#define HEIGHT 600

int main() {

	Display display(WIDTH, HEIGHT, "Hello world");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)), Vertex(
						  glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)), };

	uint indices[] = { 0, 1, 2 };

	Mesh triangle(vertices,
				  sizeof(vertices) / sizeof(vertices[0]), indices,
				  sizeof(indices) / sizeof(indices[0]));

	Mesh monkey("./res/monkey3.obj");
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");

	Camera camera(glm::vec3(0, 0, -4), 70.0f,
				  (float) WIDTH / (float) HEIGHT,
				  0.01f, 1000.0f);

	Transform transform;

	float counter = 0.0f;

	while (!display.getIsClosed()) {
		display.clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.getPosition().x = sinCounter;
		transform.getPosition().z = cosCounter;
		transform.getRotation().x = counter;
		transform.getRotation().y = counter;
		transform.getRotation().z = counter;
//		transform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.bind();
		texture.bind(0);
		shader.update(transform, camera);
		triangle.draw();
		monkey.draw();

		display.update();
		counter += 0.01f;
	}

	return 0;
}
