#include "search.h"

void search(const string &filename,const string& index) {
    ifstream file(filename);
    if(!file){
        cerr<<"Error opening the file"<<endl;
        return;
    }
    
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(index) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Index not found." << endl;
    }

    file.close();
} 
