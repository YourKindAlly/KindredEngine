#include "../header_files/Time.h"

float Time::Get_Delta_Time() const {
    return delta_time;
}

void Time::Update_Delta_Time() {
    const auto now = SDL_GetTicks();
    delta_time = static_cast<float>(now - last_time) / 1000;
    last_time = now;
    scaled_delta_time = delta_time * time_scale;
}

void Time::Set_Time_Scale(const float scale) {
    if (scale < 0)
        return;

    time_scale = scale;
}