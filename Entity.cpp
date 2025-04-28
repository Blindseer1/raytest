#include "Entity.h"
#include <raylib.h>
#include <string>

Entity::Entity(std::string name,int maxHealth,const char* spritePath): name(name),maxHealth(maxHealth),currentHealth(maxHealth),spriteTexture(LoadTexture(spritePath)){};
std::string Entity::getName() const{return name;}
void Entity::applyDamage(int damage){ if(currentHealth>0)currentHealth=currentHealth-damage;else std::cout<<"dead"<<"\n";}
void Entity::applyHeal(int heal){ currentHealth=currentHealth+heal;}
int Entity::getCurrentHealth() const{return currentHealth;}
void Entity::loadPlayer(Rectangle entityDest) const{
DrawTexturePro(spriteTexture, {0,0,300,400}, entityDest, {0,0}, 0, RAYWHITE);
}
