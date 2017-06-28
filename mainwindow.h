#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QtGui>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    QList<QUrl> files;
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void paintEvent(QPaintEvent * event);
    QPushButton *button;
private:
    //bool readFile(const QString &fileName);
    //QTextEdit *textEdit;
};
#endif
