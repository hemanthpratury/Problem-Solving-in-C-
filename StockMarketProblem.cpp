/*
*
*
* Sai Siva Hemanth Pratury 				SJSU ID:010817833
* home work 3 question-1
*/

#include <iostream>

using namespace std;
	void stockLoss(int input[]) {
        int lowIndex = 0;
        int highIndex = 0;
        int currHighIndex = 0;
        
        int loss = 0;
        int length = 8;
        int counter = 0;
        while (counter < length) {
            if (input[counter] > input[highIndex]) {
                highIndex = counter;
            }
            
            if (input[counter] - input[highIndex] < loss) {
                loss = input[counter] - input[highIndex];
                lowIndex = counter;
                if (input[currHighIndex] < input[highIndex]) {
                    currHighIndex = highIndex;
                }
            }
            counter++;
        }
        
        if (currHighIndex > lowIndex) {
            cout << "Can not sell before buying items" << endl;
        } else if (currHighIndex == lowIndex) {
            cout << "No loss" << endl;
        }
        
        cout << "Buying day index " << currHighIndex << endl;
		cout << "Selling Day index " << lowIndex << endl;
        cout << "loss: " << -(loss) << " units" << endl;
    }
    
   int main() 
	{
       int input[] = { 5, 2, 8, 1, 12, 3, 19, 6};
	           stockLoss(input);
    }
    
    

