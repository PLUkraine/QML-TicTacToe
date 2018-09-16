#ifndef CPUOPPONENT_H
#define CPUOPPONENT_H

#include <memory>

#include "opponent/igameai.h"
#include "opponent/basegameopponent.h"

class CpuOpponent : public BaseGameOpponent
{
    Q_OBJECT
private:
    std::unique_ptr<IGameAI> m_ai;
    bool m_isAiX;

public:
    explicit CpuOpponent(bool isAiX, QObject *parent = nullptr);

public:
    virtual void queryMove(GameBoard *model, bool isXTurn) override;
    virtual void endGame(GameBoard *) override;

private:
    void computeMove(GameBoard *model, bool isXTurn);
};

#endif // CPUOPPONENT_H
