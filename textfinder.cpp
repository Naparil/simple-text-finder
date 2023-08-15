#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

using namespace std;
namespace fs = filesystem;

void searchStringInFile(const string&, const string&);

int main(void) {
	string path, searchString;

	cout << "target path : ";
	cin >> path;
	cout << "target text : ";
	cin >> searchString;


	for (const auto& temp : fs::recursive_directory_iterator(path)) {
		if (temp.is_regular_file())
		{
			searchStringInFile(temp.path().string(), searchString);
		}
	}

	return 0;
}

void searchStringInFile(const string& path, const string& str) {
	ifstream readFile;

	readFile.open(path);

	if (readFile.is_open()) {
		string line;
		int lineNum = 0;
		while (getline(readFile, line)) {
			if (line.find(str) != string::npos) {
				cout << path << " / " << lineNum << "\n";
			}
			lineNum++;
		}
	}

	readFile.close();
}