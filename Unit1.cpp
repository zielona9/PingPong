//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma resource "*.dfm"
TPingPong *PingPong;
int x=-8;
int y=-8;
int leftPoints=0;
int rightPoints=0;
int bounces=0;
int angle=0;
int timer=0;
int k=1;


//---------------------------------------------------------------------------
__fastcall TPingPong::TPingPong(TComponent* Owner)
        : TForm(Owner)
{
if(Application->MessageBox("Witaj w grze PingPong.\n\nLewy gracz steruje wciskajac klawisze A i Z.\nPrawy gracz steruje wciskajac strza³ki do góry i w dó³.\n\n Dla urozmaicenia zabawy:\nKiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.\n Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.\n Mo¿esz dowolnie zmieniaæ pole gry.\n\n Mi³ej zabawy!","PingPong",MB_OK)==ID_OK)
{

                 Title-> Left=PingPong->Width/2-Title->Width/2;
                 Start-> Left=PingPong->Width/2-Start->Width/2;
                  padLeft->Left=20;
padRight->Left=background->Width-20-padRight->Width;
        padLeft->Top=PingPong->Height/2-padLeft->Height/2;
padRight->Top=PingPong->Height/2-padRight->Height/2;
     // ustawienie napisów w poziomie
   Winner ->Left=PingPong->Width/2 - Winner ->Width/2;
   Score->Left=PingPong->Width/2 -Score->Width/2;
   Counter->Left=PingPong->Width/2 -Counter->Width/2;
   newGame->Left=PingPong->Width/2 -newGame->Width/2;
   newLap->Left=PingPong->Width/2 -newLap->Width/2;
      //ustawienie napisów w pionie
  Winner ->Top=PingPong->Height/2 -Counter->Height/2-10 -Score->Height-Winner->Height;
   Score->Top=PingPong->Height/2 -Counter->Height/2-5 -Score->Height ;
   Counter->Top=PingPong->Height/2 -Counter->Height/2;
   newLap->Top=Counter->Top+Counter->Height+5;
   newGame->Top=PingPong->Height/2 +Counter->Height/2+10+newLap->Height;
  }
   }
//---------------------------------------------------------------------------
 bool collision (TImage *b ,TImage *pad)
   {
    if(b -> Left >=pad -> Left -b->Width &&
    b -> Left  <=pad -> Left +pad->Width   &&
    b  -> Top >= pad -> Top - b  ->Height   &&
    b  -> Top <=pad ->Top +pad->Height)
   {
    return true;
   }
    else
   {
   return false;
   }
   }

   bool padCenter(TImage *b ,TImage *p)
   {
   if((b->Top>p->Top +p->Height/2 - b->Height/2) && (b->Top< p->Top+p->Height/2+b->Height/2))
   {
   return true;
   }
   else
   {
   return false;
   }
   }

