#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
const int MAXLINE = 256;

void searchProc(string path, char* search);

int main(int argc, char const *argv[]){
	cout << "Task A" << endl;
	searchProc("/proc/cpuinfo", "vendor_id");
	cout << "Task B" << endl;
	searchProc("/proc/version_signature", "Ubuntu");
	cout << "Task C" << endl;
	searchProc("/proc/uptime", "");
	cout << "Task D (User 1st, System 3rd, Idle 4th)" << endl;
	searchProc("/proc/stat", "cpu");
	cout << "Task E" << endl;
	searchProc("/proc/meminfo", "MemTotal");
	searchProc("/proc/meminfo", "Active");
	cout << "Task F" << endl;
	searchProc("/proc/meminfo", "MemAvailable");
	return 0;
}

void searchProc(string path, char* search){
	ifstream inFile(path);
	char line[MAXLINE];

	while(inFile){
		inFile.getline(line, MAXLINE);

		if (strstr(line, search) != NULL){
			cout << line << endl;
			break;
		}
	}
	inFile.close();
}