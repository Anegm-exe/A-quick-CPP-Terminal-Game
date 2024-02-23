#ifndef OBJECT
#define OBJECT

#include <iostream>

using namespace std;

class Object {
private:
    char type;

public:
    Object();

    Object(char type);

    virtual ~Object();

    char getType() const;

    void setType(char type);

    friend ostream& operator<<(ostream& os, const Object& obj);
};

#endif
