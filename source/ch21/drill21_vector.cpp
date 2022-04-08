#include "../std_lib_facilities.h"
#include <list>

struct Item { 
	string name; 
	int iid; 
	double value;

};
istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	Item {it.name,it.iid,it.value};
	return is;
}
struct sort_by_name{
	bool operator()(Item& it1, Item& it2)
			{ return it1.name < it2.name;}
};
struct sort_by_iid{
	bool operator()(Item& it1, Item& it2)
			{ return it1.iid < it2.iid;}
};
struct sort_by_value_desc{
	bool operator()(Item& it1, Item& it2)
			{ return it1.value > it2.value;}
};
struct remove_by_name{
	string name;
public:
	remove_by_name(const string& na) : name(na) {}
	bool operator()(Item& it1){
		{return it1.name == name;}
	}
};
struct remove_by_iid{
	int iid;
public:
	remove_by_iid(const int& id) : iid(id) {}
	bool operator()(Item& it1){
		{return it1.iid == iid;}
	}
};
template<typename T>
void print(T v){
	for(auto& a : v)
		cout << a.name << ' ' << a.iid << ' ' << a.value << endl;
}

int main(){
	vector<Item> vi;
	//Item it;
	ifstream ifile {"valami.txt"};
	for(Item it; ifile >> it;){//while(ifile >> it.name >> it.iid >> it.value){
		vi.push_back(it);//Item {it.name,it.iid,it.value});
	}
	cout << "Before sort:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_by_name());
		//[](Item& f1, Item& f2){return f1.name < f2.name;});
	cout << "\nAfter sort by name:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_by_iid());
	cout << "\nAfter sort by iid:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_by_value_desc());
	cout << "\nAfter sort by value (desc):\n";
	print(vi);

	vi.push_back(Item {"horse shoe",99,12.34}); 
	vi.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nAfter added 2 rows:\n";
	print(vi);

	/*vi.erase(find_if(vi.begin(),vi.end(),remove_by_name("Elemér")));
	vi.erase(find_if(vi.begin(),vi.end(),remove_by_name("Tamás")));*/
	//ez nem biztonságos mert kitörli az utolsót ha nem találta meg
	const auto& a = find_if(vi.begin(),vi.end(),remove_by_name("Elemér"));
	if(a != vi.end()) vi.erase(a);
	const auto& b = find_if(vi.begin(),vi.end(),remove_by_name("Tamás"));
	if(b != vi.end()) vi.erase(b); 
	cout << "\nAfter erased 2 rows by name:\n";
	print(vi);
	//ellenőrzés nélkül ugyanazt (már nem létezőt)
	// törölve segmentation fault

	const auto& aa = find_if(vi.begin(),vi.end(),remove_by_iid(22));
	if(aa != vi.end()) vi.erase(aa);
	const auto& bb = find_if(vi.begin(),vi.end(),remove_by_iid(10));
	if(bb != vi.end()) vi.erase(bb);
	cout << "\nAfter erased 2 rows by iid:\n";
	print(vi);

	//ellenőrzés hogy tényleg nem töröl e mást
	const auto& aaa = find_if(vi.begin(),vi.end(),remove_by_iid(22));
	if(aaa != vi.end()) vi.erase(aaa);
	const auto& bbb = find_if(vi.begin(),vi.end(),remove_by_iid(10));
	if(bbb != vi.end()) vi.erase(bbb);
	cout << "\nAfter erased 2 rows by iid (the same):\n";
	print(vi);

	ifile.close();
	list<Item> li;
	ifile.open("valami.txt");
	for(Item it; ifile >> it;) li.push_back(it);
	cout << "\nBefore sort: list\n";
	print(li);

	li.sort(sort_by_name());
	cout << "\nAfter sort by name: list\n";
	print(li);

	li.sort(sort_by_iid());
	cout << "\nAfter sort by iid: list\n";
	print(li);

	li.sort(sort_by_value_desc());
	cout << "\nAfter sort by value (desc): list\n";
	print(li);

	li.push_back(Item {"horse shoe",99,12.34}); 
	li.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nAfter added 2 rows: list\n";
	print(li);
	
	//li.erase(find_if(li.begin(),li.end(),remove_by_name("Elemér")));
	//li.erase(find_if(li.begin(),li.end(),remove_by_name("Tamás")));
	const auto& al = find_if(li.begin(),li.end(),remove_by_name("Elemér"));
	if(al != li.end()) li.erase(al);
	const auto& bl = find_if(li.begin(),li.end(),remove_by_name("Tamás"));
	if(bl != li.end()) li.erase(bl);
	cout << "\nAfter erased 2 rows by name: list\n";
	print(li);

	const auto& all = find_if(li.begin(),li.end(),remove_by_iid(22));
	if(all != li.end()) li.erase(all);
	const auto& bll = find_if(li.begin(),li.end(),remove_by_iid(10));
	if(bll != li.end()) li.erase(bll);
	cout << "\nAfter erased 2 rows by iid: list\n";
	print(vi);

}