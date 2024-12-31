// Made by Ryan Thomas
// Run code from this file
#include <iostream>
#include <sstream> // Included for one-line inputs
#include <chrono> // Included to space out text
#include <thread> // Used with chrono to have pauses in code
#include <map> // Included to map specific index combinations to different outputs
#include "OPERATIONS.cpp" // Imported file that has all the tensor contractions
#include "FUNCTIONS.cpp" // Imported file that includes most created functions and graphics

using namespace std;
int main()
{
    
    int arrayA[3][3][3];
    int arrayB[3][3][3];

    int input_method;

    cout << "\nWelcome to the calculator!\n\n";

    showcase_tensor();

    cout << "\n\nHow do you want to begin inserting values into the Tensors?:"
         << "\n1. One-by-one (typing 'Enter between inputs)"
         << "\n2. All at once (with spaces between each integer)"
         << "\n\nChoose '1' or '2': ";
    
    this_thread::sleep_for(chrono::milliseconds(1500));
    // 1.5 second pause

    cin >> input_method;

    while(ValidInputSelection(input_method))
    {
        cout << "\n\nCould you try again? I don't think you entered a '1' or a '2'! ";
        cin >> input_method;
    }

    First_TNSR_A();
    // Displays tensor A

    cout << "\n";

    Input_to_Tensor(arrayA, "Tensor A", input_method);

    cout << "\nGreat! Now let's do the same for Tensor B!\n\n";

    First_TNSR_B();
    // Displays tensor B

    cout << "\n";

    Input_to_Tensor(arrayB, "Tensor B", input_method);

    Illusion_of_Choice();
    // Asks if you would an explanation as to what tensor contraction is

    this_thread::sleep_for(chrono::milliseconds(0500));
    // 0.5 second pause

    string number_of_indexes;
    
    cout << "\nHow many common axes would you like to contract over?:"
         << "\n1. one common axis (4D resultant tensor)"
         << "\n2. two common axes (2D resultant tensor)"
         << "\nChoose '1' or '2': ";
    // In tensor contraction, choosing one common axis between two 3x3x3 tensors makes a 4D tensor
        // choosing two common axes makes a 2D tensor (or a typical matrix)
        // (this is how it works mathematically)

    this_thread::sleep_for(chrono::milliseconds(1000));
    // 1 second pause

    cin >> number_of_indexes;

        while(!ValidAxisNumber(number_of_indexes))
        {
            cout << "\nInvalid number. Please choose '1' or '2': ";
            cin >> number_of_indexes;
            // if input is not '1' or '2', repeats until the input is a '1' or '2'
        }

    string array_index[4] = {"0","0","0","0"};

    cout << "\nWhich axis from Tensor A would you like to contract over?\nChoose from the following axes:"
         << "\n1. i index(rows)"
         << "\n2. j index(columns)"
         << "\n3. k index(depth)"
         << "\nChoose axis 'i,' 'j,' or 'k': ";

    cin >> array_index[0];

        while(!ValidIndex(array_index[0]))
        {
            cout << "\nInvalid input. Please choose 'i', 'j', or 'k': ";
            cin >> array_index[0];
            // If input is not an 'i', 'j', or 'k', repeats until so
        }

    if(number_of_indexes == "2")
    // a second axis for tensor A is only inputted if the user desired two common axes
    {
        cout << "\n\nWhat second axis from Tensor A would you like to contract over?\nChoose 'i', 'j', or 'k': ";
        cin >> array_index[1];

        while(SameIndex(array_index, 2))
        {   
            cout << "\nYou can't choose the same axis again! Choose a different one from Tensor A: ";
            cin >> array_index[1];
            // checks if the user chose the same axis twice for tensor A (not mathematically possible)

            while(!ValidIndex(array_index[1]))
            {
                cout << "\nInvalid input. Please choose 'i', 'j', or 'k': ";
                cin >> array_index[1];
                // checks if input is one of the possible axes in a 3x3x3 tensor
            }
        }
    }

    cout << "\nWhat axis from Tensor B would you like to contract over?\nChoose 'i', 'j', or 'k': ";
    cin >> array_index[2];

        while(!ValidIndex(array_index[2]))
        {
            cout << "\nInvalid input. Please choose 'i', 'j', or 'k': ";
            cin >> array_index[2];
        }

    if(number_of_indexes == "2")
    // a second axis for tensor B is only inputted if the user desired two common axes
    {
        cout << "\nWhat second axis from Tensor B would you like to contract over?\nChoose 'i', 'j', or 'k': ";
        cin >> array_index[3];

        while(SameIndex(array_index, 4))
        {
            cout << "\nYou can't choose the same axis again!\nChoose a different one from Tensor B: ";
            cin >> array_index[3];

            while(!ValidIndex(array_index[3]))
            {
                cout << "\nInvalid input. Please choose 'i', 'j', or 'k': ";
                cin >> array_index[3];
            }
        }
    }

    possible_contractions();
    // initiallizes the map from 'OPERATIONS.cpp' that carries every possible contraction into this file

    int output_tensor_4D[3][3][3][3] = {0}; // only used if one common axis is chosen by the user
    int output_tensor[3][3] = {0}; // only used if two common axes is chosen by the user
    string spot_1, spot_2, spot_3, spot_4, spot_5, spot_6;

    string key = create_key(array_index[0], array_index[1], array_index[2], array_index[3]);

    if(number_of_indexes == "2")
    // for the 2D matrix output
    {
        if(operation_map.find(key) != operation_map.end()) 
        {
            operation_map[key](arrayA, arrayB, output_tensor, spot_1, spot_2, spot_3, spot_4, spot_5, spot_6);
        }   
        else 
        {
            cout << "No operation found for this combination\n";
            // this should never trigger, as impossible contractions were previously excluded
        }
    }
    else if(number_of_indexes == "1")
    // for the 4D tensor output
    {
        if(operation_map2.find(key) != operation_map2.end()) 
        {
            operation_map2[key](arrayA, arrayB, output_tensor_4D, spot_1, spot_2, spot_3, spot_4, spot_5, spot_6);
        }   
        else 
        {
            cout << "No operation found for this combination\n";
            // again, this should never trigger
        }
    }

    // ****************************************

    if(number_of_indexes == "1")
    {
        cout << "______________________________________________________________________________\n\n"
             << "The resulting 4D tensor can be difficult to represent artistically,\n"
             << "so, I will just output every element of the 4D tensor as a list.\n"
             << "______________________________________________________________________________\n\n";

        this_thread::sleep_for(chrono::milliseconds(3000));
        // 3 second pause 

        print_4D_tensor_result(output_tensor_4D);
        // lists every element of the 4D tensor
        // artistic representation is hard because it's a 4-dimensional shape
    }
    else if(number_of_indexes == "2")
    {
        cout << "______________________________________________________________________________\n\n"
             << "The resulting 2D tensor is essentially just a typical-looking matrix,\n"
             << "so, it can be represented artistically pretty well.\n"
             << "______________________________________________________________________________\n\n";

        this_thread::sleep_for(chrono::milliseconds(2000));
        // 2 second pause

        print_2D_matrix_result(output_tensor); 
        // outputs the contracted output
        // since the output is 2-dimensional, the output artistically looks like a matrix
            // if values are very large, the output may not necessarily look aesthetically good
    }
}
