// Made by Ryan Thomas
#include <iostream>
#include <map>

using namespace std;

int output_tensor_4D[3][3][3][3] = {0};
int output_tensor[3][3] = {0};

int Find_Index_For_2D_Output(const string& spot, int i, int j, int k, int x, int y)
{
    if(spot == "i") return i;
    if(spot == "j") return j;
    if(spot == "k") return k;
    if(spot == "x") return x;
    if(spot == "y") return y;
    return -1;
}

int Find_Index_For_4D_Output(const string& spot, int i, int j, int k, int w, int x, int y, int z)
{
    if(spot == "i") return i;
    if(spot == "j") return j;
    if(spot == "k") return k;
    if(spot == "w") return w;
    if(spot == "x") return x;
    if(spot == "y") return y;
    if(spot == "z") return z;
    return -1;
}

void fourD_operation(int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
{
    for(int w = 0; w < 3; w++)
    {
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                for(int z = 0; z < 3; z++)
                    {
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            for(int k = 0; k < 3; k++)
                            {
                                int first_spotA = Find_Index_For_4D_Output(spot_1, i, j, k, w, x, y, z);
                                int second_spotA = Find_Index_For_4D_Output(spot_2, i, j, k, w, x, y, z);
                                int third_spotA = Find_Index_For_4D_Output(spot_3, i, j, k, w, x, y, z);

                                int first_spotB = Find_Index_For_4D_Output(spot_4, i, j, k, w, x, y, z);
                                int second_spotB = Find_Index_For_4D_Output(spot_5, i, j, k, w, x, y, z);
                                int third_spotB = Find_Index_For_4D_Output(spot_6, i, j, k, w, x, y, z);

                                output_tensor_4D[w][x][y][z] += arrayA[first_spotA][second_spotA][third_spotA] * arrayB[first_spotB][second_spotB][third_spotB];
                            }
                        }
                    }
                }
            }
        }
    }
}

void twoD_operation(int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
{
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        int first_spotA = Find_Index_For_2D_Output(spot_1, i, j, k, x, y);
                        int second_spotA = Find_Index_For_2D_Output(spot_2, i, j, k, x, y);
                        int third_spotA = Find_Index_For_2D_Output(spot_3, i, j, k, x, y);

                        int first_spotB = Find_Index_For_2D_Output(spot_4, i, j, k, x, y);
                        int second_spotB = Find_Index_For_2D_Output(spot_5, i, j, k, x, y);
                        int third_spotB = Find_Index_For_2D_Output(spot_6, i, j, k, x, y);

                        output_tensor[x][y] += arrayA[first_spotA][second_spotA][third_spotA] * arrayB[first_spotB][second_spotB][third_spotB];
                    }
                }
            }
        } 
    }
}

map<string, function<void(int[3][3][3], int[3][3][3], int[3][3], string, string, string, string, string, string)>> operation_map;
map<string, function<void(int[3][3][3], int[3][3][3], int[3][3][3][3], string, string, string, string, string, string)>> operation_map2;

void possible_contractions()
{

    operation_map["ijij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "i", "j", "y");
    };
    operation_map["ijik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "i", "k", "y");
    };    
    operation_map["ijji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "j", "i", "y");
    };
    operation_map["ijjk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "j", "k", "y");
    };
    operation_map["ijki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "k", "i", "y");
    };
    operation_map["ijkj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "j", "x", "k", "j", "y");
    };
    operation_map["ikij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "i", "y", "j");
    };
    operation_map["ikik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "i", "y", "k");
    };
    operation_map["ikji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "j", "y", "i");
    };
    operation_map["ikjk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "j", "y", "k");
    };
    operation_map["ikki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "k", "y", "i");
    };
    operation_map["ikkj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "i", "x", "k", "k", "y", "j");
    };
    operation_map["jiij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "i", "j", "y");
    };
    operation_map["jiik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "i", "k", "y");
    };
    operation_map["jiji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "j", "i", "y");
    };
    operation_map["jijk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "j", "k", "y");
    };
    operation_map["jiki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "k", "i", "y");
    };
    operation_map["jikj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "j", "i", "x", "k", "j", "y");
    };
    operation_map["jkij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "i", "j");
    };
    operation_map["jkik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "i", "k");
    };
    operation_map["jkji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "j", "i");
    };
    operation_map["jkjk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "j", "k");
    };
    operation_map["jkki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "k", "i");
    };
    operation_map["jkkj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "j", "k", "y", "k", "j");
    };
    operation_map["kiij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "i", "y", "j");
    };
    operation_map["kiik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "i", "y", "k");
    };
    operation_map["kiji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "j", "y", "i");
    };
    operation_map["kijk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "j", "y", "k");
    };
    operation_map["kiki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "k", "y", "i");
    };
    operation_map["kikj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "k", "x", "i", "k", "y", "j");
    };
    operation_map["kjij"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "i", "j");
    };
    operation_map["kjik"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "i", "k");
    };
    operation_map["kjji"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "j", "i");
    };
    operation_map["kjjk"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "j", "k");
    };
    operation_map["kjki"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "k", "i");
    };
    operation_map["kjkj"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor[3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        twoD_operation(arrayA, arrayB, output_tensor, "x", "k", "j", "y", "k", "j");
    };

// ***********************************

    operation_map2["i0i0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "i", "w", "x", "i", "y", "z");
    };
    operation_map2["i0j0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "i", "w", "x", "j", "y", "z");
    };
    operation_map2["i0k0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "i", "w", "x", "k", "y", "z");
    };
    operation_map2["j0i0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "j", "x", "y", "i", "z");
    };
    operation_map2["j0j0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "j", "x", "y", "j", "z");
    };
    operation_map2["j0k0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "j", "x", "y", "k", "z");
    };
    operation_map2["k0i0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "x", "k", "y", "z", "i");
    };
    operation_map2["k0j0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "x", "k", "y", "z", "j");
    };
    operation_map2["k0k0"] = [](int arrayA[3][3][3], int arrayB[3][3][3], int output_tensor_4D[3][3][3][3], string spot_1, string spot_2, string spot_3, string spot_4, string spot_5, string spot_6)
    {
        fourD_operation(arrayA, arrayB, output_tensor_4D, "w", "x", "k", "y", "z", "k");
    };
}

std::string create_key(const std::string& array_index_0, const std::string& array_index_1, const std::string& array_index_2, const std::string& array_index_3)
{
    return array_index_0 + array_index_1 + array_index_2 + array_index_3;
}

void print_4D_tensor_result(int output_tensor_4D[3][3][3][3])
{
    for(int w = 0; w < 3; w++)
    {
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                for(int z = 0; z < 3; z++)
                {
                    cout << "output_tensor[" << w << "]["
                         << x << "][" << y << "][" << z << "] = "
                         << output_tensor_4D[w][x][y][z] << "\n";
                }
            }
        }
    }
}

void print_2D_matrix_result(int output_tensor[3][3])
{
    cout << "[" << output_tensor[0][0] << "]     [" << output_tensor[0][1] << "]     [" << output_tensor[0][2] << "]\n\n"
         << "[" << output_tensor[1][0] << "]     [" << output_tensor[1][1] << "]     [" << output_tensor[1][2] << "]\n\n"
         << "[" << output_tensor[2][0] << "]     [" << output_tensor[2][1] << "]     [" << output_tensor[2][2] << "]\n\n"; 
}
