#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform mat4 view;

out vec2 fragUV;

void main()
{
    gl_Position = view * vec4(pos, 1.f);
    fragUV = vec2(uv.x, 1.f - uv.y);
}
