// Made by Ryan Thomas
#include <iostream>
#include <sstream>
using namespace std;

void showcase_tensor()
{
    cout << R"(                     ___________________            ___________________
                   /|                   |         /|                   |
                  / | [19A] [20A] [21A] |        / | [19B] [20B] [21B] |
                 /  |                   |       /  |                   |
                /   | [22A] [23A] [24A] |      /   | [22B] [23B] [24B] |
               /    |                   |     /    |                   |
              /     | [25A] [26A] [27A] |    /     | [25B] [26B] [27B] |
             /      |___________________/   /      |___________________/
            /___________________       /   /___________________       /
           /|                   |     /   /|                   |     /
          / | [10A] [11A] [12A] |    /   / | [10B] [11B] [12B] |    /
         /  |                   |   /   /  |                   |   /
        /   | [13A] [14A] [15A] |  /   /   | [13B] [14B] [15B] |  /
       /    |                   | /   /    |                   | /
      /     | [16A] [17A] [18A] |/   /     | [16B] [17B] [18B] |/
     /      |___________________/   /      |___________________/
    /___________________       /   /___________________       /
    |                   |     /    |                   |     /
    | [ 1A] [ 2A] [ 3A] |    /     | [ 1B] [ 2B] [ 3B] |    /
    |                   |   /      |                   |   /
    | [ 4A] [ 5A] [ 6A] |  /       | [ 4B] [ 5B] [ 6B] |  /
    |                   | /        |                   | /
    | [ 7A] [ 8A] [ 9A] |/         | [ 7B] [ 8B] [ 9B] |/
    |___________________/          |___________________/)" << endl; 
}

void First_TNSR_A()
{
    cout << R"(                     ___________________
                   /|                   |
                  / | [19A] [20A] [21A] |
                 /  |                   |
                /   | [22A] [23A] [24A] |
               /    |                   |
              /     | [25A] [26A] [27A] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [10A] [11A] [12A] |    /
         /  |                   |   /
        /   | [13A] [14A] [15A] |  /
       /    |                   | /
      /     | [16A] [17A] [18A] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [ 1A] [ 2A] [ 3A] |    /
    |                   |   /
    | [ 4A] [ 5A] [ 6A] |  /
    |                   | /
    | [ 7A] [ 8A] [ 9A] |/
    |___________________/ )" << endl;  
}

void First_TNSR_B()
{
    cout << R"(                     ___________________
                   /|                   |
                  / | [19B] [20B] [21B] |
                 /  |                   |
                /   | [22B] [23B] [24B] |
               /    |                   |
              /     | [25B] [26B] [27B] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [10B] [11B] [12B] |    /
         /  |                   |   /
        /   | [13B] [14B] [15B] |  /
       /    |                   | /
      /     | [16B] [17B] [18B] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [ 1B] [ 2B] [ 3B] |    /
    |                   |   /
    | [ 4B] [ 5B] [ 6B] |  /
    |                   | /
    | [ 7B] [ 8B] [ 9B] |/
    |___________________/ )" << endl;
}

void EXPLANATION()
{
    cout << "\n" << R"(____________________________________________________________________________________

Tensor contraction involves taking a shared index between multiple matrices and 
summing over that index until every combination of the other indexes are multiplied 
and added together.

It's very similar to matrix multiplication, but as we're working with tensors, the 
process only stops once the shared index is completely summed over.

As this calculator utilizes two 3D (or 3x3x3 square) matrices, choosing any specific 
index won't change the final size of the answer, but its final contents will change 
as the summed index is essentially discarded at the end.
____________________________________________________________________________________)" << endl;

    this_thread::sleep_for(chrono::milliseconds(4500));
}

bool ValidAxisNumber(const string& number_of_indexes)
{
    return(number_of_indexes == "1" || number_of_indexes == "2");
}

bool ValidInputSelection(const int& input_method)
{
    return(input_method != 1 && input_method != 2);
}

bool SameIndex(const string index_selection[], int array_size)
{
    if(array_size < 2)
    {
        return false;
    }
    for(int i = 1; i < array_size; i++)
    {
        if(index_selection[i] == index_selection[i - 1])
        {
            return true;
        }
    }

    return false;
}

void Input_to_Tensor(int array[3][3][3], const string& Tensor, int input_method)
{
    string Tensor_input;

    if(input_method == 1)
    {
        cout << "\nEnter the 27 elements of " << Tensor << " one-by-one: \n" << endl;
        for(int a = 0; a < 3; a++)
        {
            for(int b = 0; b < 3; b++)
            {
                for(int c = 0; c < 3; c++)
                {
                    cin >> array[a][b][c];
                }
            }
        }
    }
    else if(input_method == 2)
    {
    cout << "\nEnter the 27 elements of " << Tensor << " on one line separated by spaces: \n" << endl;
    cin.ignore();
    getline(cin, Tensor_input); 

    stringstream ss(Tensor_input);
    int i = 0;
    while(i < 27 && ss >> array[i/9][(i/3) % 3][i%3])  // Check i < 27 before extraction
    {
        i++;
    }
}
}

bool ValidIndex(const string& index_selection)
{
    return(index_selection == "i" || index_selection == "j" || index_selection == "k");
}

bool Try_again_choice(const string& explanation_choice)
{
    return(explanation_choice == ("Yes") || explanation_choice == ("No") || explanation_choice == ("yes") || explanation_choice == ("no"));
}

void Illusion_of_Choice()
{
    cout << "\nWould you like a brief explanation on Tensor Contraction? Enter 'Yes' or 'No': ";

    string choice;
    cin >> choice;
    
    if(choice == "Yes" || choice == "yes")
    {
        EXPLANATION();
    }
    else if(choice == "No" || choice == "no")
    {
        
    }
    else
    {
        while(!Try_again_choice(choice))
        {
            cout << "\n\nCan you try again?: ";
            cin >> choice;
        }
        if(choice == "Yes" || choice == "yes")
        {
            EXPLANATION();
        }
        else if(choice == "No" || choice == "no")
        {

        }
    }
}
