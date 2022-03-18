#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	
	Open_polyline lines;
	Menu color_menu;

	Button menu_button;
	/*static void cb_red(Address, Address);
	/*static void cb_blue(Address, Address);
	static void cb_black(Address, Address);*/
	static void cb_menu(Address, Address pw);
	/*static void cb_next(Address, Address);
	static void cb_quit(Address, Address);*/
	 
	static void cb_lsmenu(Address, Address pw) {reference_to<Lines_window>(pw).lsmenu_pressed();}

	void hide_menu() { color_menu.hide(); menu_button.show(); }
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void change(Color c) { lines.set_color(c); }

	Menu linestyle_menu;
	Button linestyle_button;
	void hide_lsmenu() { linestyle_menu.hide(); linestyle_button.show(); }
	void solid_pressed() {changels(Line_style::solid);hide_lsmenu();}
	void dash_pressed() {changels(Line_style::dash);hide_lsmenu();}
	void dot_pressed() {changels(Line_style::dot);hide_lsmenu();}
	void dashdot_pressed() {changels(Line_style::dashdot);hide_lsmenu();}
	void dashdotdot_pressed() {changels(Line_style::dashdotdot);hide_lsmenu();}
	void lsmenu_pressed() { linestyle_button.hide(); linestyle_menu.show(); }
	void changels(Line_style ls) { lines.set_style(ls);}
 
	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};