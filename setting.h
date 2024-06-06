#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>
#include <QLabel>
#include "pieces.h"

namespace Ui {
class setting;
}

class setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();
    void paintEvent(QPaintEvent *event);
    void getPicName();
    pieces myChess[32];
    int getNum(int x,int y);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void moveChess(int n1,int n2,int xp,int yp);

    bool exist(int xp,int yp);
    bool middleChess(int n,int xp,int yp);
    bool sameColor(int n1,int n2);
    bool threat(int n,int xk,int yk);
    bool move(int n1,int n2,int xp,int yp);
    bool moveRook(int n1,int n2,int xp,int yp);
    bool moveKnight(int n1,int n2,int xp,int yp);
    bool moveBishop(int n1,int n2,int xp,int yp);
    bool moveQueen(int n1,int n2,int xp,int yp);
    bool moveKing(int n1,int n2,int xp,int yp);
    bool movePawn(int n1,int n2,int xp,int yp);
    bool castling(int n,int xp,int yp);
    bool enPassant(int n1,int xp,int yp);
    bool legalMove();
    bool checkmate();
    bool stalemate();
    bool draw();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setting *ui;
};

#endif // SETTING_H
