#ifndef GUN
#define GUN
#include "Object.h"
#include <iostream>

class Hero;

using namespace std;

class Gun : public Object {
private:
    string name;
    int bullets;
    int damageAmount;
    int range;

public:
    Gun();

    Gun(string name, int bullets, int damageAmount, int range, char type);

    ~Gun();

    string getName() const;

    void setName(string name);

    int getBullets() const;

    void setBullets(int bullets);

    int getDamageAmount() const;

    void setDamageAmount(int damageAmount);

    int getRange() const;

    void setRange(int range);

    virtual void useSpecial(Hero& h1, Object*** map) = 0;

    friend ostream& operator<<(ostream& os, const Gun& gun);
};

#endif
