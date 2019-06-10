//
//  main.cpp
//  Assigment_1_Computer_Graphic
//
//  Created by Julia on 29/11/2018.
//  Copyright © 2018 Julia. All rights reserved.
//
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#define FIREWORKSIZE 500

int frame = 0;

GLfloat head [20][2] = {
{-260.000000,100.000000},{-264.404656,127.810736},{-277.187490,152.899323},{-297.097303,172.810059},{-322.185298,185.594056},{-349.995831,190.000000},{-377.806771,185.596632},{-402.895950,172.814960},{-422.807608,152.906070},{-435.592767,127.818667},{-440.000000,100.008339},{-435.597921,72.197194},{-422.817411,47.107423},{-402.909442,27.194843}  ,{-377.822632,14.408522},{-350.012508,10.000001},{-322.201160,14.400792},{-297.110797,27.180139},{-277.197294,47.087185},{-264.409811,72.173403}
};

GLfloat eyeLeftMen [20][2] = {
{-290.489406,93.090082},{-291.909721,95.877703},{-294.121923,98.090007},{-296.909478,99.510451},{-299.999537,100.000000},{-303.089641,99.510737},{-305.877328,98.090551},{-308.089734,95.878452},{-309.510307,93.090963},{-310.000000,90.000927},{-309.510880,86.910799},{-308.090823,84.123047},{-305.878827,81.910538},{-303.091404,80.489836},{-300.001390,80.000000},{-296.911240,80.488977},{-294.123422,81.908904},{-291.910810,84.120798},{-290.489979,86.908156},{-290.489406,93.090082}
};

GLfloat eyeRightMen [20][2] = {
{-325.489406,93.090082},{-326.909721,95.877703},{-329.121923,98.090007},{-331.909478,99.510451},{-334.999537,100.000000},{-338.089641,99.510737},{-340.877328,98.090551},{-343.089734,95.878452},{-344.510307,93.090963},{-345.000000,90.000927},{-344.510880,86.910799},{-343.090823,84.123047},{-340.878827,81.910538},{-338.091404,80.489836},{-335.001390,80.000000},{-331.911240,80.488977},{-329.123422,81.908904},{-326.910810,84.120798},{ -325.489979,86.908156},{-325.489406,93.090082}
};

GLfloat handArray [20][2] = {
{-305.244703,-188.454959},{-305.954861,-187.061149},{-307.060961,-185.954997},{-308.454739,-185.244775},{-309.999768,-185.000000},{-311.544821,-185.244632},{-312.938664,-185.954724},{-314.044867,-187.060774},{-314.755154,-188.454518},{-315.000000,-189.999537},{-314.755440,-191.544600},{-314.045412,-192.938476},{-312.939413,-194.044731},{-311.545702,-194.755082},{-310.000695,-195.000000},{-308.455620,-194.755512},{-307.061711,-194.045548},{-305.955405,-192.939601},{-305.244989,-191.545922},{-305.244703,-188.454959}
};

float heartArray [25][2] ={
    {-230.489979,-224.908156},{-230.489406,-217.090082},{-231.909721,-215.877703},{-234.121923,-212.090007},{-236.909478,-211.510451},{-239.999537,-210.000000},{-243.089641,-211.510737},{-245.877328,-212.090551},{-248.089734,-215.878452},{-249.510307,-217.090963},{-250.000000,-220.000927},{-250.489406,-220.090082},{-251.909721,-215.877703},{-254.121923,-212.090007},{-256.909478,-211.510451},{-259.999537,-210.000000},{-263.089641,-211.510737},{-265.877328,-212.090551},{-268.089734,-215.878452},{-269.510307,-217.090963},{-270.000000,-220.000927},{-279.510880,-224.910799},{-277.0, -224.0},{-248.0, -250.0},{-230.0, -224.0}
};

float shopArray [11] = {500.0, 450.0, 400.0, 350.0, 300.0, 250.0, 200.0, 150.0, 100.0, 50.0, 0.0};

float neutralMouthArray [10][2] = {
    {-385.0, 45.0},{-340.0, 45.0},{-385.0, 45.0},{-340.0, 45.0},{-385.0, 45.0},{-340.0, 45.0},{-385.0, 45.0},{-340.0, 45.0},{-385.0, 45.0},{-340.0, 45.0}
};

float happyMouthArray [10][2] = {
    {-385.4,58.4},{-381.2,51.2},{-374.0,44.0},{-362.0,38.6},{-351.8,37.4},{-343.4,39.2},{-338.0,43.4},{-333.8,50.0},{-330.8,55.4},{-385.4,58.4}
};

