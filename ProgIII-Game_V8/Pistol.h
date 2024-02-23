#ifndef PISTOL
#define PISTOL
#include "Gun.h"

using namespace std;

class Pistol : public Gun {
public:
    Pistol();

    void useSpecial(Hero& h1, Object*** map);

    ~Pistol();
};
#endif
