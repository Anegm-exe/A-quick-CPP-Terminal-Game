#ifndef AMMO
#define AMMO
#include "Item.h"

using namespace std;

class Ammo : public Item {
private:
    int bulletsNumber;

public:
    Ammo();

    Ammo(int bulletsNumber);

    ~Ammo();

    int getBulletsNumber() const;

    void setBulletsNumber(int bulletsNumber);
};

#endif
