#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream inputFile;
	ofstream outputFile;

	string line;
	string newLine;

	inputFile.open("test.txt");
	outputFile.open("newTest.txt");

	while (getline(inputFile, line)) {
		outputFile << "\thtmlFile << " << '"' << line << '"' << " << endl;" << endl;
		// outputFile << "<h1></h1>" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}