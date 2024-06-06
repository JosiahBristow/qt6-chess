#include "setting.h"
#include "ui_setting.h"
#include <QPainter>
#include <QFont>
#include <QLabel>
#include <QWidget>
#include <QToolTip>
#include <QMouseEvent>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QPushButton>
#include <QProcess>
#include <QDialog>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
// #include <QSound>
#include <cmath>
#include "start.h"
bool startGame=false;
int whiteTurn=1;
void setting::on_pushButton_clicked()
{
    // QSound::play(":/pics/sound/clickbutton.wav");
    ui->pushButton->setVisible(false);
    startGame=true;
}//开始游戏并播放开始音乐

QLabel *label[32];
QVector<QString> pic;
void setting::getPicName(){
    pic.append(":/pics/pic/white rook.png");
    pic.append(":/pics/pic/white knight.png");
    pic.append(":/pics/pic/white bishop.png");
    pic.append(":/pics/pic/white queen.png");
    pic.append(":/pics/pic/white king.png");
    pic.append(":/pics/pic/white pawn.png");
    pic.append(":/pics/pic/black rook.png");
    pic.append(":/pics/pic/black knight.png");
    pic.append(":/pics/pic/black bishop.png");
    pic.append(":/pics/pic/black queen.png");
    pic.append(":/pics/pic/black king.png");
    pic.append(":/pics/pic/black pawn.png");
}//棋子图片获取

setting::setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setting)

{
        ui->setupUi(this);
        this->setWindowTitle("国际象棋");
        this->setWindowIcon(QIcon(":/pics/pic/black king.png"));
        this->setGeometry(350,40,800,800);
        QString name;
        getPicName();
        if(start::queen==1){
    for (int i=0;i<32;i++){
        myChess[i].startChess(i);
        if (i<=3)
            name=pic.at(3);
        if (i==4)
            name=pic.at(4);
        else if (i>3&&i<=7)
            name=pic.at(3);
        else if (i>=8&&i<=15)
            name=pic.at(3);
        if (i==20)
            name=pic.at(10);
        else if (i>=16&&i<20)
            name=pic.at(9);
        else if (i>=21&&i<=23)
            name=pic.at(9);
        else if (i>=24)
            name=pic.at(9);
        label[i]=new QLabel(this);
        label[i]->resize(75,75);
        label[i]->setPixmap(QPixmap(name));
        label[i]->setFixedSize(75,75);
        label[i]->setScaledContents(true);
        label[i]->setGeometry((myChess[i].x+1)*75,(myChess[i].y+1)*75,75,75);
        update();
    }
        }
        else if(start::knight==1){
    for (int i=0;i<32;i++){
        myChess[i].startChess(i);
        if (i<=3)
            name=pic.at(1);
        if (i==4)
            name=pic.at(4);
        else if (i>3&&i<=7)
            name=pic.at(1);
        else if (i>=8&&i<=15)
            name=pic.at(1);
        if (i==20)
            name=pic.at(10);
        else if (i>=16&&i<20)
            name=pic.at(7);
        else if (i>=21&&i<=23)
            name=pic.at(7);
        else if (i>=24)
            name=pic.at(7);
        label[i]=new QLabel(this);
        label[i]->resize(75,75);
        label[i]->setPixmap(QPixmap(name));
        label[i]->setFixedSize(75,75);
        label[i]->setScaledContents(true);
        label[i]->setGeometry((myChess[i].x+1)*75,(myChess[i].y+1)*75,75,75);
        update();
    }
        }
        else if(start::queenpro==1){
            for (int i=0;i<32;i++){
                myChess[i].startChess(i);
                if (i<=3)
                    name=pic.at(3);
                if (i==4)
                    name=pic.at(4);
                else if (i>3&&i<=7)
                    name=pic.at(3);
                if (i==8)
                    name=pic.at(3);
                if (i==15)
                    name=pic.at(2);
                else if (i>8&&i<15)
                    name=pic.at(3);
                if (i==20)
                    name=pic.at(10);
                if (i==24)
                    name=pic.at(9);
                else if (i>=16&&i<20)
                    name=pic.at(9);
                else if (i>=21&&i<=23)
                    name=pic.at(9);
                else if (i>24)
                    name=pic.at(9);
                label[i]=new QLabel(this);
                label[i]->resize(75,75);
                label[i]->setPixmap(QPixmap(name));
                label[i]->setFixedSize(75,75);
                label[i]->setScaledContents(true);
                label[i]->setGeometry((myChess[i].x+1)*75,(myChess[i].y+1)*75,75,75);
                update();
        }
        }
        else if(start::normal==1){
            for (int i=0;i<32;i++){
                myChess[i].startChess(i);
                if (i<=4)
                    name=pic.at(i);
                else if (i>=5&&i<=7)
                    name=pic.at(7-i);
                else if (i>=8&&i<=15)
                    name=pic.at(5);
                else if (i>=16&&i<=20)
                    name=pic.at(i-10);
                else if (i>=21&&i<=23)
                    name=pic.at(29-i);
                else if (i>=24)
                    name=pic.at(11);
                label[i]=new QLabel(this);
                label[i]->resize(75,75);
                label[i]->setPixmap(QPixmap(name));
                label[i]->setFixedSize(75,75);
                label[i]->setScaledContents(true);
                label[i]->setGeometry((myChess[i].x+1)*75,(myChess[i].y+1)*75,75,75);
                update();
        }
}
        start::normal=0;
        start::queen=0;
        start::queenpro=0;
        start::knight=0;
        whiteTurn=1;
}
//棋子放置
setting::~setting()
{
    delete ui;
}
void setting::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
            if (i%2!=0){
                if (j%2!=0)
                    painter.setBrush(Qt::white);
                else
                    painter.setBrush(Qt::darkGray);
                painter.drawRect(i*75,j*75,75,75);
            }
            else {
                if(j%2!=0)
                    painter.setBrush(Qt::darkGray);
                else
                    painter.setBrush(Qt::white);
                painter.drawRect(i*75,j*75,75,75);
            }
}//棋盘绘制
void setting::mouseMoveEvent(QMouseEvent *e){
    QToolTip::showText(e->globalPos(), QString("( %1, %2)").arg(e->x()).arg(e->y()));
    update();
}//获取鼠标坐标
int setting::getNum(int xp, int yp){
    for (int i=0;i<32;i++)
        if (myChess[i].x==xp&&myChess[i].y==yp)
            return i;
    return -1;
}//获取棋子编号

