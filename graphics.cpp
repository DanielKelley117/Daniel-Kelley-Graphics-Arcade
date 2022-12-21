//
// Created by Daniel Kelley on 11/7/2022.
//
#include <iostream>


#include "graphics.h"
#include "circle.h"
#include "rect.h"
#include "Button.h"
#include "bubble.h"
#include "cube.h"
#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <sstream>
#include <ctime>
#include <ostream>
#include <fstream>
using namespace std;

GLdouble width, height;
int wd;
int x;
//Colors are declared;
const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);


//This screen variable is used to decide what is displayed.
int screen = 0;

//This is used to keep track of points earned in certain games
int points = -100;

//These variables are all used for confetti black jack
Button spawn({1, 0, 0}, {100, 100}, 100, 50, "Spawn");
Button pass({1, 0, 0}, {400, 100}, 100, 50, "Pass");
vector<Quad> confetti;
int confettiLocation = 10;
vector<Circle> compConfetti;
int compConfettiLocation = 20;
string numConfetti;
string numCompConfetti;
int confettiPresses;

Button buttonWin({0, 1, 0}, {100, 100}, 300, 150, "Win");
Button buttonLose({1, 0, 0}, {400, 100}, 300, 150, "Lose");

//This vector is used in Cloud Dodger and Super Architect
vector<unique_ptr<Shape>> clouds;

//These variables are used in Super Architect
Rect grass;
vector<Rect> buildings1;
vector<Rect> buildings2;
vector<Rect> buildings3;

//The following Rects are used in Chaser
Rect userBox;
Rect goalCloud;
Rect chaser;
Rect chaserTwo;
Rect chaserThree;
Rect chaserFour;
Rect chaserFive;
Rect chaserTrack;
Rect chaserGoal;


//The following variables are used in magic Bubbles
vector<Bubble> bubbles;
int magicKey = rand() % 25 + 97;
vector<string> bits;
const int SIDE_LENGTH = 20;
const int RADIUS = 50;

//These variables are used in Cube exercise
vector<Cube> boxes;
int cubeCounter = 0;


void initClouds() {
    // Note: the Rect objects that make up the flat bottom of the clouds
    // won't appear until you implement the Rect::draw method.
    clouds.clear();
    dimensions cloudBottom(30, 30);
     //First cloud
    clouds.push_back(make_unique<Circle>(white, 300, 100, 20));
    clouds.push_back(make_unique<Circle>(white, 330, 100, 20));
    clouds.push_back(make_unique<Circle>(white, 320, 90, 20));
    clouds.push_back(make_unique<Rect>(white, 315, 105, cloudBottom));
    // Second cloud
    clouds.push_back(make_unique<Circle>(white, 100, 80, 20));
    clouds.push_back(make_unique<Circle>(white, 130, 80, 20));
    clouds.push_back(make_unique<Circle>(white, 120, 70, 20));
    clouds.push_back(make_unique<Rect>(white, 115, 85, cloudBottom));
    // Third cloud
    clouds.push_back(make_unique<Circle>(white, 450, 50, 20));
    clouds.push_back(make_unique<Circle>(white, 480, 50, 20));
    clouds.push_back(make_unique<Circle>(white, 470, 40, 20));
    clouds.push_back(make_unique<Rect>(white, 465, 55, cloudBottom));

        // Fourth cloud
        clouds.push_back(make_unique<Circle>(white, 300, 400, 20));
        clouds.push_back(make_unique<Circle>(white, 330, 400, 20));
        clouds.push_back(make_unique<Circle>(white, 320, 390, 20));
        clouds.push_back(make_unique<Rect>(white, 315, 405, cloudBottom));
        // Fifth cloud
        clouds.push_back(make_unique<Circle>(white, 100, 380, 20));
        clouds.push_back(make_unique<Circle>(white, 130, 380, 20));
        clouds.push_back(make_unique<Circle>(white, 120, 370, 20));
        clouds.push_back(make_unique<Rect>(white, 115, 385, cloudBottom));
        // Sixth cloud
        clouds.push_back(make_unique<Circle>(white, 450, 350, 20));
        clouds.push_back(make_unique<Circle>(white, 480, 350, 20));
        clouds.push_back(make_unique<Circle>(white, 470, 340, 20));
        clouds.push_back(make_unique<Rect>(white, 465, 345, cloudBottom));

        // Seventh cloud
        clouds.push_back(make_unique<Circle>(white, 400, 300, 20));
        clouds.push_back(make_unique<Circle>(white, 430, 300, 20));
        clouds.push_back(make_unique<Circle>(white, 420, 290, 20));
        clouds.push_back(make_unique<Rect>(white, 415, 305, cloudBottom));
        // Eighth cloud
        clouds.push_back(make_unique<Circle>(white, 200, 280, 20));
        clouds.push_back(make_unique<Circle>(white, 230, 280, 20));
        clouds.push_back(make_unique<Circle>(white, 220, 270, 20));
        clouds.push_back(make_unique<Rect>(white, 215, 285, cloudBottom));
        // Ninth cloud
        clouds.push_back(make_unique<Circle>(white, 350, 250, 20));
        clouds.push_back(make_unique<Circle>(white, 380, 250, 20));
        clouds.push_back(make_unique<Circle>(white, 370, 240, 20));
        clouds.push_back(make_unique<Rect>(white, 365, 255, cloudBottom));

        // Tenth cloud
        clouds.push_back(make_unique<Circle>(white, 100, 200, 20));
        clouds.push_back(make_unique<Circle>(white, 30, 200, 20));
        clouds.push_back(make_unique<Circle>(white, 20, 190, 20));
        clouds.push_back(make_unique<Rect>(white, 115, 205, cloudBottom));
        // Eleventh cloud
        clouds.push_back(make_unique<Circle>(white, 300, 180, 20));
        clouds.push_back(make_unique<Circle>(white, 330, 180, 20));
        clouds.push_back(make_unique<Circle>(white, 320, 170, 20));
        clouds.push_back(make_unique<Rect>(white, 315, 185, cloudBottom));
        // Final cloud
        clouds.push_back(make_unique<Circle>(white, 450, 450, 20));
        clouds.push_back(make_unique<Circle>(white, 480, 450, 20));
        clouds.push_back(make_unique<Circle>(white, 470, 440, 20));
        clouds.push_back(make_unique<Rect>(white, 465, 455, cloudBottom));


}

