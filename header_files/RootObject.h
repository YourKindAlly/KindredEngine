#ifndef KINDREDENGINE_ROOTOBJECT_H
#define KINDREDENGINE_ROOTOBJECT_H

#include "Object.h"
#include "../game/Player.h"

class RootObject final : public Object {
    std::shared_ptr<Player> player = std::make_shared<Player>();
};


#endif //KINDREDENGINE_ROOTOBJECT_H