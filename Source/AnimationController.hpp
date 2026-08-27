#pragma once
#include "Dxlib.h"
#include <vector> 

using namespace std;

#define ANIMNUM (4)
typedef struct
{
	int anim;
	bool loop;
	float play_speed;
}AnimInfo;

class AnimationController
{
public:
	void Init();
	void Update();
	void End();
	void ChangeAnim(int anim_num);
	void Draw(VECTOR pos, float angle_y);
private:
	int model;
	int anim_motion;
	float play_time;
	int attach_index;
	float anim_total_time;
	vector<AnimInfo>anim_vec;
};

