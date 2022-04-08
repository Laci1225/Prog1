#include "../std_lib_facilities.h"
#include <fstream>

class Less_than {
    double v;
public:
    Less_than(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};

int main(){
	vector<double> vd;
	ifstream ifile {"valamimas.txt"};
	for(float f; ifile >> f;) vd.push_back(f);
	
	cout << "Vd elements:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}

	vector<int> vi(vd.size());
	copy(vd.begin(),vd.end(),vi.begin());

	float fdouble = 0;
	float fint = 0;
	cout << "\nvd and vi elements:\n";
	for (int i = 0; i < vi.size(); i++)
	{
		cout << "vd[i]: " << vd[i] << "\tvi[i]: " << vi[i] << endl;
		fdouble += vd[i];
		fint += vi[i];
	}
	cout << "Sum of vd: " << fdouble << endl;
	//cout << "Sum of vi: " << fint << endl;
	cout << "Difference between vd and vi: " << fdouble-fint << endl; 
	
	reverse(vd.begin(),vd.end());
	cout << "\nReversed Vd elements:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}
	sort(vd);
	cout << "\nSorted Vd elements:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}
	float mean_value = vd[vd.size()/2];
	cout << "\nMean value of vd is: " << mean_value << endl;

	vector<double> vd2(vd.size());
	
	/*copy_if(vd.begin(), vd.end(), vd2.begin(),
            [&](int e){return e < mean_value;});*/	
	
	auto b = find_if(vd.begin(),vd.end(),
			[&](int e){return e > mean_value;});
	
	copy(vd.begin(),b,vd2.begin());
	
	auto a = find(vd2.begin(), vd2.end(), 0);
	vd2.erase(a,vd2.end());
	for (int i = 0; i < vd2.size(); i++)
	{
		cout << vd2[i] << endl;
	}
}