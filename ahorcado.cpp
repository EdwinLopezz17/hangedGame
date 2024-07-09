
#include "game.h"



void menu() {
	
	Hangman* ahorcado = new Hangman();

	char option;

	while (true)
	{
		system("cls");
		cout << "::::MENU::::" << endl;
		cout << "1) Play Game" << endl;
		cout << "2) Salir" << endl;
		cout << ">> ";
		cin >> option;

		switch (option)
		{
		case '1':
			ahorcado->init();
			ahorcado->play();
			break;

		case '2':
			return;

		default:
			break;
		}

	}
}

int main() {

	srand(time(NULL));
	menu();

	return 0;
}