void __fastcall TPingPong::TimerBallTimer(TObject *Sender)
{
   ball->Left+=x;
   ball->Top+=y;
   //odbicie od gornej sciany
    if(ball->Top-5 <= background->Top) y=-y;
   //odbicie od dolnej sciany
    if(ball->Top+ball->Height +5 >= background->Height) y=-y;
   // odbicie od prawej sciany   -lewy wygrywa
    if((ball->Left+ball->Width+5>=background->Width) )
    {
    AnsiString lPoints, rPoints, strBounces;
    TimerBall->Enabled=false;
    ball->Visible=false;
    leftPoints++;
    lPoints=IntToStr (leftPoints);
    rPoints=IntToStr (rightPoints);
    strBounces=IntToStr(bounces);
    Winner ->Visible=true;
    Score->Visible=true;
    Counter->Visible=true;
    newGame->Visible=true;
    newLap->Visible=true;

    Winner -> Caption="< Punkt dla gracza lewego";
    Score ->Caption= lPoints+":"+rPoints;
    Counter->Caption="Iloœæ odbiæ: "+ strBounces;

    }
    // prawa paletka
    else if(ball->Top>padRight->Top -ball->Height/2&&
        ball->Top<padRight->Top+padRight->Height +ball->Height/2&&
        ball->Left+ball->Width>padRight->Left)
    {
    if(padCenter(ball,padRight))
    {
   angle-=3;
   if(TimerBall->Interval!=1)
   TimerBall->Interval--;
   //Label1->Caption=IntToStr(TimerBall->Interval);
    // Label2->Caption="R+"+IntToStr(angle);
     }

   x=-x;
   y=-y+angle;
   bounces++;

     }
   //wygrana odbicie od  lewej sciany - prawy wygrywa
   if((ball->Left-5<=background->Left))
   {
    AnsiString lPoints, rPoints, strBounces;
        TimerBall->Enabled=false;
    ball->Visible=false;
    rightPoints++;
    lPoints=IntToStr (leftPoints);
    rPoints=IntToStr (rightPoints);
    strBounces=IntToStr(bounces);

    Winner ->Visible=true;
    Score->Visible=true;
    Counter->Visible=true;
    newGame->Visible=true;
    newLap->Visible=true;

    Winner -> Caption="Punkt dla gracza prawego >";
    Score ->Caption= lPoints+":"+rPoints;
    Counter->Caption="Iloœæ odbiæ: "+ strBounces;
   }


    //lewa paletka
   else if(ball->Top>padLeft->Top-ball->Height/2 &&
        ball->Top<padLeft->Top+padLeft->Height-ball->Height/2
        && ball->Left<padLeft->Left+padLeft->Width)

   {
   if(padCenter(ball,padLeft))
   {
   angle-=3;
   if(TimerBall->Interval!=1)
   TimerBall->Interval--;
  // Label1->Caption=IntToStr(TimerBall->Interval);
   //  Label2->Caption="L+"+IntToStr(angle);

     }
   x=-x;
     y=-y+angle;
   bounces++;
   }


   if(bounces>=3*k)
   {
   k++;

   if(TimerBall->Interval!=1)
   TimerBall->Interval--;

    //Label1->Caption=IntToStr(TimerBall->Interval);
   }

}
//---------------------------------------------------------------------------
void __fastcall TPingPong::TimerUpRightTimer(TObject *Sender)
{
    if(padRight->Top>10)padRight->Top-=10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::TimerDownRightTimer(TObject *Sender)
{
    if(padRight->Top+padRight->Height<background->Height-10)  padRight->Top+=10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::TimerUpLeftTimer(TObject *Sender)
{
     if(padLeft->Top>10)padLeft->Top-=10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::TimerDownLeftTimer(TObject *Sender)
{
    if(padLeft->Top+padLeft->Height<background->Height-10)  padLeft->Top+=10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
            if(Key == VK_UP) TimerUpRight->Enabled=true;
if(Key == VK_DOWN)  TimerDownRight->Enabled=true;
if(Key == 0x0041)  TimerUpLeft->Enabled=true;
if(Key == 0x005A) TimerDownLeft->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_UP) TimerUpRight->Enabled=false;
if(Key == VK_DOWN)  TimerDownRight->Enabled=false;
if(Key == 0x0041)  TimerUpLeft->Enabled=false;
if(Key == 0x005A) TimerDownLeft->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::newLapClick(TObject *Sender)
{
     ball->Left =background->Width/2;
   ball->Top=background->Height/2;
   ball->Visible=true;
   x=8; y=8;

   TimerBall->Enabled=true;
   Winner ->Visible=false;
   Score->Visible=false;
   Counter->Visible=false;
   newGame->Visible=false;
   newLap->Visible=false;
   bounces=0;
   angle =0;
   TimerBall->Interval=30;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::newGameClick(TObject *Sender)
{
if(Application->MessageBox("Czy na pewno chcesz zacz¹æ od nowa?","PotwierdŸ",MB_YESNO)==IDYES )
  {     ball->Left =background->Width/2;
   ball->Top=background->Height/2;
   ball->Visible=true;
   x=-8; y=-8;

   TimerBall->Enabled=true;
   Winner ->Visible=false;
   Score->Visible=false;
   Counter->Visible=false;
   newGame->Visible=false;
   newLap->Visible=false;
   bounces=0;
   leftPoints=0;
   rightPoints=0;
   TimerBall->Interval=30;
   timer=0;
   }
}
//---------------------------------------------------------------------------




//rozci¹gniêcie planszy
void __fastcall TPingPong::FormResize(TObject *Sender)
{
         Title-> Left=PingPong->Width/2-Title->Width/2;
         Start-> Left=PingPong->Width/2-Start->Width/2;
         Start->Top=PingPong->Height-Start->Height-80;
         Title->Top=40;
        padLeft->Left=20;
padRight->Left=background->Width-20-padRight->Width;

padLeft->Top=PingPong->Height/2-padLeft->Height/2;
padRight->Top=PingPong->Height/2-padRight->Height/2;
     // ustawienie napisów w poziomie
   Winner ->Left=PingPong->Width/2 - Winner ->Width/2;
   Score->Left=PingPong->Width/2 -Score->Width/2;
   Counter->Left=PingPong->Width/2 -Counter->Width/2;
   newGame->Left=PingPong->Width/2 -newGame->Width/2;
   newLap->Left=PingPong->Width/2 -newLap->Width/2;
      //ustawienie napisów w pionie
  Winner ->Top=PingPong->Height/2 -Counter->Height/2-10 -Score->Height-Winner->Height;
   Score->Top=PingPong->Height/2 -Counter->Height/2-5 -Score->Height ;
   Counter->Top=PingPong->Height/2 -Counter->Height/2;
   newLap->Top=Counter->Top+Counter->Height+5;
   newGame->Top=PingPong->Height/2 +Counter->Height/2+10+newLap->Height;
   // nie zmienianie ni¿ wiêksze
   if(PingPong->Width<Winner->Width)
   PingPong->Width=Winner->Width+ padRight->Width*4;
   if(PingPong->Height<6*Winner->Height)
   PingPong->Height=  6*Winner->Height ;

}
//---------------------------------------------------------------------------


void __fastcall TPingPong::StartClick(TObject *Sender)
{
Start->Visible=false;
Title->Visible=false;
TimerBall->Enabled=true;
}
//---------------------------------------------------------------------------




