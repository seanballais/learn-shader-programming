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

    buildMesh(m_cloudMesh, 0.5f, 0.3f, glm::vec3(0.f, 0.f, 0.f));
    m_cloudImg.load("ch4/cloud.png");
    m_cloudImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    buildMesh(m_sunMesh, 1.f, 1.f, glm::vec3(0.f, 0.f, 0.4f));
    m_sunImg.load("ch4/sun.png");
    m_sunImg.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_alphaTestShader.load("ch4/passthrough.vert", "ch4/alphaTest.frag");
    m_cloudShader.load("ch4/passthrough.vert", "ch4/cloud.frag");
    m_spritesheetShader.load("ch4/spritesheet.vert", "ch4/alphaTest.frag");

    m_characterPosition = glm::vec3(0.f, 0.f, 0.f);
    m_flipCharacter = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
    float charWalkingSpeed = 0.4f * ofGetLastFrameTime();

    if (m_doWalkLeft) {
        m_characterPosition -= glm::vec3(charWalkingSpeed, 0.f, 0.f);
    } else if (m_doWalkRight) {
        m_characterPosition += glm::vec3(charWalkingSpeed, 0.f, 0.f);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_camera.position = glm::vec3(-1.f, 0.f, 0.f);
    glm::mat4 view = buildViewMatrix(m_camera);

    static float frame = 0.f;
    frame = (frame > 10) ? 0.f : frame += 0.2f;
    glm::vec2 spriteSize = glm::vec2(0.28f, 0.19f);
    glm::vec2 spriteFrame = glm::vec2((int) frame % 3, (int) frame / 3);

    ofDisableBlendMode();
    ofEnableDepthTest();

    m_spritesheetShader.begin();
    m_spritesheetShader.setUniformMatrix4f("view", view);
    m_spritesheetShader.setUniformMatrix4f("model", glm::translate(m_characterPosition));
    m_spritesheetShader.setUniformTexture("tex", m_alienImg, 0);
    m_spritesheetShader.setUniform2f("size", spriteSize);
    m_spritesheetShader.setUniform2f("offset", spriteFrame);
    m_spritesheetShader.setUniform1i("flipCharacter", m_flipCharacter);
    m_charMesh.draw();
    m_spritesheetShader.end();

    m_alphaTestShader.begin();
    m_alphaTestShader.setUniformMatrix4f("view", view);
    m_alphaTestShader.setUniformTexture("tex", m_backgroundImg, 0);
    m_backgroundMesh.draw();
    m_alphaTestShader.end();

    ofDisableDepthTest();
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);

    static float rotation = 1.f;
    rotation += 1.0f * ofGetLastFrameTime();

    // Construct the transform for our unrotated cloud.
    glm::mat4 translationA = glm::translate(glm::vec3(-0.55f, 0.f, 0.f));
    glm::mat4 scaleA = glm::scale(glm::vec3(1.5f, 1.f, 1.f));
    glm::mat4 transformA = translationA * scaleA;

    // Apply rotation.
    glm::mat4 ourRotation = glm::rotate(rotation, glm::vec3(0.f, 0.f, 1.f));
    glm::mat4 newMatrix = translationA * ourRotation * glm::inverse(translationA);
    glm::mat4 finalMatrixA = newMatrix * transformA;

    glm::mat4 transformB = buildMatrix(glm::vec3(0.4f, 0.2f, 0.f), 1.f, glm::vec3(1.f, 1.f, 1.f));

    m_cloudShader.begin();
    m_alphaTestShader.setUniformMatrix4f("view", view);
    m_cloudShader.setUniformTexture("tex", m_cloudImg, 0);

    m_cloudShader.setUniformMatrix4f("transform", finalMatrixA);
    m_cloudMesh.draw();

    m_cloudShader.setUniformMatrix4f("transform", transformB);
    m_cloudMesh.draw();

    m_cloudShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ofKey::OF_KEY_LEFT) {
        m_doWalkLeft = true;
        m_flipCharacter = true;
    } else if (key == ofKey::OF_KEY_RIGHT) {
        m_doWalkRight = true;
        m_flipCharacter = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == ofKey::OF_KEY_LEFT) {
        m_doWalkLeft = false;
    } else if (key == ofKey::OF_KEY_RIGHT) {
        m_doWalkRight = false;
    }
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

glm::mat4 ofApp::buildMatrix(glm::vec3 translation, float rotation, glm::vec3 scale)
{
    glm::mat4 trans = glm::translate(translation);
    glm::mat4 rot = glm::rotate(rotation, glm::vec3(0.f, 0.f, 1.f));
    glm::mat4 scaler = glm::scale(scale);

    return trans * rot * scaler;
}

glm::mat4 ofApp::buildViewMatrix(CameraData camera)
{
    return glm::inverse(buildMatrix(camera.position, camera.rotation, glm::vec3(1.f, 1.f, 1.f)));
}
