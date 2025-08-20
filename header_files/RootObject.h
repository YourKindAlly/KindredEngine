#ifndef KINDREDENGINE_ROOTOBJECT_H
#define KINDREDENGINE_ROOTOBJECT_H

#include "Object.h"

class GameWindow;

class RootObject final : public Object {
public:
    explicit RootObject(GameWindow* window);
};


#endif //KINDREDENGINE_ROOTOBJECT_H