#include "Entity.h"
#include <raylib.h>
#include <string>
#include <vector>

Entity::Entity(std::string name,const char* spritePath,bool isPlayer,int maxHealth,int stamina,int defense,int intelligence,int strength): isPlayer(isPlayer),name(name),maxHealth(maxHealth),stamina(stamina),defense(defense),intelligence(intelligence),strength(strength),currentHealth(maxHealth),currentStamina(stamina),spriteTexture(LoadTexture(spritePath)){};
Entity::~Entity(){ 
  UnloadTexture(spriteTexture);
    UnloadTexture(heart_texture);
};
std::string Entity::getName() const{return name;}
void Entity::applyDamage(int damage){ if(currentHealth>0){currentHealth=currentHealth-damage;std::cout<<currentHealth<<"\n";}else std::cout<<"dead"<<"\n";}
void Entity::applyConsumption(int consumption){ if(currentStamina>0){currentStamina=currentStamina-consumption;std::cout<<currentStamina<<"\n";} }
void Entity::applyHeal(int heal){ currentHealth=currentHealth+heal;}
int  Entity::getCurrentHealth() const{return currentHealth;}
int Entity::getCurrentStamina() const{return currentStamina;}
void Entity::loadPlayer(Rectangle entityDest) const{
DrawTexturePro(spriteTexture, {0,0,300,500}, entityDest, {0,0}, 0, RAYWHITE);
}
void Entity::printStats() {
std::vector<float> offsets={20.0,70.0,130.0,180.0,240.0,290.0};
if(!isPlayer)
   offsets={1100.0,1150.0,1210.0,1260.0,1320.0,1370.0};
DrawTexturePro(heart_texture,{0,0,500,500},{offsets[0],30.0,40,40},{0,0},0,RAYWHITE);
DrawTexturePro(stamina_texture,{0,0,500,500},{offsets[0],80.0,40,40},{0,0},0,RAYWHITE);
DrawText(std::to_string(currentHealth).c_str(),offsets[1], 35.0, 30, RAYWHITE);
DrawText(std::to_string(currentStamina).c_str(),offsets[1], 90.0, 30, RAYWHITE);
DrawTexturePro(defense_texture,{0,0,500,500},{offsets[2],30.0,50,40},{0,0},0,RAYWHITE);
DrawTexturePro(intelligence_texture,{0,0,500,500},{offsets[2],80.0,40,40},{0,0},0,RAYWHITE);
DrawText(std::to_string(defense).c_str(),offsets[3], 35.0, 30, RAYWHITE);
DrawText(std::to_string(intelligence).c_str(), offsets[3], 90.0,30,RAYWHITE);
DrawTexturePro(strength_texture,{0,0,500,500},{offsets[4],30.0,40,40},{0,0},0,RAYWHITE);
DrawText(std::to_string(strength).c_str(),offsets[5], 35.0, 30, RAYWHITE);

};
void Entity::restoreStamina() {
  currentStamina=stamina;

}
int Entity::getDefense() const{
 return defense;
}
int Entity::getIntelligence() const{
  return intelligence;
}
int Entity::getStrength() const{
  return strength;
}
