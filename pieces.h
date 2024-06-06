#ifndef PIECES_H
#define PIECES_H

#include <QWidget>

class pieces:public QWidget
{
    Q_OBJECT

public:
    explicit pieces(QWidget *parent = 0);
    enum TYPE {rook,knight,bishop,queen,king,pawn};
    void startChess(const int n);
    QString getType();
    int x,y,num,moved=0;
    bool white,dead;
    TYPE chessType;

};

#endif // PIECES_H
