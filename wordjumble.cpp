#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void wordjumble() {
	std::cout << "Let's Play Word Jumble!\n"
		<< "\n"
		<< "Enter 'hint' for a hint.\n"
		<< "Enter 'exit' to exit.\n\n";

	//define a vector of possible words
	std::vector<std::string> words{ "guitar", "violin", "tapestry" };

	//get a random word from vector
	std::srand(time(nullptr));
	int index = std::rand() % words.size();
	std::string word = words[index];

	//jumble the word
	std::string jumbled_word = word;
	auto length = word.size();
	for (int index1 = 0; index1 < length; ++index1) {
		int index2 = rand() % length;
		char temp = jumbled_word[index1];
		jumbled_word[index1] = jumbled_word[index2];
		jumbled_word[index2] = temp;
	}

	//display the jumbled word in uppercase
	std::cout << "The jumble is...";
	for (char c : jumbled_word) {
		std::cout << static_cast<char>(toupper(c));
	}
	std::cout << "\n\n";

	//loop until the user guesses the jumble or enters 'exit'
	int hint_count = 1;
	std::string guess = "";
	while (true) {
		std::cout << "Your Guess: ";
		std::cin >> guess;
		std::cin.ignore(1000, '\n'); //discard input up to the end of the line

		if (guess == word) {
			std::cout << "Congratulations! You guessed it.\n\n";
			break;
		}
		else if (guess == "hint") {
			std::cout << "Hint: ";
			for (int i = 0; i < word.length(); ++i) {
				if (i < hint_count) {
					std::cout << static_cast<char>(toupper(word[i])) << ' ';
				}
				else {
					std::cout << '_' << ' ';
				}
			}
			std::cout << "\n\n";
			++hint_count;
		}
		else if (guess == "exit") {
			std::cout << "Bye! Let's play again soon.\n\n";
			break;
		}
		else {
			std::cout << "Nope. Try again!\n\n";
		}
	}
}