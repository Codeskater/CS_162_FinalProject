#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Space
{
  protected:

  public:

    virtual string getRoomName()=0;
    virtual void specialFunction()=0;
    virtual int getVisited()=0;
    virtual void setVisited()=0;
    virtual void reset()=0;
};

#endif