void initGrass() {
    grass.setCenter(250, 525);
    grass.setSize(900, height/3);
    grass.setColor(grassGreen);
}

void initBuildings() {
    // First vector is for closest buildings
    int totalBuildingWidth = 0;
    dimensions buildingSize;
    while (totalBuildingWidth < width + 50) {
        // Building height between 50-100
        buildingSize.height = rand() % 51 + 50;
        // Building width between 30-50
        buildingSize.width = rand() % 21 + 30;
        buildings1.push_back(Rect(brickRed,
                                  totalBuildingWidth+(buildingSize.width/2)+5,
                                  height-((buildingSize.height/2)+50),
                                  buildingSize));
        totalBuildingWidth += buildingSize.width + 5;
    }

    // Populate second set of buildings
    totalBuildingWidth = 0;
    while (totalBuildingWidth < width + 100) {
        // Building height between 100-200
        buildingSize.height = rand() % 101 + 100;
        // Building width between 50-100
        buildingSize.width = rand() % 51 + 50;
        buildings2.push_back(Rect(darkBlue, totalBuildingWidth+(buildingSize.width/2)+5, height-((buildingSize.height/2)+50), buildingSize));
        totalBuildingWidth += buildingSize.width + 5; // Placeholder line to avoid infinite loop
    }

    // Populate third set of buildings
    totalBuildingWidth = 0;
    while (totalBuildingWidth < width + 200)  {
        // Building height between 200-400
        buildingSize.height = rand() % 201 + 200;
        // Building width between 100-200
        buildingSize.width = rand() % 101 + 100;
        buildings3.push_back(Rect(purple,
                                  totalBuildingWidth+(buildingSize.width/2)+5,
                                  height-((buildingSize.height/2)+50),
                                  buildingSize));
        totalBuildingWidth += buildingSize.width + 5; // Placeholder line to avoid infinite loop
    }
}

void initUserBox() {
    // centered in the top left e a 20x20 white blockcorner of the graphics window
    userBox = Rect(white, point2D(rand() % (600 - 1), rand() % (600 - 1)), dimensions(20, 20));
}

void initGoalCloud() {
    points += 100;
    goalCloud = Rect(orange, point2D(rand() % (300 + 1), rand() % (300 + 1)), dimensions(70, 50));
}

void initChaser() {
    chaser = Rect(brickRed, point2D(300, 200), dimensions(50, 50));
}

void initChaserTwo() {
    chaserTwo = Rect(grassGreen, point2D(50, 600), dimensions(50, 50));
}

void initChaserThree() {
    chaserThree = Rect(white, point2D(400, -200), dimensions(50, 50));
}

void initChaserFour() {
    chaserFour = Rect(purple, point2D(400, 100), dimensions(50, 50));
}

void initChaserFive() {
    chaserFive = Rect(magenta, point2D(60, 60), dimensions(50, 50));
}

void initChaserTrack() {
    chaserTrack = Rect(darkBlue, point2D(200, 500), dimensions(90, 90));
}

void initChaserGoal() {
    chaserGoal = Rect(orange, point2D(rand() % 500, rand() % 500), dimensions(90, 90));
}



void initBubbles() {

    for (int i = 100; i < width; i += 200) {
        for (int j = 100; j < height; j += 200) {
            bubbles.push_back(
                    Bubble(rand() % 5, rand() % 5, rand() % 5, 0, 1 - (rand() % 20 / 100.0), 1 - (rand() % 20 / 100.0), 1 - (rand() % 20 / 100.0),
                           0, i, j, RADIUS));//(rand() % 10 + 1)*5));

            bubbles[bubbles.size()-1].setVelocity(rand() % 5 - 2, rand() % 5 - 2);
        }
    }

}

