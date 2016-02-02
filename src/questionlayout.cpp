#include "questionlayout.h"
#include "ui_questionlayout.h"

QuestionLayout::QuestionLayout(QWidget *parent, MultiChoiceQuestion question) :
    QWidget(parent),
    ui(new Ui::QuestionLayout)
{
    ui->setupUi(this);

    this->question = question;
    setupFormLayout();
}

QuestionLayout::~QuestionLayout()
{
    delete ui;
}

void QuestionLayout::setupFormLayout()
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
