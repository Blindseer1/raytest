/// TODO: To clean up the drawTextBox function
#include "Entity.h" 
#include <raylib.h>
#include <vector>

void drawTextBox(float& timer,std::vector<const char *> text,int &charsToShow,int& totalLength, int& index,int& isFinished,Font pixelFont,Font titleFont,const char*title,Entity entity){

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

entity.loadPlayer({80.0,420.0,200.0,300.0});
}

int main(){
 
typedef struct Sprite{
  Texture2D texture;
  Rectangle dest_rect;
}Sprite;

enum Stats{
  Strength,
  Magic,
  Health,
  Defense,
  Dodge,
  Stamina,
  Mana
};
InitWindow(1500, 800,"awesome");

Font pixelFont=LoadFont("./assets/PixelOperatorSC.ttf");
Font titleFont=LoadFont("./assets/PixelOperator8-Bold.ttf");
std::vector<const char *> text={"Hello there, subject 3230.","It's finally your turn to go through the trials","As you probably already know","The world has been overtaken by humonguos monkeys","And the only way to escape their opression","Is to forge the ultimate banana","After each trial you will gain new abilities","And after the final trial your body will reach a qualitive change","Turning you into the Sharpest Banana","A banana that can cut through Heaven and Earth","This has been proven through the effort of your peers","Which unfortunately are no longer with us","Well now it's your turn","Good Luck and Have Fun"};
float typingSpeed=20.0f;
float timer=0.0f;
int totalLength; 
Texture2D player_texture= LoadTexture("./assets/banana_scientist4.png");
Entity entity("Walter",800,"./assets/banana_scientist4.png");
Sprite player=(Sprite){
  .texture=player_texture,
  .dest_rect=(Rectangle){
    .x=80.0,
    .y=420.0,
    .width=200.0,
    .height=300.0,
  },
};
int index=0;
int showText=0;
int isFinished=0;
const char*title="Dr. Splitenstein";
while(!WindowShouldClose()){

if(IsKeyPressed(KEY_A)){
  std::cout<<entity.getName()<<"\n";
  entity.applyDamage(20);
}

BeginDrawing();
ClearBackground(BLACK);
timer+=GetFrameTime();
int charsToShow=int(timer*typingSpeed);
DrawRectangleLines(20, 500, 400, 120, RAYWHITE);
DrawRectangle(20, 500, 400, 120, {161, 160, 98,100});

std::cout<<GetMouseX() <<"\n";
DrawText("Normal Attack", 120, 520, 30, RAYWHITE);
EndDrawing();
}
CloseWindow();


  return 0;
}