void initCubes() {
    int standard = 7;
    int amount = 700 / standard;
    int i = 0;
    double x = 0;
    while (i < amount) {
        boxes.push_back(Cube({x, 0, 0}, 50));
        ++i;
        ++++x;

    }
}

void init() {
    width = 500;
    height = 500;
    srand(time(0));
    initClouds();
    initGrass();
    initBuildings();
    initUserBox();
    initGoalCloud();
    initChaser();
    initChaserTwo();
    initChaserThree();
    initChaserFour();
    initChaserFive();
    initChaserGoal();
    initChaserTrack();
    initBubbles();
    initCubes();
}

void threeDInit() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 3.0, 6.0,  // eye position
              0.0, 0.0, 0.0,  // center position (not gaze direction)
              0.0, 1.0, 0.0); // up vector

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    if (screen != 2) {
        glClearColor(skyBlue.red, skyBlue.green, skyBlue.blue, 1.0f);
    }
    if (screen == 69) {
        glClearColor(black.red, black.green, black.blue, 1.0f);
    }

}

void draw_axes() {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-width/2.0, 0.0, 0.0);
    glVertex3f(width/2.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, height/2.0, 0.0);
    glVertex3f(0.0, -height/2.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, width);
    glVertex3f(0.0, 0.0, -width);
    glEnd();
}

void spawnConfetti() {
    int i = 0;
    int stopQuad = rand() % 5;
    while (i < stopQuad) {
        confetti.push_back(
                Quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, {rand() % 500, rand() % 500}, 10,
                     10));
        ++i;
    }
    stringstream ss;
    ss << confetti.size();
    ss >> numConfetti;

}

