/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   postscript.h
 * Author: Class2018
 *
 * Created on March 24, 2018, 7:45 PM
 */

#ifndef POSTSCRIPT_H
#define POSTSCRIPT_H
#include <fstream>

class Postscript{
private:
    char *fileName;
    std::ofstream drawHere;
public:
    Postscript(char *c);
    void line(int x, int y, int x2, int y2);
    void setColor (int r, int g, int b);
    void drawRect (int x, int y, int w, int h);
    void fillRect(int x, int y, int w, int h);
    void setFillColor(double r, double g, double b);
    void setStrokeColor(double r, double g, double b);
    void drawTriangle (int x1, int y1, int x2, int y2, int x3, int y3);
    void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void drawCircle(int x, int y, int r);
    void fillCircle(int x, int y, int r);
    void text (int x, int y, std::string text);
    void grid(int xStart, int xStep, int xEnd, int yStart, int yStep, int yEnd);
};

#endif /* POSTSCRIPT_H */
