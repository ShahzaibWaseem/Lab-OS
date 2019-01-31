#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
const int MAXLINE = 256;

int main(int argc, char const *argv[]){
	ifstream inFile ("/proc/cpuinfo");
	char line[MAXLINE];

	while(inFile){
		inFile.getline(line, MAXLINE);
		if (strstr(line, "vendor_id") != NULL)
			cout << line << endl;

		if (strstr(line, "model name") != NULL)
			cout << line << endl;
	}

	inFile.close();
	return 0;
}