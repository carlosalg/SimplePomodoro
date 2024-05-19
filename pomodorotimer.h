#ifndef POMODOROTIMER_H
#define POMODOROTIMER_H

#include <QObject>
#include <qqml.h>

#include <QTimer>




class PomodoroTimer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playPause READ play NOTIFY playChanged FINAL)
    Q_PROPERTY(int minutes READ minutes NOTIFY timeUpdate FINAL)
    Q_PROPERTY(int seconds READ seconds NOTIFY timeUpdate FINAL)
    Q_PROPERTY(int cycle READ cycle NOTIFY cycleChanged FINAL)
    QML_ELEMENT
public:
    explicit PomodoroTimer(QObject *parent = nullptr);
    ~PomodoroTimer();

    bool play() const;


    int minutes() const;

    int seconds() const;

    int cycle() const;

public slots:
    void leftTime();
    void startNewCycles();
    void start();
    void stop();

signals:
    void timeUpdate();
    void playChanged();

    int minutesChanged(int);

    int secondsChanged(int);

    void cycleChanged();

private:
    QTimer* m_timer;
    int m_numberOfCycles;
    int m_leftTime;
    bool m_playPause;
    int m_minutes;
    int m_seconds;
    void setPlayPause(bool newIo);
    int m_cycle;
    int m_remainingTime;
};

#endif // POMODOROTIMER_H
