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
Description -> Caption =  "Witaj w grze PingPong.\n\nLewy gracz steruje klawiszami A oraz Z. \nPrawy gracz steruje wciskaj�c strza�ki do g�ry i w d�. Dla urozmaicenia zabawy: \n\nKiedy odbijesz pi�k� na �rodku paletki, w�wczas zmienisz jej k�t odbicia i pi�ka przy�pieszy.\nIm d�u�ej odbjasz, tym pi�ka szybciej przemieszcza si�.\nMo�esz dowolnie zmienia pole gry.\n\nMilej zabawy!";
}
//---------------------------------------------------------------------------

void __fastcall Tfram::FrameClick(TObject *Sender)
{
   Description -> Caption =  "Witaj w grze PingPong.\n Lewy gracz steruje klawiszami A oraz Z. \n\n Prawy gracz steruje wciskaj�c strza�ki do g�ry i w d�. Dla urozmaicenia zabawy: \n\nKiedy odbijesz pi�k� na �rodku paletki, w�wczas zmienisz jej k�t odbicia i pi�ka przy�pieszy.\nIm d�u�ej odbjasz, tym pi�ka szybciej przemieszcza si�.\nMo�esz dowolnie zmienia pole gry.\n\n Milej zabawy";
}
//---------------------------------------------------------------------------
void __fastcall Tfram::Button1Click(TObject *Sender)
{
    fram->Visible=false;
}
//---------------------------------------------------------------------------
