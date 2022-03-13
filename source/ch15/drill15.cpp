/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x){ return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x){ return cos(x)+slope(x);}

int main()
{
try{
    using namespace Graph_lib;

    Simple_window win {Point{100,100}, 600, 600, "Function graphs"};
    Axis xa {Axis::x, {100,300},400,20,"1 == 20 pixel"};
    Axis ya {Axis::y, {300,500},400,20,"1 == 20 pixel"};
    xa.set_color(Color::red);
    ya.set_color(Color::red);

    constexpr int min = -10;
    constexpr int max = 11;
    const Point origo {300,300};
    constexpr int numofpts = 400;
    constexpr int xscale = 20;
    constexpr int yscale = 20;

    Function constant (one,min,max,origo,numofpts,xscale,yscale);
    Function linear (slope,min,max,origo,numofpts,xscale,yscale);
    Text lineartext(Point(100, 300-(-10*20/2)),"x/2");
    Function negyzetes (square,min,max,origo,numofpts,xscale,yscale);
    Function cosine (cos,min,max,origo,numofpts,xscale,yscale);
    cosine.set_color(Color::blue);  
    Function cosslope (sloping_cos,min,max,origo,numofpts,xscale,yscale);
    


    win.attach(cosslope);
    win.attach(cosine);
    win.attach(negyzetes);
    win.attach(lineartext);
    win.attach(linear);
    win.attach(constant);
    win.attach(xa);
    win.attach(ya);
    win.wait_for_button();
    return 0;
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Error\n";
    return 2;
}
}