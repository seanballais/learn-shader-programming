#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofDisableArbTex();
    ofEnableDepthTest();

    buildMesh(m_charMesh, 0.1f, 0.2f, glm::vec3(0.f, -0.24f, 0.f));
    m_alienImg.load("ch4/walk_sheet.png");
    m_alienImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_backgroundMesh, 1.f, 1.f, glm::vec3(0.f, 0.f, 0.5f));
    m_backgroundImg.load("ch4/forest.png");
    m_backgroundImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_cloudMesh, 0.5f, 0.3f, glm::vec3(-0.55f, 0.f, 0.f));
    m_cloudImg.load("ch4/cloud.png");
    m_cloudImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_sunMesh, 1.f, 1.f, glm::vec3(0.f, 0.f, 0.4f));
    m_sunImg.load("ch4/sun.png");
    m_sunImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_alphaTestShader.load("ch4/passthrough.vert", "ch4/alphaTest.frag");
    m_cloudShader.load("ch4/passthrough.vert", "ch4/cloud.frag");
    m_spritesheetShader.load("ch4/spritesheet.vert", "ch4/alphaTest.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    static float frame = 0.f;
    frame = (frame > 10) ? 0.f : frame += 0.2f;
    glm::vec2 spriteSize = glm::vec2(0.28f, 0.19f);
    glm::vec2 spriteFrame = glm::vec2((int) frame % 3, (int) frame / 3);

    ofDisableBlendMode();
    ofEnableDepthTest();

    m_spritesheetShader.begin();
    m_spritesheetShader.setUniformTexture("tex", m_alienImg, 0);
    m_spritesheetShader.setUniform2f("size", spriteSize);
    m_spritesheetShader.setUniform2f("offset", spriteFrame);
    m_charMesh.draw();
    m_spritesheetShader.end();

    m_alphaTestShader.begin();
    m_alphaTestShader.setUniformTexture("tex", m_backgroundImg, 0);
    m_backgroundMesh.draw();
    m_alphaTestShader.end();

    ofDisableDepthTest();
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);

    m_cloudShader.begin();

    m_cloudShader.setUniformTexture("tex", m_cloudImg, 0);
    m_cloudMesh.draw();

    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

    m_cloudShader.setUniformTexture("tex", m_sunImg, 0);
    m_sunMesh.draw();

    m_cloudShader.end();
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
