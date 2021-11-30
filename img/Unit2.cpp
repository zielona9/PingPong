//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfram *fram;
//---------------------------------------------------------------------------
__fastcall Tfram::Tfram(TComponent* Owner)
        : TFrame(Owner)
{
Description -> Caption =  "Witaj w grze PingPong.\n\nLewy gracz steruje klawiszami A oraz Z. \nPrawy gracz steruje wciskaj¹c strza³ki do góry i w dó³. Dla urozmaicenia zabawy: \n\nKiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.\nIm d³u¿ej odbjasz, tym pi³ka szybciej przemieszcza siê.\nMo¿esz dowolnie zmienia pole gry.\n\nMilej zabawy!";
}
//---------------------------------------------------------------------------

void __fastcall Tfram::FrameClick(TObject *Sender)
{
   Description -> Caption =  "Witaj w grze PingPong.\n Lewy gracz steruje klawiszami A oraz Z. \n\n Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³. Dla urozmaicenia zabawy: \n\nKiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.\nIm d³u¿ej odbjasz, tym pi³ka szybciej przemieszcza siê.\nMo¿esz dowolnie zmienia pole gry.\n\n Milej zabawy";
}
//---------------------------------------------------------------------------
void __fastcall Tfram::Button1Click(TObject *Sender)
{
    fram->Visible=false;
}
//---------------------------------------------------------------------------
