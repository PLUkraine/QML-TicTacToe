#include "opponent/cpuopponent.h"

#include <QtConcurrent/QtConcurrentRun>
#include "opponent/perfectgameai.h"

CpuOpponent::CpuOpponent(bool isAiX, QObject *parent)
    : BaseGameOpponent(parent),
      m_ai(new PerfectGameAi()),
      m_isAiX(isAiX)
{
}

void CpuOpponent::queryMove(GameBoard *model, bool isXTurn)
{
    QtConcurrent::run(this, &CpuOpponent::computeMove, model, isXTurn);
}

void CpuOpponent::endGame(GameBoard *)
{
    // do nothing
}

void CpuOpponent::computeMove(GameBoard *model, bool)
{
    int index = m_ai->makeMove(model, m_isAiX);
    emit moveSuccess(index);
}
