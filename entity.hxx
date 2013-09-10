#ifndef _ENTITY_HXX_
#define _ENTITY_HXX_
#include <string>

class entity
{
private:
    int x;
    int y;
    std::string name;
public:
    entity(std::string n, int xx, int yy) : name(n), x(xx), y(yy)
    {

    }
    ~entity() {}
    void setLocation(int xx, int yy) { x = xx; y = yy; }
    std::string getName() { return name; }
    int getX() {return x; }
    int getY() {return y; }

};
#endif // _ENTITY_HXX_
