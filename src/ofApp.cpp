#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofEnableDepthTest();

    m_torusMesh.load("ch7/torus.ply");
    m_uvShader.load("ch7/mesh.vert", "ch7/uv_vis.frag");
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_camera.position = glm::vec3(0.f, 0.f, 1.f);
    m_camera.fov = glm::radians(100.f);

    float aspect = 1024.f / 768.f;

    glm::mat4 model = glm::rotate(1.f, glm::vec3(1.f, 1.f, 1.f))
                      * glm::scale(glm::vec3(0.5f, 0.5f, 0.5f));
    glm::mat4 view = glm::inverse(glm::translate(m_camera.position));
    glm::mat4 projection = glm::perspective(m_camera.fov, aspect, 0.01f, 10.f);

    glm::mat4 mvp = projection * view * model;

    m_uvShader.begin();
    m_uvShader.setUniformMatrix4f("mvp", mvp);
    m_torusMesh.draw();
    m_uvShader.end();
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
