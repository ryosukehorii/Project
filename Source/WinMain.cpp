#include "DxLib.h"

#include "KeyBord.hpp"
#include "Character.hpp"
#include "AnimationController.hpp"

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
    
    Character character;
    KeyBord key;
    AnimationController animation;

    key.Init();
    character.Init();
    animation.Init();
    character.SetBind(animation, key);

    while(CheckHitKey(KEY_INPUT_Z) == 0)
    {
        ClearDrawScreen();  // 画面消去
        key.Update();
        character.Update();
        animation.Update();
        
        character.Draw();
        // 画面フリップ
        ScreenFlip();
    }

    character.End();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
