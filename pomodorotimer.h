#ifndef POMODOROTIMER_H
#define POMODOROTIMER_H

#include <QObject>
#include <qqml.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <ostream>


class PomodoroTimer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playPause READ play NOTIFY playChanged FINAL)
    Q_PROPERTY(int minutes READ minutes NOTIFY timeUpdate FINAL)
    Q_PROPERTY(int seconds READ seconds NOTIFY timeUpdate FINAL)
    QML_ELEMENT
public:
    explicit PomodoroTimer(QObject *parent = nullptr);

    bool play() const;


    int minutes() const;

    int seconds() const;

public slots:
    void leftTime();
    void start();
    void stop();

signals:
    void timeUpdate();
    void playChanged();

    int minutesChanged(int);

    int secondsChanged(int);

private:
    int m_leftTime;
    bool m_playPause;
    int m_minutes;
    int m_seconds;
    void setPlayPause(bool newIo);
};

#endif // POMODOROTIMER_H
