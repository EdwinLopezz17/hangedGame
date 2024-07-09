#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Hangman {

private:
    int lives;
    char guessedLetter;
    string secretWord;
    string correctGuesses;
    string incorrectGuesses;

    string selectRandomWord() {
        string words[] = {
            "MONITOR", "MICROFONO", "TECLADO", "RATON", "PANTALLA",
            "IMPRESORA", "ESCANER", "ALTAVOZ", "CAMARA", "TABLET",
            "PROYECTOR", "MOUSEPAD", "DISCODURO", "MEMORIA", "CABLE",
            "ADAPTADOR", "ANTENA", "WEBCAM", "BATERIA", "CARCADOR"
        };
        return words[rand() % 20];
    }

    void drawHangman() const {
        cout << "Vidas restantes: " << lives << endl;
        cout << "-----" << endl;
        cout << "|   |" << endl;
        cout << "|   " << (lives < 6 ? "O" : " ") << endl;
        cout << "|  " << (lives < 5 ? "/" : " ") << (lives < 4 ? "|" : " ") << (lives < 3 ? "\\" : " ") << endl;
        cout << "|  " << (lives < 2 ? "/" : " ") << " " << (lives < 1 ? "\\" : " ") << endl;
        cout << "-----" << endl;
    }

    bool allLettersGuessed() const {
        for (char c : secretWord) {
            if (correctGuesses.find(c) == string::npos) {
                return false;
            }
        }
        return true;
    }

public:
    Hangman() {
        srand(time(0));
    }

    void init() {
        lives = 6;
        secretWord = selectRandomWord();
        correctGuesses.clear();
        incorrectGuesses.clear();
    }

    void play() {
        while (lives > 0) {
            system("cls");
            drawHangman();

            cout << "\nLetras incorrectas: ";
            for (char c : incorrectGuesses) {
                cout << c << " ";
            }

            cout << "\n\nPalabra: ";
            for (char c : secretWord) {
                if (correctGuesses.find(c) != string::npos) {
                    cout << c;
                }
                else {
                    cout << "_";
                }
                cout << " ";
            }
            cout << endl;

            cout << "Introduce una letra: ";
            guessedLetter = _getch();
            guessedLetter = toupper(guessedLetter);
            cout << guessedLetter;
            Sleep(300);

            if (correctGuesses.find(guessedLetter) == string::npos && incorrectGuesses.find(guessedLetter) == string::npos) {
                if (secretWord.find(guessedLetter) != string::npos) {
                    correctGuesses += guessedLetter;
                }
                else {
                    incorrectGuesses += guessedLetter;
                    lives--;
                }
            }

            if (allLettersGuessed()) {
                cout << "\n¡Has ganado! La palabra es: " << secretWord << endl;
                _getch();
                break;
            }
        }

        if (lives == 0) {
            cout << "\n¡Has perdido! La palabra era: " << secretWord << endl;
            _getch();
        }
    }
};
