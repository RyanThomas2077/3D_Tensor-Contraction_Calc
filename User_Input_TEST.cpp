/*
    This is the first rendition of the code that allows users to select
    their desired method of inputting values (either one-by-one or all
    at once). Future developments minimized the total number of large
    tensor graphics needed for the calculator.

    This is only a test, the final result is more refined.
*/

#include <iostream>
#include <sstream>
    // included to make inputs more convenient for the user.

using namespace std;
int main()
{
    int array1[9];
    int array2[9];
    int array3[9];

            cout << R"(                     ___________________
                   /|                   |
                  / | [ 19] [ 20] [ 21] |
                 /  |                   |
                /   | [ 22] [ 23] [ 24] |
               /    |                   |
              /     | [ 25] [ 26] [ 27] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [ 10] [ 11] [ 12] |    /
         /  |                   |   /
        /   | [ 13] [ 14] [ 15] |  /
       /    |                   | /
      /     | [ 16] [ 17] [ 18] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [ 1 ] [ 2 ] [ 3 ] |    /
    |                   |   /
    | [ 4 ] [ 5 ] [ 6 ] |  /
    |                   | /
    | [ 7 ] [ 8 ] [ 9 ] |/
    |___________________/ )" << endl;  

    cout << "\nWelcome to the calculator!" << endl;

    cout << "How do you want to begin inserting values into the tensor?:\n" << endl;

    cout << "1. One-by-one (typing 'Enter' between inputs)" << endl;
    cout << "2. All at once (with spaces between each integer)\n" << endl;

    cout << "Choose 1 or 2: ";

    int selection;
    cin >> selection;
    cin.ignore();

    string input1;
    string input2;
    string input3;

    if(selection == 1)
    {
        cout << R"(                     ___________________
                   /|                   |
                  / | [...] [...] [...] |
                 /  |                   |
                /   | [...] [...] [...] |
               /    |                   |
              /     | [...] [...] [...] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [...] [...] [...] |    /
         /  |                   |   /
        /   | [...] [...] [...] |  /
       /    |                   | /
      /     | [...] [...] [...] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [ 1 ] [ 2 ] [ 3 ] |    /
    |                   |   /
    | [ 4 ] [ 5 ] [ 6 ] |  /
    |                   | /
    | [ 7 ] [ 8 ] [ 9 ] |/
    |___________________/ )" << endl;    

        cout << "\nEnter the first nine elements of the first level of the tensor one by one: \n" << endl;

        for(int i = 0; i < 9; i++)
        {
            cin >> array1[i];
        }

        cout << R"(                     ___________________
                   /|                   |
                  / | [...] [...] [...] |
                 /  |                   |
                /   | [...] [...] [...] |
               /    |                   |
              /     | [...] [...] [...] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [ 1 ] [ 2 ] [ 3 ] |    /
         /  |                   |   /
        /   | [ 4 ] [ 5 ] [ 6 ] |  /
       /    |                   | /
      /     | [ 7 ] [ 8 ] [ 9 ] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [...] [...] [...] |    /
    |                   |   /
    | [...] [...] [...] |  /
    |                   | /
    | [...] [...] [...] |/
    |___________________/ )" << endl; 

        cout << "\nEnter the next nine elements for the next level of the tensor one by one: \n" << endl;

        for(int i = 0; i < 9; i++)
        {
            cin >> array2[i];
        }

        cout << R"(                     ___________________
                   /|                   |
                  / | [ 1 ] [ 2 ] [ 3 ] |
                 /  |                   |
                /   | [ 4 ] [ 5 ] [ 6 ] |
               /    |                   |
              /     | [ 7 ] [ 8 ] [ 9 ] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [...] [...] [...] |    /
         /  |                   |   /
        /   | [...] [...] [...] |  /
       /    |                   | /
      /     | [...] [...] [...] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [...] [...] [...] |    /
    |                   |   /
    | [...] [...] [...] |  /
    |                   | /
    | [...] [...] [...] |/
    |___________________/ )" << endl; 

        cout << "\nEnter the final nine elements for the last level of the tensor one by one: \n" << endl;

        for(int i = 0; i < 9; i++)
        {
            cin >> array3[i];
        }

    }
    else if(selection == 2)
    {
        cout << R"(                     ___________________
                   /|                   |
                  / | [...] [...] [...] |
                 /  |                   |
                /   | [...] [...] [...] |
               /    |                   |
              /     | [...] [...] [...] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [...] [...] [...] |    /
         /  |                   |   /
        /   | [...] [...] [...] |  /
       /    |                   | /
      /     | [...] [...] [...] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [ 1 ] [ 2 ] [ 3 ] |    /
    |                   |   /
    | [ 4 ] [ 5 ] [ 6 ] |  /
    |                   | /
    | [ 7 ] [ 8 ] [ 9 ] |/
    |___________________/ )" << endl;  

        cout << "Enter the first nine elements of the tensor on a single line separated by spaces: \n" << endl;

        getline(cin, input1);

        stringstream ss1(input1);
        int i = 0;

        while(ss1 >> array1[i] && i < 9)
        {
            i++;
        }

        cout << R"(                     ___________________
                   /|                   |
                  / | [...] [...] [...] |
                 /  |                   |
                /   | [...] [...] [...] |
               /    |                   |
              /     | [...] [...] [...] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [ 1 ] [ 2 ] [ 3 ] |    /
         /  |                   |   /
        /   | [ 4 ] [ 5 ] [ 6 ] |  /
       /    |                   | /
      /     | [ 7 ] [ 8 ] [ 9 ] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [...] [...] [...] |    /
    |                   |   /
    | [...] [...] [...] |  /
    |                   | /
    | [...] [...] [...] |/
    |___________________/ )" << endl; 


        cout << "\nEnter the next nine elements of the tensor on a single line separated by spaces: \n" << endl;

        getline(cin, input2);

        stringstream ss2(input2);

        while(ss2 >> array2[i] && i < 9)
        {
            i++;
        }

        cout << R"(                     ___________________
                   /|                   |
                  / | [ 1 ] [ 2 ] [ 3 ] |
                 /  |                   |
                /   | [ 4 ] [ 5 ] [ 6 ] |
               /    |                   |
              /     | [ 7 ] [ 8 ] [ 9 ] |
             /      |___________________/
            /___________________       /
           /|                   |     /
          / | [...] [...] [...] |    /
         /  |                   |   /
        /   | [...] [...] [...] |  /
       /    |                   | /
      /     | [...] [...] [...] |/  
     /      |___________________/
    /___________________       /
    |                   |     /
    | [...] [...] [...] |    /
    |                   |   /
    | [...] [...] [...] |  /
    |                   | /
    | [...] [...] [...] |/
    |___________________/ )" << endl; 

        cout << "\nEnter the last nine elements of the tensor on a single line separated by spaces: \n" << endl;

        getline(cin, input3);

        stringstream ss3(input3);

        while(ss3 >> array3[i] && i < 9)
        {
            i++;
        }

    }
    else
    {
        cout << "Can you try again? I think you entered something other than a '1' or '2'!" << endl;
    }

    //___________________________________________________________________________________


    cout << "\nYou entered the following: "; 
    for(int i = 0; i < 9; i++)
    {
        cout << array1[i] << " ";
        cout << array2[i] << " ";
        cout << array3[i] << " ";
    }

}

// ***** choosing how to enter info into tensor

// choosing what axis to contract around

// contracting tensors

// displaying 2D matrix result