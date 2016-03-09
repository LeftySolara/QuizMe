#ifndef QUESTIONEDITDIALOG_H
#define QUESTIONEDITDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>

namespace Ui {
class QuestionEditDialog;
}

class QuestionEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionEditDialog(QWidget *parent = 0);
    ~QuestionEditDialog();

    setupLayoutButtons();
    setupLayoutForm();
    setupLayoutMaster();

private:
    Ui::QuestionEditDialog *ui;

    QVBoxLayout *layoutMaster;
    QHBoxLayout *layoutButtons;
    QFormLayout *layoutForm;

    QPushButton buttonAccept;
    QPushButton buttonReject;

    const int numChoices;
};

#endif // QUESTIONEDITDIALOG_H
