#include "questioneditdialog.h"
#include "ui_questioneditdialog.h"

QuestionEditDialog::QuestionEditDialog(int numChoices, QWidget *parent) :
    QDialog(parent), ui(new Ui::QuestionEditDialog), numChoices(numChoices)
{
    ui->setupUi(this);

    setupLayoutButtons();
    setupLayoutForm();
    setupLayoutMaster();

    setLayout(layoutMaster);
}

QuestionEditDialog::~QuestionEditDialog()
{
    delete ui;

    delete layoutForm;
    delete layoutButtons;
    delete layoutMaster;
}

void QuestionEditDialog::setupLayoutMaster()
{
    layoutMaster = new QVBoxLayout;
    layoutMaster->addLayout(layoutForm);
    layoutMaster->addLayout(layoutButtons);
}

// Set up the layout containing the "accept" and "reject" buttons
void QuestionEditDialog::setupLayoutButtons()
{
    layoutButtons = new QHBoxLayout;
    buttonAccept = new QPushButton("Accept");
    buttonReject = new QPushButton("Cancel");

    connect(buttonAccept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(buttonReject, SIGNAL(clicked()), this, SLOT(reject()));

    layoutButtons->addWidget(buttonAccept);
    layoutButtons->addWidget(buttonReject);

    layoutButtons->setAlignment(Qt::AlignRight);

//    buttonAccept->setSizePolicy(QSizePolicy::Fixed);
//    buttonReject->setSizePolicy(QSizePolicy::Fixed);
}

// Set up the form layout for editing a question
void QuestionEditDialog::setupLayoutForm()
{
    layoutForm = new QFormLayout;
    spinboxPoints = new QSpinBox;
    spinboxPosition = new QSpinBox;
    lineEditQuestion = new QLineEdit;
    lineEditAnswer = new QLineEdit;
    lineEditChoice = new QLineEdit;

    lineEditQuestion->setPlaceholderText("Enter a question");
    lineEditAnswer->setPlaceholderText("Enter the correct answer");
    lineEditChoice->setPlaceholderText("Enter another answer choice");

    layoutForm->addRow("Position", spinboxPosition);
    layoutForm->addRow("Points", spinboxPoints);
    layoutForm->addRow("Question", lineEditQuestion);
    layoutForm->addRow("Answer", lineEditAnswer);
    layoutForm->addRow("Choices", lineEditChoice);

    // add as many line edits as specified by the Quiz object
    for (int i = 0; i < numChoices - 1; ++i) {
        lineEditChoice = new QLineEdit;
        lineEditChoice->setPlaceholderText("Enter another answer choice");
        layoutForm->addRow(" ", lineEditChoice);
    }
}
