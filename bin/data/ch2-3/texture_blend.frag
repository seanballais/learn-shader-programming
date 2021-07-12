#version 410

uniform sampler2D parrotTex;
uniform sampler2D checkerboardTex;
uniform float time;

in vec2 fragUV;

out vec4 outColour;

void main()
{
    const float pi = 3.1415926f;

    vec4 parrotCol = texture(parrotTex, fragUV);
    vec4 checkerCol = texture(checkerboardTex, fragUV);

    outColour = mix(checkerCol, parrotCol, ((sin(pi * time) * 0.5f) + 0.5f) * checkerCol.r);
}
