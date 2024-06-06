#include "pieces.h"
#include "setting.h"
#include "start.h"
pieces::pieces(QWidget *parent)
{

}
void pieces::startChess(const int n){
    dead=false;
    num=n;
    if (n<16)
        white=true;
    else
        white=false;
    if(start::queenpro==1){
    switch(n){
        case 0:x=0; y=7; chessType=queen; break;
        case 1:x=1; y=7; chessType=queen; break;
        case 2:x=2; y=7; chessType=queen; break;
        case 3:x=3; y=7; chessType=queen; break;
        case 4:x=4; y=7; chessType=king; break;
        case 5:x=5; y=7; chessType=queen; break;
        case 6:x=6; y=7; chessType=queen; break;
        case 7:x=7; y=7; chessType=queen; break;
        case 8:x=0; y=6; chessType=queen; break;
        case 9:x=1; y=6; chessType=queen; break;
        case 10:x=2; y=6; chessType=queen; break;
        case 11:x=3; y=6; chessType=queen; break;
        case 12:x=4; y=6; chessType=queen; break;
        case 13:x=5; y=6; chessType=queen; break;
        case 14:x=6; y=6; chessType=queen; break;
        case 15:x=7; y=6; chessType=bishop; break;
        case 16:x=0; y=0; chessType=queen; break;
        case 17:x=1; y=0; chessType=queen; break;
        case 18:x=2; y=0; chessType=queen; break;
        case 19:x=3; y=0; chessType=queen; break;
        case 20:x=4; y=0; chessType=king; break;
        case 21:x=5; y=0; chessType=queen; break;
        case 22:x=6; y=0; chessType=queen; break;
        case 23:x=7; y=0; chessType=queen; break;
        case 24:x=0; y=1; chessType=queen; break;
        case 25:x=1; y=1; chessType=queen; break;
        case 26:x=2; y=1; chessType=queen; break;
        case 27:x=3; y=1; chessType=queen; break;
        case 28:x=4; y=1; chessType=queen; break;
        case 29:x=5; y=1; chessType=queen; break;
        case 30:x=6; y=1; chessType=queen; break;
        case 31:x=7; y=1; chessType=queen; break;

    }
}
    if(start::queen==1){
        switch(n){
            case 0:x=0; y=7; chessType=queen; break;
            case 1:x=1; y=7; chessType=queen; break;
            case 2:x=2; y=7; chessType=queen; break;
            case 3:x=3; y=7; chessType=queen; break;
            case 4:x=4; y=7; chessType=king; break;
            case 5:x=5; y=7; chessType=queen; break;
            case 6:x=6; y=7; chessType=queen; break;
            case 7:x=7; y=7; chessType=queen; break;
            case 8:x=0; y=6; chessType=queen; break;
            case 9:x=1; y=6; chessType=queen; break;
            case 10:x=2; y=6; chessType=queen; break;
            case 11:x=3; y=6; chessType=queen; break;
            case 12:x=4; y=6; chessType=queen; break;
            case 13:x=5; y=6; chessType=queen; break;
            case 14:x=6; y=6; chessType=queen; break;
            case 15:x=7; y=6; chessType=queen; break;
            case 16:x=0; y=0; chessType=queen; break;
            case 17:x=1; y=0; chessType=queen; break;
            case 18:x=2; y=0; chessType=queen; break;
            case 19:x=3; y=0; chessType=queen; break;
            case 20:x=4; y=0; chessType=king; break;
            case 21:x=5; y=0; chessType=queen; break;
            case 22:x=6; y=0; chessType=queen; break;
            case 23:x=7; y=0; chessType=queen; break;
            case 24:x=0; y=1; chessType=queen; break;
            case 25:x=1; y=1; chessType=queen; break;
            case 26:x=2; y=1; chessType=queen; break;
            case 27:x=3; y=1; chessType=queen; break;
            case 28:x=4; y=1; chessType=queen; break;
            case 29:x=5; y=1; chessType=queen; break;
            case 30:x=6; y=1; chessType=queen; break;
            case 31:x=7; y=1; chessType=queen; break;

        }
    }
    else if(start::knight==1){
        switch(n){
            case 0:x=0; y=7; chessType=knight; break;
            case 1:x=1; y=7; chessType=knight; break;
            case 2:x=2; y=7; chessType=knight; break;
            case 3:x=3; y=7; chessType=knight; break;
            case 4:x=4; y=7; chessType=king; break;
            case 5:x=5; y=7; chessType=knight; break;
            case 6:x=6; y=7; chessType=knight; break;
            case 7:x=7; y=7; chessType=knight; break;
            case 8:x=0; y=6; chessType=knight; break;
            case 9:x=1; y=6; chessType=knight; break;
            case 10:x=2; y=6; chessType=knight; break;
            case 11:x=3; y=6; chessType=knight; break;
            case 12:x=4; y=6; chessType=knight; break;
            case 13:x=5; y=6; chessType=knight; break;
            case 14:x=6; y=6; chessType=knight; break;
            case 15:x=7; y=6; chessType=knight; break;
            case 16:x=0; y=0; chessType=knight; break;
            case 17:x=1; y=0; chessType=knight; break;
            case 18:x=2; y=0; chessType=knight; break;
            case 19:x=3; y=0; chessType=knight; break;
            case 20:x=4; y=0; chessType=king; break;
            case 21:x=5; y=0; chessType=knight; break;
            case 22:x=6; y=0; chessType=knight; break;
            case 23:x=7; y=0; chessType=knight; break;
            case 24:x=0; y=1; chessType=knight; break;
            case 25:x=1; y=1; chessType=knight; break;
            case 26:x=2; y=1; chessType=knight; break;
            case 27:x=3; y=1; chessType=knight; break;
            case 28:x=4; y=1; chessType=knight; break;
            case 29:x=5; y=1; chessType=knight; break;
            case 30:x=6; y=1; chessType=knight; break;
            case 31:x=7; y=1; chessType=knight; break;

        }

    }
    else if(start::normal==1){
        switch(n){
            case 0:x=0; y=7; chessType=rook; break;
            case 1:x=1; y=7; chessType=knight; break;
            case 2:x=2; y=7; chessType=bishop; break;
            case 3:x=3; y=7; chessType=queen; break;
            case 4:x=4; y=7; chessType=king; break;
            case 5:x=5; y=7; chessType=bishop; break;
            case 6:x=6; y=7; chessType=knight; break;
            case 7:x=7; y=7; chessType=rook; break;
            case 8:x=0; y=6; chessType=pawn; break;
            case 9:x=1; y=6; chessType=pawn; break;
            case 10:x=2; y=6; chessType=pawn; break;
            case 11:x=3; y=6; chessType=pawn; break;
            case 12:x=4; y=6; chessType=pawn; break;
            case 13:x=5; y=6; chessType=pawn; break;
            case 14:x=6; y=6; chessType=pawn; break;
            case 15:x=7; y=6; chessType=pawn; break;
            case 16:x=0; y=0; chessType=rook; break;
            case 17:x=1; y=0; chessType=knight; break;
            case 18:x=2; y=0; chessType=bishop; break;
            case 19:x=3; y=0; chessType=queen; break;
            case 20:x=4; y=0; chessType=king; break;
            case 21:x=5; y=0; chessType=bishop; break;
            case 22:x=6; y=0; chessType=knight; break;
            case 23:x=7; y=0; chessType=rook; break;
            case 24:x=0; y=1; chessType=pawn; break;
            case 25:x=1; y=1; chessType=pawn; break;
            case 26:x=2; y=1; chessType=pawn; break;
            case 27:x=3; y=1; chessType=pawn; break;
            case 28:x=4; y=1; chessType=pawn; break;
            case 29:x=5; y=1; chessType=pawn; break;
            case 30:x=6; y=1; chessType=pawn; break;
            case 31:x=7; y=1; chessType=pawn; break;
        }
    }
}
QString pieces::getType(){
    switch(chessType){
        case pawn: return "pawn"; break;
        case rook: return "rook"; break;
        case knight: return "knight"; break;
        case bishop: return "bishop"; break;
        case queen: return "queen"; break;
        case king: return "king"; break;
    }
}
