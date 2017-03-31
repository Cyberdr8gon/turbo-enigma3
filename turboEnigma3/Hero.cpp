#include "Hero.h"


int hero::xCord()
{
  return _xCord;
}

int hero::yCord()
{
  return _yCord;
}


void hero::spawn(int xCord, int yCord)
{
  _xCord = xCord;
  _yCord = yCord;
}

void hero::moveUp()
{
  _yCord++;
}

void hero::moveDown()
{
  _yCord--;
}

void hero::moveLeft()
{
  _xCord--;
}

void hero::moveRight()
{
  _xCord++;
}

