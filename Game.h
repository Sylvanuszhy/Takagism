//
//  Game.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef Takagism_Game_h
#define Takagism_Game_h

#include "Camera.h"
#include "Chamber.h"
#include "Video.h"
#include "Item.h"
#include "Object.h"
#include <iostream>

class Game {
private:
    Item collection[5];     //items to collect
    Object itemPos[5];
    bool toPut;             //item to put
    void initMap();
    void move();
    void turn();
    void drawXXX();
    float x, y;
    const float z;
    float direct;           // from 0 to 2 pi
    float perspAngle;
    float moveSpeed;
    float turnSpeed;
    bool smoothMove;
    bool smoothTurn;

    void initItems();
    void initWhiteRabbit();
    void initBlackRabbit();
    void initCrystal();
    void initBook();
    void initVase();

    int fitItem;
    float distance(float position[]);
    void updateMoveSpeed();
    void updateTurnSpeed();
    void updateZoomToFit(Object&);
    enum { FORWARD, BACKWARD, STOP_FORWARD, STOP_BACKWARD, STILL } moving;
    enum { LEFT, RIGHT, STOP_LEFT, STOP_RIGHT, NO_TURNING } turning;
    enum { OPERATING, RESTORING, ZOOM_TO_FIT, NO_ZOOM_TO_FIT } zooming;
public:
    Game() : z(1.6f) {}
    int map[41][51];
    Camera camera;
    Chamber chamber;
    float getPerspAngle() { return perspAngle; }
    void init();
    void printPos() {
        std::cout << "x = " << x << "; y = " << y << std::endl
                  << "eye = " << camera.eye[0] << ", " << camera.eye[1] << ", " << camera.eye[2] << std::endl
                  << "center = " << camera.center[0] << ", " << camera.center[1] << ", " << camera.center[2] << std::endl; }
    void drawScene();
    void setLight();
    void screenCut(int width, int height);
    void stopMove();
    void stopTurn();
    void moveForward();
    void turnLeft();
    void turnRight();
    void moveBackward();
    void zoomIn();
    void zoomOut();
    void zoomToFit();
    void pickup();
    void put();
};

#endif
