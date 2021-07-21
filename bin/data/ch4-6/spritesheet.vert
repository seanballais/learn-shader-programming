#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec2 size;
uniform vec2 offset;
uniform bool flipCharacter;

out vec2 fragUV;

void main()
{
    gl_Position = projection * view * model * vec4(pos, 1.f);
    fragUV = vec2(abs(int(flipCharacter) - uv.x), 1.f - uv.y) * size + (offset * size);
}
