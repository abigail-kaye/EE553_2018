#include <cstdlib>
#include <iostream>
#include "Postscript.h"
using namespace std;


int main(int argc, char** argv) {
    Postscript p ("test.txt");
    p.line(0,0,100,100);
    int r = 255, g = 0, b = 0;
    p.setColor(r, g, b);
    p.drawRect(0,0,100,100);
    p.setFillColor(0, 1, 0); // 1 0 0 setrgbcolor
    p.fillRect(150,150,100,100);// x y moveto x+w y lineto x+w y+ lineto closepath fill
    
    p.setStrokeColor(0, 0.5, 0.5);
    p.drawTriangle(300, 300, 500, 300, 400, 500);
    
    p.setStrokeColor(1,1,1);
    p.drawCircle(400,350,100); //x y 0 360 r arc stroke
    p.text(200,600,"Testing"); //look it up setfont (ABC) show
    
    p.grid(300, 50, 500, 400, 50, 700);
    return 0;
}



