#pragma once

#include "ofMain.h"

struct CameraData
{
    glm::vec3 position;
    float rotation;
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
    glm::mat4 buildMatrix(glm::vec3 translation, float rotation, glm::vec3 scale);
    glm::mat4 buildViewMatrix(CameraData camera);

private:
    CameraData m_camera;

    ofShader m_alphaTestShader;
    ofShader m_cloudShader;
    ofShader m_spritesheetShader;

    ofMesh m_charMesh;
    ofImage m_alienImg;

    ofMesh m_backgroundMesh;
    ofImage m_backgroundImg;

    ofMesh m_cloudMesh;
    ofImage m_cloudImg;

    ofMesh m_sunMesh;
    ofImage m_sunImg;

    bool m_doWalkLeft;
    bool m_doWalkRight;
    bool m_flipCharacter;
    glm::vec3 m_characterPosition;
};
