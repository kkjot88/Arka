//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TG *G;

        int x = 0;
        int y = 0;
        int tempx = x;
        int tempy = y;

        int BallsLP = 0;
        int BallsRP = 0;

        int hitCounter = 0;
        int goCounter = 0;

        bool paddleLock = false;

void endGame(){
        G->BT->Enabled = false;
        G->B->Enabled = false;
        G->B->Visible = false;
        G->hits->Enabled = true;
        G->hits->Visible = true;
        G->hits->Caption = "Number of hits: " + IntToStr(hitCounter);
        G->winner->Enabled = true;
        G->winner->Visible = true;
        if (G->LPB1->Visible == false) {
                G->winner->Caption = "Right player is the winner!";
        }
        if (G->RPB1->Visible == false) {
                G->winner->Caption = "Left player is the winner!";
        }

        G->Resume->Enabled = false;
        G->Resume->Visible = false;
        G->Pause->Enabled = false;
        G->Pause->Visible = false;

        G->Start->Enabled = true;
        G->Start->Visible = true;
        G->Start->Caption = "Again!";

        paddleLock = true;
}

void startCountDown() {
        goCounter = 0;
        G->BT->Enabled = false;
        paddleLock = true;
        G->Resume->Enabled = false;
        G->Resume->Visible = false;
        G->Pause->Enabled = false;
        G->Pause->Visible = false;
        G->countDown->Enabled = true;
        G->countDown->Visible = true;
        G->countDown->Caption = "3";
        Application->ProcessMessages(); Sleep(1000);
        G->countDown->Caption = "2";
        Application->ProcessMessages(); Sleep(1000);
        G->countDown->Caption = "1";
        Application->ProcessMessages(); Sleep(1000);
        G->BT->Enabled = true;
        G->Pause->Enabled = true;
        G->Pause->Visible = true;
        paddleLock = false;
        G->countDown->Caption = "Go!";
}

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
        if (!paddleLock) {
                if (LP->Top > 8) LP->Top -= 16;
        }
}
//---------------------------------------------------------------------------
void __fastcall TG::DownLPTimer(TObject *Sender)
{
        if (!paddleLock) {
                if ((LP->Top + LP->Height) < (BG->Height - MB->Height - 8))
                        LP->Top += 16;
        }
}
//---------------------------------------------------------------------------
void __fastcall TG::UpRPTimer(TObject *Sender)
{
        if (!paddleLock) {
                if (RP->Top > 8) RP->Top -= 16;
        }
}
//---------------------------------------------------------------------------
void __fastcall TG::DownRPTimer(TObject *Sender)
{
        if (!paddleLock) {
                if ((RP->Top + RP->Height) < (BG->Height - MB->Height - 8))
                        RP->Top += 16;
        }
}
//---------------------------------------------------------------------------
void __fastcall TG::BTTimer(TObject *Sender)
{
        if (LPB1->Visible == false || RPB1->Visible == false){
                endGame();
                return;
        }

        goCounter++;
        if (goCounter > 125) {
                G->countDown->Enabled = false;
                G->countDown->Visible = false;
        }

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
                if (ballHitBoxL <= LPHitBoxR) {
                        x = -x;
                        hitCounter++;
                        if (hitCounter % 8 == 0) {
                                if (x < 0) {
                                        x = x - 2;
                                }
                                else {
                                        x = x + 2;
                                }
                        }
                }
        }
        //LP Lose
        else {
                if (ballHitBoxL <= LPHitBoxR){
                        B->Left = BG->Left + (BG->Width / 2) - (B->Width / 2);
                        B->Top = BG->Top + (BG->Height / 2) - (B->Height / 2);
                        x = -x;
                        BallsLP--;
                        LP->Top = 192;
                        RP->Top = 192;
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
                                countDown->Enabled = false;
                                countDown->Visible = false;
                                return;
                        }
                        startCountDown();
                }
        }

        //RP Hit
        if (ballHitBoxD > RPHitBoxU && ballHitBoxU < RPHitBoxD){
                if (ballHitBoxR >= RPHitBoxL) {
                        x = -x;
                        hitCounter++;
                        if (hitCounter % 8 == 0) {
                                if (x < 0) {
                                        x = x - 2;
                                }
                                else {
                                        x = x + 2;
                                }
                        }
                }
        }
        //RP Lose
        else {
                if (ballHitBoxR >= RPHitBoxL){
                        B->Left = BG->Left + (BG->Width / 2) - (B->Width / 2);
                        B->Top = BG->Top + (BG->Height / 2) - (B->Height / 2);
                        x = -x;
                        BallsRP--;
                        LP->Top = 192;
                        RP->Top = 192;
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
                                countDown->Enabled = false;
                                countDown->Visible = false;
                                return;
                        }
                        startCountDown();
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TG::PauseClick(TObject *Sender)
{
        tempx = x;
        tempy = y;

        x = 0;
        y = 0;

        Pause->Enabled = false;
        Pause->Visible = false;

        Resume->Enabled = true;
        Resume->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TG::StartClick(TObject *Sender)
{
        B->Enabled = true;
        B->Visible = true;

        BallsLP = 3;
        BallsRP = 3;

        int xRandom = random(2);
        int yRandom = random(2);

        if (xRandom == 0) x = 8;
        else x = -8;

        if (yRandom == 0) y = 8;
        else y = -8;

        LPB1->Visible = true;
        LPB2->Visible = true;
        LPB3->Visible = true;

        RPB1->Visible = true;
        RPB2->Visible = true;
        RPB3->Visible = true;

        Start->Enabled = false;
        Start->Visible = false;

        hits->Enabled = false;
        hits->Visible = false;

        winner->Enabled = false;
        winner->Visible = false;

        Pause->Enabled = false;
        Pause->Visible = false;
        Resume->Enabled = false;
        Resume->Visible = false;

        startCountDown();

        Pause->Enabled = true;
        Pause->Visible = true;

        Resume->Enabled = false;
        Resume->Visible = false;

        paddleLock = false;
}
//---------------------------------------------------------------------------

void __fastcall TG::ResumeClick(TObject *Sender)
{
        x = tempx;
        y = tempy;

        Resume->Enabled = false;
        Resume->Visible = false;

        startCountDown();

        Pause->Enabled = true;
        Pause->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TG::FormCreate(TObject *Sender)
{
        randomize();
        AnsiString leftPlayer = "Left player controls: W - up, S - down.";
        AnsiString rightPlayer = "Right player controls: Up Arrow Key - up, Down Arrow Key - down.";
        AnsiString loseCond = "First player to lose three balls loses game.";
        AnsiString ballSpeed = "Every eight hits ball speed goes up slightly.";
        AnsiString pauseButton = "Game can be paused at will.";
        ShowMessage(leftPlayer + sLineBreak + rightPlayer + sLineBreak + sLineBreak
         + loseCond + sLineBreak + ballSpeed + sLineBreak + pauseButton);
}
//---------------------------------------------------------------------------



