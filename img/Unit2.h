//---------------------------------------------------------------------------


#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfram : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Description;
        TButton *Button1;
        void __fastcall FrameClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfram(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfram *fram;
//---------------------------------------------------------------------------
#endif
