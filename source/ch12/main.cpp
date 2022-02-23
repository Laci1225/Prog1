#include "../Graph.h"
#include "../Simple_window.h"
//#include "../std_lib_facilities.h"
	
int main () {
	try
	{
	Simple_window win {Point{100,100}, 600,400, "My window"};


		Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
		xa.set_color(Color::white);
		win.attach(xa);
		win.set_label("Canvas else");
		win.wait_for_button();

		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
		ya.set_color(Color::blue);
		ya.label.set_color(Color::yellow); 
		win.attach(ya);
		win.set_label("Canvas #3");
		win.wait_for_button();

		Function sine {sin,0,25,Point{20,300},1000,20,20};
		win.attach(sine);
		win.set_label("Canvas #4");
		win.wait_for_button();
		sine.set_color(Color::red);
		

		Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::dark_red);
		poly.set_style(Line_style::solid);
		win.attach(poly);
		win.set_label("Canvas #5");
		win.wait_for_button();

		Rectangle r {Point{350,200}, 100, 50};
		win.attach(r);
		r.set_style(Line_style(Line_style::dash));
		win.set_label("Canvas #6");
		win.wait_for_button();

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		poly_rect.set_color(Color::green);
		win.attach(poly_rect);
		win.wait_for_button();
		poly_rect.add(Point{50,75});
		win.wait_for_button();

		r.set_fill_color(Color::red);
		poly.set_style(Line_style(Line_style::dash,3));
		poly_rect.set_style(Line_style(Line_style::dash,5));
		poly_rect.set_fill_color(Color::cyan);
		win.set_label("Canvas #7");
		win.wait_for_button();

		Text t {Point{10,150}, "Hello, graphical world!"};
		win.attach(t);
		t.set_font(Font::times);
		t.set_font_size(40);
		win.set_label("Canvas #8");
		win.wait_for_button();

		t.set_font(Font::times_bold);
		t.set_font_size(20);
		win.set_label("Canvas #9");
		win.wait_for_button();

		Image ii {Point{100,50},"unnamed.jpg"};
		ii.set_mask(Point{200,200},200,200);
		win.attach(ii);
		win.set_label("Canvas #10");
		win.wait_for_button();

		ii.move(100,100);
		win.set_label("Canvas #11");
		win.wait_for_button();

		Circle c {Point{100,200},50};

		Ellipse e {Point{100,200}, 75,25};
		e.set_color(Color::dark_red);

		Mark m {Point{100,200},'x'};

		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};

		Image cal {Point{225,225},"badge.jpg"};
		cal.set_mask(Point{40,40},200,150);

		win.attach(c);
		win.attach(m);
		win.attach(e);
		win.attach(sizes);
		win.attach(cal);
		win.set_label("Canvas #12");
		win.wait_for_button();

	}

	catch(exception& e) {
		cerr << e.what() << '\n';
		return 1;
	}
	catch(...) {
		cerr << "Some error";
		return 2;
	}
}
