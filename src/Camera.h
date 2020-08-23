/*
 * Camera.h
 *
 *  Created on: Aug 22, 2020
 *      Author: belphegor
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;

class Camera {

private:
	mat4 perspective;
	vec3 position;
	vec3 forward;
	vec3 up;

public:
	Camera(const vec3& pos, float fov, float aspect,
							float zNear, float zFar){
		perspective = glm::perspective(fov, aspect, zNear, zFar);
		position = pos;
		forward = vec3(0,0,1);
		up = vec3(0,1,0);
	}

	inline mat4 getViewProjection() const {
		return perspective * lookAt(position, position + forward, up);
	}
};

#endif /* CAMERA_H_ */
