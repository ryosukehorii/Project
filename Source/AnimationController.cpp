#include "AnimationController.hpp"

void AnimationController::Init()
{
	play_time = 0;
	anim_motion = 0;
	AnimInfo anim_info;

	// ３Ｄモデルの読み込み
	model = MV1LoadModel("Assets/Model/Player/Player.mv1");
	
	anim_info.anim = MV1LoadModel("Assets/Model/Player/PlayerIdle2.mv1");
	anim_vec.push_back(anim_info);
	anim_info.anim = MV1LoadModel("Assets/Model/Player/PlayerRun2.mv1");
	anim_vec.push_back(anim_info);
	anim_info.anim = MV1LoadModel("Assets/Model/Player/PlayerAttack1_1.mv1");
	anim_vec.push_back(anim_info);
	anim_info.anim = MV1LoadModel("Assets/Model/Player/PlayerRoll2.mv1");
	anim_vec.push_back(anim_info);

	attach_index = MV1AttachAnim(model, 0, anim_vec[0].anim);
	anim_total_time = MV1GetAttachAnimTotalTime(model, attach_index);
}

void AnimationController::Update()
{
	
		// 再生時間を進める
		play_time += 0.5f;
		// 再生時間がアニメーションの総再生時間に達したら次のアニメーションにする
		if (play_time >= anim_total_time)
		{
			play_time = 0;
		}
		//計算した再生時間をモデルに反映させる
		MV1SetAttachAnimTime(model, attach_index, play_time);
}

void AnimationController::ChangeAnim(int anim_num)
{
	MV1DetachAnim(model, attach_index);
	play_time = 0;
	attach_index = MV1AttachAnim(model, 0, anim_vec[anim_num].anim);
	anim_total_time = MV1GetAttachAnimTotalTime(model, attach_index);
}

void AnimationController::Draw(VECTOR pos,float angle_y)
{
	DrawFormatString(0, 80, GetColor(255, 0, 0), "model %f", angle_y);
	// 画面に映る位置に３Ｄモデルを移動
	MV1SetPosition(model, pos);
	MV1SetRotationXYZ(model, VGet(0.0f, angle_y + DX_PI_F, 0.0f));
	MV1DrawModel(model);
}

void AnimationController::End()
{
	MV1DeleteModel(model);
}