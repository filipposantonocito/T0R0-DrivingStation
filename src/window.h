#ifndef WINDOW_H
#define WINDOW_H

#include <QKeyEvent>
#include <QLabel>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class QBoxLayout;
class QLabel;


class Window : public QWidget
{
	Q_OBJECT

public:
    explicit Window(QRect screen, QWidget *parent = 0);
		~Window();

public Q_SLOTS:

protected:
	void keyPressEvent(QKeyEvent *e);

private:
    bool connected;
};

#endif // WINDOW_H
