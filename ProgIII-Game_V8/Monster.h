#ifndef MONSTER
#define MONSTER
#include "Character.h"

using namespace std;

class Monster : public Character {
private:
    string name;

public:
    Monster();

    Monster(char type, int x, int y, int healthPoints, string name);

    virtual ~Monster();

    string getName() const;

    void setName(string name);
};

#endif
