#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

	using namespace std;

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>()&& Output_iterator<Iter2>()
Iter2 iter_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for (Iter1 p = f1; p != e1; p++)
        {
        	*f2 = *p;
        	f2++;
        }
    return f2;
}

template<typename T>
void increase(T& t,double cc){
	for(auto& a : t)
		a += cc;
}
template<typename T>
void print(T& t){
	for(auto& a : t)
		cout << a << ' ';
	cout << endl;
}

int main(){


	int a[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> b {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> c {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	int aa[10];
	for (int i = 0; i < 10; ++i) aa[i] = a[i];
	vector<int> bb = b;
	list<int> cc = c; 

	/*for (int i = 0; i < 10; ++i) aa[i] +=2;
	for (int i = 0; i < bb.size(); ++i) bb[i] +=3;
	for (auto& a : cc) a +=5;*/
	increase(aa,2); increase(bb,3); increase(cc,5);

	print(aa); print(bb); print(cc);

	iter_copy(aa,aa+10, bb.begin());
	iter_copy(cc.begin(),cc.end(),aa);

	cout << "\n\n";
	print(aa); print(bb);


	auto /*vector<int>::iterator*/ p = find(bb.begin(), bb.end(), 3);
	if(p != bb.end()) cout << "Placed on: " << distance(bb.begin(), p) << endl;
	else cout << "we didnt find it" << endl;

	list<int>::iterator p2 = find(cc.begin(), cc.end(), 27);
	if(p2 != cc.end()) cout << "Placed on: " << distance(cc.begin(), p2) << endl;
	else cout << "we didnt find it" << endl;
	return 0;
}