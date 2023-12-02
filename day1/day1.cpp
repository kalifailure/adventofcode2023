#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std; 

int main() {
    ifstream inputFile("input.txt");    // Input File Path 
    vector<string> input;               // Vector for input strings
    vector<int> nums;                   // Temp vector for int extractions
    int total;                          // Total amount of first and last ints
    string line;                        // Line for reading input.txt 

    // Append each line to a vector
    while(getline(inputFile, line)) {
        input.push_back(line);
    }
    
    // Get all the ints from the string
    for (const auto& str : input) {
        // Clears the vector 
        nums.clear(); 

        // Puts all ints into a vector
        for (char x : str) {
            if(isdigit(x)) {
                nums.push_back(x - '0'); // x = '0' turns char into an int
            }
        }

        // If there is only one integer, double it
        if (nums.size() == 1) {
            string temp = to_string(nums[0]);    // Convert to string
            temp = temp + temp;                  // Concantinate both numbers together
            total += stoi(temp);
        } else { 
            string temp = to_string(nums[0]);
            temp += to_string(nums[nums.size() - 1]);
            total += stoi(temp);
        }
    }

    // Print the total
    cout << "Total: " << total << endl;
    
    return 0; 
}