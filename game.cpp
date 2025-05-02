/// TODO: To clean up the drawTextBox function
#include "Entity.h"
#include "Attacks.h"
#include "Prompt.h"
#include "Skill.h"
#include <raylib.h>
#include <string>
#include <vector>

 int SCREEN_WIDTH = 1500;
 int SCREEN_HEIGHT = 800;
Prompt prompt;




void endTurn(Rectangle coords,Entity& player,Entity& enemy,Skill& skill){
Vector2 mousePos=GetMousePosition();
bool mouseHover=
mousePos.x>=coords.x &&  
mousePos.x<=coords.x+coords.width && 
mousePos.y>=coords.y && 
mousePos.y<=coords.y+coords.height; 
DrawRectangle(coords.x,coords.y,coords.width,coords.height ,{11, 77, 13,100});
DrawRectangleLinesEx({coords.x,coords.y,coords.width,coords.height},3,{255, 255, 255,100});
DrawText("End turn",620,25.0, 35, RAYWHITE);
if(mouseHover){
  DrawRectangle(coords.x,coords.y,coords.width,coords.height ,{101, 194, 126,100});
DrawRectangleLinesEx({coords.x,coords.y,coords.width,coords.height},5,{255, 255, 255,100});
}
if (mouseHover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
  if(enemy.getCurrentHealth()<=0)
    prompt.setPrompt("You won");
  else {
  skill.use(); 
    if( player.getCurrentHealth()<=0)
        prompt.setPrompt("You Lost");
    else {
      player.restoreStamina();
      enemy.restoreStamina();
         }
  }
}


}


void drawTextBox(float& timer,std::vector<const char *> text,int &charsToShow,int& totalLength, int& index,int& isFinished,Font pixelFont,Font titleFont,const char*title,Entity player){

totalLength=TextLength(text[index]);
if(IsKeyDown(KEY_SPACE)){  
  if(index<=text.size()-2 && isFinished){
    ++index;
    isFinished=0;
    timer=0; 
  }
}
if (charsToShow > totalLength) {
  charsToShow = totalLength;
  isFinished=1;
}

DrawTextEx(pixelFont,TextSubtext(text[index], 0, charsToShow), {390,570}, 42, 2,RAYWHITE);
DrawTextEx(titleFont,title, {500,520}, 30, 5, RAYWHITE);
DrawRectangleLinesEx({90.0, 480.0, 1310, 300},3, RAYWHITE);

player.loadPlayer({80.0,420.0,200.0,300.0});
}
PenetrationAttack pierceAttack("Pierce",30,100);
PenetrationAttack specialAttack("Special attack",80,300);
NormalAttack normalAttack("Normal Attack",10,30);
Heal heal("Heal",40,-20); 

void drawButton(Rectangle coords,std::string text,Entity& player,Entity& enemy,Skill& skill){ ///switch (position) {
Vector2 mousePos=GetMousePosition();
bool mouseHover=
mousePos.x>=coords.x &&  
mousePos.x<=coords.x+coords.width && 
mousePos.y>=coords.y && 
mousePos.y<=coords.y+coords.height; 
  
if (mouseHover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
  skill.use();
  std::cout<<"am fost apasat"<<'\n';
}
if (mouseHover){
   DrawRectangleLinesEx( coords,4,RAYWHITE);
DrawRectangle(coords.x,coords.y , coords.width, coords.height, {161, 160, 98,100});
}


DrawRectangleLines( coords.x,coords.y , coords.width, coords.height,RAYWHITE);
DrawRectangle(coords.x,coords.y , coords.width, coords.height, {161, 160, 98,100});
DrawText(skill.getName().c_str(),(coords.width+coords.x*2)/2-100, coords.y+10, 30, RAYWHITE);
DrawText(std::to_string(skill.getStamina()).c_str(),(coords.width+coords.x*2)/2+280 , coords.y+70, 25, RAYWHITE);
DrawText("Stamina Cost: ",(coords.width+coords.x*2)/2+90, coords.y+70, 25, RAYWHITE);
DrawText(std::to_string(skill.getStrength()).c_str(),(coords.width+coords.x*2)/2-190,coords.y+70,25,RAYWHITE); 
DrawText("Raw Damage: ",(coords.width+coords.x*2)/2-350,coords.y+70,25,RAYWHITE);
}

int main(){
 
InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"awesome");

Font pixelFont=LoadFont("./assets/PixelOperatorSC.ttf");
Font titleFont=LoadFont("./assets/PixelOperator8-Bold.ttf");
std::vector<const char *> text={"Hello there, subject 3230.","It's finally your turn to go through the trials","As you probably already know","The world has been overtaken by humonguos monkeys","And the only way to escape their opression","Is to forge the ultimate banana","After each trial you will gain new abilities","And after the final trial your body will reach a qualitive change","Turning you into the Sharpest Banana","A banana that can cut through Heaven and Earth","This has been proven through the effort of your peers","Which unfortunately are no longer with us","Well now it's your turn","Good Luck and Have Fun"};
float typingSpeed=20.0f;
float timer=0.0f;
int totalLength; 
Texture2D player_texture= LoadTexture("./assets/banana_scientist4.png");

Texture2D stamina_texture=LoadTexture("./assets/battery-pack.png");

Entity player("Walter","./assets/banana_player.png",true,800,100,25,10,20);
Entity enemy("The Prisoner","./assets/banana_prisoner.png",false,1000,50,30,0,10);

Skill skill_1(pierceAttack,player,enemy,prompt);
Skill skill_2(specialAttack,player,enemy,prompt);
Skill skill_3(normalAttack,player,enemy,prompt);
Skill skill_4(heal,player,enemy,prompt);
Skill enemySkill(pierceAttack,enemy,player,prompt);
int index=0;
int showText=0;
int isFinished=0;
const char*title="Dr. Splitenstein";
while(!WindowShouldClose()){

if(IsKeyPressed(KEY_A)){
  std::cout<<player.getName()<<"\n";
 player.applyDamage(200);
}

  

BeginDrawing();
ClearBackground(BLACK);
timer+=GetFrameTime();
int charsToShow=int(timer*typingSpeed);
drawButton({20, 500, 720, 120},"Normal Attack",player,enemy,skill_1);
drawButton({760,500,720,120},"Normal Attack",player,enemy,skill_2);
drawButton({20, 630, 720, 120},"Normal Attack",player,enemy,skill_3);
drawButton({760, 630, 720, 120},"Heal",player,enemy,skill_4);
enemy.loadPlayer({1000.0,30.0,300.0,500.0});
player.loadPlayer({20.0,30.0,300.0,500.0});
player.printStats();
enemy.printStats();
prompt.drawPrompt();
endTurn({600.0,15.0,200,50},player,enemy,enemySkill);
EndDrawing();
}
CloseWindow();


  return 0;
}
