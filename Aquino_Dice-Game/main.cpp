#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string input;

int rng(int min, int max) {
	return min + (rand() % max);
}

struct myBet {
	bool bet4 = false;
	bool bet5 = false;
	bool bet6 = false;
	bool bet8 = false;
	bool bet9 = false;
	bool bet10 = false;
};

void displayBoard(myBet x, int cash) {
	char placeBet4[2][4] = {"500","   "};
	char placeBet5[2][4] = {"500","   "};
	char placeBet6[2][4] = {"500","   "};
	char placeBet8[2][4] = {"500","   "};
	char placeBet9[2][4] = {"500","   "};
	char placeBet10[2][4] = {"500","   "};
	
	system("cls");
	cout << "cash : " << cash << endl;
	cout << "\n\t\t\t________________________________________________ " << endl;
	cout << "\t\t\t|       |       |       |       |       |       |" << endl;
	cout << "\t\t\t|       |       |       |       |       |       |" << endl;
	cout << "\t\t\t|   4   |   5   |   6   |   8   |   9   |   10  |" << endl;
	cout << "\t\t\t|       |       |       |       |       |       |" << endl;
	cout << "\t\t\t|_______|_______|_______|_______|_______|_______|" << endl;
	cout << "\t\t\t|  "<<placeBet4[!x.bet4]<<"  |  "<<placeBet5[!x.bet5]<<"  |  "<<placeBet6[!x.bet6]<<"  |  "<<placeBet8[!x.bet8]<<"  |  "<<placeBet9[!x.bet9]<<"  |  "<<placeBet10[!x.bet10]<<"  |" << endl;
	cout << "\t\t\t|_______|_______|_______|_______|_______|_______|" << endl;	  
}

void displayDice(int dice1, int dice2) {
	char hole1[7] = {' ',' ', ' ', ' ', 'o','o','o'};
	char hole2[7] = {' ',' ', 'o', 'o', 'o','o','o'};
	char hole3[7] = {' ',' ', ' ', ' ', ' ',' ','o'};
	char hole4[7] = {' ','o', ' ', 'o', ' ','o',' '};
	char hole5[7] = {' ',' ', ' ', ' ', ' ',' ','o'};
	char hole6[7] = {' ',' ', 'o', 'o', 'o','o','o'};
	char hole7[7] = {' ',' ', ' ', ' ', 'o','o','o'};

	cout << endl;
	cout << "\t\t\t\t _____________  \t _____________  \n";
	cout << "\t\t\t\t|  "<<hole1[dice1]<<"       "<<hole2[dice1]<<"  | \t|  "<<hole1[dice2]<<"       "<<hole2[dice2]<<"  | \n";
	cout << "\t\t\t\t|             | \t|             | \n";
	cout << "\t\t\t\t|  "<<hole3[dice1]<<"   "<<hole4[dice1] <<"   "<<hole5[dice1]<<"  | \t|  "<<hole3[dice2]<<"   "<<hole4[dice2] <<"   "<<hole5[dice2]<<"  | \n";
	cout << "\t\t\t\t|             | \t|             | \n";
	cout << "\t\t\t\t|  "<<hole6[dice1]<<"       "<<hole7[dice1]<<"  | \t|  "<<hole6[dice2]<<"       "<<hole7[dice2]<<"  | \n";
	cout << "\t\t\t\t|_____________| \t|_____________| \n";
	
}

