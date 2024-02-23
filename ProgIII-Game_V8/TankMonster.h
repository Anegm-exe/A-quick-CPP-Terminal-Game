#ifndef TANKMONSTER
#define TANKMONSTER
#include "Monster.h"

using namespace std;

class TankMonster : public Monster {
private:
    int shield;

public:
    TankMonster();

    TankMonster(char type, int x, int y, int healthPoints, string name, int shield);

    ~TankMonster();

    int getShield() const;

    void setShield(int shield);
};
#endif
