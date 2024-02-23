#ifndef GHOSTMONSTER
#define GHOSTMONSTER
#include "Monster.h"

using namespace std;

class GhostMonster : public Monster {
private:
    bool isVisible;

public:
    GhostMonster();

    GhostMonster(char type, int x, int y, int healthPoints, string name, bool isVisible);

    ~GhostMonster();

    bool getIsVisible() const;

    void setIsVisible(bool isVisible);
};
#endif
