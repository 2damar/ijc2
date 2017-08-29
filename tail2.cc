#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

void tail(istream& is, unsigned int nlines) {
	string line;
	queue<string> lines;

	while(getline(is, line)) {
		if(lines.size() == nlines) 
			lines.pop();
		lines.push(line);
	}

	while(!lines.empty()) {
		cout << lines.front() << endl;
		lines.pop();
	}
}

void usage() {
	cerr << "Usage: ./tail2 [-n lines] [file]";
}

int main(int argc, char* argv[]) {

	std::ios::sync_with_stdio(false);

	long unsigned nsize = 10;
	char* filename = NULL;

	if(argc == 2) {
		filename = argv[1];		
	} else if(argc == 3) {
		if(string(argv[1]).compare("-n") != 0) { 
			usage();
			return -1;
		}
		nsize = stoi(argv[2]);
	} else if(argc == 4) {
		if(string(argv[1]).compare("-n") != 0) {
			usage();
			return -1;
		}
		nsize = stoi(argv[2]);
		filename = argv[3];
	} else if(argc != 1) {
		usage();
		return -1;
	} 
	
	if(filename) {
		ifstream in(filename);
		if(!in) {
			cerr << "Could not open file " << filename;
			return -1;
		}
		tail(in, nsize);
	} else {
		tail(cin, nsize);
	}

	return 0;
}
