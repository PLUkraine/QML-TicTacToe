#ifndef IGAMEAI_H
#define IGAMEAI_H

#include <utility>
#include "gameboard.h"

class IGameAI
{
public:
    virtual ~IGameAI();
    virtual int makeMove(GameBoard *model, bool isAiX)=0;
};

#endif // IGAMEAI_H
