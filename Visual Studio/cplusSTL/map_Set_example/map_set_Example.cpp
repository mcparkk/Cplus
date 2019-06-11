#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
// 너무 눈이 부시네요. 출출해요. 졸려요. 저랑 자리 바꾸실래요? 좋다구요? 저도 좋아요. 목마르네요. 여기서는 졸아도 편하게 잘 수 있겠네요. 부러워요. 편하게 자고싶다ㅠㅠㅠㅠ  우리 은지언니 잘부탁해요.
class Pitcher_Info
{

public :
	double _ERA;		//평균자책
	int _GameNumber;	//경기수
	double _Inning;		//이닝
	int _Win;			//승
	int _Lose;			//패
	int _Save;			//save
	int _Hold;			//hold
	int _SO;			//탈삼진
	int _H;				//피안타
	int _HR;			//피홈런
	int _ER;			//실점
	int _B4;			//볼넷
	int _HBP;			//사구
	double _WinningRate;

	/*Pitcher_Info(double era, int gameNumber, double inning, int win, int lose, int save, int hold, int so, int h, int hr, int er, int b4, int hbp)
		:_ERA(era), _GameNumber(gameNumber), _Inning(inning), _Win(win), _Lose(lose), _Save(save), _Hold(hold), _SO(so), _H(h), _HR(hr), _ER(er), _B4(b4), _HBP(hbp)
	{}*/

	Pitcher_Info() {}
};

ostream& operator<<(ostream& out, const Pitcher_Info& p)
{
	out << p._ERA << ", " << p._GameNumber << ", " << p._Inning << ", " << p._Win 
		<< ", " << p._Lose << ", " << p._Save << ", " << p._Hold << ", " << p._SO << ", " << p._H << ", " << p._HR << ", "
		<< p._ER << ", " << p._B4 << ", " << p._HBP << ", " << p._WinningRate;
	return out;
}

int main()
{
	string Name[20] = { "윌슨","산체스" ,"루찬스키" ,"켈리" ,"린드블럼" ,"김광현" ,"유희관" ,"알칸타라" ,"박종훈"
						,"채드밸" ,"요키시" ,"박진우" ,"다익손" ,"이영하" ,"차우찬" ,"양현종" ,"서폴드" ,"장민재" ,"레일리" ,"버틀러" };
	double ERA[20] = { 1.62,1.76,1.95,2.14,2.15,2.66,2.77,3.06,
						3.23,3.38,3.41,3.42,3.56,3.68,3.80,3.91,4.01,4.06,4.23,4.27 };
	int GameNumber[20] = { 14,13,13,14,14,14,13,12,13,14,14,14,12,12,12,13,14,14,13,11 };
	double Inning[20] = { 94.66,81.66,83,88.33,92,84.66,78,85.33,69.66,
						88,87,79,65.66,73.33,68.66,78.33,83,75.33,76.66,65.33 };
	int Win[20] = { 6,9,4,6,9,7,3,5,3,5,5,4,3,7,6,5,4,6,2,3 };
	int Lose[20] = { 4,2,3,6,1,1,4,5,3,5,3,5,2,1,2,7,6,3,6,6 };
	int Save[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int Hold[20] = { 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 };
	int SO[20] = { 62,73,61,71,84,88,34,48,47,62,69,51,58,36,55,78,63,69,61,42 };
	int H[20] = { 78,67,60,72,75,88,83,87,77,93,76,77,65,66,74,89,88,82,83,68 };
	int HR[20] = { 1,0,3,4,6,6,2,7,6,6,4,8,7,2,3,4,4,5,7,5 };
	int ER[20] = { 27,19,23,32,23,27,29,30,28,35,34,34,29,31,35,36,42,36,42,38 };
	int B4[20] = { 16,17,19,21,15,17,17,9,23,34,19,18,18,35,26,15,26,13,29,23 };
	int HBP[20] = { 5,1,5,6,3,1,3,4,5,5,4,10,2,6,2,1,3,4,2,2 };
	double WinningRate[20] = { 0.600,0.818,0.571,0.500,0.900,0.875,0.429,0.500,0.500,
					0.500,0.625,0.444,0.600,0.875,0.750,0.417,0.400,0.667,0.250,0.333 };

	map<string, Pitcher_Info> pitchers;
	for (int i = 0; i < 20; i++)
	{
		pitchers.insert(make_pair(Name[i], Pitcher_Info()));
		pitchers[Name[i]]._ERA = ERA[i];
		pitchers[Name[i]]._GameNumber = GameNumber[i];
		pitchers[Name[i]]._Inning = Inning[i];
		pitchers[Name[i]]._Win = Win[i];
		pitchers[Name[i]]._Lose = Lose[i];
		pitchers[Name[i]]._Save = Save[i];
		pitchers[Name[i]]._Hold = Hold[i];
		pitchers[Name[i]]._SO = SO[i];
		pitchers[Name[i]]._H = H[i];
		pitchers[Name[i]]._HR = HR[i];
		pitchers[Name[i]]._ER = ER[i];
		pitchers[Name[i]]._B4 = B4[i];
		pitchers[Name[i]]._HBP = HBP[i];
		pitchers[Name[i]]._WinningRate = WinningRate[i];
		
	}
}