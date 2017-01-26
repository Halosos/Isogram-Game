#include <iostream>
#include <string>
using namespace std;

void PrintIntro();
void PlayGame();
string GetPlayerName();
string GetGuess();
bool AskToPlayAgain();
void NewPrintIntro();




// the entry point for the application
int main()
{

	bool bPlayAgain = false;
	do {
		
		if (bPlayAgain == false) {
			PrintIntro();
			GetPlayerName();
		}
		else {
			NewPrintIntro();
		}
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}





void PrintIntro() 
{
	//intoduce game

	cout << "Welcome to My game: Guess the Isogram!\n\n";
	cout << "If you do not know what an isogram is, it is a word that has no repeating letters." << endl;
	cout << "\"Isogram\", for example, is an isogram!" << endl;
	return;
}

void PlayGame()
{
	// loop to count the turns asking for guesses
	constexpr int GUESSTRACKER = 5;
	for (int count = 1; count <= GUESSTRACKER; count++)
	{
		string Guess = GetGuess();
		
		cout << endl << "Your guess was: " << Guess << endl;
		cout << "You have used " << count << " of your 5 guesses" << endl;
	}
}

string GetPlayerName() 
{
	// Players name
	constexpr int WORD_LENGTH = 7;
	cout << "First, please enter your name: ";
	string Name = "";
	getline(cin, Name);

	cout << endl;
	cout << "Hello " << Name << "!" << endl;

	//Current Isogram infomation

	cout << "Your current isogram is " << WORD_LENGTH << " letters long and the hint is \"ISOGRAMHINT\"" << endl;
	return Name;
}

string GetGuess() 
{
	//get guess from player
	cout << "Please enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n) ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void NewPrintIntro() {
	string PlayerName = GetPlayerName();
	cout << "Ready for another game " << PlayerName << "?" << endl;
	return;
}

