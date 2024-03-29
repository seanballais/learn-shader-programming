#pragma once

#include "ofMain.h"

struct CameraData
{
    glm::vec3 position;
    float fov;
};

struct DirectionalLight
{
    glm::vec3 direction;
    glm::vec3 colour;
    float intensity;
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

private:
    ofMesh m_torusMesh;
    ofShader m_shader;

    CameraData m_camera;

    glm::vec3 m_ambientColour;
};
