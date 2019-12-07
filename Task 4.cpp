#include <iostream>
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
		int value=14;
		int suite=3;
		int count=3;
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

/*
int main() {
	CardDeck Deck;
	Deck.printDeck();
	system("pause");
	return 0;
}
*/