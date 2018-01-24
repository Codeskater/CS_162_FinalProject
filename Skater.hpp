#ifndef SKATER_HPP
#define SKATER_HPP
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Skater
{
  protected:


  public:
    virtual int attack()= 0;
    virtual void defend(int)= 0;
    virtual int attackRoll()=0;
    virtual int defendRoll()=0;
    virtual int getStrength()=0;
};

#endif
