#version 410

uniform vec3 lightDirection;
uniform vec3 lightColour;
uniform vec3 meshColour;
uniform vec3 cameraPosition;
uniform float rimIntensity;

in vec3 fragNorm;
in vec3 fragWorldPosition;

out vec4 outColour;

void main()
{
    vec3 normal = normalize(fragNorm);

    vec3 fragToCam = normalize(cameraPosition - fragWorldPosition);
    float rimAmount = 1.f - max(0.f, dot(normal, fragToCam));
    rimAmount = pow(rimAmount, 2);

    float lightAmount = max(0.f, dot(normal, lightDirection));
    vec3 fragLight = lightColour * lightAmount;

    outColour = vec4((meshColour * fragLight) + (rimAmount * rimIntensity), 1.f);
}
