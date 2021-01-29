/*
 * Model.h
 *
 *  Created on: Jan 29, 2021
 *      Author: khang.le
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <string>
#include <vector>

const std::string CONFIG_FILE_PATH = "config.txt";

class Officer {
public:
	std::string m_name, m_title;
	int m_revenue, m_penalty, m_bonus;
	int m_total = m_revenue + m_bonus - m_penalty;
};

class Salary {
public:
	std::string m_title;
	int m_salary;
};

class Model {
	std::vector<Officer> m_officerInfo;
	std::vector<Salary> m_salaryTable;
	std::string m_dataFilePath;
public:
	Model(std::string&);
	~Model();
};

#endif /* MODEL_H_ */
