#version 410

layout (location = 0) in vec3 position;
layout (location = 3) in vec2 uv;

uniform float time;

out vec2 fragUV;

void main()
{
    gl_Position = vec4(position, 1.f);
    fragUV = vec2(uv.x, 1.f - uv.y) + (vec2(1.f, 0.f) * time);
}
