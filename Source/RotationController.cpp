#include "RotationController.hpp"
#include <cmath>

void RotationController::Init()
{
    angle_y = 0.0f;
}

void RotationController::Update(VECTOR char_pos)
{
    int mouse_x = 0;
    int mouse_y = 0;
    GetMousePoint(&mouse_x, &mouse_y);

    // 2Dのマウス座標を3D空間のレイに変換
    VECTOR line_start = ConvScreenPosToWorldPos(VGet((float)mouse_x, (float)mouse_y, 0.0f));
    VECTOR line_end = ConvScreenPosToWorldPos(VGet((float)mouse_x, (float)mouse_y, 1.0f));

    float dir_y = line_end.y - line_start.y;
    if (std::abs(dir_y) < 0.0001f)
    {
        return;
    }

    // キャラと同じ高さの平面との交点を計算
    float t = (char_pos.y - line_start.y) / dir_y;
    VECTOR target_pos;
    target_pos.x = line_start.x + (line_end.x - line_start.x) * t;
    target_pos.z = line_start.z + (line_end.z - line_start.z) * t;

    // 向き（角度）を計算
    float dx = target_pos.x - char_pos.x;
    float dz = target_pos.z - char_pos.z;

    angle_y = atan2f(dx, dz);
}