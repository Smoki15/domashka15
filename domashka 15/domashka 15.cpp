
//завдання 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void task1(const string& inputFile, const string& outputFile) {
	ifstream fin(inputFile);
	ofstream fout(outputFile);

	if (!fin.is_open() || !fout.is_open()) {
		cout << "Помилка відкриття файлів\n";
		return;
	}

	vector<string> lines;
	string line;
	while (getline(fin, line)) {
		lines.push_back(line);
	}

	for (size_t i = 0; i + 1 < lines.size(); i++) {
		fout << lines[i] << endl;
	}

	fin.close();
	fout.close();
	cout << "Останній рядок видалено.\n";
}

//завдання 2
void task2(const string& inputFile) {
	ifstream fin(inputFile);
	if (!fin.is_open()) {
		cout << "Помилка відкриття файлів\n";
		return;
	}
	
	string line;
	size_t maxlen = 0;
	while (getline(fin, line)) {
		if (line.size() > maxlen) maxlen = line.size();
	}

	cout << "Найдовший рядок має довжину: " << maxlen << endl;
	fin.close();
}

//завдання 3
void task3(const string& inputFile) {
	ifstream fin(inputFile);
	if (!fin.is_open()) {
		cout << "Помилка відкриття файлів\n";
		return;
	}

	string word;
	cout << "Введіть слово для пошуку: ";
	cin >> word;

	int count = 0;
	string temp;
	while (fin >> temp) {
		if (temp == word) count++;
	}

	cout << "Слово \"" << word << "\" зустрічається " << count << " раз(и).\n";
	fin.close();
}

//завдання 4
void task4(const string& inputFile, const string& outputFile) {
	ifstream fin(inputFile);
	ofstream fout(outputFile);

	if (!fin.is_open() || !fout.is_open()) {
		cout << "Помилка відкриття файлів\n";
		return;
	}

	string findWord, replaceWord;
	cout << "Що шукати: ";
	cin >> findWord;
	cout << "На що замінювати: ";
	cin >> replaceWord;

	string word;
	while (fin >> word) {
		if (word == findWord) fout << replaceWord << " ";
		else fout << word << " ";
	}

	fin.close();
	fout.close();
	cout << "Заміна виконана.\n";
}
int main()
{
	system("chcp 1251>null");
	int choice;
	cout << "Оберіть завдання (1-4): ";
	cin >> choice;

	string inFile = "input.txt";
	string outFile = "output.txt";
	
	switch (choice) {
	case 1: task1(inFile, outFile); break;
	case 2: task2(inFile); break;
	case 3: task3(inFile); break;
	case 4: task4(inFile, outFile); break;
	default: cout << "Невірний вибір!\n"; break;
	}

	return 0;
}
