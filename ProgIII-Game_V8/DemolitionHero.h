#ifndef DEMOLITIONHERO
#define DEMOLITIONHERO
#include "Hero.h"

using namespace std;

class DemolitionHero : public Hero {
private:
    Gun* gun2;

public:
    DemolitionHero();

    DemolitionHero(char type, int x, int y, int healthPoints, Gun* weapon, Gun* gun2);

    ~DemolitionHero();

    Gun* getGun2() const;

    void setGun2(Gun* gun2);

    void useSpecial();

    void print(ostream& os) const override;
};

#endif
