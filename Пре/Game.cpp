#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int quad(int x, int y)
{
	int temp = x;
	for (int i = 2; i <= y; i++)
	{
		x *= temp;
	}
	return x;
}

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
	class Err
	{
	public:
		Err(int x)
		{
			std::cout << "=============================================" <<x << "=============================================" << endl;
		}
	};
	Game();
	void Move();void Move(bool x); void Move(int pole);
	void printG();
	bool GAME();
	int main_b();
	void ChangeStats();
};

int Game::main_b()
{
	
	std::string an; std::string ant;
	if (moves >= 9)
	{
		throw Err(1);
	}
	std::string stro(moves, '*');
	int mas = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i > 8)
		{
			throw Err(2);
		}
		if (move_c[i] == true)
		{
			if (mas >= moves)
			{
				throw Err(3);
			}
			stro[mas] = i + '0';
			mas++;
		}
	}
	mas = 0;
	ifstream in(stro + ".txt");
	if (in)
	{
		getline(in, an);
		main_ind = an[0] - '0';
		main_stats = stoi(an);
		if (main_ind != 0)
		{
			main_stats = main_stats % quad(10, an.length() - 1);
		}
		while (!(in.eof()))
		{
			if (std::getline(in, ant))
			{
				temp_ind = ant[0] - '0';
				temp_stats = stoi(ant);
				if (temp_ind != 0)
				{
					temp_stats = temp_stats % quad(10, ant.length() - 1);
				}

				if (temp_stats > main_stats)
				{
					main_stats = temp_stats; main_ind = temp_ind;
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (moves == i)
				{
					string xx(1, '*');
					xx = to_string(main_ind);
					chan[i] = xx[0];
					pos[i] = stro;
				}
		}
		
		/*else if (moves == 3)
		{
			string xx(1, '*');
			xx = to_string(main_ind);
			chan[1] = xx[0];
			pos[1] = stro;
		}
		else if (moves == 5)
		{
			string xx(1, '*');
			xx = to_string(main_ind);
			chan[2] = xx[0];
			pos[2] = stro;
		}
		else if (moves == 7)
		{
			string xx(1, '*');
			xx = to_string(main_ind);
			chan[3] = xx[0];
			pos[3] = stro;
		}*/
		in.close();
		return main_ind;


	}
	else
	{
		ofstream set(stro + ".txt");
		for (int i = 0; i < 9; i++)
		{
			if (moves == 0)
			{
					set << i << "241441" << std::endl;
			}
			bool check = false;
			for (int j = 0; j < moves;j++)
			{
				if (j >= moves)
					throw Err(4);
				int ch = stro[j] - '0';
				if (i != ch)
				{
					check = true;
				}
				else
				{
					check = false;
					j = moves;
				}
			}
			if (check)
			{
				set << i << "241441" << std::endl;
			}
		}
		set.close();
		return (main_b());
	}
}

void Game::ChangeStats()
{
	if (winner == 'x')
	{
		
		for (int i = 0; i < 9; i++)
		{
			ofstream temp("temp.txt");
			if (temp)
			{
				if (pos[i][0] != '*')
				{
					
					ifstream obr(pos[i] + ".txt");
					if (obr)
					{	
						string changer;
						if ((i % 2 == 0) || (i == 0))
						{
							while (getline(obr, changer))
							{
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt++;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}
						
						}
						else
						{
							while (getline(obr, changer))
							{
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt--;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}
						}
					}
					obr.close();
				}
			}
			temp.close();
			ifstream tempp("temp.txt");
			if (temp)
			{
				ofstream last(pos[i] + ".txt");
				if (last)
				{
					string changer;
					while (getline(tempp, changer))
					{
						last << changer << endl;
					}
				}
				last.close();
			}
			tempp.close();
		}

	}
    else if (winner == 'o')
	{
		/*ofstream temp("temp.txt");
		for (int i = 0; i < 9; i++)
		{
			if (temp)
			{
				if (pos[i][0] != '*')
				{

					ifstream obr(pos[i] + ".txt");
					if (obr)
					{
						string changer;
						if ((i % 2 == 0) || (i == 0))
						{
							while (getline(obr, changer))
							{
								
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt--;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}
						}
						else
						{
							while (getline(obr, changer))
							{
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt++;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}
						}
					}
					obr.close();
				}
			}
			temp.close();
			ifstream tempp("temp.txt");
			if (temp)
			{
				ofstream last(pos[i] + ".txt");
				if (last)
				{
					string changer;
					while (getline(tempp, changer))
					{
						last << changer << endl;
					}
				}
				last.close();
			}
			tempp.close();
		}*/
		for (int i = 0; i < 9; i++)
		{
			ofstream temp("temp.txt");
			if (temp)
			{
				if (pos[i][0] != '*')
				{

					ifstream obr(pos[i] + ".txt");
					if (obr)
					{
						string changer;
						if ((i % 2 == 0) || (i == 0))
						{
							while (getline(obr, changer))
							{
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt--;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}

						}
						else
						{
							while (getline(obr, changer))
							{
								if (changer[0] == chan[i])
								{
									bool zero = false;
									if (changer[0] == '0')
										zero = true;
									int changerInt = stoi(changer);
									changerInt++;
									changer = to_string(changerInt);
									if (zero)
									{
										changer = '0' + changer;
										zero = false;
									}
								}
								temp << changer << endl;
							}
						}
					}
					obr.close();
				}
			}
			temp.close();
			ifstream tempp("temp.txt");
			if (temp)
			{
				ofstream last(pos[i] + ".txt");
				if (last)
				{
					string changer;
					while (getline(tempp, changer))
					{
						last << changer << endl;
					}
				}
				last.close();
			}
			tempp.close();
		}
	}
}

void Game::Move()
{
	moves++;
	int pole;
	cin >> pole;
	pole--;

	if (pole >= 9)
		throw Err(5);
	if (!move_c[pole])
	{
		if (x_o == 1)
		{
			move[pole] = 'o';
			x_o = 0;
		}
		else
		{
			move[pole] = 'x';
			x_o = 1;
		}
		move_c[pole] = 1;
	}
	else
	{
		std::cout << "ERROR" << endl;
		Move(false);
	}
}
void Game::Move(bool x)
{
	int pole;
	cin >> pole;
	pole--;

	if (pole >= 9)
		throw Err(11);
	if (!move_c[pole])
	{
		if (x_o == 1)
		{
			move[pole] = 'o';
			x_o = 0;
		}
		else
		{
			move[pole] = 'x';
			x_o = 1;
		}
		move_c[pole] = 1;
	}
	else
	{
		std::cout << "ERROR" << endl;
		Move(false);
	}
}
void Game::Move(int pole)
{
	if (pole >= 9)
		throw Err(6);
	moves++;
	if (!move_c[pole])
	{
		if (x_o == 1)
		{
			move[pole] = 'o';
			x_o = 0;
		}
		else
		{
			move[pole] = 'x';
			x_o = 1;
		}
		move_c[pole] = 1;
	}
	else
	{
		std::cout << "ERROR" << endl;
		Move(main_b());
	}
}
void Game::printG()
{
	system("cls");
	int z = 0;
	for (int i = 0; i < 3; i++)
	{
		if (z >= 9)
			throw Err(7);
		std::cout << "|";
		if (move_c[z])
			std::cout << move[z];
		else
			std::cout << " ";
		z++;

		if (z >= 9)
			throw Err(8);
		std::cout << "|";
		if (move_c[z])
			std::cout << move[z];
		else
			std::cout << " ";
		z++;
		if (z >= 9)
			throw Err(9);
		std::cout << "|";
		if (move_c[z])
			std::cout << move[z];
		else
			std::cout << " ";
		z++;

		std::cout << "|" << endl;

	}
}
bool Game::GAME()
{
	//горизонтальная
	//=========================================================================
	if (move_c[1])
	{
		if (move_c[0])
		{
			if (move[0] == move[1])
			{
				if (move_c[2])
				{
					if (move[2] == move[1])
					{
						std::cout << move[1] << " won" << endl;
						winner = move[1];
						return false;
					}
				}
			}
		}
	}
	if (move_c[7])
	{
		if (move_c[6])
		{
			if (move[6] == move[7])
			{
				if (move_c[8])
				{
					if (move[8] == move[7])
					{
						std::cout << move[7] << " won" << endl;
						winner = move[7];
						return false;
					}
				}
			}
		}
	}
	//=========================================================================

	//вертикальная
	//=========================================================================
	if (move_c[3])
	{
		if (move_c[0])
		{
			if (move[0] == move[3])
			{
				if (move_c[6])
				{
					if (move[6] == move[0])
					{
						std::cout << move[0] << " won" << endl;
						winner = move[0];
						return false;
					}
				}
			}
		}
	}
	if (move_c[5])
	{
		if (move_c[2])
		{
			if (move[2] == move[5])
			{
				if (move_c[8])
				{
					if (move[8] == move[2])
					{
						std::cout << move[2] << " won" << endl;
						winner = move[2];
						return false;
					}
				}
			}
		}
	}
	//=========================================================================

	//центральная
	//=========================================================================
	if (move_c[4])
	{
		if (move_c[1])
		{
			if (move[1] == move[4])
			{
				if (move_c[7])
				{
					if (move[7] == move[4])
					{
						std::cout << move[7] << " won" << endl;
						winner = move[7];
						return false;
					}
				}
			}
		}
	}
	if (move_c[4])
	{
		if (move_c[3])
		{
			if (move[3] == move[4])
			{
				if (move_c[5])
				{
					if (move[5] == move[4])
					{
						std::cout << move[4] << " won" << endl;
						winner = move[4];
						return false;
					}
				}
			}
		}
	}
	if (move_c[4])
	{
		if (move_c[2])
		{
			if (move[2] == move[4])
			{
				if (move_c[6])
				{
					if (move[6] == move[4])
					{
						std::cout << move[4] << " won" << endl;
						winner = move[4];
						return false;
					}
				}
			}
		}
	}
	if (move_c[4])
	{
		if (move_c[0])
		{
			if (move[0] == move[4])
			{
				if (move_c[8])
				{
					if (move[8] == move[4])
					{
						std::cout << move[4] << " won" << endl;
						winner = move[4];
						return false;
					}
				}
			}
		}
	}
	if (moves == 9)
	{
		std::cout << "DRAW!!!";
		winner = 'o'; //
		return false;
	}
	//=========================================================================
	return true;
}
Game::Game()
{
	char x_o_choose = 'o';
	x_o = 0;
	pos[0] = '*'; pos[1] = "**"; pos[2] = "***"; pos[3] = "****"; pos[4] = "*****";pos[5] = "******";pos[6] = "*******";pos[7] = "********";pos[8] = "*********";
	winner = '0';
	chan[0] = chan[1] = chan[2] = chan[3]= chan[4]= chan[5]= chan[6]= chan[7]= chan[8] = '0';

	std::cout << "Select: 'x' or 'o'";
	std::cin >> x_o_choose;

	for (int i = 0; i < 9; i++)
	{
		if (i >= 9)
			throw Err(10);
		move_c[i] = 0;
		move[i] = '0';
	}

	std::cout << "| | | |" << endl << "| | | |" << endl << "| | | |" << endl;

	

	if (x_o_choose == 'x')
	{
		while (GAME())
		{
			Move();

			printG();


			if (GAME())
			{
				Move(main_b());

				printG();
			}
		}
	}
	else
	{
		while (GAME())
		{
			Move(main_b());

			printG();


			if (GAME())
			{
				Move();

				printG();
			}
		}
	}
	ChangeStats();
}

