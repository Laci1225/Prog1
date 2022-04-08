#include "../std_lib_facilities.h"
#include "matrix.txt"
#include <complex>

int main(){
	cout << "sizeof(char) = "<< sizeof(char) << endl;
	cout << "sizeof(short) = "<< sizeof(short) << endl;
	cout << "sizeof(int) = "<< sizeof(int) << endl;
	cout << "sizeof(long) = "<< sizeof(long) << endl;
	cout << "sizeof(float) = "<< sizeof(float) << endl;
	cout << "sizeof(double) = "<< sizeof(double) << endl;
	cout << "sizeof(int*) = "<< sizeof(int*) << endl;
	cout << "sizeof(double*) = "<< sizeof(double*) << "\n\n";

	Numeric_lib::Matrix<int>a(10);
	Numeric_lib::Matrix<int>b(100);
	Numeric_lib::Matrix<double>c(10);
	Numeric_lib::Matrix<int,2>d(10,10);
	Numeric_lib::Matrix<int,3>e(10,10,10);
	cout << "sizeof(Matrix<int>a(10)) = "<< sizeof(a) << endl;
	cout << "sizeof(Matrix<int>b(100)) = "<< sizeof(b) << endl;
	cout << "sizeof(Matrix<double>c(10)) = "<< sizeof(c) << endl;
	cout << "sizeof(Matrix<int,2>d(10,10)) = "<< sizeof(d) << endl;
	cout << "sizeof(Matrix<int,3>e(10,10,10)) = "<< sizeof(e) << "\n\n";;

	cout << "Matrix<int>a(10) size = "<< a.size() << endl;
	cout << "Matrix<int>b(100) size = "<< b.size() << endl;
	cout << "Matrix<double>c(10) size = "<< c.size() << endl;
	cout << "Matrix<int,2>d(10,10) size = "<< d.size() << endl;
	cout << "Matrix<int,3>e(10,10,10) size = "<< e.size() << "\n\n";

	cout << "Type some integer: end it with \"0\"\n";
	vector<int> iv;
	// ha stringet kap kilövi az egészet bekérés szempontából
	for(int x; cin >> x && x != 0;){
		iv.push_back(x);
	}
	for (int i = 0; i < iv.size(); ++i)
	{
		if(iv[i] >= 0) cout << "Sqrt("<<iv[i]<<") = " << sqrt(iv[i]) << endl;
		else cout << iv[i]<< " has no sqare root." << endl;
	}
	cout << "\nType 10 floating-point number: \n";
	vector<double> fv;
	for(double i = 0; i < 10; ++i){
		float x;
		cin >> x;
		fv.push_back(x);
	}
	Numeric_lib::Matrix<double> mat(fv.size());
	for (int i = 0; i < fv.size(); ++i)
	{
		mat[i] = fv[i];
	}
	cout << "Matrix values: " << endl;
	for (int i = 0; i < mat.size(); ++i)
	{
		cout << mat[i] << endl;
	}
	cout << "Type an n*m multiplication table \n";
	
	int n,m;
	cout << "n m: "; cin >> n >> m;
	Numeric_lib::Matrix<int,2> multi(n,m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
				multi[i][j] = (i+1)*(j+1);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
				cout << multi[i][j] << '\t';
		}
		cout << endl<< endl << endl;
	}
	cout << "\nType 10 complex number: \n";
	//(x.y,x.y)
	Numeric_lib::Matrix<complex<double>> comp(10);
	for (int c = 0; c < comp.size(); c++)
	{
		cin >> comp[c];		
	}
	//mátrixnak nem begin() hanem data() tagja van
	cout << "Sum if complex: " << accumulate(comp.data(), comp.data() 
    	+ comp.size(),complex<double>{}) << '\n';
	cout << "\nType 2*3 integer to integer matrix: \n";
	Numeric_lib::Matrix<int,2> mm(2,3);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> mm[i][j];
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << mm[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}