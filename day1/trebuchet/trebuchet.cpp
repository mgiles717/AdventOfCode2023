#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const int NOT_FOUND = -1;

// Pass logic whilst loading to avoid having to deal with parsing 
// lines after alreaady using getline
// 
// Make vector to dynamically store the number corresponding to 
// the first and last digit (too lazy to allocate size for static array)
vector<int> loadFile(std::string file_path){
    ifstream myFile(file_path);

    if (!myFile.is_open()){
        cout << "Unable to open the file!" << endl;
        return {};
    }

    vector<int> line_digits {};

    // Iterate through each line of the file
    string line;
    while (getline(myFile, line)){
        int first = NOT_FOUND;
        int last = NOT_FOUND;
        int combined = 0;
        for(char c : line){
            if(isdigit(c) == true){
                // Convert to numeric
                if(first == NOT_FOUND){
                    first = c - '0';
                }
                else{
                    last = c - '0';
                }
            }   
        }
        
        // Check if not combining
        // if not, increase to 2nd order base10 and add first
        // first = 7, last = , combined = 77
        if (last == -1){
            combined = (first * 10) + first;
        }
        // Shift first to 2nd order base10 to combined as 2 digit number
        else{
            combined = (first * 10) + last;
        }

        line_digits.push_back(combined); 
    }
    
    myFile.close();
    return line_digits;
}

int main(){
    vector<int> digits = loadFile("inputs.txt");
    int sum = accumulate(digits.begin(), digits.end(), 0);
    
    cout << sum << endl;
    return 0;
}