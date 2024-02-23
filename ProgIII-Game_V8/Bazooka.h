#ifndef BAZOOKA
#define BAZOOKA
#include "Gun.h"
#include "Game.h"

using namespace std;

class Bazooka : public Gun {
public:
    Bazooka();

    void useSpecial(Hero& h1, Object*** map);

    ~Bazooka();
};

#endif
