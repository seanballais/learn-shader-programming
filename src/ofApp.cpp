#include <cmath>

#include <glm/gtx/string_cast.hpp>

#include "ofApp.h"

glm::vec3 getLightDirection(DirectionalLight& light)
{
    return glm::normalize(light.direction * -1.f);
}

glm::vec3 getLightColour(DirectionalLight& light)
{
    return light.colour * light.intensity;
}

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofEnableDepthTest();

    m_torusMesh.load("ch7/torus.ply");
    m_shader.load("ch7/mesh.vert", "ch7/torus.frag");
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    DirectionalLight directionalLight;
    directionalLight.direction = glm::normalize(glm::vec3(0.f, -1.f, 0.f));
    directionalLight.colour = glm::vec3(1.f, 1.f, 1.f);
    directionalLight.intensity = 1.f;

    m_camera.position = glm::vec3(0.f, 0.75f, 1.f);
    m_camera.fov = glm::radians(90.f);

    float camAngle = glm::radians(-45.f);
    float aspect = 1024.f / 768.f;

    glm::vec3 right = glm::vec3(1.f, 0.f, 0.f);

    glm::mat4 model = glm::rotate(glm::radians(90.f), right)
                      * glm::scale(glm::vec3(0.5f, 0.5f, 0.5f));
    glm::mat4 view = glm::inverse(glm::translate(m_camera.position)
                                  * glm::rotate(camAngle, right));
    glm::mat4 projection = glm::perspective(m_camera.fov, aspect, 0.01f, 10.f);

    glm::mat4 mvp = projection * view * model;
    glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(model)));

    float rimIntensity = (std::sin(M_PI * (ofGetElapsedTimeMillis() / 1000.f)) / 4.f) + 0.5f;

    m_shader.begin();
    m_shader.setUniformMatrix4f("mvp", mvp);
    m_shader.setUniformMatrix3f("normalMatrix", normalMatrix);
    m_shader.setUniformMatrix4f("model", model);
    m_shader.setUniform3f("lightDirection", getLightDirection(directionalLight));
    m_shader.setUniform3f("lightColour", getLightColour(directionalLight));
    m_shader.setUniform3f("meshColour", glm::vec3(1.f, 0.f, 0.f));
    m_shader.setUniform3f("cameraPosition", m_camera.position);
    m_shader.setUniform1f("rimIntensity", rimIntensity);
    m_torusMesh.draw();
    m_shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
