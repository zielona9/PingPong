//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TPingPong : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *padRight;
        TImage *padLeft;
        TImage *ball;
        TTimer *TimerBall;
        TTimer *TimerUpRight;
        TTimer *TimerDownRight;
        TTimer *TimerUpLeft;
        TTimer *TimerDownLeft;
        TLabel *Score;
        TLabel *Counter;
        TLabel *Winner;
        TButton *newLap;
        TButton *newGame;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Title;
        TButton *Start;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall TimerUpRightTimer(TObject *Sender);
        void __fastcall TimerDownRightTimer(TObject *Sender);
        void __fastcall TimerUpLeftTimer(TObject *Sender);
        void __fastcall TimerDownLeftTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall newLapClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall StartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPong *PingPong;
//---------------------------------------------------------------------------
#endif
