#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 200 */ void reverse()
{
	char ch;
	/* 201 */ cin.get(ch);
	/* 202 */ if (ch != '\n')
	{
		/* 203 */ reverse();
		/* 204 */ cout.put(ch);
	}
}

int main()
{
	reverse();
}