#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class Compenent {
public:
    string id;
    list<Compenent *> compList;

    Compenent(string s) {
        this->id = s;
    }

    virtual void operation() {};

    void Add(Compenent *c) {
        compList.push_back(c);
    };

    void Remove(Compenent *c) {
        compList.remove(c);
    };

    virtual void GetChild() {};
};

class Leaf : public Compenent {
public:
    Leaf(string s) : Compenent(s) {};

    void operation() override {
        cout << "Leaf" << endl;
    }

    void GetChild() override {
        cout << this->id << endl;
    }

};

class Composite : public Compenent {
public:
    Composite(string s) : Compenent(s) {};

    void operation() override {
        cout << "Composite" << endl;
    }

    void GetChild(){
        for (auto c : this->compList){
            cout << this->id << endl;
            c->GetChild();
        }
    }

};

//int main() {
//    Compenent *c = new Composite("c");
//    Compenent *c1 = new Composite("c1");
//    Compenent *c2 = new Composite("c2");
//    Compenent *l = new Leaf("l");
//    Compenent *l1 = new Leaf("l1");
//    Compenent *l2 = new Leaf("l2");
//
//    c->Add(c1);
//    c->Add(c2);
//    c->Add(l);
//    c2->Add(l2);
//    c1->Add(l1);
//
//    c->GetChild();
//    return 0;
//};