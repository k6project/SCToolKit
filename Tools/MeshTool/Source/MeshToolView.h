#ifndef MESHTOOLVIEW_H
#define MESHTOOLVIEW_H

#include <QWidget>

namespace Ui {
class MeshToolView;
}

class MeshToolView : public QWidget
{
    Q_OBJECT

public:
    explicit MeshToolView(QWidget *parent = 0);
    ~MeshToolView();

private:
    Ui::MeshToolView *ui;
};

#endif // MESHTOOLVIEW_H
