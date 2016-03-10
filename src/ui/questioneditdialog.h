#ifndef QUESTIONEDITDIALOG_H
#define QUESTIONEDITDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>

namespace Ui {
class QuestionEditDialog;
}

class QuestionEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionEditDialog(int numChoices, QWidget *parent = 0);
    ~QuestionEditDialog();

    void setupLayoutMaster();
    void setupLayoutButtons();
    void setupLayoutForm();

    int position();
    int points();
    QString question();
    QString answer();
    QStringList choices();

private:
    Ui::QuestionEditDialog *ui;

    QVBoxLayout *layoutMaster;
    QHBoxLayout *layoutButtons;
    QFormLayout *layoutForm;

    QPushButton *buttonAccept;
    QPushButton *buttonReject;

    QSpinBox *spinboxPosition;
    QSpinBox *spinboxPoints;

    QLineEdit *lineEditQuestion;
    QLineEdit *lineEditAnswer;
    QLineEdit *lineEditChoice;

    const int numChoices;
};

#endif // QUESTIONEDITDIALOG_H
