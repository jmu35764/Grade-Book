// Grade Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int TESTNUMBER = 5;
void ReadTxt(string file, string names[], int grades[][TESTNUMBER]);
void calc_average(int grades[][TESTNUMBER], int avg[]);

int main()
{
    string stud_name[20];
    int average[20];
    //int x = 0;
    int grade_num[20][TESTNUMBER];
    string filename = "StudentGrades.txt";

    ReadTxt(filename, stud_name, grade_num);
               
    calc_average(grade_num, average);

        

}

void ReadTxt(string file, string names[20],int grades[20][TESTNUMBER])
{
    ifstream inputFile(file);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: OCuld not open the file";
        //return "";
    }

    //std::string name[20];
    /*std::string name[20];
    int average[20];
    int grade[20][TESTNUMBER];*/
    int x = 0;

    while (inputFile >> names[x] >> grades[x][0] >> grades[x][1] >> 
           grades[x][2] >> grades[x][3] >> grades[x][4])
    {
        std::cout << names[x] 
            << std::setw(4) << grades[x][0]
            << std::setw(4) << grades[x][1]
            << std::setw(4) << grades[x][2]
            << std::setw(4) << grades[x][3]
            << std::setw(4) << grades[x][4] << std::endl;
            x++;
    }

    inputFile.close();
    //return 0;
}

void calc_average(int grades[][TESTNUMBER], int avg[])
{
    int total = 0;
    //int average[20];

    for (int z = 0; z < 20; z++)
    {
        for (int y = 0; y < TESTNUMBER; y++)
        {
            total = grades[z][y] + total;
        }

        avg[z] = total / TESTNUMBER;

        cout << avg[z] << endl;
        //cout << total << endl;
        total = 0;
    }

    //return avg[];
    
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
