#include "CameraController.hpp"

void CameraController::Init()
{
	angle_y = 0.0f;
}

void CameraController::Update()
{
    int mouse_x = 0;
    int mouse_y = 0;

    GetMousePoint(&mouse_x, &mouse_y);

    // 画面中央
    const int center_x = 600;
    const int center_y = 400;

    int diff_x = mouse_x - center_x;

    // カメラの回転角度を更新
    angle_y += diff_x * 0.002f;
}

void CameraController::End()
{

}

void CameraController::SetCamera()
{
    VECTOR camera_pos = VGet(0.0f, 100.0f, -300.0f);

    VECTOR target_pos = VGet(0.0f, 0.0f, 0.0f);

    SetCameraPositionAndTarget_UpVecY(camera_pos, target_pos);
}