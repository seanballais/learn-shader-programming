#version 410

uniform sampler2D tex;

in vec2 fragUV;

out vec4 outColour;

void main()
{
    outColour = texture(tex, fragUV);
    outColour.a = min(outColour.a, 0.8);
}