void diceGame() {
	int cash = 5000;
	myBet user;
	
	bool flag3 = false;
	while (true) {
		user.bet4 = false;
		user.bet5 = false;
		user.bet6 = false;
		user.bet8 = false;
		user.bet9 = false;
		user.bet10 = false;
		bool flag = false;
		while (true) {
			if (cash < 500) {
				cout << "You have no more cash :(\n\n"
					 << "Cash: " << cash << "\n\n";
				flag3 = true;
				break;
			}
			while (true) {
				displayBoard(user, cash);
				cout << "\nPlease enter your bet [4, 5, 6, 8, 9, 10]: ";
				getline(cin, input);
				try {
					switch (stoi(input)) {
						case 4:
							if (!user.bet4) {
								user.bet4 = true;
								cash -= 500;
							}
							break;
						case 5:
							if (!user.bet5) {
								user.bet5 = true;
								cash -= 500;
							}
							break;
						case 6:
							if (!user.bet6) {
								user.bet6 = true;
								cash -= 500;
							}
							break;
						case 8:
							if (!user.bet8) {
								user.bet8 = true;
								cash -= 500;
							}
							break;
						case 9:
							if (!user.bet9) {
								user.bet9 = true;
								cash -= 500;
							}
							break;
						case 10:
							if (!user.bet10) {
								user.bet10 = true;
								cash -= 500;
							}
							break;
						default: 
							continue;
					}
				}
				catch (exception e) {
					continue;
				};
				break;
			}
			while (true) {
				if (cash < 500) {
					flag = true;
					cout << "You have no more cash to bet.\n\n";
					system("pause");
					break;
				}
				displayBoard(user, cash);
				cout << "\nDo you want to place another bet [y/n] ? ";
				getline(cin, input);
				if (input == "y") break;
				if (input == "n") {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag3) break;
		flag = false;
		bool flag2 = false;
		while (true) {
			int result;
			int dice1 = rng(1, 6);
			int dice2 = rng(1, 6);
			while (true) {
				displayBoard(user, cash);
				displayDice(dice1, dice2);
				int win = 0;
				switch (dice1 + dice2) {
					case 4:
						if (user.bet4) {
							result = 1;
							win = 950;
						}
						else result = 2;
						break;
					case 5:
						if (user.bet5) {
							result = 1;
							win = 700;
						}
						else result = 2;
						break;
					case 6:
						if (user.bet6) {
							result = 1;
							win = 625;
						}
						else result = 2;
						break;
					case 7:
						result = 3;
						break;
					case 8:
						if (user.bet8) {
							result = 1;
							win = 625;
						}
						else result = 2;
						break;
					case 9:
						if (user.bet9) {
							result = 1;
							win = 700;
						}
						else result = 2;
						break;
					case 10:
						if (user.bet10) {
							result = 1;
							win = 950;
						}
						else result = 2;
						break;
					default:
						result = 2;
				}
				switch (result) {
					case 1:
						while (true) {
							cout << "You win!!! Dice number is " << dice1 + dice2 << "\n"
								 << "Win: " << win << "\tTotal cash: " << win + cash << "\n\n"
								 << "Roll again [y/n] ? ";
							getline(cin, input);
							if (input == "y") {
								cash += win;
								flag = true;
							}
							else if (input == "n") {
								flag = true;
								flag2 = true;
							}
							break;
						}
						break;
					case 2:
						while (true) {
							cout << "No win... Dice number is " << dice1 + dice2 << "\n\n"
								 << "Roll again [y/n] ? ";
							getline(cin, input);
							if (input == "y") {
								flag = true;
							}
							else if (input == "n") {
								flag = true;
								flag2 = true;
							}
							break;
						}
						break;
					case 3:
						while (true) {
							cout << "You loose!!! Dice number is " << dice1 + dice2 << "\n\n";
							if (cash < 500) {
								flag = true;
								flag2 = true;
								break;
							}
							cout << "Do you want to play another [y/n] ? ";
							getline(cin, input);
							if (input == "y") {
								flag = true;
								flag2 = true;
							}
							else if (input == "n") {
								flag = true;
								flag2 = true;
								flag3 = true;
							}
							break;
						}
				}
				if (flag) break;
			}
			if (flag2) break;
		}
		if (flag3) break;	
	}
}

int main() {
	srand(time(0));
	diceGame();
	
	return 0;
}
