#include "../../header_files/CollisionHolder.h"

CollisionHolder::CollisionHolder(GameWindow *window) : Object(window) { }

void CollisionHolder::On_Collision_Enter(const CollisionBox &other) { }

void CollisionHolder::On_Collision_Exit(const CollisionBox &other) { }
