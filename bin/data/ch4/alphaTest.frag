#version 410

uniform sampler2D tex;

in vec2 fragUV;

out vec4 outColour;

void main()
{
    outColour = texture(tex, fragUV);
    if (outColour.a < 1.f) {
        discard;
    }

    outColour = vec4(fragUV.xy, 0.f, 1.f);
}
