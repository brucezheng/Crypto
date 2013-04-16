/*
	Bruce Zheng
	Classical substitution cipher
	4/15/2013
*/

#include <iostream>

class SubCipher{
public:
	SubCipher();
	SubCipher(char ch);
	char out(char in);
private:
	int offset;
};

SubCipher::SubCipher()
{
	offset = 0;
}

SubCipher::SubCipher(char ch)
{
	if(isupper(ch)) {
		offset = int(ch-'a');
	}
	else if (islower(ch)) {
		offset = int(ch-'A');
	}
	else std::cerr << "SubCipher error: char must be a letter!";
}

char SubCipher::out(char in)
{
	if (isupper(in)) {
		return 'A'+int(in-'A'+offset)%26;
	}
	else if (islower(in)) {
		return 'a'+int(in-'a'+offset)%26;
	}
	else std::cerr << "SubCipher error: char must be a letter!";
}