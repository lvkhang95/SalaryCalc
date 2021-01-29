/*
 * Model.cpp
 *
 *  Created on: Jan 29, 2021
 *      Author: khang.le
 */

#include "Model.h"
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

Model::Model(string& dataFilePath) {
	m_dataFilePath = dataFilePath;
	string line, word, temp;
	ifstream readFile(CONFIG_FILE_PATH);
	while(getline(readFile, line)){
		line.erase(remove(line.begin(), line.end(), ' '), line.end());// remove all blank space
		Salary salary;
		salary.m_title = line.substr(0, line.find('='));// get title
		string salaryInStr = line.substr(line.find('=') + 1, line.length() - (salary.m_title).length() - 1);
		salary.m_salary = stoi(salaryInStr);
		m_salaryTable.push_back(salary);
	}
	line.clear();
	vector<string> row;
	readFile.close();
	readFile.open(dataFilePath);
	while(readFile >> temp){
		row.clear();
		getline(readFile, line);
		stringstream s(line);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		Officer officer;
		officer.m_name = row[0];
		officer.m_revenue = stoi(row[1]);
		officer.m_title = row[2];
		officer.m_penalty = stoi(row[3]);
		officer.m_bonus = stoi(row[4]);
		m_officerInfo.push_back(officer);
	}
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

