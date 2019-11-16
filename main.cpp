#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string line;
	ifstream input_file (argv[1]);
	
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			cout << line << "\n";
		}
	} else {
		cout << "Unable to open file: " << argv[1] << "\n";
		return 1;
	}

	input_file.close();
	
	return 0;
}
