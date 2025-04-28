#ifndef DIALOGUE_H
#define DIALOGUE_H
#include<raylib.h>
#include <vector>
#include <iostream>
class Dialogue{ 
  Texture2D avatar;
  std::string name;
  std::vector<const char*> messages;
  const float typingSpeed=20.0f;
  

};



#endif
