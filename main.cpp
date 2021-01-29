/*
 * main.cpp
 *
 *  Created on: Jan 29, 2021
 *      Author: khang.le
 */
#include <string.h>
#include <iostream>
#include <dirent.h>
#include "Model.h"

using namespace std;

string csvFileInDir(){
	DIR *d;
	char *p1, *p2;
	int ret;
	string userSel = "";
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			p1 = strtok(dir->d_name, ".");
			p2 = strtok(NULL, ".");
			if (p2 != NULL) {
				ret = strcmp(p2, "csv");
				if (ret == 0)
					cout << p1 << endl;
			}
		}
		closedir(d);
		cout << "->Your selection: ";
		cin >> userSel;
		userSel += ".csv";
	}
	return userSel;
}

int main(){
	//do stuff
}
