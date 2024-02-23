#ifndef RIFLE
#define RIFLE
#include "Gun.h"

using namespace std;

class Rifle : public Gun {
public:
    Rifle();

    void useSpecial(Hero& h1, Object*** map);

    ~Rifle();
};

#endif
