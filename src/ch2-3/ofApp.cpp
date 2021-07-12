#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    m_quad.addVertex(glm::vec3(-1.f, -1.f, 0.f));
    m_quad.addVertex(glm::vec3(-1.f,  1.f, 0.f));
    m_quad.addVertex(glm::vec3( 1.f,  1.f, 0.f));
    m_quad.addVertex(glm::vec3( 1.f, -1.f, 0.f));

    m_quad.addTexCoord(glm::vec2(0.f, 0.f));
    m_quad.addTexCoord(glm::vec2(0.f, 1.f));
    m_quad.addTexCoord(glm::vec2(1.f, 1.f));
    m_quad.addTexCoord(glm::vec2(1.f, 0.f));

    ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0 };
    m_quad.addIndices(indices, 6);
    \
    m_shader.load("uv_passthrough.vert", "texture_blend.frag");

    ofDisableArbTex();

    m_parrotImg.load("parrot.png");
    m_parrotImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_checkerboardImg.load("checker.jpg");
    m_checkerboardImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_brightness = 2.f;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_shader.begin();

    m_shader.setUniformTexture("parrotTex", m_parrotImg, 0);
    m_shader.setUniformTexture("checkerboardTex", m_checkerboardImg, 1);
    m_shader.setUniform1f("time", ofGetElapsedTimef());
    m_shader.setUniform1f("brightness", m_brightness);

    m_quad.draw();

    m_shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
