#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

#include "milespergallon.h"
#include "employeewage.h"

using namespace std;

int main()
{
	string teststring = "RichardMerrigan";
	auto doesItContain = teststring.find_first_of("0123456789");
	if (doesItContain == -1) {
		cout << "This does not contain a number";
	}

	string name = "Grace Brewster Murray Hopper";
}


