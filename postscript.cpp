#include <cstdlib>
#include <string>
#include "Postscript.h"
#include <fstream>
using namespace std;


    Postscript::Postscript(char *s) : fileName(s){}
 
    //Set color given 0 - 255 value
    void Postscript::setColor(int r, int g, int b){
        setStrokeColor(r/255,g/255,b/255);
    }
    

    //Set color using 0 - 1 value
    void Postscript::setStrokeColor(double r, double g, double b){
        drawHere.open(fileName,ofstream::app);
        drawHere << r << " " << g << " " << b << " setrgbcolor" << '\r' << '\n';
        drawHere.close();
    }
    
    //Set color using 0 - 1 value
    void Postscript::setFillColor(double r, double g, double b){
        setStrokeColor(r,g,b);
    }
    
    //Draw line from (x,y) to (x1,y2)
     void Postscript::line (int x, int y, int x1, int y2){
        drawHere.open(fileName,ofstream::app);
        drawHere << x << " " << y << " moveto" << '\r' << '\n';
        drawHere << x1 << " " << y2 << " lineto" << '\r' <<'\n';
        drawHere << "stroke" << '\r' << '\n';
        drawHere.close();
    }
     
    //Stroke or fill shape
    void fillType (bool stroke, ofstream& drawHere){
         if (stroke == true)
            drawHere << "stroke" << '\r' << '\n';
        else
            drawHere << "fill" << '\r' << '\n';  
    }
    
    //Rectangle shape
    void rectHelper(int x, int y, int w, int h, bool stroke, ofstream& drawHere){
        drawHere << x << " " << y << " moveto" << '\r' << '\n';
        drawHere << x+w << " " << y << " lineto" << '\r' << '\n';
        drawHere << x+w << " " << y+h << " lineto" << '\r' << '\n';
        drawHere << x << " " << y+h << " lineto" << '\r' << '\n';
        drawHere << "closepath" << '\r' << '\n';
        fillType(stroke,drawHere);
    }
    
    //Rectangle outline
    void Postscript::drawRect(int x, int y, int w, int h){
        drawHere.open(fileName,ofstream::app);
        rectHelper(x, y, w, h, true, drawHere);
        drawHere.close();
    }
    
    //Rectangle fill
    void Postscript::fillRect(int x, int y, int w, int h){
        drawHere.open(fileName,ofstream::app);
        rectHelper(x, y, w, h, false, drawHere);
        drawHere.close();
    }
    
    //Triangle shape
    void triangleHelper(int x1, int y1, int x2, int y2, int x3, int y3, bool stroke, ofstream& drawHere){
        drawHere << x1 << " " << y1 << " moveto" << '\r' << '\n';
        drawHere << x2 << " " << y2 << " lineto" << '\r' << '\n';
        drawHere << x3 << " " << y3 << " lineto" << '\r' << '\n';
        drawHere << "closepath" << '\r' << '\n';
        fillType(stroke,drawHere);
    }
    
    //Triangle outline
    void Postscript::drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
        drawHere.open(fileName,ofstream::app);
        triangleHelper(x1, y1, x2, y2, x3, x3, true, drawHere);
        drawHere.close();
    }
    
    //Triangle fill
    void Postscript::fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
        drawHere.open(fileName,ofstream::app);
        triangleHelper(x1, y1, x2, y2, x3, y3, false, drawHere);
        drawHere.close();
    }
    
    //Circle shape
    void circleHelper(int x, int y, int r, bool stroke, ofstream& drawHere){
        drawHere << x << " " << y << " " << r << "0 360 arc closepath" << '\r' << '\n';
        fillType(stroke,drawHere);
    }
    
    //Circle outline
    void Postscript::drawCircle(int x, int y, int r){
        drawHere.open("test.txt",ofstream::app);
        circleHelper(x, y,r, true, drawHere);
        drawHere.close();
    }
    
    //Circle fill
    void Postscript::fillCircle(int x, int y, int r){
        drawHere.open(fileName,ofstream::app);
        circleHelper(x, y,r, false, drawHere);
        drawHere.close();
    }
    
    //Write text in Time New Roman 
    void Postscript::text(int x, int y, string s){
        drawHere.open(fileName,ofstream::app);
        drawHere << "/Times-Roman findfont" << '\r' << '\n';
        drawHere << "20 scalefont" << '\r' << '\n';
        drawHere << "setfont" << '\r' << '\n';
        drawHere << "newpath" << '\r' << '\n';
        drawHere << x << " " << y << " moveto" << '\r' << '\n';
        drawHere << "(" << s << ") show" << '\r' << '\n';
        drawHere.close();
    }
     
    //Draw grid from xStart to xEnd (with xStep space in between); yStart to yEnd (with yStep in between)
    void Postscript::grid(int xStart, int xStep, int xEnd, int yStart, int yStep, int yEnd){
        drawHere.open(fileName,ofstream::app);
        
        //Draw horizontal lines
        for (int i = 0; i<=((yEnd-yStart)/yStep); i++){
            drawHere << xStart << " " << yStart + (xStep * i)<< " moveto" << '\r' << '\n';
            drawHere << xEnd << " " << yStart + (xStep * i) << " lineto" << '\r' << '\n';
        }
        
        //Draw vertical lines
        for (int j = 0; j<=((xEnd-xStart)/xStep); j++){
            drawHere << xStart + (yStep * j) << " " << yStart << " moveto" << '\r' << '\n';
            drawHere << xStart + (yStep * j) << " " << yEnd << " lineto" << '\r' << '\n';
        }
        drawHere << "stroke" << '\r' << '\n';
        drawHere.close();
    }