void spawnCompConfetti() {
    int i = 0;
    int stopCircle = rand() % 5;
    while (i < stopCircle) {
        double size = rand() % 500;
        double sizeTwo = rand() % 500;
        compConfetti.push_back(Circle({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, size,sizeTwo,
                                      10));
        ++i;
    }
    stringstream ss;
    ss << compConfetti.size();
    ss >> numCompConfetti;

}



/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing

    //This is the start screen for the selection of games.
    if (screen == 0) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        string direction = "Here are the games you can choose from:";
        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }
        string opt1 = "a: cloud dodger";
        glRasterPos2i(150, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt1.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt1[i]);
        }
        glFlush();

        string opt2 = "b: chaser";
        glRasterPos2i(150, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt2.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt2[i]);
        }
        glFlush();

        string opt3 = "c: super architect";
        glRasterPos2i(150, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt3.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt3[i]);
        }
        glFlush();

        string opt4 = "d: confetti black jack";
        glRasterPos2i(150, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt4.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt4[i]);
        }

        string opt5 = "e: magic key";
        glRasterPos2i(150, 330);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt5.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt5[i]);
        }

        string opt6 = "f: cube of progress";
        glRasterPos2i(150, 350);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < opt6.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, opt6[i]);
        }
        glFlush();

    }

    //This is the instructions for Cloud Dodger
    if (screen == 1) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        string direction = "Welcome to cloud dodger! Press s to start";
        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "Begin with your mouse at the bottom of the screen.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "The white box will follow your mouse.";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "Touch the white box to the orange box as many times as you";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        string directionFive = "can withput being hit by the clouds.";
        glRasterPos2i(0, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFive.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFive[i]);
        }
        glFlush();


    }

    //This is Cloud Dodger the game.
    if (screen == 10) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        /*
         * Draw here
         */


        goalCloud.draw();

        for (unique_ptr<Shape> &s: clouds) {
            // #polymorphism
            s->draw();
        }

        userBox.draw();

        // Check if the user is overlapping with the cloud
        // Only check the Rect object within the cloud
        for (int i = 3; i < clouds.size(); i += 4) {
            if ((dynamic_cast<Rect &>(*clouds[i]).isOverlapping(userBox))) {
                screen = 100;
            }
        }
        int counter = 0;
        if (goalCloud.isOverlapping(userBox)) {
            points += 100;
            initGoalCloud();
        }

        glFlush();
    }

    //This is the end screen to Cloud Dodger.
    if (screen == 100) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        stringstream ss;
        string sPoints = "";

        ss << points;
        ss >> sPoints;
        string direction = "You were hit by a cloud! You got ";
        direction += sPoints;
        direction += " points!";
        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }
        glFlush();


    }

    //This is the start screen for Super Architect
    if (screen == 3) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        string direction = "Welcome to super architect! Press s to start";
        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "Begin with your mouse at the top of the screen.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "Move the white box across the buildings with your mouse several times.";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionThreeTimes = " times.";
        glRasterPos2i(0, 280);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThreeTimes.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThreeTimes[i]);
        }

        string directionFour = "Move your mouse over the grass when you're finished.";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        string directionFive = "You will get 500 points.";
        glRasterPos2i(0, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFive.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFive[i]);
        }
        glFlush();

    }

    //This isi the building segment for Super Architect
    if (screen == 30) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        /*
         * Draw here
         */


        // rest of the buildings. Note that the order of drawing
        // matters because whatever is drawn last appears on top.
        // Note that darkBlue buildings turn cyan when overlapping
        // with the user, and purple buildings turn magenta.


        for (unique_ptr<Shape> &s: clouds) {
            // #polymorphism
            s->draw();
        }

        for (Rect &r: buildings3) {
            if (r.isOverlapping(userBox)) {
                r.setColor(magenta);
                int push = rand() % 100;
                if (push <= 50) {
                    bits.push_back("g");
                }
                else {
                    bits.push_back("b");
                }
            } else {
                r.setColor(purple);
            }
            r.draw();

        }

        for (Rect &r: buildings2) {
            if (r.isOverlapping(userBox)) {
                r.setColor(cyan);
                int num = rand() % 100;
                if (num <= 50) {
                    bits.push_back("r");
                }
                else {
                    bits.push_back("y");
                }
            } else {
                r.setColor(darkBlue);
            }
            r.draw();

        }

        for (Rect &r: buildings1) {
            if (r.isOverlapping(userBox)) {
                r.setColor(orange);
                bits.push_back("m");
            } else {
                r.setColor(brickRed);
            }
            r.draw();
        }

        userBox.draw();
        grass.draw();


        //Writing to scene.txt
        ofstream record;
        record.open("../scene.txt");

        if (grass.isOverlapping(userBox) && bits.size() >= 12) {
            int i = 0;
            if (bits.size() >= 12) {
                while (i < bits.size()) {
                    string enter = "";
                    enter += bits[i];
                    enter += bits[i + 1];
                    enter += bits[i + 2];
                    enter += bits[i + 3];
                    enter += bits[i + 4];
                    enter += bits[i + 5];
                    enter += bits[i + 6];
                    enter += bits[i + 7];
                    enter += bits[i + 8];
                    enter += bits[i + 9];
                    enter += bits[i + 10];
                    enter += bits[i + 11];
                    enter += bits[i];
                    enter += bits[i];
                    enter += bits[i + 1];
                    enter += bits[i + 2];
                    enter += bits[i + 3];
                    enter += bits[i + 4];
                    enter += bits[i + 5];
                    enter += bits[i + 6];
                    enter += bits[i + 7];
                    enter += bits[i + 8];
                    enter += bits[i + 9];
                    enter += bits[i + 10];
                    enter += bits[i + 11];
                    record << enter;
                    record << "\n";
                    ++ ++ ++ ++ ++ ++ ++i;
                }
            }
            record.close();
            screen = 300;
        }

        glFlush();  // Render now
    }

    //Bit art screen for Super Architect
    if (screen == 300) {
        // Tell OpenGL to use the whole window for drawing
        glViewport(0, 0, width, height);

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        /*
         * Draw here
         */
        ifstream inFile("../scene.txt");
        inFile >> noskipws;
        int xCoord = 0, yCoord = 0;
        char letter;
        bool draw;
        while (inFile >> letter) {
            draw = true;
            switch(letter) {
                case 'r': glColor3f(1, 0, 0); break;
                case 'g': glColor3f(0, 1, 0); break;
                case 'b': glColor3f(0, 0, 1); break;
                case 'y': glColor3f(1, 1, 0); break;
                case 'm': glColor3f(1, 0, 1); break;
                case 'c': glColor3f(0, 1, 1); break;
                case ' ': glColor3f(0, 0, 0); break;
                default: // newline
                    draw = false;
                    xCoord = 0;
                    yCoord += SIDE_LENGTH;
            }
            if (draw) {
                glBegin(GL_QUADS);
                glVertex2i(xCoord, yCoord);
                glVertex2i(xCoord+SIDE_LENGTH, yCoord);
                glVertex2i(xCoord+SIDE_LENGTH, yCoord+SIDE_LENGTH);
                glVertex2i(xCoord, yCoord+SIDE_LENGTH);
                glEnd();
                xCoord += SIDE_LENGTH;
            }
        }
        inFile.close();

        glFlush();  // Render now

    }

    //Start screen for Chaser
    if (screen == 2) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string direction = "Welcome to Chaser! Press s to start";
        chaserTrack.draw();
        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "Begin with your mouse inside the blue square.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "Keep the white box inside the blue square with your mouse.";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "Move the blue square with the arrow keys.";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        string directionFive = "Touch the white box to the orange one as many times as you can.";
        glRasterPos2i(0, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFive.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFive[i]);
        }

        string directionSix = "Don't get hit by the moving squares.";
        glRasterPos2i(0, 330);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionSix.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionSix[i]);
        }

        glFlush();
    }

    //Chaser game screen
    if (screen == 20) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        chaserTrack.draw();
        userBox.draw();
        chaser.draw();
        chaserTwo.draw();
        chaserThree.draw();
        chaserFour.draw();
        chaserFive.draw();
        chaserGoal.draw();


        if (chaser.isOverlapping(userBox) || chaserTwo.isOverlapping(userBox) || chaserThree.isOverlapping(userBox) || chaserFour.isOverlapping(userBox) || chaserFive.isOverlapping(userBox)) {
            screen = 200;
        }

        if (!chaserTrack.isOverlapping(userBox)) {
            screen = 2000;
        }

        if (chaserGoal.isOverlapping(userBox)) {
            initChaserGoal();
            points += 500;
        }

        glFlush();
    }

    //Chaser screen for getting caught by one of the squares.
    if (screen == 200) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string sPoints = "";
        stringstream ss;
        ss << points;
        ss >> sPoints;
        string direction = "You were caught by one of the squares! You get ";
        direction += sPoints;
        direction += " points!";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        glFlush();
    }

    //Chaser screen for mouse falling off track.
    if (screen == 2000) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string sPoints = "";
        stringstream ss;
        ss << points;
        ss >> sPoints;
        string direction = "The mouse fell off of the track! You get ";
        direction += sPoints;
        direction += " points!";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        glFlush();

    }

    //Start screen for Black Jack
    if (screen == 4) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string direction = "Welcome to Black Jack! Press s to start!";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "You spawn square confetti, and the computer spawn circles.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "The winner must spawn closer to 21 confetti without going over.";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "The winner must spawn closer to 21 confetti without going over.";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        string directionFive = "Spawn spawns between 1 and 5 of both confetti.";
        glRasterPos2i(0, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFive.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFive[i]);
        }

        string directionSix = "Pass spawns between 1 and 5 of 1 of the confettis.";
        glRasterPos2i(0, 330);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionSix.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionSix[i]);
        }

        string directionSeven = "You get 10 presses.";
        glRasterPos2i(0, 350);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionSeven.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionSeven[i]);
        }

        glFlush();

    }

    //Black Jack game screen.
    if (screen == 40) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /*
         * Draw here
         */


        spawn.draw();
        pass.draw();

        glRasterPos2i(150, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        string direction = "You currently have ";
        direction += numConfetti;
        direction += " confetti.";
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "The computer currently has ";
        directionTwo += numCompConfetti;
        directionTwo += " confetti.";
        glRasterPos2i(150, 430);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        for (const Quad &piece: confetti) {
            piece.draw();
        }

        for (const Circle &piece: compConfetti) {
            piece.draw();
        }

        glFlush(); // Render now

        if ((confetti.size() > 21 && compConfetti.size() < 21) || (21 - confetti.size() > 21 - compConfetti.size() && confettiPresses > 10)) {
            screen = 4000;
        }

        if ((confetti.size() < 21 && compConfetti.size() > 21) || (21 - confetti.size() < 21 - compConfetti.size() && confettiPresses > 10)) {
            screen = 400;
        }


    }

    //Confetti user win screen.
    if (screen == 400) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        string direction = "You currently have ";
        stringstream ss;
        ss << confetti.size();
        ss >> numConfetti;
        direction += numConfetti;
        direction += " confetti.";
        glRasterPos2i(50, 130);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "The computer currently has ";
        ss << compConfetti.size();
        ss >> numCompConfetti;
        directionTwo += numCompConfetti;
        directionTwo += " confetti.";
        glRasterPos2i(150, 430);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }


        string directionThree = "You got closer to 21 without going over! You get 500 points!";
        points += 500;
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        glFlush();

    }

    //Confetti computer win screen
    if (screen == 4000) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        string direction = "You currently have ";
        stringstream ss;
        ss << confetti.size();
        ss >> numConfetti;
        direction += numConfetti;
        direction += " confetti.";
        glRasterPos2i(50, 130);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "The computer currently has ";
        ss << compConfetti.size();
        ss >> numCompConfetti;
        directionTwo += numCompConfetti;
        directionTwo += " confetti.";
        glRasterPos2i(150, 430);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }


        string directionThree = "The computer got closer to 21 without going over!";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "Ypu get 100 points!";
        points += 100;
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        glFlush();
    }

    //Magic Key start screen
    if (screen == 5) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string direction = "Welcome to Magic Key! Press s to start!";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "You will need to spawn 100 bubbles.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "Bubbles are spawned by pressing a random lower case alphabet ";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "key. The key changes every time it is pressed.";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        glFlush();

    }

    //Magic key game screen
    if (screen == 50) {
        // Tell OpenGL to use the whole window for drawing
        glViewport(0, 0, width, height);

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        /*
         * Draw here
         */
        for (const Bubble &bubble : bubbles) {
            bubble.draw();
        }

        if (bubbles.size() > 100) {
            screen = 500;
        }

        glFlush();  // Render now

    }

    //Magic Key end screen
    if (screen == 500) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string direction = "You reached 100 bubbles! You get 500 points!";
        points += 500;
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        glFlush();

    }

    //Cube Exercise start screen.
    if (screen == 6) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

        string direction = "Welcome to Cube Exercise! Press s to start";
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        string directionTwo = "Exercise the square by moving it with the arrow keys.";
        glRasterPos2i(0, 250);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionTwo.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionTwo[i]);
        }

        string directionThree = "You can also rotate it with the x and y keys.";
        glRasterPos2i(0, 270);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionThree.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionThree[i]);
        }

        string directionFour = "When the square is exercised enough, it will become a 3d cube.";
        glRasterPos2i(0, 290);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFour.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFour[i]);
        }

        string directionFive = "You will then get 500 points.";
        glRasterPos2i(0, 310);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionFive.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionFive[i]);
        }

        string directionSix = "You can also move it with . and , and rotate with z.";
        glRasterPos2i(0, 330);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < directionSix.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, directionSix[i]);
        }


        glFlush();
    }

    //Cube Exercise game screen
    if (screen == 60) {
        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-width/2, width/2, -height/2, height/2, -width, width);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glEnable(GL_DEPTH);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT, GL_FILL);

        //threeDInit();
        draw_axes();
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].draw();
            ++i;
        }
        if (cubeCounter > 500) {
            screen = 600;
        }
        glFlush();

    }

    //Cube size end screen.
    if (screen == 600) {
        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-width/2, width/2, -height/2, height/2, -width, width);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glEnable(GL_DEPTH);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT, GL_FILL);

        threeDInit();
        draw_axes();
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].draw();
            ++i;
        }
        if (cubeCounter > 10) {
            screen = 600;
        }
        glFlush();
    }

    if (screen == 69) {
        glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you are running Catalina on Mac)

        // Do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
        glLoadIdentity(); // DO NOT CHANGE THIS LINE
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

        // Clear the color buffer with current clearing color
        glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
        string direction = "Welcome to Button Presser! Press s to start";
        points += 500;
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }

        glFlush();

    }

    if (screen == 690) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /*
         * Draw here
         */


        buttonWin.draw();
        buttonLose.draw();



        glFlush(); // Render now

    }

    if (screen == 6900) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /*
         * Draw here
         */

        string direction = "You win!";
        points += 500;
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }




        glFlush(); // Render now
    }

    if (screen == 69000) {
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /*
         * Draw here
         */

        string direction = "You lose!!";
        points += 500;
        glRasterPos2i(0, 230);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < direction.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, direction[i]);
        }




        glFlush(); // Render now
    }

}


// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
//Detects keyboard input and performs appropriate actions based on current screen and current key pressed.
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (screen == 1 && (key == 115 || key == 83)) {
        screen = 10;
    }

    if (screen == 2 && (key == 115 || key == 83)) {
        screen = 20;
    }

    if (screen == 3 && (key == 115 || key == 83)) {
        screen = 30;
    }

    if (screen == 4 && (key == 115 || key == 83)) {
        screen = 40;
    }

    if (screen == 5 && (key == 115 || key == 83)) {
        screen = 50;
    }

    if (screen == 50 && key == magicKey) {
        for (int i = 100; i < width; i += 200) {
            for (int j = 100; j < height; j += 200) {
                bubbles.push_back(
                        Bubble(rand() % 5, rand() % 5, rand() % 5, 0, 1 - (rand() % 20 / 100.0), 1 - (rand() % 20 / 100.0), 1 - (rand() % 20 / 100.0),
                               0, i, j, RADIUS));//(rand() % 10 + 1)*5));
                bubbles[bubbles.size()-1].setVelocity(rand() % 100 - 2, rand() % 100 - 2);
            }
        }
        magicKey = rand() % 25 + 97;
    }

    if (screen == 0 && (key == 97 || key == 65)) {
        screen = 1;
    }

    if (screen == 0 && (key == 98 || key == 66)) {
        screen = 2;
    }

    if (screen == 0 && (key == 99 || key == 67)) {
        screen = 3;
    }

    if (screen == 0 && (key == 100 || key == 68)) {
        screen = 4;
    }

    if (screen == 0 && (key == 101 || key == 69)) {
        screen = 5;
    }

    if (screen == 0 && (key == 102 || key == 70)) {
        screen = 6;
    }

    if (screen == 60 && key == 'x') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(PI / 100.0, 0, 0);
            ++i;
        }
        int branch = rand() % 100;
        if (branch < 50) {
            cubeCounter += 1;
        }
        bits.push_back("y");
    }

    if (screen == 6 && key == 's') {

        //initCubes();
        screen = 60;
    }

    if (screen == 60 && key == 'y') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(0, PI / 100.0, 0);
            ++i;
        }
        int branch = rand() % 100;
        if (branch < 50) {
            cubeCounter += 1;
        }
        bits.push_back("b");
    }

    if (screen == 60 && key == 'z') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(0, 0, PI / 100.0);
            ++i;
        }
        int branch = rand() % 100;
        if (branch < 50) {
            cubeCounter += 1;
        }
        bits.push_back(("g"));
    }

    if (screen == 60 && key == '.') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].move(0, 0, -5);
            ++i;
        }
        int branch = rand() % 100;
        if (branch < 50) {
            cubeCounter += 1;
        }
        bits.push_back("r");
    }

    if (screen == 60 && key == ',') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].move(0, 0, 5);
            ++i;
        }
        int branch = rand() % 100;
        if (branch < 50) {
            cubeCounter += 1;
        }
        bits.push_back("r");
    }

    if (screen == 600 && key == 'x') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(PI / 100.0, 0, 0);
            ++i;
        }
    }

    if (screen == 600 && key == 'y') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(0, PI / 100.0, 0);
            ++i;
        }
    }

    if (screen == 600 && key == 'z') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].rotate(0, 0, PI / 100.0);
            ++i;
        }
    }

    if (screen == 600 && key == '.') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].move(0, 0, -5);
            ++i;
        }
    }

    if (screen == 600 && key == ',') {
        int i = 0;
        while (i < boxes.size()) {
            boxes[i].move(0, 0, 5);
            ++i;
        }
    }

    if (screen == 60 && key == 'r') {

        screen = 600;

    }

    if (screen == 69 && key == 's') {
        screen = 690;
    }


    glutPostRedisplay();
}

