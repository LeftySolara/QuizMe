#ifndef QUESTIONFORM_H
#define QUESTIONFORM_H

#include "multichoicequestion.h"
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QRadioButton>

namespace Ui {
class QuestionForm;
}

class QuestionForm : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionForm(QWidget *parent = 0, MultiChoiceQuestion question = MultiChoiceQuestion());
    ~QuestionForm();

    void setupFormLayout();

private:
    Ui::QuestionForm *ui;

    MultiChoiceQuestion question;
    QFormLayout *formLayout;
    QLabel *numberLabel;
    QLabel *questionLabel;
    QRadioButton *radioButton;
};

#endif // QUESTIONFORM_H
