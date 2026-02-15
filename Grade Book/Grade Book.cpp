// Grade Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int TESTNUMBER = 5;
int ReadTxt(string file, string names[], int grades[][TESTNUMBER], int a);
void calc_average(int grades[][TESTNUMBER], int avg[]);

int main()
{
    string stud_name[20];
    int average[20];
    int x = 0;
    int grade_num[20][TESTNUMBER];
    string filename = "StudentGrades.txt";

    x = ReadTxt(filename, stud_name, grade_num, x); 

    cout << x << endl;

    calc_average(grade_num, average);

    //for (i = 0; i)
        

}

int ReadTxt(string file, string names[20],int grades[20][TESTNUMBER], int a)
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
    //int x = 0;

    while (inputFile >> names[a] >> grades[a][0] >> grades[a][1] >> 
           grades[a][2] >> grades[a][3] >> grades[a][4])
    {
        std::cout << names[a] 
            << std::setw(4) << grades[a][0]
            << std::setw(4) << grades[a][1]
            << std::setw(4) << grades[a][2]
            << std::setw(4) << grades[a][3]
            << std::setw(4) << grades[a][4] << std::endl;
            a++;
    }

    inputFile.close();
    return a;
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


}

char ConvertScore(int num_grade[], int a)
{
    char grade;
    //int a;

    if (num_grade[a] <= 100 && num_grade[a] >= 90)
    {
        grade = 'A';
    }

    else if (num_grade[a] <= 89 && num_grade[a] >= 80)
    {
        grade = 'B';
    }

    else if (num_grade[a] <= 79 && num_grade[a] >= 70)
    {
        grade = 'C';
    }

    else if (num_grade[a] <= 69 && num_grade[a] >= 60)
    {
        grade = 'D';
    }

    else if (num_grade[a] < 60)
    {
        grade = 'F';
    }
    return grade;
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
