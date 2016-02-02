#ifndef QUESTIONLAYOUT_H
#define QUESTIONLAYOUT_H

#include "multichoicequestion.h"
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QRadioButton>

namespace Ui {
class QuestionLayout;
}

class QuestionLayout : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionLayout(QWidget *parent = 0, MultiChoiceQuestion question = MultiChoiceQuestion());
    ~QuestionLayout();

    void setupFormLayout();

private:
    Ui::QuestionLayout *ui;

    MultiChoiceQuestion question;
    QFormLayout *formLayout;
    QLabel *numberLabel;
    QLabel *questionLabel;
    QLabel *answerLabel;
    QRadioButton *radioButton;
};

#endif // QUESTIONLAYOUT_H
