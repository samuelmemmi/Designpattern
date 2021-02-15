#include <iostream>
using namespace std;
/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
public:
    //virtual ~Target() = default;
    virtual void Request() const {
        cout<< "Target" <<endl;
    }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
public:
    void SpecificRequest() const {
        cout<< "specific request" <<endl;
    }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
private:
    Adaptee *adaptee_;
public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    void Request() const override {
        cout << "req override" <<endl;
        this->adaptee_->SpecificRequest();
    }
};

//int main(){
//    Target* t = new Adapter(new Adaptee);
//    t->Req();
//    return 0;
//}