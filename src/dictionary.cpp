//============================================================================
// Name        : dictionary.cpp
// Author      : Xiao Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <algorithm>
#include<map>
using namespace std;

map<string, string> dictionary;
map<string, string>::iterator iter;
class Option {
private:
	bool isexist = true;
public:
	Option();
	void adding();
	void deleting();
	void checking();
	void initialize();
};

Option::Option() {
}

void Option::adding() {
	string wordForAdding;
	cout << "please input a word for adding: " << endl;
	cin >> wordForAdding;
	transform(wordForAdding.begin(), wordForAdding.end(), wordForAdding.begin(),
			::tolower);

	iter = dictionary.find(wordForAdding);
	if (iter != dictionary.end()) {
		cout << "The word is already exist!" << endl;
	}

	else {
		dictionary.insert(make_pair(wordForAdding, " "));
		for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
				cout << " " << iter->first << " " << iter->second << endl;
			}

		cout << "The word is added!" << endl;
	}
}

void Option::deleting() {
	string wordForDeleting;
	cout << "please input a word for deleting: " << endl;
	cin >> wordForDeleting;
	transform(wordForDeleting.begin(), wordForDeleting.end(),
			wordForDeleting.begin(), ::tolower);
	iter = dictionary.find(wordForDeleting);
	if (iter != dictionary.end()) {
		dictionary.erase(wordForDeleting);
		for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
				cout << " " << iter->first << " " << iter->second << endl;
			}

		cout << "The word is deleted!" << endl;
	} else {
		cout << "The word is not exist!" << endl;
	}
}

void Option::checking() {
	string wordForChecking;
	cout << "please input a word for checking : " << endl;
	cin >> wordForChecking;
	transform(wordForChecking.begin(), wordForChecking.end(),
			wordForChecking.begin(), ::tolower);
	iter = dictionary.find(wordForChecking);
	if (iter != dictionary.end()) {
		cout << "The word is exist!" << endl;
	} else {
		cout << "The word is not exist!" << endl;
	}
}

static map<string, int> mapoptionValue;

void Option::initialize() {
	mapoptionValue["add"] = 1;
	mapoptionValue["delete"] = 2;
	mapoptionValue["check"] = 3;
	mapoptionValue["quit"] = 4;
}

int main() {

	ifstream d;
	d.open("dictionary.txt");
	if (d.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	string word;
	string const value = "";
	while (d >> word) {
		transform(word.begin(), word.begin() + 1, word.begin(), ::tolower);
		dictionary[word] = value;
	}

	for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
		cout << " " << iter->first << " " << iter->second << endl;
	}

	Option op;
	string choice;
	op.initialize();

	while (1) {
		cout << "Please input your option: add, delete, check or quit." << endl;
		cin >> choice;
		switch (mapoptionValue[choice]) {
		case 1:
			op.adding();
			continue;
		case 2:
			op.deleting();
			continue;
		case 3:
			op.checking();
			continue;
		case 4:
			cout << "program quit." << endl;
			return 0;
		default:
			cout << "wrong command." << endl;
			continue;
		}

	}

	d.close();
	return 0;
}
