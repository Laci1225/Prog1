#include "../std_lib_facilities.h"
#include <map>

template<typename T>
void print(T v){
	for(auto& a : v)
		cout << a.first << ' ' << a.second << endl;
}
template<typename T1, typename T2>
istream& operator>>(istream& is, map<T1,T2> m){
	is >> m.fisrt >> m.second;
	return is;
}
int main(){
	map<string,int> msi;
	msi["Lecture"] = 21;
	msi["Hecture"] = 31;
	msi["Gecture"] = 41;
	msi["Tecture"] = 51;
	msi["Recture"] = 91;
	msi["Pecture"] = 71;
	msi["Vecture"] = 29;
	msi["Cecture"] = 23;
	msi["Necture"] = 33;
	msi["Mecture"] = 55;
	//msi.insert(pair<string, int>("www",444));
	print(msi);
	msi.erase(msi.begin(),msi.end());
	print(msi);
	cout << "\nBekért dolgok:\n";
	/*for(string s, ii; cin >> s >> ii && s != "q" || ii != "q";)
		msi[s] = stoi(ii);*/
	for (int i = 0; i < 10; i++)
	{
		string s; int ii;
		cin >> s >> ii;
		msi[s] = ii;
	}
	cout << "\nBekért kiíratása:\n";
	print(msi);
	int sum = 0;
	for(auto& a : msi)
		sum +=  a.second;
	cout << "Sum: " << sum << endl;

	map<int,string> mis;

	for (const auto& a : msi)
        mis[a.second] = a.first;
    cout << "\nmegfordított map:\n";
    print(mis);
}