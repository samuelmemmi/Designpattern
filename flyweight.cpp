#include <iostream>
using namespace std;
#include <map>

class Character {
public:
    int col, row;
    string type;
    string condition;

    Character(string s, int x, int y, string condition) {
        this->type = s;
        this->row = x;
        this->col = y;
        this->condition = condition;
    }

    virtual void print() {};

    void changeCon(string condition) {
        this->condition = condition;
    }
};

class Terrorist : public Character {
public:
    Terrorist(int x, int y, string s) : Character("Terrorist", x, y, s) {};

    void print() override {
        cout << "Terrorist in" << this->col << this->row << endl;
    }
};

class CounterTerrorist : public Character {
public:
    CounterTerrorist(int x, int y, string s) : Character("Counter Terrorist", x, y, s) {};

    void print() override {
        cout << "Counter Terrorist in" << this->col << this->row << endl;
    }
};

class Flyweight_Factory {
public:
    static Character *
    getFly(string type, int x, int y, string condition, map<string, Character *> &FlyweightMap) {
        auto c = FlyweightMap.find(type);
        if (c != FlyweightMap.end() && c->second->condition == condition) {
            c->second->row = x;
            c->second->col = y;
            return FlyweightMap.find(type)->second;
        } else {
            if (type == "Terrorist") {
                pair<string, Character *> p(type, new Terrorist(x, y, condition));
                FlyweightMap.insert(p);
                return FlyweightMap.find(type)->second;
            } else if (type == "Counter Terrorist") {
                pair<std::string, Character *> p(type, new CounterTerrorist(x, y, condition));
                FlyweightMap.insert(p);
                return FlyweightMap.find(type)->second;
            }
        }
    }
};

//
//int main() {
//    map<string, Character *> FlyweightMap;
//    Character *c1 = Flyweight_Factory::getFly("Counter Terrorist", 10, 10, "alive", FlyweightMap);
//    cout << c1->type << "-" << c1->condition << "-" << c1->col << "-" << c1->row << endl;
//    Character *c2 = Flyweight_Factory::getFly("Counter Terrorist", 15, 12, "alive", FlyweightMap);
//    cout << c2->type << "-" << c2->condition << "-" << c2->col << "-" << c2->row << endl;
//
//    Character *t1 = Flyweight_Factory::getFly("Terrorist", 20, 10, "alive", FlyweightMap);
//    cout << t1->type << "-" << t1->condition << "-" << t1->col << "-" << t1->row << endl;
//    Character *t2 = Flyweight_Factory::getFly("Terrorist", 10, 20, "alive", FlyweightMap);
//    cout << t2->type << "-" << t2->condition << "-" << t2->col << "-" << t2->row << endl;
//
//    cout << c1 << "-" << c2 << endl;
//    cout << t1 << "-" << t2 << endl;
//
//
//    return 0;
//}