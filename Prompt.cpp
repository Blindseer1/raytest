#include "Prompt.h"
#include <raylib.h>
void Prompt::drawPrompt(){
 DrawText(text.c_str(), 450, 200.0, 25.0, RAYWHITE);
}
void Prompt::setPrompt(std::string newText){
  text=newText;
}
