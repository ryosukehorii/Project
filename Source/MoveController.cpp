#include "MoveController.hpp"
#include <cmath>

#define DEFORTSPEED (2.0f)

void MoveController::Init()
{

}

void MoveController::Update(int key, const float camera_angle_y)
{
    DrawFormatString(0, 20, GetColor(255, 0, 0), "x %f z%f", pos.x, pos.z);
    // 何も押されていない時は何もしない
    if (key == 0) return;

    // キー入力に応じた移動の「オフセット角度」を計算
    float move_angle = camera_angle_y;

    if (key == Front) { move_angle += 0.0f; }                   // 前
    if (key == Back) { move_angle += DX_PI_F; }                 // 後 (180度)
    if (key == Left) { move_angle -= (DX_PI_F / 2.0f); }        // 左 (-90度)
    if (key == Right) { move_angle += (DX_PI_F / 2.0f); }        // 右 (+90度)
    // ※斜め移動（W+Aなど）も組み合わせる場合は適宜角度を調整
    // AND演算子（&）でそのビットが立っているか判定
    
    // カメラの角度に合わせて移動ベクトルを計算
    // （※カメラの座標計算の向きと合わせて sin / cos を調整します）
    pos.x -= sinf(move_angle) * 5.0f;
    pos.z -= cosf(move_angle) * 5.0f;
    angle = move_angle;
}

void MoveController::End()
{

}