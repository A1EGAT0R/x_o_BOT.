#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int quad(int x, int y);
class Game
{
	int main_ind = 0;
	int main_stats = 0;
	int temp_ind = 0;
	int temp_stats = 0;
	char move[9];
	bool move_c[9];
	bool x_o;
	//=========================================================================================================================================================
	int moves = 0;
	//=========================================================================================================================================================
	char chan[9]; string pos[9];
	//=========================================================================================================================================================
	char winner;
public:
	class Err;
	Game();
	void Move();
	void printG();
	bool GAME();
	int main_b();
	void ChangeStats();
};