#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QtNetwork>
#include <QTimer>

class MainWindow : public QDeclarativeView
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();

public slots:
    void sendMessage(const QString &message);

private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketError(QLocalSocket::LocalSocketError);
    void onSocketReadyRead();
    void onSocketStateChange(QLocalSocket::LocalSocketState );
    void tryConnect();
    void onConnectTimerTimeout();
    
private:
    QLocalSocket *m_socket;
    QTimer *m_connectTimer;
};

#endif // MAINWINDOW_H
