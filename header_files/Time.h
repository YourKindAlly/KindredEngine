#ifndef SDL3TEST_TIME_H
#define SDL3TEST_TIME_H

#include <SDL3/SDL.h>

class Time {
public:
    [[nodiscard]] float Get_Delta_Time() const;
    void Update_Delta_Time();
    void Set_Time_Scale(float scale);
private:
    float delta_time = 0;
    float time_scale = 1;
    Uint64 last_time = 0;
    float scaled_delta_time = 0;
};


#endif //SDL3TEST_TIME_H