void kbdUp(unsigned char key, int x, int y) {

    glutPostRedisplay();
}

//Detects  the arrow keys being pressed and performs appropriate actions based on what screen is being shown.
void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            if (screen == 20) {
                chaserTrack.move(0, 5);
            }



            if (screen == 60) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(0, -5, 0);
                    ++i;
                }
                int branch = rand() % 100;
                if (branch < 50) {
                    cubeCounter += 1;
                }
                bits.push_back("m");
            }

            if (screen == 600) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(0, -5, 0);
                    ++i;
                }
            }

            break;
        case GLUT_KEY_LEFT:

            if (screen == 20) {
                chaserTrack.move(-5, 0);
            }

            if (screen == 60) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(-5, 0, 0);
                    ++i;
                }
                int branch = rand() % 100;
                if (branch < 50) {
                    cubeCounter += 1;
                }
                bits.push_back("c");
            }

            if (screen == 600) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(-5, 0, 0);
                    ++i;
                }
            }

            break;
        case GLUT_KEY_RIGHT:

            if (screen == 20) {
                chaserTrack.move(5, 0);
            }

            if (screen == 60) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(5, 0, 0);
                    ++i;
                }
                int branch = rand() % 100;
                if (branch < 50) {
                    cubeCounter += 1;
                }
                bits.push_back("y");
            }

            if (screen == 600) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(5, 0, 0);
                    ++i;
                }
            }

            break;
        case GLUT_KEY_UP:

            if (screen == 20) {
                chaserTrack.move(0, -5);
            }


            if (screen == 60) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(0, 5, 0);
                    ++i;
                }
                int branch = rand() % 100;
                if (branch < 50) {
                    cubeCounter += 1;
                }
                bits.push_back("r");
            }
            if (screen == 600) {
                int i = 0;
                while (i < boxes.size()) {
                    boxes[i].move(0, 5, 0);
                    ++i;
                }
            }

            break;
    }

    glutPostRedisplay();
}

