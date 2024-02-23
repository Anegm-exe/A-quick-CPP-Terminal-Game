#ifndef HERO
#define HERO
#include "Character.h"
#include "Gun.h"
#include "Potion.h"
#include "Monster.h"

using namespace std;

class Hero : public Character {
private:
    Gun* gun;

public:
    Hero();

    Hero(char type, int x, int y, int healthPoints, Gun* gun);

    virtual ~Hero() =0;

    Gun* getGun() const;

    void setGun(Gun* gun);

    virtual void useSpecial() = 0;

    virtual void print(ostream& os) const;

    friend ostream& operator<<(ostream& os, Hero& hero);

    friend Hero& operator+(Hero& hero, const Ammo& ammo);

    friend Hero& operator+(Hero& hero, const Potion& potion);

    friend Hero& operator-(Hero& hero, Monster& monster);
};

#endif
