#version 410

uniform sampler2D parrotTex;

in vec2 fragUV;
out vec4 outColour;

void main()
{
    outColour = texture(parrotTex, fragUV);
}
