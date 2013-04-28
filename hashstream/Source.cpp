/*
	Finds first hash if using a hash for streaming authentication, homework asignment 3 for
	cryptography. Uses CryptoPP.
*/

#include <fstream>
#include <string>

#include "filters.h"
#include "files.h"
#include "sha.h"
#include "hex.h"


using namespace std;
using namespace CryptoPP;

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	string file;

	FileSource("6 - 1 - Introduction (11 min).mp4", true /*pumpAll*/, new StringSink(file));
	
	SHA256 sha;
	int i = ceil(double(file.size())/1024) - 1;
	string chunk = file.substr(i*1024);
	string tag;
	StringSource(chunk, true, new HashFilter(sha, new StringSink(tag)));
	i -= 1;
	
	while (i >= 0) {
		chunk = file.substr(i*1024,1024)+tag;
		tag.clear();
		StringSource(chunk, true, new HashFilter(sha, new StringSink(tag)));
		--i;
	}
	
	string output;
	StringSource(tag, true /*pumpAll*/,
		new HexEncoder(new StringSink(output),false) 
	); 

	cout << output << endl;

	pause();
}