#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <iostream>
#include <string>
#include <vector>


class Entity{
  private:
    std::string name;
    int strength=0;
    int intelligence=0;
    int defense=50;
    int stamina=100;
    int mana=50;
    int maxHealth=200;
    int criticalChance=10;
    int criticalMultiplier=2;
    int currentHealth;
    int currentStamina;
    bool isPlayer=0;
    Texture2D spriteTexture;
    Texture2D heart_texture=LoadTexture("./assets/hearts.png");
    Texture2D defense_texture=LoadTexture("./assets/shield(1).png");
    Texture2D stamina_texture=LoadTexture("./assets/battery-pack.png");
    Texture2D intelligence_texture=LoadTexture("./assets/brain.png");
    Texture2D strength_texture=LoadTexture("./assets/biceps.png");
  public:
    Entity(std::string name,const char* spritePath,bool isPlayer,int maxHealth,int stamina,int defense,int intelligence,int strength);
    ~Entity();
    std::string getName() const;
    void setName();
    void applyDamage(int damage);
    void applyConsumption(int consumption);
    void applyHeal(int heal);
    int getCurrentHealth() const;
    int getCurrentStamina() const;
    int getDefense() const;
    void loadPlayer(Rectangle entityDest) const;
    void printStats() ;
    void restoreStamina() ;
    int getIntelligence() const;
    int getStrength() const;
};


#endif 

