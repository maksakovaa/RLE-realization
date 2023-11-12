// Реализация RLE алгоритма

#include <iostream>
#include <string>
using namespace std;

string decode(string encoded)
{
	string symTemplate = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numTemplate = "0123456789";
	string result = "";
	int lenght = encoded.size();
	int i = 0;
	int pos = 0;
	while (i < lenght - 1)
	{
		int numStart = encoded.find_first_of(numTemplate, i);
		int numEnd = encoded.find_first_not_of(numTemplate, i);
		int repeatCount = stoi(encoded.substr(numStart, numEnd - numStart));
		int charStart = encoded.find_first_of(symTemplate, i);
		char repeatSym = encoded[charStart];
		result = result.insert(pos, repeatCount, repeatSym);
		pos = result.size();
		i = charStart + 1;
	}
	return result;
}

string encode(string decoded)
{
	int	lenght = decoded.size();
	string result = "";
	int i = 0;
	int pos = 0;
	int count;
	while (i <= lenght - 1)
	{
		
		if (decoded.find_first_not_of(decoded[i], i) != string::npos)
		{
			count = decoded.find_first_not_of(decoded[i], i)-i;
		}
		else
		{
			count = lenght - i;
		}
		string temp = to_string(count) + decoded[i];
		result = result.append(temp);
		i += count;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string example1 = "4r5g1b";
	string decoded = decode(example1);
	cout << "Раскодированное: " << decoded << endl;
	string example2 = "rrrrgggggbbbb";
	string encoded = encode(example2);
	cout << "Закодированное: " << encoded << endl;
	return 0;
}