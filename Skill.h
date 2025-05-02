
#ifndef SKILL_H
#define SKILL_H

#include <memory>
#include <raylib.h>
#include "Attacks.h"
#include "Entity.h"
#include "Prompt.h"

class Skill{
  private: 
  std::unique_ptr<Attack> attack;
    Entity& attacker;    
    Entity& enemy;
    Prompt& prompt;
  public:
 Skill(const Attack& atk, Entity& attacker, Entity& enemy, Prompt& prompt)
        : attack(atk.clone()), attacker(attacker), enemy(enemy), prompt(prompt) {}

    void use() const {
        attack->dealDamage(attacker, enemy, prompt);}
    std::string getName() const{
      return attack->getName();
    }
      int getStamina() const{
      return attack->getConsumption();
    }
      int getStrength() const{
        return attack->getDamage();
      }

};

#endif
