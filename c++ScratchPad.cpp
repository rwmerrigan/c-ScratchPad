#include <iostream>
#include <iomanip>
#include <vector>

#include "rickstrings.h"

using namespace std;

int main()
{
	string str = "hello";

	cout << rickToUpper(str) << endl;
	rickStringStats(str);

}


