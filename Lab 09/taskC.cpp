#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
const int MAXLINE = 256;

int main(int argc, char const *argv[]){
	ifstream inFile ("/proc/uptime");
	char line[MAXLINE];

	while(inFile){
		inFile.getline(line, MAXLINE);
		cout << line << endl;
	}

	inFile.close();
	return 0;
}