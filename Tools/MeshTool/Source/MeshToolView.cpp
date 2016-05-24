#include "MeshToolView.h"
#include "ui_MeshToolView.h"

MeshToolView::MeshToolView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeshToolView)
{
    ui->setupUi(this);
}

MeshToolView::~MeshToolView()
{
    delete ui;
}
