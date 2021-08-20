#version 410

uniform vec3 lightDirection;
uniform vec3 lightColour;
uniform vec3 meshColour;
uniform vec3 meshSpecularColour;
uniform vec3 ambientColour;
uniform vec3 cameraPosition;

in vec3 fragNorm;
in vec3 fragWorldPosition;

out vec4 outColour;

void main()
{
    vec3 norm = normalize(fragNorm);
    vec3 viewDirection = normalize(cameraPosition - fragWorldPosition);

    float diffusionAmount = max(0.f, dot(norm, lightDirection));
    vec3 diffusionColour = meshColour * lightColour * diffusionAmount;

    vec3 halfVec = normalize(viewDirection + lightDirection);
    float specularAmount = max(0.f, dot(halfVec, norm));
    float specularBrightness = pow(specularAmount, 2.f);
    vec3 specularColour = meshSpecularColour * lightColour * specularBrightness;

    vec3 ambientCol = ambientColour * meshColour;

    outColour = vec4(diffusionColour + specularColour + ambientCol, 1.f);
}
