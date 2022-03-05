#include "../std_lib_facilities.h"

class B1 {
public:
	virtual void vf() { cout << "B1::vf() \n"; }
	void f() { cout << "B1::f() \n"; }
	virtual void pvf()=0;
};

class D1 : public B1 {
public:
	void vf() override { cout << "D1::vf() \n"; }
	void f() { cout << "D1::f() \n"; }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf() \n"; }
};

class B2 {
public: 
	virtual void pvf()=0;
};

class D21 : public B2 {
public:
	string data = "D21::pvf()";
	void pvf() override { cout << data << '\n'; }
};

class D22 : public D21 {
public:
	int data = 21;
	void pvf() override {cout << 21 << '\n'; }
};

void f(B2& b2){
	b2.pvf();
}

void call(B1& b1)
	{
	b1.vf();b1.f();
}
int main(){
	// 1
/*	B1 b; 
	b.vf(); //B1::vf()
	b.f();  //B1::f()
	cout << '\n';
	// 2
	D1 d1; 
	d1.vf(); //D1::vf()
	d1.f();  //B1::f() f() nélkül
	cout << '\n';
	// 3
	D1 d2; 
	call(d2); //D1::vf(), B1::f()
	// 4
	d2.f(); //D1::f() f() használatával többi ugyanaz
	// 5
	// cannot declare variable ‘b’ to be of abstract type ‘B1’ B1 b;
*/
	// 6
	//B1 b1; call(b1); error abstract 
	//D1 d1; call(d1); error abstract 
	D2 d2; 
	d2.vf();  //D1::vf()
	d2.f();	  //D1::f()
	d2.pvf(); //D2::pvf()
	call(d2); //D1::vf(), B1::f()
	//7
	D21 d21; f(d21); //D21::pvf()
	D22 d22; f(d22); //21
}