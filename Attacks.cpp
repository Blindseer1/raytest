#include "Attacks.h"
#include "Entity.h"
#include "Prompt.h"
#include "Errors.h"
#include <raylib.h>
Attack::Attack(std::string name,int consumption,int damage):name(name),consumption(consumption),damage(damage){};
bool Attack::checkStamina(Entity& entity) const {
  if(entity.getCurrentStamina()<consumption)
    return false;
  return true;
};
void Attack::dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const{
 try{ if(!checkStamina(attacker)) 
       throw StaminaException();
 attacker.applyConsumption(consumption);
  defender.applyDamage(damage-defender.getDefense());
 
prompt.setPrompt(attacker.getName()+ " has used " +getName() );
 } catch( const GameException& e){
 prompt.setPrompt(e.what());
 }
};
std::string Attack::getName() const{
  return name;
}
int Attack::getConsumption()const{
  return consumption;
}
int Attack::getDamage() const{
  return damage;
} 
void PenetrationAttack::dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const{
 try{ if(!checkStamina(attacker)) 
       throw StaminaException();
    attacker.applyConsumption(getConsumption());
   defender.applyDamage(attacker.getStrength()+getDamage()); 
 describe(attacker,prompt);
    } catch( const GameException& e){
 prompt.setPrompt(e.what());
 }
}

void PenetrationAttack::describe(Entity& entity,Prompt& prompt) const{
  prompt.setPrompt(entity.getName()+ " has used a Penetration Attack");
}

void NormalAttack::describe(Entity& entity,Prompt& prompt) const{
  prompt.setPrompt(entity.getName()+ " has used a Normal Attack");
}
void Heal::describe(Entity& entity,Prompt& prompt) const{
  prompt.setPrompt(entity.getName()+ " has used Heal");
}

void Heal::dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const{
if(!checkStamina(attacker)) 
   prompt.setPrompt("Not enough stamina");
else {
    attacker.applyConsumption(getConsumption());
   attacker.applyHeal(-getDamage()+attacker.getIntelligence());
  defender.applyDamage(getDamage()); 
 describe(attacker,prompt);
    }
}

void NormalAttack::dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const{
if(!checkStamina(attacker)) 
   prompt.setPrompt("Not enough stamina");
else {
    attacker.applyConsumption(getConsumption());
   defender.applyDamage(attacker.getStrength()+getDamage()-defender.getDefense()); 
 describe(attacker,prompt);
    }
}
