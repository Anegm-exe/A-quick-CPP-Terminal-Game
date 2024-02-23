#ifndef CHARACTERCLASS_H_INCLUDED
#define CHARACTERCLASS_H_INCLUDED
#include "Object.h"

using namespace std;

class Character : public Object {
private:
    int x;
    int y;
    int healthPoints;

public:
    Character();

    Character(int x, int y, int healthPoints);

    ~Character();

    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    int getHealthPoints();

    void setHealthPoints(int healthPoints);
};
#endif
