#ifndef ITEM
#define ITEM
#include "Object.h"

using namespace std;

class Item : public Object {
public:
    Item(char type);

    ~Item();
};
#endif
