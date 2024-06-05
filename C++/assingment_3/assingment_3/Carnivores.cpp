#include "Carnivores.h"



Carnivores::Carnivores()
{
	Exersize = "chasing after potential food";
}


Carnivores::~Carnivores()
{
}

  /*********************/
 /* Great_White_Shark */
/*********************/
Great_White_Shark::Great_White_Shark()
{
	Name = "Great White Shark";
	FeedingHabits = "praying, eating fish, yummy!";
	ShowCase = "water diving";
}

Great_White_Shark::~Great_White_Shark()
{
}

  /********/
 /* Wolf */
/********/
Wolf::Wolf()
{
	Name = "Wolf";
	FeedingHabits = "praying, eating rabbit, yummy!";
	ShowCase = "joyful running and flapping their tail";
}

Wolf::~Wolf()
{
}

  /********/
 /* Lion */
/********/
Lion::Lion()
{
	Name = "Lion";
	FeedingHabits = "praying, eating gnu, yummy!";
	ShowCase = "royal walking in the garden";
}

void Lion::Exhibition()
{
	cout << "Hunting!! ";
}

Lion::~Lion()
{
}
