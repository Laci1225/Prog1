/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
try{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "My window"};

    Lines grid;

    for (int i = 1; i < 9; ++i)
    {
    	grid.add(Point(0,i*100),Point(800,i*100));
    	grid.add(Point(i*100,0),Point(i*100,800));
    }
	win.attach(grid);

	Vector_ref<Rectangle> rect;

    for (int i = 0; i < 8; ++i)
    {
    rect.push_back(new Rectangle{Point{i*100,i*100},100, 100});
    rect[i].set_fill_color(Color::red);
    rect[i].set_color(Color::invisible);
    win.attach(rect[i]);
    }
    
    Vector_ref<Image> im;

    for (int i = 0; i < 3; ++i)
    {
    
        im.push_back(new Image({i*200,200+i*200}, "unnamed.jpg"));
        im[i].set_mask(Point(0,0),200,200);
        win.attach(im[i]);

    }

    Image ii(Point{100,0},"unnamed.jpg");
    ii.set_mask(Point(100,100),100,100);
    win.attach(ii);
    win.wait_for_button();
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if(i == j+1) {
                ii.move(200,0);
                win.wait_for_button();
            }
            else{
                ii.move(100,0);
                win.wait_for_button();
            }
        }
        if(i == 7)break;
        ii.move(-700,100);
        win.wait_for_button();       
    }
}
    catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "error\n";
        return 2;
    }
}