//Detects mouse hovering over buttons in Black Jack and performs appropriate actions.
void cursor(int x, int y) {
    // TODO: Set the user's center point to be the coordinates
    // passed in as parameters to this function. This will make
    // the user block move with the mouse.
    if (spawn.isOverlapping(x, y)) {
        spawn.hover();
    }
    else {
        spawn.release();
    }

    if (pass.isOverlapping(x, y)) {
        pass.hover();
    }
    else {
        pass.release();
    }

    userBox.setCenter(x, y);
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
// Detects if the mouse is pressing the spawn or release button, and performs the appropriate actions.
void mouse(int button, int state, int x, int y) {

    // TODO: If the left button is down and the cursor is overlapping with the Button, call the pressDown method. Otherwise, call the release method.
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && spawn.isOverlapping(x, y)) {
        spawn.pressDown();
    }
    else {
        spawn.release();
    }

    // TODO: If the left button is up and the cursor is overlapping with the Button, call spawnConfetti.
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && spawn.isOverlapping(x, y))
    {
        spawnConfetti();
        spawnCompConfetti();
        confettiPresses += 1;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && pass.isOverlapping(x, y)) {
        pass.pressDown();
    }
    else {
        pass.release();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && pass.isOverlapping(x, y)) {
        int decision = rand() % 100;
        if (decision <= 50) {
            spawnCompConfetti();
        }
        else {
            spawnConfetti();
        }
        confettiPresses += 1;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && buttonWin.isOverlapping(x, y)) {
        screen = 6900;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && buttonLose.isOverlapping(x, y)) {
        screen = 69000;
    }

    glutPostRedisplay();
}

