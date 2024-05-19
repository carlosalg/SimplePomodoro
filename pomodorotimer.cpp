#include "pomodorotimer.h"
#include <QTimer>

using namespace std;


PomodoroTimer::PomodoroTimer(QObject *parent)
    : QObject{parent}, m_timer(new QTimer(this)), m_numberOfCycles(0), m_playPause(false), m_minutes(0), m_seconds(0)
{
    connect(m_timer, &QTimer::timeout, this, &PomodoroTimer::leftTime);
}

PomodoroTimer::~PomodoroTimer()
{
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
}

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
    if(!m_playPause){
        setPlayPause(true);
        startNewCycles();
    }
}

void PomodoroTimer::stop()
{
    if(m_playPause){
        setPlayPause(false);
        if(m_timer){
            m_timer->stop();
        }
        m_cycle = 0;
        emit cycleChanged();
    }
    exit(0);
}

void PomodoroTimer::startNewCycles()
{
    if(m_numberOfCycles >= 4){
        stop();
        return;
    }
    m_remainingTime = 30;

    m_timer->start(1000);
    m_cycle = m_numberOfCycles;
    emit cycleChanged();
}

void PomodoroTimer::leftTime()
{

    if(!m_playPause){
       return;
    }

    if(m_remainingTime <=0){
        m_minutes = 0;
        m_seconds = 0;
        emit timeUpdate();
        m_timer->stop();
        m_numberOfCycles++;
        startNewCycles();
        return;
    }

    m_remainingTime--;

    m_minutes = m_remainingTime / 60;
    m_seconds = m_remainingTime % 60;
    emit timeUpdate();

}

int PomodoroTimer::minutes() const
{
    return m_minutes;
}

int PomodoroTimer::seconds() const
{
    return m_seconds;
}

int PomodoroTimer::cycle() const
{
    return m_cycle;
}
