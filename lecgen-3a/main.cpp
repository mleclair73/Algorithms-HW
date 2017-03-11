// LecGen-3a.cpp : Defines the entry point for the console application.
//

#include "dictionary.h"
#include "grid.h"
#include <string>

using namespace std;

int main()
{
	// string a1 = "huntress";
	// string a2 = "inspirations";
	//
	// cout << (a1 < a2);

	string n = "dictionary.txt";
	dictionary dictionary1;
	dictionary1.loadDictionary(n);
	cout << dictionary1 << endl << endl;
	dictionary1.sortDict();
	cout << dictionary1 << endl << endl;


	//grid grid1;
	// string a = "cbcdefg";
	// string b = "b";
	// cout << (a < b);
	//	gid1.loadMatrix();

	//system("pause");
    return 0;
}
