#include <iostream>
#include <string>

using namespace std;

bool checkAnagram(string phraseOne, string phraseTwo)
{
	
	int counter[256] = { 0 };
	for (int i = 0; i < phraseOne.size(); i++) counter[toupper(phraseOne[i])]++;
	for (int i = 0; i < phraseTwo.size(); i++) counter[toupper(phraseTwo[i])]--;
	for (int i = 0; i < 256; i++)
	{
		if (i == 32) i++;
		if (counter[i] != 0) return false;
	}
	return true;
}

int main()
{
	std::string initial, checkString;
	std::cout << "Enter in two phrases and the machine will tell you if they are anagrams or not. Type exit to exit\n";
	while(1)
	{
		bool flag;
		std::cout << "Enter in the initial phrase:\n";
		std::getline(std::cin, initial);
		if (!initial.compare("exit"))
			break;
		std::cout << "Enter in the second phrase:\n";
		std::getline(std::cin,checkString);
		flag = checkAnagram(initial, checkString);
		if (flag)
			std::cout << "\"" << initial << "\" and \"" << checkString << "\" are anagrams!" << endl;
		else
			std::cout << "\"" << initial << "\" and \"" << checkString << "\" are NOT anagrams!" << endl;
	}
}