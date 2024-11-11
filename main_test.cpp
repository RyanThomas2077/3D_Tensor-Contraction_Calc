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

    int selection;
    cin >> selection;
    cin.ignore();

    string input;

    cout << "Input your desired values for this first dimension of the tensor: " << endl;

    if(selection == 1)
    {
        // show first level of tensor

        cout << "Enter the first nine elements of the first level of the tensor one by one: " << endl;

        for(int i = 0; i < 9; i++)
        {
            cin >> array1[i];
        }
    }
    else if(selection == 2)
    {
        // show first level fo tensor

        cout << "Enter the first nine elements of the tensor on a single line separated by spaces: \n";

        getline(cin, input);

        stringstream ss(input);
        int i = 0;
        while(ss >> array1[i] && i < 9)
        {
            i++;
        }
        
    }
    else
    {
        cout << "Can you try again? I think you entered something other than a '1' or '2'!" << endl;
    }

    cout << "You entered the following: "; 
    for(int i = 0; i < 9; i++)
    {
        cout << array1[i] << " ";
    }

}