//Timer function for the clouds used in Cloud Dodger and Super Architect.
void cloudTimer(int dummy) {

    for (unique_ptr<Shape> &s : clouds) {
        // Move all the clouds to the left
        s->moveX(-30);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(50, cloudTimer, dummy);
}

//Timer for all of the objects cubes that eliminate the user in Chaser.
void chaserTimer(int dummy) {




    chaser.moveX(-2);
    if (chaser.getCenterX() < -20) {
        chaser.setCenterX(300);
    }
    chaserTwo.moveY(-2);
    if (chaserTwo.getCenterY() < -20) {
        chaserTwo.setCenterY(900);
    }
    chaserThree.moveY(2);
    if (chaserThree.getCenterY() > 900) {
        chaserThree.setCenterY(0);
    }

    chaserFour.moveX(-2);
    if (chaserFour.getCenterX() < -20) {
        chaserFour.setCenterX(300);
    }
    chaserFive.moveY(2);
    if (chaserFive.getCenterY() > 900) {
        chaserFive.setCenterY(0);
    }
    glutTimerFunc(30, chaserTimer, dummy);


}

//Timer for the buildings used in Super Architect.
void buildingTimer(int dummy) {
    // TODO: Make the other two vectors of buildings move.
    // The larger the buildings, the slower they should move.

    for (int i = 0; i < buildings1.size(); ++i) {
        // Move all the red buildings to the left
        buildings1[i].moveX(-3);
        // If a shape has moved off the screen
        if (buildings1[i].getCenterX() < -(buildings1[i].getWidth()/2)) {
            // Set it to the right of the screen so that it passes through again
            int buildingOnLeft = (i == 0) ? buildings1.size()-1 : i - 1;
            buildings1[i].setCenterX(buildings1[buildingOnLeft].getCenterX() + buildings1[buildingOnLeft].getWidth()/2 + buildings1[i].getWidth()/2 + 5);
        }
    }

    for (int i = 0; i < buildings2.size(); ++i) {
        // Move all the red buildings to the left
        buildings2[i].moveX(-2);
        // If a shape has moved off the screen
        if (buildings2[i].getCenterX() < -(buildings2[i].getWidth()/2)) {
            // Set it to the right of the screen so that it passes through again
            int buildingOnLeft = (i == 0) ? buildings2.size()-1 : i - 1;
            buildings2[i].setCenterX(buildings2[buildingOnLeft].getCenterX() + buildings2[buildingOnLeft].getWidth()/2 + buildings2[i].getWidth()/2 + 5);
        }
    }

    for (int i = 0; i < buildings3.size(); ++i) {
        // Move all the red buildings to the left
        buildings3[i].moveX(-1);
        // If a shape has moved off the screen
        if (buildings3[i].getCenterX() < -(buildings3[i].getWidth()/2)) {
            // Set it to the right of the screen so that it passes through again
            int buildingOnLeft = (i == 0) ? buildings3.size()-1 : i - 1;
            buildings3[i].setCenterX(buildings3[buildingOnLeft].getCenterX() + buildings3[buildingOnLeft].getWidth()/2 + buildings3[i].getWidth()/2 + 5);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, buildingTimer, dummy);
}

//Timer for the bubbles in Magic Key
void bubbleTimer(int dummy) {

    for (Bubble &bubble : bubbles) {
        bubble.move(bubble.getXVelocity(), bubble.getYVelocity());
        if (bubble.getCenterX() < bubble.getRadius()) {
            bubble.bounceX();
            bubble.setCenterX(bubble.getRadius());
        } else if (bubble.getCenterX() > (width-bubble.getRadius())) {
            bubble.bounceX();
            bubble.setCenterX(width-bubble.getRadius());
        }
        if (bubble.getCenterY() < bubble.getRadius()) {
            bubble.bounceY();
            bubble.setCenterY(bubble.getRadius());
        } else if (bubble.getCenterY() > (height-bubble.getRadius())) {
            bubble.bounceY();
            bubble.setCenterY(height-bubble.getRadius());
        }
    }

    for (int i = 0; i < bubbles.size() - 1; ++i) {
        for (int j = i + 1; j < bubbles.size(); ++j) {
            if (bubbles[i].isOverlapping(bubbles[j])) {
                bubbles[i].collide(bubbles[j]);
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, bubbleTimer, dummy);
}


/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv) {
    /*
    cout << "How many points do you currently have?" << endl;

    points = get_int_from_user();
     */

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Graphics Corner" /* title  */);

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);


    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, cloudTimer, 0);
    glutTimerFunc(0, buildingTimer, 0);
    glutTimerFunc(0, chaserTimer, 0);
    glutTimerFunc(0, bubbleTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}



