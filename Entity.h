#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <iostream>
#include <string>

class Entity{
  private:
    std::string name;
    int strength=0;
    int magic=0;
    int defense=0;
    int dodge=0;
    int stamina=100;
    int mana=50;
    int maxHealth=200;
    int currentHealth;
    Texture2D spriteTexture;
  public:
    Entity(std::string name,int maxHealth,const char* spritePath );
    std::string getName() const;
    void setName();
    void applyDamage(int damage);
    void applyHeal(int heal);
    int getCurrentHealth() const;
    void loadPlayer(Rectangle entityDest) const;
};


#endif 

