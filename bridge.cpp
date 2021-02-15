#include <iostream>
using namespace std;
/**
 * The Implementation defines the interface for all implementation classes. It
 * doesn't have to match the Abstraction's interface. In fact, the two
 * interfaces can be entirely different. Typically the Implementation interface
 * provides only primitive operations, while the Abstraction defines higher-
 * level operations based on those primitives.
 */

class Implementation {
public:
    virtual ~Implementation() {}
    virtual void OperationImplementation() const = 0;
};

/**
 * Each Concrete Implementation corresponds to a specific platform and
 * implements the Implementation interface using that platform's API.
 */
class ConcreteImplementationA : public Implementation {
public:
    void OperationImplementation() const override {
        cout<< "ConcreteImplementationA"<<endl;
    }
};
class ConcreteImplementationB : public Implementation {
public:
    void OperationImplementation() const override {
        cout<< "ConcreteImplementationB"<<endl;
    }
};

/**
 * The Abstraction defines the interface for the "control" part of the two class
 * hierarchies. It maintains a reference to an object of the Implementation
 * hierarchy and delegates all of the real work to this object.
 */

class Abstraction {
    /**
     * @var Implementation
     */
protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation) : implementation_(implementation) {
    }

    virtual ~Abstraction() {
    }

    virtual void Operation() const {
        cout<< "Abstraction: Base operation with:\n"<<endl;
        this->implementation_->OperationImplementation();
    }
};
/**
 * You can extend the Abstraction without changing the Implementation classes.
 */
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {
    }
    void Operation() const override {
        cout<< "ExtendedAbstraction: Extended operation with:\n"<<endl;
        this->implementation_->OperationImplementation();
    }
};