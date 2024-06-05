#include "SnakesAndLadders.h"







SnakesAndLadders::SnakesAndLadders()
{ 
	//------------------init board-------------------------
	for (int i = 0; i < Game_Board; i++)
		for (int j = 0; j < Game_Board; j++)
			board[i][j] = E;
	//------------------init numberd board-------------------------
	int n = 1;
	for (int i = 0; i < Game_Board; i++)
	{
		for (int j = 0; j < Game_Board; j++)
		{
			Places_board[j][i] = n++;
		}
		
	}
	//------------------init amount of players-------------------------
	cout << "how many players? ";
	cin >> Num_Players;
	//------------------store players names-------------------------
	Players = new char[Num_Players];
	for (int i = 0; i < Num_Players; i++) 
	{
		cout << "enter " << i + 1 << " player ";
		cin >> Players[i];
	}
	//------------------init players locations to 0------------------------
	Player_location = new int*[Num_Players];
	for (int i=0;i < Num_Players;i++)
			Player_location[i] = new int[2];
	
	for (int i = 0; i < Num_Players; i++)
		for (int j = 0; j < 2; j++)
			Player_location[i][j] = 0;
	//-------------------init snakes&ladders-------------------------
	Generate_Ladders();
	Generate_Snakes();

}

void SnakesAndLadders::play()
{
	int winner = 0;
	

	srand(time(NULL));


	cout << "~~~##~~~##~~~##~~~##~~~##~~~" << endl;
	cout << "game starts:" << endl;
	cout << "~~~##~~~##~~~##~~~##~~~##~~~" << endl;
	cout << "\n";

	while (!winner) //while not winner
	{
		getchar();

		for (int i = 0; i < Num_Players; i++)
		{
			cout << "\n";
			cout << Players[i] << "'s turn" << endl;
			cout << "corent place:" << gatPlace(i) << endl;
			Step(i);
			cout << "place after movement:" << gatPlace(i) << endl;
			if (gatPlace(i) == Winner)
			{
				winner = 1;
				cout << "YOU WIN!!!";
				exit(1);
			}

			getchar(); // to make sure every step is separate
		}
	}
}

void SnakesAndLadders::Generate_Ladders()
{
	srand(time(NULL)); 

	Ladders = new int*[Environment];
	for (int i = 0; i < Environment; i++) {// initiate cordnents of start and end of ladders simultaneously
		Ladders[i] = new int[Start_End];

		Ladders[i][0] = Generate(6,0);//x1
		Ladders[i][2] = Generate(7, Ladders[i][0]+1);//x2
		Ladders[i][1] = Generate();//y1
		Ladders[i][3] = Generate();//y2

		//cout << "ther is a ladder in;" <<"start("<< Ladders[i][1] << "," << Ladders[i][0]<<")end("<< Ladders[i][3]<<","<< Ladders[i][2] <<")"<< endl;

		board[Ladders[i][1]][Ladders[i][0]] = L;
	}

}

void SnakesAndLadders::Generate_Snakes()
{
	srand(time(NULL)); 
	int flag = 0;

	Snakes = new int*[Environment];
	for (int i = 0; i < Environment; i++){ //initiate start and end of snakes simultaneously
		Snakes[i] = new int[Start_End];

		while (!flag)//while place on board is not empty
		{

			Snakes[i][2] = Generate(7, 1); //x2
			Snakes[i][0] = Generate(Snakes[i][2],0); //x1
			Snakes[i][1] = Generate(); //y1
			Snakes[i][3] = Generate(); //y2

			if ((board[Snakes[i][3]][Snakes[i][2]]) == E)
				flag = 1;
			if ((board[Snakes[i][3]][Snakes[i][2]]) == L)
				flag = 0;
		}
		flag = 0;

		//cout << "ther is a snake in;" << "end(" << Snakes[i][3] << "," << Snakes[i][2] << ")start(" << Snakes[i][1] << "," << Snakes[i][0] << ")" << endl;

		board[Snakes[i][3]][Snakes[i][2]] = S;

	}
}

void SnakesAndLadders::Step(int p)
{

	int x, y;

	x = rand() % 6 + 1;
	y = rand() % 6 + 1;

	cout << "first qube roled:" << x << " ,second qube rolde:" << y << endl << "move " << x + y << " steps" << endl;

	for(int k=0;k<Game_Board;k++)
		for(int n=0;n<Game_Board;n++)
		{
			if (((gatPlace(p)+1) + (x + y)) == Places(n, k)) //compare between end location and location on numberd board
			{
				switch (board[n][k])
				{
				case 0:
					cout << "nice you landed on a ladder!" << endl;
					Player_location[p][0] = Ladders[k][2];
					Player_location[p][1] = Ladders[k][3];
					break;
				case 1:
					cout << "bad luck you landed on a snake" << endl;
					Player_location[p][0] = Snakes[k][0];
					Player_location[p][1] = Snakes[k][1];
					break;
				default:

					Player_location[p][0] = k;
					Player_location[p][1] = n;
					break;
				}
			}
		}

}


SnakesAndLadders::~SnakesAndLadders()
{

	for (int i = 0; i < Environment; i++)
		delete[]Ladders[i];
	delete[]Ladders;
	cout << "ladders deleted>>" << endl;

	for (int i = 0; i < Environment; i++)
		delete[]Snakes[i];
	delete[]Snakes;
	cout << "snakes deleted>>" << endl;

	for (int i = 0; i < Num_Players; i++)
		delete[]Player_location[i];
	delete[]Player_location;
	cout << "location deleted>>" << endl;

	delete[]Players;
	cout << "players deleted>>" << endl;
}


int SnakesAndLadders::gatPlace(int p) const
{
	return Places_board[Player_location[p][0]][Player_location[p][1]];
}

int SnakesAndLadders::Generate(int max,int min ) //conditioned
{
	if (max == min)
		return max;
	return (rand() % (max-min)) + min;
}
int SnakesAndLadders::Generate() //not conditioned
{
	return rand() % 7;
}
/*
void SnakesAndLadders::PrintBoard() const
{
	for (int i = 0; i < Game_Board; i++) {
		for (int j = 0; j < Game_Board; j++) {
			cout << board[i][j] << " ("<<i<<","<<j<<") ";
		}
		cout << endl;
	}
}
*/
/*
void SnakesAndLadders::PrintP_B() const
{
	cout << "\n";
	for (int i = 0; i < Game_Board; i++) {
		for (int j = 0; j < Game_Board; j++) {
			cout << Places_board[i][j] << " (" << i << "," << j << ") ";
		}
		cout << endl;
	}
}
*/

int SnakesAndLadders::Places(int x,int y)
{
	return Places_board[x][y];
}
