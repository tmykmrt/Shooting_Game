#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	//	カウントタイムの設定
	void SetCountTime(float time);
	//	カウントフレームの設定
	void SetCountFrame(int frame);
	//bool CheckTimeOut();
	//	カウントフレームが経過したか
	bool CheckFrameOut();
	//	計測フレームの更新
	int UpdateFrame();
	//	計測フレームリセット
	void ResetFrame();
private:
	//	カウントタイム
	float countTime;
	//	カウントフレーム
	int countFrame;
	//	計測フレーム
	int nowFrame;
};

