#include "DxLib.h"

#include "KeyBord.hpp"
#include "Character.hpp"
#include "AnimationController.hpp"
#include "CameraController.hpp"

#define SCREAN_SIZEX (1200)
#define SCREAN_SIZEY (800)
#define SCREAN_RIFRESH (0) 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(true); // Windowモード
    // 画面モードの設定
    SetGraphMode(SCREAN_SIZEX, SCREAN_SIZEY, SCREAN_RIFRESH);
    
    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    // Ｚバッファを有効にする
    SetUseZBuffer3D(TRUE);

    // Ｚバッファへの書き込みを有効にする
    SetWriteZBuffer3D(TRUE);

    Character character;
    KeyBord key;
    AnimationController animation;
    CameraController camera;

    key.Init();
    character.Init();
    animation.Init();
    camera.Init();
    character.SetBind(animation, key, camera);

    while(CheckHitKey(KEY_INPUT_Z) == 0)
    {
        ClearDrawScreen();  // 画面消去
        key.Update();
        character.Update();
        animation.Update();
        camera.Update();

        camera.SetCamera(character.GetMyPos(), character.GetOffSetY());
        character.Draw();
        DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
        // 画面フリップ
        ScreenFlip();
    }

    character.End();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
