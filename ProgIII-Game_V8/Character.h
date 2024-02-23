#ifndef CHARACTER
#define CHARACTER
#include "Object.h"

using namespace std;

class Character : public Object {
private:
    int x;
    int y;
    int healthPoints;

public:
    Character();

    Character(char type, int x, int y, int healthPoints);

    virtual ~Character() = 0;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getHealthPoints() const;

    void setHealthPoints(int healthPoints);
};
#endif