bool setting::exist(int xp, int yp){
    for (int i=0;i<32;i++)
        if (myChess[i].x==xp&&myChess[i].y==yp)
            return true;
    return false;
}//判断该位置是否有棋子

bool setting::middleChess(int n, int xp, int yp){
    if (myChess[n].x==xp){ //in the same column
        if (yp>myChess[n].y){
            for (int i=myChess[n].y+1;i<yp;i++)
                if (exist(xp,i))
                    return true;
        }
        else {
            for (int i=yp+1;i<myChess[n].y;i++)
                if (exist(xp,i))
                    return true;
        }
    }
    else if (myChess[n].y==yp){
        if (xp>myChess[n].x){
            for (int i=myChess[n].x+1;i<xp;i++)
                if (exist(i,yp))
                    return true;
        }
        else {
            for (int i=xp+1;i<myChess[n].x;i++)
                if (exist(i,yp))
                    return true;
        }
    }
    else{
        if (xp>myChess[n].x){
            if (yp>myChess[n].y){
                int j=myChess[n].y+1;
                for (int i=myChess[n].x+1;i<xp;i++)
                    if (exist(i,j))
                        return true;
                    else
                        j++;
            }
            else{
                int j=myChess[n].y-1;
                for (int i=myChess[n].x+1;i<xp;i++)
                    if (exist(i,j))
                        return true;
                    else
                        j--;
            }
        }
        else{
            if (yp>myChess[n].y){
                int j=myChess[n].y+1;
                for (int i=myChess[n].x-1;i>xp;i--)
                    if (exist(i,j))
                        return true;
                    else
                        j++;
            }
            else{
                int j=myChess[n].y-1;
                for (int i=myChess[n].x-1;i>xp;i--)
                    if (exist(i,j))
                        return true;
                    else
                        j--;
            }
        }
    }
    return false;
}//判断行棋路径上有无子的阻挡

