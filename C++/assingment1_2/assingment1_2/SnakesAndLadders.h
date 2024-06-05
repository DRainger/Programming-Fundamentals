#pragma once
#ifndef SNAKESANDLADDERS_H
#define SNAKESANDLADDERS_H
#define Game_Board 8
#define Start_End 4 //cordnents for snakes/ladders
#define Environment 10 //amount of ladders and snakes
#define Winner 64
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



enum Cell{ L, S, E };

class SnakesAndLadders
{
	Cell board[Game_Board][Game_Board];
	int Places_board[Game_Board][Game_Board]; //second board weth numbering for locations
	int Num_Players;
	char *Players;
	int **Player_location; 
	int **Snakes;
	int **Ladders;

public:
	SnakesAndLadders();
	void play();
	void Generate_Ladders();
	void Generate_Snakes();
	void Step(int);
	int gatPlace(int)const;
	int Generate(int,int); //generate conditioned number
	int Generate(); //generate non conditioned number
	int Places(int, int); //return location number in given cordinants
	void PrintBoard()const;
	void PrintP_B()const;
	~SnakesAndLadders();
};

#endif  //SNAKESANDLADDERS_H

