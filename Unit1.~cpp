//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TG *G;

        int x = 8;
        int y = 8;

        int BallsLP = 3;
        int BallsRP = 3;

//---------------------------------------------------------------------------
__fastcall TG::TG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TG::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57)        UpLP->Enabled = true;
        if (Key == 0x53)        DownLP->Enabled = true;
        if (Key == VK_UP)       UpRP->Enabled = true;
        if (Key == VK_DOWN)     DownRP->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TG::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57)        UpLP->Enabled = false;
        if (Key == 0x53)        DownLP->Enabled = false;
        if (Key == VK_UP)       UpRP->Enabled = false;
        if (Key == VK_DOWN)     DownRP->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TG::UpLPTimer(TObject *Sender)
{
        if (LP->Top > 8) LP->Top -= 8;
}
//---------------------------------------------------------------------------
void __fastcall TG::DownLPTimer(TObject *Sender)
{
        if ((LP->Top + LP->Height) < (BG->Height - 8))
                LP->Top += 8;
}
//---------------------------------------------------------------------------
void __fastcall TG::UpRPTimer(TObject *Sender)
{
        if (RP->Top > 8) RP->Top -= 8;
}
//---------------------------------------------------------------------------
void __fastcall TG::DownRPTimer(TObject *Sender)
{
        if ((RP->Top + RP->Height) < (BG->Height - 8))
                RP->Top += 8;
}
//---------------------------------------------------------------------------
void __fastcall TG::BTTimer(TObject *Sender)
{
        BT->Interval = 8;
        B->Left += x;
        B->Top += y;

        int ballHitBoxL = B->Left;
        int ballHitBoxR = B->Left + B->Width;
        int ballHitBoxU = B->Top;
        int ballHitBoxD = B->Top + B->Height;

        int LPHitBoxL = LP->Left;
        int LPHitBoxR = LP->Left + LP->Width;
        int LPHitBoxU = LP->Top;
        int LPHitBoxD = LP->Top + LP->Height;

        int RPHitBoxL = RP->Left;
        int RPHitBoxR = RP->Left + RP->Width;
        int RPHitBoxU = RP->Top;
        int RPHitBoxD = RP->Top + RP->Height;

        int BGHitBoxL = BG->Left;
        int BGHitBoxR = BG->Left + BG->Width;
        int BGHitBoxU = BG->Top;
        int BGHitBoxD = BG->Top + BG->Height - MB->Height;

        //Top and bot
        if (ballHitBoxU <= BGHitBoxU) y = -y;
        if (ballHitBoxD >= BGHitBoxD) y = -y;

        //LP Hit
        if (ballHitBoxD > LPHitBoxU && ballHitBoxU < LPHitBoxD){
                if (ballHitBoxL <= LPHitBoxR)
                        x = -x;
        }
        //LP Lose
        else {
                if (ballHitBoxL <= LPHitBoxR){
                        B->Left = BG->Left + (BG->Width / 2) - (B->Width / 2);
                        B->Top = BG->Top + (BG->Height / 2) - (B->Height / 2);
                        x = -x;
                        BallsLP--;
                        BT->Interval = 1000;
                }
        }

        //RP Hit
        if (ballHitBoxD > RPHitBoxU && ballHitBoxU < RPHitBoxD){
                if (ballHitBoxR >= RPHitBoxL)
                        x = -x;
        }
        //RP Lose
        else {
                if (ballHitBoxR >= RPHitBoxL){
                        B->Left = BG->Left + (BG->Width / 2) - (B->Width / 2);
                        B->Top = BG->Top + (BG->Height / 2) - (B->Height / 2);
                        x = -x;
                        BallsRP--;
                        BT->Interval = 1000;
                }
        }

        //LP Balls
        if (BallsLP == 3){
                LPB1->Visible = true;
                LPB2->Visible = true;
                LPB3->Visible = true;
        }
        if (BallsLP == 2){
                LPB1->Visible = true;
                LPB2->Visible = true;
                LPB3->Visible = false;
        }
        if (BallsLP == 1){
                LPB1->Visible = true;
                LPB2->Visible = false;
                LPB3->Visible = false;
        }
        if (BallsLP == 0){
                LPB1->Visible = false;
                LPB2->Visible = false;
                LPB3->Visible = false;
        }

        //RP Balls
        if (BallsRP == 3){
                RPB1->Visible = true;
                RPB2->Visible = true;
                RPB3->Visible = true;
        }
        if (BallsRP == 2){
                RPB1->Visible = true;
                RPB2->Visible = true;
                RPB3->Visible = false;
        }
        if (BallsRP == 1){
                RPB1->Visible = true;
                RPB2->Visible = false;
                RPB3->Visible = false;
        }
        if (BallsRP == 0){
                RPB1->Visible = false;
                RPB2->Visible = false;
                RPB3->Visible = false;
        }

}
//---------------------------------------------------------------------------
