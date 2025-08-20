#include "../header_files/RootObject.h"
#include "../header_files/GameWindow.h"
#include "../game/Player.h"

RootObject::RootObject(GameWindow* window) : Object(window) {
    auto player = window->Create_Object<Player>();
    player->parent = this;
    children.push_back(player);
}