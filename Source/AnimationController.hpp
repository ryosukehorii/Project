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
	bool GetPlay() { return play; };
private:
	int model{ 0 };
	int anim_motion{ 0 };
	float play_time{ 0 };
	int attach_index{0};
	float anim_total_time{0};
	bool play{false};
	vector<AnimInfo>anim_vec;
};

