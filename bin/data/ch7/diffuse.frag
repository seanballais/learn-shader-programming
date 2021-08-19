#version 410

uniform vec3 lightDirection;
uniform vec3 lightColour;
uniform vec3 meshColour;

in vec3 fragNorm;

out vec4 outColour;

void main()
{
    vec3 normal = normalize(fragNorm);
    float lightAmount = dot(normal, lightDirection);
    vec3 fragLight = lightColour * lightAmount;

    outColour = vec4(meshColour * fragLight, 1.f);
}
