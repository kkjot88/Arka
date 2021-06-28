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
//---------------------------------------------------------------------------
class TG : public TForm
{
__published:	// IDE-managed Components
        TShape *BG;
        TImage *LP;
        TImage *RP;
        TImage *B;
        TTimer *UpLP;
        TTimer *DownLP;
        TTimer *UpRP;
        TTimer *DownRP;
        TTimer *BT;
        TImage *LPB1;
        TImage *LPB2;
        TImage *LPB3;
        TImage *RPB3;
        TImage *RPB2;
        TImage *RPB1;
        TShape *MB;
        TButton *Pause;
        TButton *Resume;
        TButton *Start;
        TLabel *hits;
        TLabel *winner;
        TTimer *ST;
        TLabel *countDown;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall UpLPTimer(TObject *Sender);
        void __fastcall DownLPTimer(TObject *Sender);
        void __fastcall UpRPTimer(TObject *Sender);
        void __fastcall DownRPTimer(TObject *Sender);
        void __fastcall BTTimer(TObject *Sender);
        void __fastcall PauseClick(TObject *Sender);
        void __fastcall StartClick(TObject *Sender);
        void __fastcall ResumeClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TG(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TG *G;
//---------------------------------------------------------------------------
#endif
 