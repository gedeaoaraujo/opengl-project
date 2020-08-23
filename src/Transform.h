/*
 * Transform.h
 *
 *  Created on: Aug 22, 2020
 *      Author: belphegor
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;

class Transform {

private:
	vec3 position;
	vec3 rotation;
	vec3 scale;

public:
	Transform(const vec3 pos = vec3(),
			  const vec3& rot = vec3(),
			  const vec3& scale = vec3(1.0f, 1.0f, 1.0f)
			  ): position(pos), rotation(rot), scale(scale){}

	inline mat4 getModel() const {
		mat4 positionMatrix = translate(position);
		mat4 rotationXMatrix = rotate(rotation.x, vec3(1,0,0));
		mat4 rotationYMatrix = rotate(rotation.y, vec3(0,1,0));
		mat4 rotationZMatrix = rotate(rotation.z, vec3(0,0,1));
		mat4 scaleMatrix = glm::scale(scale);

		mat4 rotationMatrix = 	rotationZMatrix *
								rotationYMatrix *
								rotationXMatrix;

		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	inline vec3& getPosition() { return position; }
	inline vec3& getRotation() { return rotation; }
	inline vec3& getScale() { return scale; }

	void setPosition(const vec3 &pos) { this->position = pos; }
	void setRotation(const vec3 &rot) { this->rotation = rot; }
	void setScale(const vec3 &scale) { this->scale = scale; }

};

#endif /* TRANSFORM_H_ */
