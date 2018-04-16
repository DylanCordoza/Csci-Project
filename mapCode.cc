#include <iostream>
#include <ncurses.h>
using namespace std;

void clrscr() {
	cout << "\033[2J\033[1;1H";
}


void printMap(int lvl) {

	string emptyflr = " \\                                 / \n /                                 \\ \n | 			           | \n |_________________________________| \n";
	string emptyflrgr = " \\                                 / \n /                                 \\ \n | 			           | \n_|_________________________________|______ \n";
	string roof = "|--|__|--|__|--|__|--|__|--|__|--|__| \n|                                   | \n| 			            | \n |_________________________________| \n";
	string plrflr = " \\                                 / \n /                @                \\ \n | 		 /H\\               | <-- You are here\n |_______________/_\\_______________| \n";
	string plrflrgr = " \\                                 / \n /                @                \\ \n | 		 /H\\               | <-- You are here\n_|_______________/_\\_______________|______\n";

	string t6 = roof;
	string t5 = emptyflr;
	string t4 = emptyflr;
	string t3 = emptyflr;
	string t2 = emptyflr;
	string t1 = emptyflrgr;

	if (lvl == 1) t1 = plrflrgr;
	if (lvl == 2) t2 = plrflr;
	if (lvl == 3) t3 = plrflr;
	if (lvl == 4) t4 = plrflr;
	if (lvl == 5) t5 = plrflr;
	cout << t6 << t5 << t4 << t3 << t2 << t1;

	cout << "To exit, type e and press ENTER\n";

	while (true) {
		string s = "";
		cin >> s;
		if (s == "e") break;
	}
	clrscr();

}



