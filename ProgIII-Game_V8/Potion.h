#ifndef POTION
#define POTION
#include "Item.h"

using namespace std;

class Potion : public Item {
private:
    int healingValue;
public:
    Potion();

    Potion(int healingValue);

    ~Potion();

    int getHealingValue() const;

    void setHealingValue(int healingValue);
};
#endif
