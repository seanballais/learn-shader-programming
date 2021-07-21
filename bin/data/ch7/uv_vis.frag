#version 410

in vec2 fragUV;

out vec4 outColour;

void main()
{
    outColour = vec4(fragUV, 0.f, 1.f);
}
