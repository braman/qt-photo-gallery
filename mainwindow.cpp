#include <QtGui>
#include "mainwindow.h"
MainWindow::MainWindow()
{
    //setCentralWidget(this);
    //textEdit->setAcceptDrops(false);
    setAcceptDrops(true);
    setWindowTitle(tr("Gallery v1.0"));
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    
    /*
        QMessageBox::information(this, tr("My App"),
                                         "image",
                                          QMessageBox::Close);
            
        
    
    QMimeData *mime = event->mimeData();
    if(event->mimeData()->hasImage())
    */
    //foreach(QString format,list)
     //   {
        
       // if(event->mimeData()->hasFormat(format))
     //  if(list.contains(event->mimeData()->data()))
        event->acceptProposedAction();
     //   }
   }

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QByteArray> list = QImageWriter::supportedImageFormats ();
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
            return;
    foreach(QUrl url,urls)
        foreach(QString format,list)
        {
            if(url.toString().endsWith(format))
            {
                //QString fileName = url.toLocalFile();
                files.append(url);
                update();
                //if (fileName.isEmpty())
                //    return;
                //if (readFile(fileName))
                //    setWindowTitle(tr("%1 - %2").arg(fileName)
            //                                    .arg(tr("Drag File")));
            }
        }
}

void MainWindow::paintEvent(QPaintEvent *event)
     {
     //QPainter painter(this);
    // painter.drawImage(0,0,QImage(fname));                                   
     QPainter painter(this);
     painter.setPen(Qt::blue);
     painter.setFont(QFont("Arial", 30));
     //painter.drawText(rect(), Qt::AlignCenter, "Qt");
     foreach(QUrl url,files)
        {
        painter.drawImage(qrand()%width(),qrand()%height(),QImage(url.toLocalFile()));
        }
     }

