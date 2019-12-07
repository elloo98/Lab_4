#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Card {
public:
	//Value is equivalent to the value of the card with Jack=11, Queen=12, King=13 and Ace=14, Jokers are a 15 due to the next task
	int value;
	//Suite goes from most valued to least valued as seen in task 5, 4=Jokers (never used), 3=Spades, 2=Hearts, 1=Diamonds, 0=Clubs
	int suite;

	Card(int in_value, int in_suite) {
		value = in_value;
		suite = in_suite;
	}
	Card() {
		value = 14;			//Ace
		suite = 3;			//of Spades
	}
	void printCard() {
		if (value == 15) {
			cout << "Joker\n";
		}
		else {
			if (value <= 10 && 2 <= value)
				cout << value << " of";
			else {
				switch (value) {
				case 11:
					cout << "Jack of";
					break;
				case 12:
					cout << "Queen of";
					break;
				case 13:
					cout << "King of";
					break;
				case 14:
					cout << "Ace of";
					break;
				}
			}
			switch (suite) {
			case 3:
				cout << " Spades\n";
				break;
			case 2:
				cout << " Hearts\n";
				break;
			case 1:
				cout << " Diamonds\n";
				break;
			case 0:
				cout << " Clubs\n";
				break;
			}
		}
	}
};

class CardDeck {
public:
	Card* card;
	CardDeck() {
		int value = 14;
		int suite = 3;
		int count = 3;
		card = new Card[55];
		card[0].value = 15;
		card[0].suite = 4;
		card[1] = card[2] = card[0];
		while (count < 55) {
			card[count].value = value;
			card[count].suite = suite;
			count++;
			value--;
			if (value == 1) {
				suite--;
				value = 14;
			}
		}
	}
	void printDeck() {
		int count = 0;
		while (count < 55) {
			card[count].printCard();
			count++;
		}
	}
	~CardDeck() {
		delete[] card;
	}
};

class CardUtilities {
public:
	Card* missingArray;
	void shuffleDeck(CardDeck* deck) {
		srand(time(0));
		int temp_value, temp_suite, count=0;
		int first_card, second_card;
		while (count < 10000) {
			first_card = rand() % 55;
			second_card = rand() % 55;
			temp_value = deck->card[first_card].value;
			temp_suite = deck->card[first_card].suite;
			deck->card[first_card] = deck->card[second_card];
			deck->card[second_card].value = temp_value;
			deck->card[second_card].suite = temp_suite;
			count++;
		}
	}
	void sortDeck(CardDeck* deck) {
		//A bubble-sort was used because it is the easiest to implement and I was short of time
		int count = 0, count_2 = 0, count_3 = 1;
		int temp_value, temp_suite;
		while (count < 55) {
			while (count_2 < 54) {
				if (deck->card[count_2].suite <= deck->card[count_3].suite) {
					temp_suite = deck->card[count_2].suite;
					temp_value = deck->card[count_2].value;
					deck->card[count_2] = deck->card[count_3];
					deck->card[count_3].suite = temp_suite;
					deck->card[count_3].value = temp_value;
				}
				count_2++;
				count_3++;
			}
			count_2 = 0;
			count_3 = 1;
			count++;
		}
		int count_4 = 0;
		count = 3;
		while (count < 50) {
			while (count_4<15) {
				while (count_3 < 14) {
					if (deck->card[count + count_2].value < deck->card[count + count_3].value) {
						temp_value = deck->card[count + count_2].value;
						deck->card[count + count_2].value = deck->card[count + count_3].value;
						deck->card[count + count_3].value = temp_value;
					}
					count_2++;
					count_3++;
				}
				count_2 = 0;
				count_3 = 1;
				count_4++;
			}
			count_4 = 0;
			count = count + 13;
		}
	}
	/* This part din't want to work and seeing as I had no time left and this task was optional I skipped it
	Card* checkMissing(CardDeck* deck) {
		CardDeck facit;
		int count = 0, ammountMissing=0;
		bool isMissing[55];
		while (count < 55) {
			isMissing[count] = false;
			cout << isMissing[count];
			count++;
		}
		cout << "\n";
		count = 0;
		while (count < 55) {
			if (deck->card[count].suite != facit.card[count].suite || deck->card[count].value != facit.card[count].value) {
				isMissing[count] = true;
				ammountMissing++;
			}
			cout << isMissing[count];
			count++;
		}
		missingArray = new Card[ammountMissing];
		count = ammountMissing = 0;
		while (count < 55) {
			if (isMissing[count]==true) {
				missingArray[ammountMissing] = facit.card[count];
				missingArray[ammountMissing].printCard();
				ammountMissing++;
			}
			count++;
		}
		return missingArray;
	}
	~CardUtilities() {
		delete[] missingArray;
	}*/
};

int main() {
	CardDeck deck;
	CardUtilities utility;
	Card* missing;
	utility.shuffleDeck(&deck);
	deck.printDeck();
	utility.sortDeck(&deck);
	cout << "\nNow Sorted\n\n";
	deck.printDeck();
	system("pause");
	return 0;
}