bool setting::sameColor(int n1, int n2){
    if (myChess[n1].white==myChess[n2].white)
        return true;
    return false;
}//判断颜色是否一致
bool setting::threat(int n, int xk, int yk){
    if (myChess[n].dead)
        return false;
    if (myChess[n].chessType==0){ //rook
        if (myChess[n].x==xk||myChess[n].y==yk){
            if (middleChess(n,xk,yk))
                return false;
            else
                return true;
         }
         else
            return false;
    }
    else if (myChess[n].chessType==1){ //knight
        if (abs(xk-myChess[n].x)==1&&abs(yk-myChess[n].y)==2)
            return true;
        else if (abs(xk-myChess[n].x)==2&&abs(yk-myChess[n].y)==1)
            return true;
        else
            return false;
    }
    else if (myChess[n].chessType==2){ //bishop
        if (abs(xk-myChess[n].x)==abs(yk-myChess[n].y)){
            if (middleChess(n,xk,yk))
                return false;
            else
                return true;
        }
        else
            return false;
    }
    else if (myChess[n].chessType==3){ //queen
        if (myChess[n].x==xk||myChess[n].y==yk){
            if (middleChess(n,xk,yk))
                return false;
            else
                return true;
        }
        else if (abs(xk-myChess[n].x)==abs(yk-myChess[n].y)){
            if (middleChess(n,xk,yk))
                return false;
            else
                return true;
        }
        else
            return false;
    }
    else if (myChess[n].chessType==4){ //king
        if (abs(myChess[n].x-xk)==1&&abs(myChess[n].y-yk)==1)
            return true;
        else if (myChess[n].x==xk&&abs(myChess[n].y-yk)==1)
            return true;
        else if (abs(myChess[n].x-xk)==1&&myChess[n].y==yk)
            return true;
        else
            return false;
    }
    else if (myChess[n].chessType==5){ //pawn
        if (myChess[n].white){
            if ((myChess[n].y-yk)==1&&abs(myChess[n].x-xk)==1)
                return true;
            else
                return false;
        }
        else{
            if ((yk-myChess[n].y)==1&&abs(xk-myChess[n].x)==1)
                return true;
            else
                return false;
        }
    }
}
        //判断王是否正在被将
bool setting::moveRook(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (exist(xp,yp)&&sameColor(n1,n2))
        return false;
    if (middleChess(n1,xp,yp))
        return false;
    if (xp!=myChess[n1].x&&yp!=myChess[n1].y)
        return false;
    return true;
}//车的走法

bool setting::moveKnight(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (exist(xp,yp)&&sameColor(n1,n2))
        return false;
    if (abs(xp-myChess[n1].x)==1&&abs(yp-myChess[n1].y)==2)
        return true;
    else if (abs(xp-myChess[n1].x)==2&&abs(yp-myChess[n1].y)==1)
        return true;
    return false;
}//马的走法

bool setting::moveBishop(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (exist(xp,yp)&&sameColor(n1,n2))
        return false;
    if (middleChess(n1,xp,yp))
        return false;
    if (abs(xp-myChess[n1].x)==abs(yp-myChess[n1].y))
        return true;
    return false;
}//象的走法

bool setting::moveQueen(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (exist(xp,yp)&&sameColor(n1,n2))
        return false;
    if (middleChess(n1,xp,yp))
        return false;
    if (xp==myChess[n1].x||yp==myChess[n1].y)
        return true;
    else if (abs(xp-myChess[n1].x)==abs(yp-myChess[n1].y))
        return true;
    return false;
}//后的走法

