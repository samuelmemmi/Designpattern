#include <iostream>
using namespace std;

class Component {
public:
    virtual void operation() {};
};

class ConcreteCompA : public Component {
    void operation() override {
        cout << "ConcCompA" << endl;
    }
};

class ConcreteCompB : public Component {
    void operation() override {
        cout << "ConcCompB" << endl;
    }
};

class Decorator : public Component {
public:
    Component *c;
    Decorator(Component *com) {
        this->c = com;
    }
};

class ConDecoratorA : public Decorator {
public:
    ConDecoratorA(Component* c): Decorator(c){};
    void operation() override {
        this->c->operation();
        cout << "ConDecA" << endl;
    }
};

class ConDecoratorB : public Decorator {
public:
    ConDecoratorB(Component* c): Decorator(c){};
    void operation() override {
        this->c->operation();
        cout << "ConDecB" << endl;
    }
};

//int main() {
//    Component* c = new ConDecA(new ConDecB(new ConcCompA));
//    Component* c1 = new ConDecB(new ConDecA(new ConcCompB));
//
//    c->print();
//    c1->print();
//
//    return 0;
//}