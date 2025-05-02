#ifndef  ATTACK_H
#define ATTACK_H
#include "Entity.h" 
#include "Prompt.h"
#include <memory>
class Attack{
 private:
   std::string name;
   int consumption;
   int damage;
 public:
 virtual std::unique_ptr<Attack> clone() const = 0;
 bool checkStamina(Entity& entity) const;
 Attack(std::string name,int consumption,int damage);
 virtual ~Attack(){}; 
 virtual  void dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const;
 std::string getName() const;        
 int getConsumption() const;
 int getDamage() const;

 virtual void describe(Entity& entity,Prompt& prompt) const = 0;
};

class PenetrationAttack: public Attack {
 private:
   virtual std::unique_ptr<Attack> clone() const override{
        return std::make_unique<PenetrationAttack> (*this);
   }
 public:
  ~PenetrationAttack() override{};
  PenetrationAttack(std::string name,int consumption,int damage):Attack(name, consumption, damage){};
 virtual  void dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const override;
 virtual void describe(Entity& entity,Prompt& prompt) const override;
};

class NormalAttack: public Attack {
 private:
   virtual std::unique_ptr<Attack> clone() const override{
        return std::make_unique<NormalAttack> (*this);
   }
 public:
  ~NormalAttack() override{};
 NormalAttack(std::string name,int consumption,int damage):Attack(name, consumption, damage){};
 virtual  void dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const override;
 virtual void describe(Entity& entity,Prompt& prompt) const override;
};

class Heal: public Attack {
 private:
   virtual std::unique_ptr<Attack> clone() const override{
        return std::make_unique<Heal> (*this);
   }
 public:
  ~Heal() override{};
  Heal(std::string name,int consumption,int damage):Attack(name, consumption, damage){};
 virtual  void dealDamage(Entity& attacker,Entity& defender,Prompt& prompt) const override;
 virtual void describe(Entity& entity,Prompt& prompt) const override;
};

#endif
