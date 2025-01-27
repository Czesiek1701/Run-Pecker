#ifndef GAMEPAUSE_H
#define GAMEPAUSE_H

#include <QWidget>

namespace Ui {
class GamePause;
}

class GamePause : public QWidget
{
    Q_OBJECT
public:
    explicit GamePause(QWidget *parent = nullptr);
    virtual ~GamePause();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_Start_clicked();

    void on_pushButton_Exit_clicked();

signals:
    void s_exitGame();
    void s_startGame();

private:
    Ui::GamePause *ui;
};

#endif // GAMEPAUSE_H
