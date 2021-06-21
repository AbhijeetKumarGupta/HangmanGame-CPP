//============================================================================
// Name        : Hangman.cpp
// Author      : DEVIL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// CS 200

// "Hangman" word guessing game.

// Program shell hangMan.cpp

#include<iostream>

using namespace ::std;

// Function prototypes

void createTemplate(const char secretWord[], char guessTemplate[]);

void updateTemplate(const char secretWord[], char guessLetter,
		char guessTemplate[]);

bool matchTemplate(const char secretWord[], const char guessTemplate[]

);

//--------------------------------------------------------------------

const int MAX_SIZE = 15;

int main()

{

	const int NUM_LINES = 25; // Number of lines on the screen

	char secretWord[MAX_SIZE], // Secret word to be guessed

			guessTemplate[MAX_SIZE]; // Template showing correct guesses

	char guessLetter; // Letter guessed

	int numGuesses, // Number of letters guessed

			j; // Counter

// Get the secret word.

	cout << endl << "Enter the secret word: ";

	cin >> secretWord;

// Scroll it off the screen.

	for (j = 0; j < NUM_LINES; j++)

		cout << endl;

// Create an empty guess template.

	createTemplate(secretWord, guessTemplate);

// Play the game.

	numGuesses = 0;

	while (!matchTemplate(secretWord, guessTemplate))

	{

		numGuesses++;

		cout << guessTemplate << endl;

// Get a letter guess.

		cout << "Guess a letter: ";

		cin >> guessLetter;

// Fill in the occurrences of this letter.

		updateTemplate(secretWord, guessLetter, guessTemplate);

	}

// Display the secret word and the number of guesses.

	cout << guessTemplate << "=" << secretWord << endl;

	cout << "You guessed the word in " << numGuesses << " guesses"

	<< endl;

	return 0;

}

//--------------------------------------------------------------------

// Insert your function implementations here.

//--------------------------------------------------------------------

void createTemplate(const char secretWord[], char guessTemplate[])

{
	// The guessTemplate will be an array of characters, all cells

	// filled with the char '-' and with a '\0' at the end

	// The number of cells filled will be determined by the numbers

	// of characters in secretWord

	// If secretWord is the C++ string monday

	// Then guessTemplate will be ------

	// ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION

	// NOTE: An array of char is NOT a C++ string until the '\0' character

	// has been added after the last character. You will need

	// to add the '\0' character to the guessTemplate array in order

	// for that array to become a C++ string

	int i = 0;
	do {
		guessTemplate[i] = '-';
		i++;
	} while (secretWord[i] != '\0');
	guessTemplate[i] = '\0';

}

void updateTemplate(const char secretWord[], char guessLetter,

char guessTemplate[])

{
	// Update guessTemplate by replacing '-' in the array with

	// guessLetter for each corresponding cell in secretWord

	// If secretWord is kansas and guessLetter is 's'.

	// If guessTemplate was --n--- then guessTemplate would

	// be changed to --ns-s

	// ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION

	int i = 0;
	do {
		if (guessLetter == secretWord[i]) {
			guessTemplate[i] = guessLetter;
		}
		i++;
	} while (secretWord[i] != '\0');
}

bool matchTemplate(const char secretWord[], const char guessTemplate[])

{
	// will return true if secretWord and guessTemplate contain the same

	// C++ string and will return false otherwise

	// ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION

	int i = 0;
	do {
		if (secretWord[i] != guessTemplate[i]) {
			return false;
			break;
		}
		i++;
	} while (secretWord[i] != '\0');

	return true;

}