bool whiteCastled=false,blackCastled=false;
bool setting::castling(int n, int xp, int yp){
    if (myChess[n].white){
        if (xp>myChess[n].x){ //短易位
            if (!myChess[7].moved&&!myChess[n].moved){
                if (!middleChess(n,myChess[7].x,myChess[7].y)){
                    for (int i=16;i<32;i++){
                        if (threat(i,myChess[n].x,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x+1,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x+2,myChess[n].y))
                            return false;
                    }
                    myChess[7].x-=2;
                    label[7]->move((myChess[7].x+1)*75,(myChess[7].y+1)*75);
                }
            }
        }
        else{ //长易位
            if (!myChess[0].moved&&!myChess[n].moved){
                if (!middleChess(n,myChess[0].x,myChess[0].y)){
                    for (int i=16;i<32;i++){
                        if (threat(i,myChess[n].x,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x-1,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x-2,myChess[n].y))
                            return false;
                    }
                    myChess[0].x+=3;
                    label[0]->move((myChess[0].x+1)*75,(myChess[0].y+1)*75);
                }
            }

        }
        whiteCastled=true;
    }
    else{
        if (xp>myChess[n].x){ //短易位
            if (!myChess[23].moved&&!myChess[n].moved){
                if (!middleChess(n,myChess[23].x,myChess[23].y)){
                    for (int i=0;i<16;i++){
                        if (threat(i,myChess[n].x,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x+1,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x+2,myChess[n].y))
                            return false;
                    }
                    myChess[23].x-=2;
                    label[23]->move((myChess[23].x+1)*75,(myChess[23].y+1)*75);
                }
            }
        }
        else{ //长易位
            if (!myChess[16].moved&&!myChess[n].moved){
                if (!middleChess(n,myChess[16].x,myChess[16].y)){
                    for (int i=0;i<16;i++){
                        if (threat(i,myChess[n].x,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x-1,myChess[n].y))
                            return false;
                        if (threat(i,myChess[n].x-2,myChess[n].y))
                            return false;
                    }
                    myChess[16].x+=3;
                    label[16]->move((myChess[16].x+1)*75,(myChess[16].y+1)*75);
                }
            }
        }
        blackCastled=true;
    }
    return true;
}//王车易位

