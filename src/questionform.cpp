#include "questionform.h"
#include "ui_questionform.h"

QuestionForm::QuestionForm(QWidget *parent, MultiChoiceQuestion question) :
    QWidget(parent),
    ui(new Ui::QuestionForm)
{
    ui->setupUi(this);

    this->question = question;
    setupFormLayout();
}

QuestionForm::~QuestionForm()
{
    delete ui;
}

void QuestionForm::setupFormLayout()
{
    formLayout = new QFormLayout();

    radioButton = new QRadioButton();
    questionLabel = new QLabel(question.getQuestion());

    formLayout->addRow(radioButton, questionLabel);

    this->setLayout(formLayout);
}
