#version 410

uniform sampler2D parrotTex;
uniform float brightness;

in vec2 fragUV;
out vec4 outColour;

void main()
{
    outColour = texture(parrotTex, fragUV) * brightness;
}
