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

    questionLabel = new QLabel(question.getQuestion());
    numberLabel = new QLabel(QString::number(question.getPosition()) + ")");
    formLayout->addRow(numberLabel, questionLabel);

    // TODO: Make shuffling optional through settings menu
    question.shuffleChoices();
    for (int i = 0; i < question.choices.size(); ++i) {
        radioButton = new QRadioButton();
        answerLabel = new QLabel(question.choices[i]);
        formLayout->addRow(radioButton, answerLabel);
    }

    this->setLayout(formLayout);
}
