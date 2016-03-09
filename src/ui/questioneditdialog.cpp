#include "questioneditdialog.h"
#include "ui_questioneditdialog.h"

QuestionEditDialog::QuestionEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionEditDialog)
{
    ui->setupUi(this);

    setupLayoutButtons();
}

QuestionEditDialog::~QuestionEditDialog()
{
    delete ui;

    delete layoutForm;
    delete layoutButtons;
    delete layoutMaster
}

// Set up the layout containing the "accept" and "reject" buttons
QuestionEditDialog::setupLayoutButtons()
{
    layoutButtons = new QHBoxLayout;
    buttonAccept = new QPushButton("Accept");
    buttonReject = new QPushButton("Cancel");

    connect(buttonAccept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(buttonReject, SIGNAL(clicked()), this, SLOT(reject());

    layoutButtons->addWidget(buttonAccept);
    layoutButtons->addWidget(buttonReject);

    layoutButtons->setAlignment(Qt::AlignRight);

    buttonAccept.setSizePolicy(QSizePolicy::Fixed);
    buttonReject.setSizePolicy(QSizePolicy::Fixed);
}
