#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofEnableDepthTest();

    buildMesh(m_charMesh, 0.1f, 0.2f, glm::vec3(0.f, -0.24f, 0.f));
    m_alienImg.load("ch4/alien.png");
    m_alienImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_backgroundMesh, 1.f, 1.f, glm::vec3(0.f, 0.f, 0.5f));
    m_backgroundImg.load("ch4/forest.png");
    m_backgroundImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_cloudMesh, 0.5f, 0.3f, glm::vec3(-0.55f, 0.f, 0.f));
    m_cloudImg.load("ch4/cloud.png");
    m_cloudImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_shader.load("ch4/passthrough.vert", "ch4/alphaTest.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_shader.begin();

    m_shader.setUniformTexture("tex", m_backgroundImg, 0);
    m_backgroundMesh.draw();

    m_shader.setUniformTexture("tex", m_alienImg, 0);
    m_charMesh.draw();

    m_shader.setUniformTexture("tex", m_cloudImg, 0);
    m_cloudMesh.draw();

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

void ofApp::buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos)
{
    float verts[] = {
        -w + pos.x, -h + pos.y, pos.z,
        -w + pos.x,  h + pos.y, pos.z,
         w + pos.x,  h + pos.y, pos.z,
         w + pos.x, -h + pos.y, pos.z
    };
    float uvs[] = { 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f };

    for (int i = 0; i < 4; i++) {
        int vertIdx = i * 3;
        int uvIdx = i * 2;

        mesh.addVertex(glm::vec3(verts[vertIdx], verts[vertIdx + 1], verts[vertIdx + 2]));
        mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
    }

    ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0 };
    mesh.addIndices(indices, 6);
}
