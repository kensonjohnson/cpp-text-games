// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Gooing slowly, isn't it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."},
    };

    // Setup the randomizer and pick a random word
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];

    // Jumble the letters in the chosen word
    string jumble = theWord;
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    // Interact with the player
    cout << "\t\t\tWelcome to the Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    // Enter the game loop
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Sorry, that's not it.";
        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    // The player exits the loop by entering the right guess or 'quit'
    if (guess == theWord)
    {
        cout << "\vThat's it! You guessed it!\n";
    }

    cout << "\nThanks for playing.\n";

    return 0;
}