bool setting::moveKing(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (exist(xp,yp)&&sameColor(n1,n2))
        return false;
    if (abs(xp-myChess[n1].x)==1&&abs(yp-myChess[n1].y)==1)
        return true;
    if (xp==myChess[n1].x&&abs(yp-myChess[n1].y)==1)
        return true;
    if (abs(xp-myChess[n1].x)==1&&yp==myChess[n1].y)
        return true;
    if (yp==myChess[n1].y&&abs(xp-myChess[n1].x)==2){ //castling
        if (myChess[n1].white&&!whiteCastled)
            return castling(n1,xp,yp);
        else if (!myChess[n1].white&&!blackCastled)
            return castling(n1,xp,yp);
        else
            return false;
    }
    return false;
}
//王的走法
int white=16,black=16;
bool setting::movePawn(int n1, int n2, int xp, int yp){
    if (xp==myChess[n1].x&&yp==myChess[n1].y)
        return false;
    if (n2!=-1&&sameColor(n1,n2))
        return false;
    if (n2!=-1&&myChess[n1].x==xp&&abs(myChess[n1].y-yp)==1)
        return false;
    if (xp==myChess[n1].x){
        if (myChess[n1].white){
            if ((myChess[n1].y-yp)==2&&!myChess[n1].moved)
                return true;
            else if (myChess[n1].y-yp==1)
                return true;
        }
        else {
            if ((yp-myChess[n1].y)==2&&!myChess[n1].moved)
                return true;
            else if (yp-myChess[n1].y==1)
                return true;
        }
    }
    else if (abs(xp-myChess[n1].x)==1){
        if (myChess[n1].white&&(myChess[n1].y-yp==1)){
            if (n2!=-1)
                return true;
            else if (enPassant(n1,xp,yp))
                return true;
        }
        else if (!myChess[n1].white&&(yp-myChess[n1].y==1)){
            if (n2!=-1)
                return true;
            else if (enPassant(n1,xp,yp))
                return true;
        }
    }
    return false;
}//兵的走法
bool setting::enPassant(int n1, int xp, int yp){
    int n2=-1;
    if (myChess[n1].white){
        n2=getNum(xp,yp+1);
        if (n2>=24&&n2<32){
            if (myChess[n2].y==3&&myChess[n2].moved==1){
                myChess[n2].dead=true;
                myChess[n2].x=-1;
                myChess[n2].y=-1;
                label[n2]->clear();
                black--;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else{
        n2=getNum(xp,yp-1);
        if (n2>=8&&n2<16){
            if (myChess[n2].y==4&&myChess[n2].moved==1){
                myChess[n2].dead=true;
                myChess[n2].x=-1;
                myChess[n2].y=-1;
                label[n2]->clear();
                white--;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}//吃过路兵
bool isthreatened=false;
bool setting::move(int n1, int n2, int xp, int yp){
    if (n1>=0&&n1<=15){
        if (whiteTurn==1) ;
        else
            return false;
    }
    else if (n1>=16&&n1<=31){
        if (whiteTurn==1)
            return false;
    }
    else
        return false;
    if (xp<0||xp>7||yp<0||yp>7)
        return false;
    switch(myChess[n1].chessType){
        case 0:
            if(moveRook(n1,n2,xp,yp));
            else return false;
            break;
        case 1:
            if(moveKnight(n1,n2,xp,yp));
            else return false;
            break;
        case 2:
            if(moveBishop(n1,n2,xp,yp));
            else return false;
            break;
        case 3:
            if(moveQueen(n1,n2,xp,yp));
            else return false;
            break;
        case 4:
            if(moveKing(n1,n2,xp,yp));
            else return false;
            break;
        case 5:
            if(movePawn(n1,n2,xp,yp));
            else return false;
            break;
        default:
            return false;
            break;
    }

    int xt=myChess[n1].x,yt=myChess[n1].y;
    myChess[n1].x=xp;
    myChess[n1].y=yp;
    if (n2!=-1)
        myChess[n2].dead=true;
    if (myChess[n1].white){
        for (int i=16;i<32;i++){
            if (!myChess[i].dead&&threat(i,myChess[4].x,myChess[4].y)){
                isthreatened=true;
                break;
            }
            else isthreatened=false;
        }
    }
    else {
        for (int i=0;i<16;i++){
            if (!myChess[i].dead&&threat(i,myChess[20].x,myChess[20].y)){
                isthreatened=true;
                break;
            }
            else isthreatened=false;
        }
    }
    myChess[n1].x=xt;
    myChess[n1].y=yt;
    if (n2!=-1)
        myChess[n2].dead=false;
    if (isthreatened)
        return false;
    else
        return true;
}
//判断棋子移动是否合法
void setting::moveChess(int n1,int n2,int xp, int yp){
    if(whiteTurn==-1){
       ui->textBrowser->setText("轮到白方行棋");
    }
    else{
        ui->textBrowser->setText("轮到黑方行棋");
    }
    if (n2!=-1){
       myChess[n2].dead=true;
       myChess[n2].x=-1;
       myChess[n2].y=-1;
       label[n2]->clear();
       if (myChess[n2].white)
           white--;
       else
           black--;
    }
    myChess[n1].x=xp;
    myChess[n1].y=yp;
    label[n1]->move((xp+1)*75,(yp+1)*75);
    if (myChess[n1].chessType==pieces::pawn&&(yp==0||yp==7)){ //兵的升变
        QMessageBox mess(QMessageBox::Information, tr("QUESTION"), tr("你要升变吗"));
            QPushButton *buttonRook = (mess.addButton(tr("车"), QMessageBox::AcceptRole));
            QPushButton *buttonKnight = (mess.addButton(tr("马"), QMessageBox::YesRole));
            QPushButton *buttonBishop = (mess.addButton(tr("象"), QMessageBox::RejectRole));
            QPushButton *buttonQueen = (mess.addButton(tr("后"), QMessageBox::RejectRole));
        mess.exec();
        // QSound::play(":/pics/sound/pawn.wav");
        label[n1]->clear();
        if (mess.clickedButton()==buttonRook){
            myChess[n1].chessType=pieces::rook;
            if (myChess[n1].white)
                label[n1]->setPixmap(QPixmap(":/pics/pic/white rook.png"));
            else
                label[n1]->setPixmap(QPixmap(":/pics/pic/black rook.png"));
        }
        else if(mess.clickedButton()==buttonKnight){
            myChess[n1].chessType=pieces::knight;
            if (myChess[n1].white)
                label[n1]->setPixmap(QPixmap(":/pics/pic/white knight.png"));
            else
                label[n1]->setPixmap(QPixmap(":/pics/pic/black knight.png"));
        }
        else if(mess.clickedButton()==buttonBishop){
            myChess[n1].chessType=pieces::bishop;
            if (myChess[n1].white)
                label[n1]->setPixmap(QPixmap(":/pics/pic/white bishop.png"));
            else
                label[n1]->setPixmap(QPixmap(":/pics/pic/black bishop.png"));
        }
        else if(mess.clickedButton()==buttonQueen){
            myChess[n1].chessType=pieces::queen;
            if (myChess[n1].white)
                label[n1]->setPixmap(QPixmap(":/pics/pic/white queen.png"));
            else
                label[n1]->setPixmap(QPixmap(":/pics/pic/black queen.png"));
        }
        label[n1]->resize(75,75);
        label[n1]->setFixedSize(75,75);
        label[n1]->setScaledContents(true);
        label[n1]->setGeometry((myChess[n1].x+1)*75,(myChess[n1].y+1)*75,75,75);
    }
    update();
}//实际移动棋子，更新棋子状态（含兵的升变）
bool setting::legalMove(){
    int os=0,es=0,oe=0,ee=0,kg=0;
    if (whiteTurn==1){
        os=0;
        oe=16;
        es=16;
        ee=32;
        kg=4;
    }
    else{
        os=16;
        oe=32;
        es=0;
        ee=16;
        kg=20;
    }
    for (int i=os;i<oe;i++){
        int xt=myChess[i].x;
        int yt=myChess[i].y;
        int nt=-1,j=0,m=0;
        if (myChess[i].chessType==pieces::rook){
            for (;j<8;j++){
                nt=getNum(j,yt);
                if (move(i,nt,j,yt))
                    return true;
            }
            for (;m<8;m++){
                nt=getNum(xt,m);
                if (move(i,nt,xt,m))
                    return true;
            }
        }
        else if(myChess[i].chessType==pieces::knight){
            int xx[8]={xt-1,xt-1,xt-2,xt-2,xt+1,xt+1,xt+2,xt+2};
            int yy[8]={yt-2,yt+2,yt-1,yt+1,yt-2,yt+2,yt-1,yt+1};
            for (j=0;j<8;j++){
                nt=getNum(xx[j],yy[j]);
                if (move(i,nt,xx[j],yy[j]))
                    return true;
            }
        }
        else if (myChess[i].chessType==pieces::bishop){
            for (j=xt+1;j<8;j++){
                m=yt+j-xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt+1;j<8;j++){
                m=yt-j+xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt-1;j>=0;j--){
                m=yt+j-xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt-1;j>=8;j--){
                m=yt-j+xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
        }
        else if (myChess[i].chessType==pieces::queen){
            for (j=0;j<8;j++){
                nt=getNum(j,yt);
                if (move(i,nt,j,yt))
                    return true;
            }
            for (m=0;m<8;m++){
                nt=getNum(xt,m);
                if (move(i,nt,xt,m))
                    return true;
            }
            for (j=xt+1;j<8;j++){
                m=yt+j-xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt+1;j<8;j++){
                m=yt-j+xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt-1;j>=0;j--){
                m=yt+j-xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
            for (j=xt-1;j>=8;j--){
                m=yt-j+xt;
                nt=getNum(j,m);
                if (move(i,nt,j,m))
                    return true;
            }
        }
        else if (myChess[i].chessType==pieces::king){
            int xx[8]={xt-1,xt,xt+1,xt+1,xt+1,xt,xt-1,xt-1};
            int yy[8]={yt-1,yt-1,yt-1,yt,yt+1,yt+1,yt+1,yt};
            for (j=0;j<8;j++){
                nt=getNum(xx[j],yy[j]);
                if (move(i,nt,xx[j],yy[j]))
                    return true;
            }
        }
        else if (myChess[i].chessType==pieces::pawn){
            if (whiteTurn==1)
                m=yt-1;
            else
                m=yt+1;
            nt=getNum(xt,m);
            if (move(i,nt,xt,m))
                return true;
            j=xt-1;
            if (move(i,nt,j,m))
                return true;
            j=xt+1;
            if (move(i,nt,j,m))
                return true;
        }
    }
    return false;
}
//判定某方是否仍然还有合法移动便于判断结果
bool setting::checkmate(){
    if (whiteTurn==1){
        for (int i=16;i<32;i++){
            if (threat(i,myChess[4].x,myChess[4].y)){
                isthreatened=true;
                break;
            }
            else
                isthreatened=false;
        }
        if (isthreatened){
            if (!legalMove())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        for (int i=0;i<16;i++){
            if (threat(i,myChess[20].x,myChess[20].y)){
                isthreatened=true;
                break;
            }
            else
                isthreatened=false;
        }
        if (isthreatened){
            if (!legalMove())
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
//将杀
bool setting::draw(){
    if (white==1&&black==1)
        return true;
    else return false;
}//和棋
QMessageBox::StandardButton result;
void setting::mousePressEvent(QMouseEvent *e){
    static int move_flag=0,n1=0,n2=0;
    int xp=-1,yp=-1;
    for (int i=0;i<8;i++){
        for (int j=0;j<9;j++){
            if (pow(e->x()-(i+2)*75,2)+pow(e->y()-(j+1)*75,2)<pow(75,2)){
                xp=i;
                yp=j;
                break;
            }
        }
    }
    if (xp>-1&&yp>-1){
        switch (move_flag) {
        case 0:{
            n1=getNum(xp,yp);
            move_flag++;
        }
            break;
        case 1:{
            n2=getNum(xp,yp);
            move_flag++;
        }
            break;
        }
        if (move_flag==2){
            move_flag=0;
            if (move(n1,n2,xp,yp)) {
                // QSound::play(":/pics/sound/movechess.wav");
                moveChess(n1,n2,xp,yp);
                myChess[n1].moved++;
                whiteTurn*=-1;
                if (checkmate()||draw()){
                    // QSound::play(":/pics/sound/victory.wav");
                    if (checkmate()){
                        if (whiteTurn==1)
                            result=QMessageBox::information(NULL,"CONGRATULATION!","黑方胜",QMessageBox::Retry|QMessageBox::Ok);
                        else
                            result=QMessageBox::information(NULL,"CONGRATULATION!","白方胜",QMessageBox::Retry|QMessageBox::Ok);
                    }
                    else if (draw()){
                        result=QMessageBox::information(NULL,"CONGRATULATION!","和棋",QMessageBox::Retry|QMessageBox::Ok);
                    }
                    if (result==QMessageBox::Ok){
                        this->close();
                        QApplication::exit();
                    }
                    else{
                        QApplication::quit();
                        QProcess::startDetached(QApplication::applicationFilePath(),QStringList());
                    }
                }
            }
            else if (isthreatened){
                // QSound::play(":/pics/sound/warning.wav");
                QMessageBox::information(NULL,"WARNING","您正在被将军，或该步会被将军，无效动子",QMessageBox::Retry|QMessageBox::Ok,QMessageBox::Retry);
            }
            else{
                // QSound::play(":/pics/sound/warning.wav");
                QMessageBox::information(NULL,"WARNING","无效动子",QMessageBox::Retry|QMessageBox::Ok,QMessageBox::Retry);
            }
        }
    }
}
//鼠标点击，胜负的判定







