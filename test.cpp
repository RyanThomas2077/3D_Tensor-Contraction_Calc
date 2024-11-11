/*
#include <iostream>
#include <sstream>

using namespace std;
int main()
{
    int array1[9];
    int array2[9];
    int array3[9];

    // Insert diagram of entire tensor, showing first level;

    cout << "How do you want to begin inserting values into the tensor?:\n" << endl;

    cout << "1. One-by-one (typing 'Enter' between inputs)" << endl;
    cout << "2. All at once (with spaces between each integer)\n" << endl;

    cout << "Choose 1 or 2: ";

    int x;
    cin >> x;
    if (x != (1 || 2))
    {
        cout << "Can you try again? I don't think you put a '1' or a '2'" << endl;
    }
}
*/

#include <iostream>
#include <sstream>  // For stringstream
using namespace std;

int main() {
    const int SIZE = 10; // Define a fixed size for the array
    int arr[SIZE];       // Declare a fixed-size array
    string input;
    int n;

    cout << "How do you want to input the elements?" << endl;
    cout << "1. Input one by one (press 'Enter' after each input)" << endl;
    cout << "2. Input all elements in one line, separated by spaces" << endl;
    cout << "Enter 1 or 2: ";
    cin >> n;
    cin.ignore();  // To clear the newline left over from the previous input

    if (n == 1) {
        cout << "Enter " << SIZE << " elements one by one (press 'Enter' after each input):" << endl;
        // Input elements one by one
        for (int i = 0; i < SIZE; i++) {
            cin >> arr[i];
        }
    }
    else if (n == 2) {
        cout << "Enter all elements in one line, separated by spaces:" << endl;
        getline(cin, input);  // Read the entire line

        stringstream ss(input);  // Create a stringstream to split the input
        int i = 0;
        while (ss >> arr[i] && i < SIZE) {
            i++;  // Fill the array with input values
        }
    }
    else {
        cout << "Invalid option!" << endl;
        return 1;  // Exit if the user chooses an invalid option
    }

    // Output the entered elements
    cout << "You entered the following elements:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}