#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 fragUV;

void main()
{
    gl_Position = projection * view * model * vec4(pos, 1.f);
    fragUV = vec2(uv.x, 1.f - uv.y);
}
