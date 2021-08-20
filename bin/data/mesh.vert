#version 410

layout (location = 0) in vec3 pos;
layout (location = 2) in vec3 normal;

uniform mat4 mvp;
uniform mat3 normalMatrix;
uniform mat4 model;

out vec3 fragNorm;
out vec3 fragWorldPosition;

void main()
{
    gl_Position = mvp * vec4(pos, 1.f);
    fragNorm = (normalMatrix * normal).xyz;
    fragWorldPosition = (model * vec4(pos, 1.f)).xyz;
}
