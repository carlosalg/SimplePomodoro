#include "pomodorotimer.h"
#include <QTimer>

using namespace std;
using namespace chrono;

PomodoroTimer::PomodoroTimer(QObject *parent)
    : QObject{parent}
{}



bool PomodoroTimer::play() const
{
    return m_playPause;
}

void PomodoroTimer::setPlayPause(bool newIo)
{
    if(m_playPause == newIo)
        return;
    m_playPause = newIo;
    emit playChanged();
}

void PomodoroTimer::start()
{
    setPlayPause(true);
    leftTime();
}

void PomodoroTimer::stop()
{
    setPlayPause(false);
}

void PomodoroTimer::leftTime()
{

    if(!m_playPause){
        return;
    }
    auto starTime = system_clock::now();
    auto targetTime = starTime + 25min;


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, targetTime, starTime, &timer](){
        auto remaining = std::chrono::duration_cast<std::chrono::seconds>(targetTime - system_clock::now());
        m_minutes = remaining.count() / 60;
        m_seconds = remaining.count() % 60;
        emit timeUpdate();

        if(targetTime <= system_clock::now()){
            timer->stop();
            delete timer;
        }
    });
    timer->start(1000);


}

int PomodoroTimer::minutes() const
{
    return m_minutes;
}

int PomodoroTimer::seconds() const
{
    if (m_seconds < 10){
        return m_seconds + 48;
    } else {
        return m_seconds;
    }
}
