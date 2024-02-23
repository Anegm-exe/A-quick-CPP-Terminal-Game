#ifndef MEDICHERO
#define MEDICHERO
#include "Hero.h"

using namespace std;

class MedicHero : public Hero {
private:
    int healingAmount;
    bool hasHealed = false;

public:
    MedicHero();

    MedicHero(char type, int x, int y, int healthPoints, Gun* weapon, int healingAmount);

    ~MedicHero();

    int getHealingAmount() const;

    void setHealingAmount(int healingAmount);

    bool getHasHealed() const;

    void setHasHealed(bool hasHealed);

    void useSpecial();

    void print(ostream& os) const override;
};

#endif
