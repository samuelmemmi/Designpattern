#include <iostream>
using namespace std;
#include <vector>

class Level {
public:
    string Platform;
    string Character;
    string Enemy;
};

class MarioLevel : public Level {
};

class LevelBuilder {
public:
    virtual void setPlatform(string plat) {};

    virtual void setCharacter(string Char) {};

    virtual void setEnemy(string Enemy) {};

    virtual Level *getLevel() {};
};

class MarioBuilder : public LevelBuilder {
public:
    MarioLevel *level;

    MarioBuilder() {
        this->level = new MarioLevel();
    }

    void setPlatform(string plat) override {
        this->level->Platform = plat;
        cout << plat << endl;

    };

    void setCharacter(std::string Char) override {
        this->level->Character = Char;
        cout << Char << endl;
    };

    void setEnemy(std::string Enemy) override {
        this->level->Enemy = Enemy;
        cout << Enemy << endl;
    };

    Level *getLevel() override {
        return this->level;
    };
};

class LevelDirector {
public:
    virtual void construct(LevelBuilder *builder) {};
};

class BossLevelDirector : public LevelDirector {
public:
    void construct(LevelBuilder *builder) override {
        cout << "Boss Level Created" << endl;
        builder->setPlatform("Mario Platform");
        builder->setCharacter("Mario Character");
        builder->setEnemy("Boss");
    }
};

//int main() {
//    LevelBuilder *MarioBuild = new MarioBuilder();
//    LevelDirector *BossLev = new BossLevel();
//    BossLev->construct(MarioBuild);
//    Level *l = MarioBuild->getLevel();
//    return 0;
//};