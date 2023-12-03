#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Pass logic whilst loading to avoid having to deal with parsing 
// lines after alreaady using getline
// 
// Make vector to dynamically store the number corresponding to 
// the first and last digit (too lazy to allocate size for static array)
string loadFile(std::string file_path){
    string fileContent;
    ifstream myFile(file_path);
    if (myFile.is_open()){
        while (getline(myFile, fileContent)){
            cout << fileContent << '\n';
        }
    myFile.close();
    }
    else cout << "Unable to open the file!";

    return fileContent;
}

int main(){
    string fileContent = loadFile("inputs.txt");
    cout << fileContent;
    return 0;
}