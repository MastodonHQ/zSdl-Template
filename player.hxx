#ifndef _PLAYER_HXX_
#define _PLAYER_HXX_
#include "entity.hxx"
#include <string>

class player : public entity
{
private:
    int xp;
    int hp;
    int level;
public:
    player(std::string pn, int px, int py) : entity(pn, px, py)
    {
        xp = 0;
        hp = 100;
        level = 1;
    }

    void setHP(int nhp) { hp = nhp; }
    void setXP(int nxp) { xp = nxp; }
    void setLevel(int nlevel) { level = nlevel; }
    int getHP() { return hp; }
    int getXP() { return xp; }
    int getLevel() { return level; }
    void calcXP();  //Used to "Level the Player Up and add attributes"
};

void calcXP()
{
    //do nothing atm
}

#endif // _PLAYER_HXX_
