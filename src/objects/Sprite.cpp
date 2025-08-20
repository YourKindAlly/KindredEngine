#include "../../header_files/Sprite.h"

Sprite::Sprite(const char* path) : RenderObject(path) {
    texture_path = path;
}
