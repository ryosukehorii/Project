#include <cmath>
#include "CameraController.hpp"

void CameraController::Init()
{
	angle_y = 0.0f;
}

void CameraController::Update()
{
    int mouse_x = 0;
    int mouse_y = 0;
    static int prev_mouse_x = 0;
    static int prev_mouse_y = 0;

    GetMousePoint(&mouse_x, &mouse_y);

    int diff_x = mouse_x - 320;
    //int diff_x = mouse_x - prev_mouse_x;

    // カメラの回転角度を更新
    angle_y += diff_x * 0.002f;

    prev_mouse_x = mouse_x;
    prev_mouse_y = mouse_y;
    // 毎フレーム中央に戻す
    SetMousePoint(320, 240);

}

void CameraController::End()
{

}

void CameraController::SetCamera(VECTOR target_pos,float offset_y)
{
    float distance = -600.0f;

    // キャラの座標を中心に、角度 angle_y の位置にカメラを配置
    // カメラをキャラの後ろ（-sin, -cos）に配置する
    float camera_x = target_pos.x - sinf(angle_y) * distance;
    float camera_z = target_pos.z - cosf(angle_y) * distance;
    float camera_y = target_pos.y + offset_y; // 少し見下ろす高さ

    VECTOR camera_pos = VGet(camera_x, camera_y, camera_z);
    
    SetCameraPositionAndTarget_UpVecY(camera_pos, target_pos);
    // 白の色コードを保存
    unsigned int Cr = GetColor(255, 255, 255);
    DrawFormatString(0, 0, Cr, "カメラ角度 %f", angle_y);
    DrawFormatString(0, 40, GetColor(255, 0, 0), "camera_x %f camera_z%f", camera_pos.x, camera_pos.z);
    DrawFormatString(0, 60, GetColor(255, 0, 0), "angle %f", angle_y);
}