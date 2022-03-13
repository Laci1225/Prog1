/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../std_lib_facilities.h"

const string inval(";:\"'[]*&^%$#@!");

struct Person{
    //class Invalid{};
    Person() {}
    Person(string s,string ss, int i) : firstn(s),secondn(ss), a(i) 
    {valid();/*if(!valid()) throw Invalid{};*/}
    void valid();
    string fname() const {return firstn;}
    string sname() const {return secondn;}
    int age() const {return a;}
    
    
private:
    string firstn;
    string secondn;
    int a;
};
void Person::valid(){
    if(a<0 || a > 150) { error("Invalid age\n");}//return false;}
        
    for(int i= 0; i < inval.size(); i++){
        for(int j = 0; j < firstn.size(); j++){
            if(inval[i] == firstn[j]) {error("Invalid first name\n");}//return false;}
        }
    }
    for(int i= 0; i < inval.size(); i++){
        for(int j = 0; j < secondn.size(); j++){
            if(inval[i] == secondn[j]) {error("Invalid second name\n");}//return false;}
        }
    }
    //return true ;
}
ostream& operator<<(ostream& os, Person p){
    os << p.fname() <<' ' << p.sname() << ' ' << p.age() << endl;
    return os;
}
istream& operator>>(istream& is, Person& p){
    string s; string ss;int i;
    is >> s >> ss >> i;
    p = Person{s,ss,i};
    return is;
}

int main()
{  
try{ 
    Vector<Person> pers;
    Person p;
    p = Person("Goofy","Goofy",  63);
    cout << p;
    /*p.name() = "Goofy";
    p.age() = 63;
    cout << p.name() <<' '<< p.age() << endl;
    cout << p;*/
    cout<< "Enter a full name and an age:\n";
    cin >> p;
    cout<< p;
    cout<< "Enter as many name and age as you want, terminate with \"end\"\n";
    for(Person pp;cin >> pp;){
        if(pp.fname() == "end") break;
        pers.push_back(pp);
    };
    
    for(int i = 0; i < pers.size(); i++){
        cout << pers[i];    
    }
    
    
    return 0;
    }
    /*catch(Person::Invalid){
        cerr << "Invalid name/age";
        return 1;
    }*/
    catch(exception& e){
        cerr << e.what();
        return 1;
    }
    catch(...){
        cerr << "Some error";
        return 2;
    }
}