void init(void)
{
    glClearColor(0.6, 1.0, 0.9, 0.0); //set the background colour to blue

    /* initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450.0,450.0,-600.0,600.0);
}

//void init3D()
//{
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    ///3d these parameters are left, right bottom, top, Znear clipping  distance , zfar clipping distance
//    glOrtho(-450.0, winWidth, 450.0, winHeight, -600.0, 600.0);
//    glMatrixMode(GL_MODELVIEW);
//}

//Writing text on screen
void renderSpacedBitmapString(float x, float y, void *font, char *string) {
    char *c;
    int x1=x;
    for (c=string; *c != '\0'; c++) {
        glRasterPos2f(x1,y);
        glutBitmapCharacter(font, *c);
        x1 = x1 + glutBitmapWidth(font,*c);
    }
}

void drawGround()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.7, 0.2);   //set colour to green
    glVertex2d(-450.0, -450.0); // Start point of grass
    glVertex2d(450.0, -450.0);  // Second point of grass
    glVertex2d(450.0, -650.0);  // Third point of grass
    glVertex2d(-450.0, -650.0); // Last point of grass
    glEnd(); // end of line drawing
}

void trunk() //base of the tree
{
    glColor3f(0.5, 0.3, 0.0); //set colour to brown
    
    glBegin(GL_POLYGON);
    glVertex2d(175, -320);
    glVertex2d(225, -320);
    glVertex2d(225, -450);
    glVertex2d(175, -450);
    glEnd(); // end of line drawing
}

float tx = 0, ty = 0.0;
float inc = 2.0;
void treeTransformations()
{
    glTranslatef(-15.0, -5.0, 0.0);
    // move the tree to the left side of the screen
    glTranslatef(tx ,ty, 0.0);
    tx -= inc; ty = inc;
}

void drawTree(){

    glPushMatrix();
    treeTransformations();
    double pushDownBy = 0;

    for (int i = 0; i < 8; i++) {
        pushDownBy -= 65;

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.6, 0.3);
        glVertex2d(200.0, 400.0 + pushDownBy); //first point of triangle
        glVertex2d(100.0, 200.0 + pushDownBy); //next point of triangle
        glVertex2d(300.0, 200.0 + pushDownBy); //third point of triangle
        glEnd(); // end of line drawing
    }
    trunk();
    glPopMatrix();
}

void drawShop()
{
    glBegin(GL_POLYGON);
    glColor3f(0.9, 1.0, 0.9);  //set colour to light green
    glVertex2d(-50.0, -460.0); //1 point of shop
    glVertex2d(-50.0, 300.0);  //2 point of shop
    glVertex2d(350.0, 300.0);  //3 point of shop
    glVertex2d(350.0, -460.0); //4 point of shop
    glEnd(); // end of line drawing

    //draw edges around the shop
    glColor3f(0.0, 0.0, 0.0);  //set colour to black
    glLineWidth(1);
    
    glBegin(GL_LINES);
    glVertex2d(-50.0, 300.0);  //1
    glVertex2d(350.0, 300.0);  //2
    glVertex2d(350.0, 300.0);  //2
    glVertex2d(350.0, -460.0); //3
    glVertex2d(350.0, -460.0); //3
    glVertex2d(-50.0, -460.0); //4
    glVertex2d(-50.0, -460.0); //4
    glVertex2d(-50.0, 300.0);  //1
    glEnd(); // end of line drawin

    //draw the roof for shop
    double pushRightBy = 0;
    for (int i = 0; i < 8; i++) {
        pushRightBy += 40;

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);  //set colour to red
    glVertex2d(-50.0 + pushRightBy, 300.0);  //1
    glVertex2d(-30.0 + pushRightBy, 300.0);  //2
    glVertex2d(-30.0 + pushRightBy, 100.0);  //3
    glVertex2d(-50.0 + pushRightBy, 100.0);  //4
    glEnd(); // end of line drawin

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);  //set colour to white
    glVertex2d(-30.0 + pushRightBy, 300.0);  //1
    glVertex2d(-10.0 + pushRightBy, 300.0);  //2
    glVertex2d(-10.0 + pushRightBy, 100.0);  //1
    glVertex2d(-30.0 + pushRightBy, 100.0);  //2
    glEnd(); // end of line drawin

    } //end of loop

}

void drawDoorForShop()
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);   //set colour to black
    glVertex2d(170.0, -455.0);  //1
    glVertex2d(170.0, -200.0);  //2
    glVertex2d(170.0, -200.0);  //2
    glVertex2d(300.0, -200.0);  //3
    glVertex2d(300.0, -200.0);  //3
    glVertex2d(300.0, -455.0);  //4
    glEnd(); // end of line drawin

    //draw small window1
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 0.5);   //set colour to gray
    glVertex2d(190.0, -430.0);  //1 point of window1
    glVertex2d(190.0, -350.0);  //2 point of window1
    glVertex2d(280.0, -350.0);  //3 point of window1
    glVertex2d(280.0, -430.0);  //4 point of window1
    glVertex2d(190.0, -430.0);  //5 point of window1
    glEnd(); // end of line drawin

    //draw small window2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 0.5);   //set colour to gray
    glVertex2d(190.0, -340.0);  //1 point of window1
    glVertex2d(190.0, -240.0);  //2 point of window1
    glVertex2d(280.0, -240.0);  //3 point of window1
    glVertex2d(280.0, -340.0);  //4 point of window1
    glVertex2d(190.0, -340.0);  //5 point of window1
    glEnd(); // end of line drawin

    //draw handle for door
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);   //set colour to black
    glVertex2d(165.0, -350.0);  //1 point of window2
    glVertex2d(165.0, -330.0);  //2 point of window2
    glVertex2d(175.0, -330.0);  //3 point of window2
    glVertex2d(175.0, -350.0);  //4 point of window2
    glVertex2d(165.0, -350.0);  //5 point of window2
    glEnd(); // end of line drawin

}

void drawWindowForShop()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 0.5);  //set colour to gray
    glVertex2d(130.0, -400.0); //1 point of window3
    glVertex2d(130.0, 10.0);   //2 point of window3
    glVertex2d(0.0, 10.0);     //3 point of window3
    glVertex2d(0.0, -400.0);   //4 point of window3
    glEnd(); // end of line drawin
}

void drawWindowForShop2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 0.5);  //set colour to gray
    glVertex2d(170.0, 10.0); //1 point of window4
    glVertex2d(170.0, -150.0); //2 point of window3
    glVertex2d(290.0, -150.0); //3 point of window3
    glVertex2d(290.0, 10.0); //4 point of window3
    glEnd(); // end of line drawin

}

void shopPositions()
{
    drawShop();
    drawDoorForShop();
    drawWindowForShop();
    drawWindowForShop2();
}

int count = 0;
int i = 0;
void shopPositionsAll()
{
    count++;
    if(i<11) {
        glTranslatef(shopArray[i], 0.0, 0.0);
        shopPositions();
    
        if(count % 12 == 0) {
            i++;
        }
    }
}

void shopPosition4()
{
    glTranslatef(350.0, 0.0, 0.0);
    shopPositions();
}

void shopPosition11()
{
    glTranslatef(0.0, 0.0, 0.0);
    shopPositions();
}


//Morphig heart in his hand
int tweenPoly[25][2];
double proportion =0.0;

void tween(float source[20][2], float destination[25][2], int numPoints, double proportion, int tweenPoly[25][2])
{
    
    for( int p = 0; p < numPoints; p++)
    {
        // get the source point
        double sourceX = source[p][0];
        double sourceY = source[p][1];
        
        // get the destination point
        double destinationX = destination[p][0];
        double destinationY = destination[p][1];
        
        // get the difference between source and destination
        double differenceX = (destinationX - sourceX);
        double differenceY = (destinationY - sourceY);
        
        // tween point is source position + proportion
        // of distance between source and destination
        double tweenX = sourceX + ( differenceX * proportion );
        double tweenY = sourceY + ( differenceY * proportion );
        
        // create point with tween co-ordinates in tween array
        tweenPoly[p][0]= int (tweenX);
        tweenPoly[p][1]= int (tweenY );
    }
    
}

void circle(double radius, double xc, double yc)
{
    int i;
    double angle = 2 * 3.1415 / 20;    // circle is drawn using 20 line.
    double circle_xy[20][2];
    
    circle_xy[0][0] = radius + xc;
    circle_xy[0][1] = yc;
    glBegin(GL_POLYGON);
    for (i = 1; i<20; i++)
    {
        circle_xy[i][0] = radius * cos(i *angle) + xc;
        circle_xy[i][1] = radius * sin(i * angle) + yc;
        
        glVertex2f(circle_xy[i - 1][0], circle_xy[i - 1][1]); //used for the rest circle functions
        glVertex2f(circle_xy[i][0], circle_xy[i][1]);
        
        //printf("%f,%f\n" ,circle_xy[i][0],circle_xy[i][1]);

    }
    glEnd();
}

void drwaHeart()
{
    glPushMatrix();
//    //printf("left circle of heart\n");
//    circle(10, -100, 90);
//    //printf("right circle of heart\n");
//    circle(10, -120, 90);
//    glBegin(GL_TRIANGLES);
//    glVertex2d(-130.0, 90.0);
//    glVertex2d(-90.0, 90.0);
//    glVertex2d(-110.0, 60.0);
//    glEnd();
//    //printf("\nend\n\n");
    
    glColor3f(1.0, 0.0, 0.0);  //set colour to red
    
    glTranslated(-150.0, -100.0, 0.0);
    glScaled(0.6, 0.6, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i<25; i++){
        glVertex2d(heartArray[i][0], heartArray[i][1]);
    }
    glEnd();
    glPopMatrix();
}

void largeHeart()
{
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);  //set colour to red
    circle(100, -50.0, 190);
    circle(100, 100, 190);
    glBegin(GL_TRIANGLES);
    glVertex2d(-150.0, 180.0);
    glVertex2d(200.0, 180.0);
    glVertex2d(50.0, -160.0);
    glEnd();
    glPopMatrix();
}

void drawBrokenHeart()
{
    glPushMatrix();
    largeHeart();
    glColor3f(1.0, 1.0, 1.0);  //set colour to white
    glLineWidth(10);
    
    //draw the crack on heart
    glBegin(GL_LINES);
    glVertex2d(22.0, 257.0); //1st line 1point
    glVertex2d(62.0, 200.0); //1st line 2point
    glVertex2d(62.0, 200.0); //2nd line 1point
    glVertex2d(22.0, 143.0); //2nd line 2point
    glVertex2d(22.0, 143.0); //3rd line 1point
    glVertex2d(62.0, 86.0);  //3rd line 2point
    glVertex2d(62.0, 86.0);  //4th line 1point
    glVertex2d(22.0, 33.0);  //4th line 2point
    glVertex2d(22.0, 33.0);  //5th line 1point
    glVertex2d(62.0, -20.0); //5th line 2point
    glVertex2d(62.0, -20.0); //6th line 1point
    glVertex2d(22.0, -73.0); //6th line 2point
    glVertex2d(22.0, -73.0); //7th line 1point
    glVertex2d(61.0,-140.0); //7th line 2point
    glEnd();
    glPopMatrix();
}

void XL_Heart()
{
    glPushMatrix();
    glScaled(2.0, 1.5, 0.0);
    largeHeart();
    glPopMatrix();
}


//Draw my bird
void drawBirdBody() // Draw body and head for a bird
{
    glPushMatrix();
    glColor3f(0.8, 1.0, 0.3);
    circle(45, 200, 90); // body
    circle(25, 266, 90); // head
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    circle(5, 278, 90); //eye
    glPopMatrix();
    
    glPushMatrix();  //mouth
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.6, 0.0);
    glVertex2d(287.0, 105.0);
    glVertex2d(305.0, 90.0);
    glVertex2d(285.0, 70.0);
    glEnd();
    glPopMatrix();
}

void drawTail()
{
    glBegin(GL_LINES);
    glVertex2d(155.0, 90.0); //first line
    glVertex2d(135.0, 120.0);
    glVertex2d(155.0, 90.0); //midle line
    glVertex2d(135.0, 90.0);
    glVertex2d(155.0, 90.0); //last line
    glVertex2d(135.0, 60.0);
    glEnd();
}

void drawWing1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.0);
    glVertex2d(200.0, 90.0);//first point
    glVertex2d(230.0, 165.0);//second point
    glVertex2d(170.0, 165.0);//last point
    glEnd();
}

void drawWing2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.0);
    glVertex2d(200.0, 90.0);//first point
    glVertex2d(230.0, 15.0);//second point
    glVertex2d(170.0, 15.0);//last point
    glEnd();
}

float inc2 = 2.0;
float tx2 = 0, ty2 = 0.0;

void birdTrasformation()
{
    glTranslatef(-15.0, 150.0, 0.0);
    // move the bird to the right side of the screen
    glTranslatef(tx2 ,ty2, 0.0);
    tx2 += inc2; ty2 = inc2;
}
void drawBird1()
{
    glPushMatrix();
    glTranslatef(-600.0, 200.0, 0.0); //move my bird to the beging of the screen
    birdTrasformation();
 
    drawBirdBody();
    drawTail();
    drawWing1();
    glPopMatrix();
}

void drawBird2()
{
    glPushMatrix();
    glTranslatef(-600.0, 220.0, 0.0); //move my bird to the beging of the screen
    birdTrasformation();

    drawBirdBody();
    drawTail();
    drawWing2();
    glPopMatrix();
}

float tx5 = 1.0, ty5 = 0.0;
float inc5 = 0.7;

void cloudTransformations()
{
    glTranslatef(-5.0, 0.0, 0.0);
    // move the clud to the left side of the screen
    glTranslatef(tx5 ,ty5, 0.0);
    tx5 -= inc5; ty5 = inc5;
}

//Draw clouds
void drawCloud()
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    cloudTransformations();

    circle(50, -200, 500);
    circle(40, -150, 510);
    circle(30, -100, 510);
    circle(50, -50, 510);
    circle(40, -50, 480);
    circle(50, -100, 480);
    circle(40, -150, 470);
    glPopMatrix();
}

void drawCloud2()
{
    glPushMatrix();
    glTranslated(250.0, -150.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    cloudTransformations();
    
    circle(50, -200, 500);
    circle(60, -140, 520);
    circle(40, -100, 500);
    circle(30, -100, 510);
    circle(50, -50, 510);
    circle(40, -50, 480);
    circle(50, -100, 480);
    circle(40, -150, 470);
    glPopMatrix();
}

void drawCloud3()
{
    glPushMatrix();
    glTranslated(-690.0, -130.0, 0.0);
    drawCloud();
    glPopMatrix();
}

void drawCloud4()
{
    glPushMatrix();
    glTranslated(660.0, -180.0, 0.0);
    drawCloud();
    glPopMatrix();
}

void drawCloud5()
{
    glPushMatrix();
    glTranslated(800.0, -10.0, 0.0);
    drawCloud();
    glPopMatrix();
}

void drawCloud6()
{
    glPushMatrix();
    glTranslated(1000.0, -200.0, 0.0);
    drawCloud();
    glPopMatrix();
}

void drawAllClouds()
{
    drawCloud();
    drawCloud2();
    drawCloud3();
    drawCloud4();
    drawCloud5();
    drawCloud6();
}



//Draw my character - men
void drawEyes1() // draw eyes for person1
{
    glBegin(GL_POLYGON);
    for (int i = 0; i<20; i++){
        glVertex2d(eyeLeftMen[i][0], eyeLeftMen[i][1]);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for (int i = 0; i<20; i++){
        glVertex2d(eyeRightMen[i][0], eyeRightMen[i][1]);
    } //end of loop
    glEnd();
    
    //    printf("left eye\n");
    //    circle(10, -300, 90); // left eye
    //    printf("\nright eye\n");
    //    circle(10, -335, 90); // right eye
    //    printf("\nend\n\n");
    
}

void drawHead1()
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i<20; i++){
        glVertex2d(head[i][0], head[i][1]);
    }
    glEnd();
    
    drawEyes1(); // draw eyes for person1
}

void drawMouth1() //neutral smile
{
    glBegin(GL_LINES);
    glVertex2d(-345.0, 45.0);
    glVertex2d(-300.0, 45.0);
    glEnd();
}

//Draw my character 2 - women
void drawEyes2() // draw eyes for person2
{
    circle(10, -350, 90); // left eye
    circle(10, -385, 90); // right eye
}

void drawHead2() //head for second person
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i<20; i++){
        glVertex2d(head[i][0], head[i][1]);
    }
    glEnd();

    drawEyes2(); // draw eyes for person1
}

void drawMouth2() //neutral smile for second person
{
    glBegin(GL_LINES);
    glVertex2d(-385.0, 45.0);
    glVertex2d(-340.0, 45.0);
    glEnd();

}
void drawBody()
{
    glBegin(GL_LINES);
    glVertex2f(-350.0, 10.0);
    glVertex2f(-350.0, -260.0 );
    glEnd();
}



void drawPose1() //men pose1
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glTranslatef(0.0, -110.0, 0.0); //and move him a little bit down
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
        glVertex2d(-350.0,-140.0); //right hand only
        glVertex2d(-310.0,-190.0);
        circle(5, -310, -190); // part of the right hand
    glEnd();
    //draw legs
    glBegin(GL_LINES);
        glVertex2d(-350.0, -260.0);//right leg
        glVertex2d(-300.0,-450.0);

        glVertex2d(-350.0, -260.0); //left leg
        glVertex2d(-400.0,-450.0);
    glEnd();
    glPopMatrix();
}

void drawPose2() //men pose2
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //and move him a little bit down
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //left hand only
    glVertex2d(-390.0,-190.0);
    circle(5, -390, -190); //part of left hand
    glEnd();
    
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-352.0,-450.0);

    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-352.0,-400.0);
    glEnd();
    glPopMatrix();
}

void drawBow() //draw bow
{
    glPushMatrix();
    glColor3f(0.9, 0.0, 0.7);
    glRotated(-10, 0.0, 0.0, 1.0);
    circle(15, -320, 100);
    
    glBegin(GL_TRIANGLES);
    glVertex2d(-320.0, 100.0);
    glVertex2d(-350.0, 145.0);
    glVertex2d(-350.0, 70);
    glVertex2d(-320.0, 100.0);
    glVertex2d(-290.0, 145.0);
    glVertex2d(-290.0, 70);
    glEnd();
    glPopMatrix();
}

float inc3 = 2.0;
float tx3 = 0, ty3 = 0.0;

void character3and4transformation()
{
    glTranslatef(700.0, 0.0, 0.0); // move her to the right side of the screen
    glTranslatef(tx3 ,ty3, 0.0);
    tx3 -= inc3; ty3 = inc3;
}

void drawPose3()
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -110.0, 0.0); //move her a little bit down
    if(tx3 <= -300) {
        tx3 = -300;
        character3and4transformation();
    } else {
        character3and4transformation();
    }

    drawHead2();
    drawMouth2();
    drawBody();
    drawBow();
        glColor3f(0.0, 0.0, 0.0);
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
        
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-352.0,-450.0);
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-352.0,-400.0);
    glEnd();
    glPopMatrix();
}

void drawPose4() // women pose2
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);

    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //move her a little bit down
    
    if(tx3 <= -300) {
        tx3 = -300;
        character3and4transformation();
    } else {
        character3and4transformation();
    }

    drawHead2();
    drawMouth2();
    drawBody();
        drawBow();
        glColor3f(0.0, 0.0, 0.0);
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //left hand only
    glVertex2d(-390.0,-190.0);
    circle(5, -390, -190); //part of left hand
    glEnd();

    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-300.0,-450.0);
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-400.0,-450.0);
    glEnd();
    glPopMatrix();

}

void dremBubble()
{
    glPushMatrix();
    glColor3f(1.0, 5.0, 1.0);
    circle(15, -200, 50);
    circle(30, -155, 95);
    circle(45, -90, 150);
    glTranslatef(215.0, 390.0, 0.0); //move my heart inside the bubble
    drwaHeart();
    glPopMatrix();
}

float inc1 = 2.0;
float tx1 = 0, ty1 = 0.0;

void character5and6transformation()
{
    glTranslatef(10.0, 0.0, 0.0); // move him to the right side of the screen
    glTranslatef(tx1 ,ty1, 0.0);
    tx1 += inc1; ty1 = inc1;
}
void drawPose5() //men pose3 - moving
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    if(tx1 <= -300) {
        tx1 = -300;
        character5and6transformation();
    } else {
        character5and6transformation();
    }
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glTranslatef(0.0, -110.0, 0.0); //and move him a little bit down

        drawHead1();
        drawMouth1();
        drawBody();
        //draw hands
        glBegin(GL_LINES);
        glVertex2d(-350.0,-140.0); //right hand only
        glVertex2d(-310.0,-190.0);
        circle(5, -310, -190); // part of the right hand
        glEnd();
        //draw legs
        glBegin(GL_LINES);
        glVertex2d(-350.0, -260.0);//right leg
        glVertex2d(-300.0,-450.0);
        
        glVertex2d(-350.0, -260.0); //left leg
        glVertex2d(-400.0,-450.0);
    glEnd();
    glPopMatrix();
    
        glPushMatrix();
        glTranslatef(58.0, 0.0, 0.0); // move the heart (in his RIGHT hand)
        drwaHeart();
        glPopMatrix();
    
    glPopMatrix();
}

void drawPose6() //men pose4 - moving
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    if(tx1 <= -300) {
        tx1 = -300;
        character5and6transformation();
    } else {
        character5and6transformation();
    }
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //and move him a little bit down
        drawHead1();
        drawMouth1();
        drawBody();
        //draw hands
        glBegin(GL_LINES);
        glVertex2d(-350.0,-140.0); //left hand only
        glVertex2d(-390.0,-190.0);
        circle(5, -390, -190); //part of left handp
        glEnd();
        
        //draw legs
        glBegin(GL_LINES);
        glVertex2d(-350.0, -260.0);//right leg
        glVertex2d(-352.0,-450.0);
        
        glVertex2d(-350.0, -260.0); //left leg
        glVertex2d(-352.0,-400.0);
    glEnd();
    glPopMatrix();
    
        glPushMatrix();
        glTranslatef(-5.0, 0.0, 0.0); // move the heart (in his LEFT hand)
        drwaHeart();
        glPopMatrix();
    
    glPopMatrix();
}

void drawPose7() //men pose7
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(50.0, 0.0, 0.0); // move the heart (in his hand)
    drwaHeart();
    glPopMatrix();
}

void drawPose8()
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(100.0, 50.0, 0.0); // move the heart (up in air)
    drwaHeart();
    glPopMatrix();
}

void drawPose9()
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(150.0, 0.0, 0.0); // move the heart (in her hand)
    drwaHeart();
    glPopMatrix();
}

void drawPose10()
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(150.0, 100.0, 0.0); // move the heart (up on top of her hand)
    drwaHeart();
    glPopMatrix();
}

void drawPose11()
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(150.0, -200.0, 0.0); // move the heart (down t the floor)
    drwaHeart();
    glPopMatrix();
}

void drawPose12()
{
    glPushMatrix();
    glTranslatef(150.0, 0.0, 0.0); //stay where you stoped after pose6
    drawPose1();
    
    glTranslatef(-150.0, -435.0, 0.0); // move the heart (down on the floor and broken)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}

//move her, so she leaves the screen
float inc4 = 3.0;
float tx4 = 0, ty4 = 0.0;
int pushLeft2 = 0;

void character13and14transformation()
{
    glTranslatef(400.0, 0.0, 0.0); // move her to the right side of the screen
    glTranslatef(tx4 ,ty4, 0.0);
    tx4 -= inc4; ty4 = inc4;
}

void drawPose13() // women walking pose1
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -110.0, 0.0); //move her a little bit down
    if(tx4 <= 0) {
        tx4++;
        character13and14transformation();
    }
        drawHead2();
        drawMouth2();
        drawBody();
        drawBow();
        glColor3f(0.0, 0.0, 0.0);
        //draw hands
        glBegin(GL_LINES);
        glVertex2d(-350.0,-140.0); //right hand only
        glVertex2d(-310.0,-190.0);
        circle(5, -310, -190); // part of the right hand
        glEnd();
        
        //draw legs
        glBegin(GL_LINES);
        glVertex2d(-350.0, -260.0);//right leg
        glVertex2d(-352.0,-450.0);
        glVertex2d(-350.0, -260.0); //left leg
        glVertex2d(-352.0,-400.0);
    glEnd();
    glPopMatrix();
}

void drawPose14() // women walking pose2
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //move her a little bit down

    if(tx4 <= 0) {
        tx4++;
        character13and14transformation();
    }
        drawHead2();
        drawMouth2();
        drawBody();
        drawBow();
        glColor3f(0.0, 0.0, 0.0);
        //draw hands
        glBegin(GL_LINES);
        glVertex2d(-350.0,-140.0); //left hand only
        glVertex2d(-390.0,-190.0);
        circle(5, -390, -190); //part of left hand
        glEnd();
        
        //draw legs
        glBegin(GL_LINES);
        glVertex2d(-350.0, -260.0);//right leg
        glVertex2d(-300.0,-450.0);
        glVertex2d(-350.0, -260.0); //left leg
        glVertex2d(-400.0,-450.0);
    glEnd();
    glPopMatrix();
}
void smallBrokenHeart() //for men to pick up
{
    glPushMatrix();
    glTranslatef(0.0, -435.0, 0.0); // move the heart (down on the floor and broken)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}

void drawPoseBendingForHeart1()
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glRotated(-10, 0, 0, 1);
    glTranslatef(350.0, -150.0, 0.0);
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-300.0,-450.0);
    
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-400.0,-450.0);
    glPopMatrix();
    glEnd();
}

void drawPoseBendingForHeart2()
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glRotated(-10, 0, 0, 1);
    glTranslatef(350.0, -150.0, 0.0);
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-325.0,-340.0);
    
    glVertex2d(-325.0,-340.0); //bending right knee
    glVertex2d(-350.0,-450.0);
    glPopMatrix();
    glEnd();
}

void drawPoseBendingForHeart3()
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glRotated(-10, 0, 0, 1);
    glTranslatef(350.0, -250.0, 0.0);
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-325.0,-340.0);
    
    glVertex2d(-325.0,-340.0); //bending right knee
    glVertex2d(-350.0,-450.0);
    glPopMatrix();
    glEnd();
}

void drawPoseBendingForHeart4()
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale him a liitle bit
    glRotated(-10, 0, 0, 1);
    glTranslatef(350.0, -250.0, 0.0);
    drawHead1();
    drawMouth1();
    drawBody();
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-325.0,-340.0);
    
    glVertex2d(-325.0,-340.0); //bending right knee
    glVertex2d(-350.0,-450.0);
    glPopMatrix();
    glEnd();
    
}

void drawPoseBendingForHeart5()
{
    drawPoseBendingForHeart3();
    glPushMatrix();
    glTranslatef(-300.0, -170.0, 0.0); // move the heart (down on the floor and broken)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
    
}

void drawPoseBendingForHeart6()
{
    drawPoseBendingForHeart2();
    glPushMatrix();
    glTranslatef(-295.0, -170.0, 0.0); // move the heart (down on the floor and broken)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}

void drawPoseBendingForHeart7()
{
    drawPoseBendingForHeart1();
    glPushMatrix();
    glTranslatef(-300.0, -160.0, 0.0); // move the heart (down on the floor and broken)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}

void drawHeratInLeftHand()
{
    glPushMatrix();
    glTranslatef(-320.0, -230.0, 0.0); // move the heart (to the hand of men)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}

void drawHeartInRightHand()
{
    glPushMatrix();
    glTranslatef(-240.0, -230.0, 0.0); // move the heart (to the hand of men)
    glScaled(0.07, 0.07, 0.0);
    drawBrokenHeart();
    glPopMatrix();
}


void drawPose15() //men walking towards shop walking pose1
{
    glTranslatef(150.0, 0.0, 0.0); //chane the walking position from where he was standing
    drawPose1();
}

void drawPose16() //men walking towards shop walking pose2
{
    glTranslatef(150.0, 0.0, 0.0); //chane the walking position from where he was standing
    drawPose2();
}


float inc7 = 2.0;
float tx7 = 0, ty7 = 0.0;

void character17and18transformation()
{
    glTranslatef(300.0, 0.0, 0.0); // move him to the right side of the screen
    glTranslatef(tx7 ,ty7, 0.0);
    tx7 -= inc7; ty7 = inc7;
}

void drawPose17() //men walking from the shop, walking pose1
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -110.0, 0.0); //move her a little bit down
    if(tx7 <= -380) {
        tx7 = -380;
        character17and18transformation();
    } else {
        character17and18transformation();
    }
    
    drawHead2();
    drawMouth2();
    drawBody();
    glColor3f(0.0, 0.0, 0.0);
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //right hand only
    glVertex2d(-310.0,-190.0);
    circle(5, -310, -190); // part of the right hand
    glEnd();
    
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-352.0,-450.0);
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-352.0,-400.0);
    glEnd();
    
    glTranslatef(-10.0, 70.0, 0.0); // move the heart (up on top of his hand)
    drwaHeart();
    glPopMatrix();
    
}

//Used for Morphig smille
float tweenSmille[10][2];
double proportion2 =0.0;

void tween2(float source[10][2], float destination[10][2], int numPoints, double proportion2, float tweenSmille[10][2])
{
    
    for( int p = 0; p < numPoints; p++)
    {
        // get the source point
        double sourceX = source[p][0];
        double sourceY = source[p][1];
        
        // get the destination point
        double destinationX = destination[p][0];
        double destinationY = destination[p][1];
        
        // get the difference between source and destination
        double differenceX = (destinationX - sourceX);
        double differenceY = (destinationY - sourceY);
        
        // tween point is source position + proportion
        // of distance between source and destination
        double tweenX = sourceX + ( differenceX * proportion2 );
        double tweenY = sourceY + ( differenceY * proportion2 );
        
        // create point with tween co-ordinates in tween array
        tweenSmille[p][0]= int (tweenX);
        tweenSmille[p][1]= int (tweenY );
    }
    
}

void drawHappySmile()
{
    glPushMatrix();
    //glScaled(0.6, 0.6, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i<10; i++){
        glVertex2d(happyMouthArray[i][0], happyMouthArray[i][1]);
    }
    glEnd();
    
    glPopMatrix();
    
}

void drawPose18() //men walking from the shop, walking pose2
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //move her a little bit down
    
    if(tx7 <= -380) {
        tx7 = -380;
        character17and18transformation();
    } else {
        character17and18transformation();
    }
    
    drawHead2();
    if(frame <2800) {
    drawMouth2();
    }
    drawBody();
    glColor3f(0.0, 0.0, 0.0);
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //left hand only
    glVertex2d(-390.0,-190.0);
    circle(5, -390, -190); //part of left hand
    glEnd();
    
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-300.0,-450.0);
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-400.0,-450.0);
    glEnd();
    
    glTranslatef(-90.0, 70.0, 0.0); // move the heart (up on top of his hand)
    drwaHeart();
    glPopMatrix();

    
}

void drawPose19() //men walking from the shop, walking pose2
{
    glLineWidth(4);
    glColor3f(0.0, 0.0, 0.0);
    
    glPushMatrix();
    glScaled(0.8, 0.8, 1); //scale her a liitle bit
    glTranslatef(0.0, -112.0, 0.0); //move her a little bit down
    
    if(tx7 <= -380) {
        tx7 = -380;
        character17and18transformation();
    } else {
        character17and18transformation();
    }
    
    drawHead2();
    drawBody();
    glColor3f(0.0, 0.0, 0.0);
    //draw hands
    glBegin(GL_LINES);
    glVertex2d(-350.0,-140.0); //left hand only
    glVertex2d(-390.0,-190.0);
    circle(5, -390, -190); //part of left hand
    glEnd();
    
    //draw legs
    glBegin(GL_LINES);
    glVertex2d(-350.0, -260.0);//right leg
    glVertex2d(-300.0,-450.0);
    glVertex2d(-350.0, -260.0); //left leg
    glVertex2d(-400.0,-450.0);
    glEnd();
    
    glTranslatef(-90.0, 70.0, 0.0); // move the heart (up on top of his hand)
    drwaHeart();
    glPopMatrix();
}


//Draw signs for Glue
void glueSign1()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(95,345,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign2()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(130,275,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign3()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(90,215,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign4()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(130,165,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign5()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(100,100,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign6()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(130,40,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign7()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(90,-10,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign8()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(120,-80,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void glueSign9()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(-340,-180,GLUT_BITMAP_HELVETICA_18,"Rapid"); // Add text on the glue
}
void RapidSign()
{
    glColor3f(0.0, 0.0, 0.0); //black sign
    renderSpacedBitmapString(-250,-180,GLUT_BITMAP_TIMES_ROMAN_24,"FIX EVERYTHING"); // Add text on the glue
}

//Draw body for glue
void glueBody()
{
    glColor3f(1.0, 1.0, 1.0); //white
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glVertex2f(-50.0, 100.0);
    glVertex2f(0.0, 100.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-50.0, 0.0);
    glEnd();
    // draw lid
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 1.0); //gery
    glVertex2f(-40.0, 100.0);
    glVertex2f(-10.0, 100.0);
    glVertex2f(-10.0, 130.0);
    glVertex2f(-40.0, 130.0);
    glEnd();
    // draw top of the glue
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0); //white
    glVertex2f(-30.0, 130.0);
    glVertex2f(-30.0, 180.0);
    glVertex2f(-30.0, 180.0);
    glVertex2f(-17.0, 160.0);
    glVertex2f(-17.0, 130.0);
    glVertex2f(-30.0, 130.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); //black

    //draw lines around glue
    glBegin(GL_LINES);
    //around top
    glVertex2f(-40.0, 100.0);
    glVertex2f(-10.0, 100.0);
    glVertex2f(-10.0, 130.0);
    glVertex2f(-40.0, 130.0);
    // around lid
    glVertex2f(-30.0, 130.0);
    glVertex2f(-30.0, 180.0);
    glVertex2f(-30.0, 180.0);
    glVertex2f(-17.0, 160.0);
    glVertex2f(-17.0, 130.0);
    glVertex2f(-30.0, 130.0);
    //around bottle
    glVertex2f(-50.0, 100.0);
    glVertex2f(0.0, 100.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-50.0, 0.0);
    glEnd();
}

void rotateGlue()
{
    glRotated(130, 0.0, 0.0, 1.0); // rotate my glue
}

void drawGlue1()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(220.0, -365.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign1(); //draw my sign inside the glue
}

void drawGlue2()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(145.0, -350.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign2(); //draw my sign inside the glue
}
void drawGlue3()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(125.0, -285.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign3(); //draw my sign inside the glue
}

void drawGlue4()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(60.0, -280.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign4(); //draw my sign inside the glue
}

void drawGlue5()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(30.0, -210.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign5(); //draw my sign inside the glue
}
void drawGlue6()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(-35.0, -200.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign6(); //draw my sign inside the glue
}

void drawGlue7()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(-50.0, -135.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign7(); //draw my sign inside the glue
}

void drawGlue8()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(-120.0, -120.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign8(); //draw my sign inside the glue
}

void drawGlue9()
{
    // draw bottle
    glPushMatrix();
    rotateGlue();
    glTranslated(100.0, 290.0, 0.0); // change position
    glueBody();
    glPopMatrix();

    glueSign9(); //draw my sign inside the glue
}

float txC = 1.0, tyC = 0.0;
float incC = 1.0;

void drawCloudRapid()
{
    glPushMatrix();
    glTranslated(-50.0, -980.0, 0.0);
    glScaled(1.5, 1.5, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    circle(50, -200, 500);
    circle(60, -140, 520);
    circle(40, -100, 500);
    circle(30, -100, 510);
    circle(50, -50, 510);
    circle(40, -50, 480);
    circle(50, -100, 480);
    circle(40, -150, 470);
    glPopMatrix();
}

void drawStar() //yellow part of the star
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.3);
    glVertex2d(-270.0, -200.0);
    glVertex2d(-250.0, 50.0);
    glVertex2d(-220.0, -200.0);
    glEnd();
}
void drawStar2() //yellow part of the star
{
    glPushMatrix();
    glRotated(180, 1.0, 1.0, 0.0);
    glTranslatef(35.0, -50.0, 0.0);
    drawStar();
    glPopMatrix();
}

void drawStar3() //yellow part of the star
{
    glPushMatrix();
    glRotated(-180, 0.0, 0.0, 1.0);
    glTranslatef(495.0, 420.0, 0.0);
    drawStar();
    glPopMatrix();
}

void drawStar4() //yellow part of the star
{
    glPushMatrix();
    glRotated(-270, 0.0, 0.0, 1.0);
    glTranslatef(20.0, 440.0, 0.0);
    drawStar();
    glPopMatrix();
}

void drawStar5() //yellow part of the star
{
    glPushMatrix();
    glRotated(-25, 0.0, 0.0, 1.0);
    glTranslatef(120.0, -100.0, 0.0);
    drawStar();
    glPopMatrix();
}

void drawStar6() //yellow part of the star
{
    glPushMatrix();
    glTranslatef(-350.0, -520.0, 0.0);
    glRotated(-150, 0.0, 0.0, 1.0);
    drawStar();
    glPopMatrix();
}

void drawStar7() //yellow part of the star
{
    glPushMatrix();
    glTranslatef(-560.0, -320.0, 0.0);
    glRotated(-200, 0.0, 0.0, 1.0);
    drawStar();
    glPopMatrix();
}

void drawStar8() //yellow part of the star
{
    glPushMatrix();
    glTranslatef(-280.0, 90.0, 0.0);
    glRotated(60, 0.0, 0.0, 1.0);
    drawStar();
    glPopMatrix();
}

void drawAllStars()
{
    glPushMatrix();
    drawCloudRapid();
    drawStar();
    drawStar2();
    drawStar3();
    drawStar4();
    drawStar5();
    drawStar6();
    drawStar7();
    drawStar8();
    glPopMatrix();

}

void drawAllStars2()
{
    glPushMatrix();
    drawStar();
    drawStar2();
    drawStar3();
    drawStar4();
    drawStar5();
    drawStar6();
    drawStar7();
    drawStar8();
    glPopMatrix();
    
}

void drawR() //draw letter R for Rapid Glue
{
    glColor3f(0.0, 0.0, 0.0);

    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2d(-305.0, -300.0);
    glVertex2d(-305.0, -250.0);
    glVertex2d(-300.0, -250.0);
    glVertex2d(-300.0, -300.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-285.0, -250.0);
    glVertex2d(-305.0, -250.0);
    glVertex2d(-305.0, -245.0);
    glVertex2d(-285.0, -245.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-280.0, -245.0);
    glVertex2d(-285.0, -245.0);
    glVertex2d(-285.0, -270.0);
    glVertex2d(-280.0, -270.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-285.0, -270.0);
    glVertex2d(-305.0, -270.0);
    glVertex2d(-305.0, -265.0);
    glVertex2d(-285.0, -265.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-305.0, -260.0);
    glVertex2d(-265.0, -300.0);
    glVertex2d(-275.0, -300.0);
    glVertex2d(-305.0, -265.0);

    glEnd();
    glPopMatrix();
}

void drawA()
{
    glPushMatrix();
    glBegin(GL_LINES);
    glLineWidth(1);
    glVertex2d(-285.0, -310.0);
    glVertex2d(-265.0, -230.0);

    glVertex2d(-265.0, -230.0);
    glVertex2d(-245.0, -310.0);

    glVertex2d(-275.0, -270.0);
    glVertex2d(-255.0, -270.0);

    glEnd();
    glPopMatrix();
}

void drawP()
{
    glPushMatrix();
    glTranslated(60.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-305.0, -300.0);
    glVertex2d(-305.0, -250.0);
    glVertex2d(-300.0, -250.0);
    glVertex2d(-300.0, -300.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-285.0, -250.0);
    glVertex2d(-305.0, -250.0);
    glVertex2d(-305.0, -245.0);
    glVertex2d(-285.0, -245.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-280.0, -245.0);
    glVertex2d(-285.0, -245.0);
    glVertex2d(-285.0, -270.0);
    glVertex2d(-280.0, -270.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-285.0, -270.0);
    glVertex2d(-305.0, -270.0);
    glVertex2d(-305.0, -265.0);
    glVertex2d(-285.0, -265.0);
    glEnd();
    glPopMatrix();
}

void drawI()
{
    glPushMatrix();
    glTranslated(60.0, 0.0, 0.0);
    circle(10, -275, -230);
    glBegin(GL_LINES);
    glVertex2d(-270.0, -315.0);
    glVertex2d(-270.0, -245.0);
    glEnd();
    glPopMatrix();
}

void drawD()
{
    glPushMatrix();
    glTranslated(60.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(-255.0, -317.0);
    glVertex2d(-255.0, -242.0);
    glVertex2d(-255.0, -245.0);
    glVertex2d(-230.0, -265.0);
    glVertex2d(-255.0, -315.0);
    glVertex2d(-230.0, -295.0);
    glVertex2d(-232.0, -297.0);
    glVertex2d(-232.0, -263.0);
    glEnd();
    glPopMatrix();
}

void drawRAPID()
{
    glPushMatrix();
    glLineWidth(5);
    drawR();
    drawA();
    drawP();
    drawI();
    drawD();
    RapidSign();
    glPopMatrix();
}

//DRAW FIREWORKS
float fireworkCenterX = -300, fireworkCenterY = 400;
//variables for firework colour, set once per firework
float fr = 1; float fg = 1;  float fb = 1;

// the properties of a fire particle are defined in a struct
struct fireParticle {
    float x = 0; // position in x
    float y = 0; // position in y
    float inc = 0.4;
    float radius;
    float xd = 0; //direction in x
    float yd = 0; //direction in y
};

time_t t;

fireParticle firework[FIREWORKSIZE];

void setDirectionVector(int i)
{
    firework[i].xd = (float)((rand() % 1000) + 1) / 1000.0;
    firework[i].yd = sqrt(1.0 - (firework[i].xd*firework[i].xd));
    if (rand() % 1000 < 500) firework[i].xd = -firework[i].xd;
    if (rand() % 1000 < 500) firework[i].yd = -firework[i].yd;
}

void initFirework()
{
    for (int i = 0; i < FIREWORKSIZE; i++) {
        firework[i].x = fireworkCenterX;
        firework[i].y = fireworkCenterY;
        firework[i].inc = 0.01 + (float)(rand() % 150) / 1000.0;
        firework[i].radius = (float)(rand() % 15);
        setDirectionVector(i);
    }
    // set fireowrk centre
    fireworkCenterX = -300;
    fireworkCenterY = 400;
    //set firework color
    fr = (float)(rand() % 1000) / 1000.0;
    fg = (float)(rand() % 1000) / 1000.0;
    fb = (float)(rand() % 1000) / 1000.0;
}
void drawParticleShape(int i)
{
    glBegin(GL_LINES);
    glVertex2d(firework[i].x, firework[i].y);
    glVertex2d(firework[i].x + firework[i].xd * 5, firework[i].y + firework[i].yd * 5);
    glEnd();
}

void drawFireParticle(int i)
{
    glColor3f(fr, fg, fb);
    glLineWidth(2);
    
    drawParticleShape(i);
    // update partcile movement based on its speed (inc) and its direction vector
    firework[i].x = firework[i].x + (firework[i].xd*firework[i].inc);
    firework[i].y = firework[i].y + (firework[i].yd*firework[i].inc);
    
}

void drawFirework()
{
    // draw each fire particle
    for (int i = 0; i < FIREWORKSIZE; i++)
    {
        drawFireParticle(i);
    }
    //start a firework in a new position every so often randomly
    if (frame % 400 == 0) {
        fireworkCenterX = -300;
        fireworkCenterY = 400;
        initFirework();
    }
}
//END OF FIREWORKS

//Draw stars on the sky
void drawStarsOnSky()
{
    glPushMatrix();
    glTranslated(-200, 300, 0);
    glScaled(0.2, 0.2, 0.1);
    drawStar();
    drawStar2();
    drawStar3();
    drawStar4();
    drawStar5();
    drawStar6();
    drawStar7();
    drawStar8();
    glPopMatrix();
    
}

void drawStarsOnSky2()
{
    glPushMatrix();
    glTranslated(400, 30, 0);
    drawStarsOnSky();
    glPopMatrix();
}

void drawStarsOnSky3()
{
    glPushMatrix();
    glTranslated(600, 130, 0);
    drawStarsOnSky();
    glPopMatrix();
}

void drawStarsOnSky4()
{
    glPushMatrix();
    glTranslated(250, 350, 0);
    glScaled(0.5, 0.5, 0.1);
    drawStarsOnSky();
    glPopMatrix();
}

void drawStarsOnSky5()
{
    glPushMatrix();
    glTranslated(-250, 350, 0);
    glScaled(0.5, 0.5, 0.1);
    drawStarsOnSky();
    glPopMatrix();
}

void drawStarsOnSky6()
{
    glPushMatrix();
    glTranslated(-50, 450, 0);
    glScaled(0.5, 0.5, 0.1);
    drawStarsOnSky();
    glPopMatrix();
}

void drawAllStarsOnSky()
{
    drawStarsOnSky();
    drawStarsOnSky2();
    drawStarsOnSky3();
    drawStarsOnSky4();
    drawStarsOnSky5();
    drawStarsOnSky6();
}

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(20, Timer, value);
}

void visibility(int state)
{
    switch (state)
    {
        case GLUT_VISIBLE:
            Timer(1);
            break;
        case GLUT_NOT_VISIBLE:
            Timer(0);
            break;
        default:
            break;
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Draw ground and tree
    glPushMatrix();
    drawGround();
    drawTree();
    glPopMatrix();

    //Part1 - Draw all poses of my first character - men
    glPushMatrix();
    if ((frame > 0) && (frame <= 800)){
        if (frame % 50 < 25) { //walking pose1
            drawPose1();
        }
        else if (frame > 450){ // stop for while
            drawPose1();
        }
        else {
            drawPose2(); //walking pose2
        }
    }
    glPopMatrix();
    
    //Part1 - Draw all poses of my second character - women
    glPushMatrix();
        if ((frame > 500) && (frame < 1300)) {
            if (frame % 50 < 25) { //walking pose1
                drawPose4();
            }
            else if (frame > 650){ // stop for while
                drawPose4();
            }
            else {
                drawPose3(); //walking pose2
            }
        }
    glPopMatrix();
    
    //Dream buble
    glPushMatrix();
    if ((frame > 500) && (frame < 800)){
        dremBubble();
    }
    glPopMatrix();
    
    //Draw clouds
    glPushMatrix();
    if ((frame > 0) && (frame < 1890)){
        drawAllClouds();
        //if its moved off screen reset it to move accross the screen
        if (tx5 < -900) {
            tx5 = 600; ty5 = 200;
        }
    }
    glPopMatrix();

    // Draw all poses for bird
    glPushMatrix();
    if ((frame > 0) && (frame < 1890)){
        if (frame % 50 < 25) {
            drawBird1();
        }
        else {
            drawBird2();
        }
    }
    glPopMatrix();
    //if its moved off screen reset it to move accross the screen
    if (tx2 > 900)
    {
        tx2 = -600; ty = 200;
    }
    
    //Morphing the heart
    glPushMatrix();
    int i;
    if ((frame>670) && (frame<800))
    {
        glColor3f(1.0,0.0,0.0);
        tween(handArray,heartArray,25,proportion,tweenPoly);

        glBegin(GL_POLYGON);
        for(i=0;i<25;i++)
            glVertex2i (tweenPoly[i][0],tweenPoly[i][1]);    // Morphing hand circle to heart.
        glEnd();

        proportion +=0.01;
        if(proportion >1.0) proportion =1.0;
    }
    glPopMatrix();
    
    //Part2 - Draw men as he giving the heart for a women
    glPushMatrix();
    if ((frame > 800) && (frame <= 874)) {
        if (frame % 50 < 25) { //walking pose1
            drawPose5();
        }
        else if (frame > 874){ // stop for while
            drawPose7();
        }
        else {
            drawPose6(); //walking pose2
        }
    //Throwing heart for the women
    } else if ((frame > 871) && (frame < 890)){
        drawPose7();
    } else if ((frame > 890) && (frame <=950)){
        drawPose8();
    } else if ((frame > 950) && (frame <=1000)){
        drawPose9();
        
    //Women is playing with the heart and drop it down
    } else if ((frame > 1000) && (frame < 1050)){
        drawPose10();
    } else if ((frame >= 1050) && (frame < 1100)){
        drawPose9();
    }  else if ((frame >= 1100) && (frame < 1150)){
        drawPose10();
    }else if ((frame >= 1150) && (frame < 1200)){
        drawPose9();
    }else if ((frame >= 1200) && (frame < 1250)){
        drawPose11();
    } else if ((frame >= 1250) && (frame < 1300)){
        drawPose12();
    }
    glPopMatrix();

    //Move the women across the screen
    glPushMatrix();
    if ((frame >= 1300) && (frame <= 1850)){
        if (frame % 50 < 25) { //walking pose1
            drawPose14();
            glutPostRedisplay();
        }
        else if (frame > 1850){ // stop behinde the scene
            drawPose14();
            glutPostRedisplay();
        }
        else {
            drawPose13(); //walking pose2
            glutPostRedisplay();
        }
    }
    glPopMatrix();
    
    //draw small broken heart on the floor until the man will pick it up
    glPushMatrix();
    if ((frame >= 1300) && (frame <= 1505)){
        smallBrokenHeart();
    }
    glPopMatrix();
    
    
    //Men stand still until women leave
    glPushMatrix();
    if((frame > 880) && (frame <= 1400)){
        drawPose15();
    }
    glPopMatrix();
    
    //Men bending for the heart
    glPushMatrix();
    if ((frame > 1400) && (frame < 1440)){
        drawPoseBendingForHeart1();
    } else if ((frame >= 1440) && (frame < 1460)) {
        drawPoseBendingForHeart2();
    } else if ((frame >= 1460) && (frame < 1480)) {
        drawPoseBendingForHeart3();
    } else if ((frame >= 1480) && (frame < 1500)) {
        drawPoseBendingForHeart4();
    }else if ((frame >= 1500) && (frame < 1520)) {
        drawPoseBendingForHeart5();
    }else if ((frame >= 1520) && (frame < 1540)) {
        drawPoseBendingForHeart6();
    }else if ((frame >= 1540) && (frame < 1560)) {
        drawPoseBendingForHeart7();
    }
    glPopMatrix();
    
    //Men walking towards shop after women leave
    glPushMatrix();
    if ((frame > 1560) && (frame < 1900)) {
        if (frame % 50 < 25) { //walking pose1
            drawPose15();
            drawHeartInRightHand();
            glutPostRedisplay();
        }
        else if (frame > 1800){ // stop for while
            drawPose15();
            drawHeartInRightHand();
            glutPostRedisplay();
        }
        else {
            drawPose16(); //walking pose2
            drawHeratInLeftHand();
            glutPostRedisplay();
        }
    }
    glPopMatrix();

    //draw the shop, moving towards men
    glPushMatrix();
    if ((frame > 1690) && (frame <= 1810)) {
        shopPositionsAll();
    }
    else if((frame > 1810) && (frame <= 1900)) {
        shopPosition11();
    }
    glPopMatrix();
    
    //Fixing heart in the shop
    glPushMatrix();
    if(frame >= 1900 && frame <= 1950){
        drawBrokenHeart();
        drawGlue1();
    } else if (frame > 1950 && frame <= 2000){
        drawBrokenHeart();
        drawGlue2();
    }else if (frame > 2000 && frame <= 2050){
        drawBrokenHeart();
        drawGlue3();
    }else if (frame > 2050 && frame <= 2100){
        drawBrokenHeart();
        drawGlue4();
    }else if (frame > 2100 && frame <= 2150){
        drawBrokenHeart();
        drawGlue5();
    }else if(frame > 2150 && frame <= 2200) {
        drawBrokenHeart();
        drawGlue6();
    } else if(frame > 2200 && frame <= 2250) {
        drawBrokenHeart();
        drawGlue7();
    }else if(frame > 2250 && frame <= 2300) {
        drawBrokenHeart();
        drawGlue8();
    } else if(frame > 2300 && frame <= 2350){
        drawBrokenHeart();
    } else if (frame > 2350 && frame <= 2400){
        XL_Heart();
    } else if (frame > 2400 && frame <= 2450){
        largeHeart();
    } else if (frame > 2450 && frame <= 2600){
        largeHeart();
        drawAllStars();
        drawGlue9();
        drawRAPID();
    }
    glPopMatrix();
    
    //men leaving from the shop happy with fixed heart ;)
    glPushMatrix();
    if ((frame >= 2600) && (frame <= 4000)){
        shopPosition4();
        
        if (frame % 50 < 25) { //walking pose1
            drawPose18();
            glutPostRedisplay();
        }
        else if (frame > 2800){ // stop behinde the scene
            drawPose19();
            glutPostRedisplay();
        }
        else {
            drawPose17(); //walking pose2
            glutPostRedisplay();
            }
        }
        glPopMatrix();
    
    //Morphing smile
    glPushMatrix();
    glTranslatef(345, -100, 0);
    int i2;
    if ((frame>2800) && (frame<4000))
    {
        glColor3f(0.0,0.0,0.0);
        tween2(neutralMouthArray,happyMouthArray,10,proportion,tweenSmille);
        
        glBegin(GL_LINE_LOOP);
        for(i2=0;i2<10;i2++)
            glVertex2i (tweenSmille[i2][0],tweenSmille[i2][1]);    // Morphing neutral smile to happy smille.
        glEnd();
        
        proportion +=0.02;
        if(proportion >1.0) proportion =1.0;
    }
    glPopMatrix();
    
    //Also draw the star and the glue at the end
    if ((frame >= 2600) && (frame <=4000)){
        glClearColor(0.05, 0.45, 0.65, 0.0);
        glPushMatrix();
        glTranslated(200.0, 600.0, 0.0);
        drawAllStars2();
        drawGlue9();
        drawRAPID();
        glPopMatrix();
        
        //Draw fireworks in 2 diffrent possition
        if(frame % 800  < 400) {
        glPushMatrix();
        glTranslated(-300, 400, 0);
        glScaled(1.8, 1.8, 1.0);
        glTranslated(300, -400, 0);
        drawFirework();
            glPopMatrix();
        } else {
            glPushMatrix();
            glScaled(1.8, 1.8, 1.0);
            glTranslated(500, -100, 0);
            drawFirework();
            glPopMatrix();
        }
        
        //Draw stars on the sky
        glPushMatrix();
        drawAllStarsOnSky();
        glPopMatrix();
        
    }

    
    frame++;
    glFlush(); //end drawing
    
    glutSwapBuffers(); //double buffering
}

//main() function - is the entry point for execution of the program
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // turns on double buffereing
    glutInitWindowSize(900, 1200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Story of this life");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(20, Timer, 1);
    glutMainLoop();
    return 0;
}
