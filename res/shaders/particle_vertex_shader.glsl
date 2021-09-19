#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in uint textureIndex;
layout (location = 2) in float size;

out float pass_textureIndex;

uniform mat4 projection;
uniform mat4 view;

void main(){
	gl_Position = projection * view * vec4(position, 1.0);
	gl_PointSize = size / gl_Position.w;
	pass_textureIndex = float(textureIndex);
}
