#version 410

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;

uniform vec2 size;
uniform vec2 offset;

out vec2 fragUV;

void main()
{
    gl_Position = vec4(pos, 1.0);
    fragUV = vec2(uv.x, 1.0 - uv.y) * size * (offset * size);
}
