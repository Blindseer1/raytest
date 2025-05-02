#ifndef PROMPT_H
#define PROMPT_H
#include<iostream>
class Prompt{
  private:
    std::string text="";
  public:
    void drawPrompt();
    void setPrompt(std::string text);

  
};

#endif
