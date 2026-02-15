// Grade Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int TESTNUMBER = 5;
int ReadTxt(string file, string names[], int grades[][TESTNUMBER], int a);
void calc_average(int grades[][TESTNUMBER], double avg[], int b);
char ConvertScore(double num_grade[], int a);
void Report(string s_name[], double aver[], int c);

int main()
{
    string stud_name[20];
    double average[20];
    int x = 0;
    int grade_num[20][TESTNUMBER];
    string filename = "StudentGrades.txt";

    x = ReadTxt(filename, stud_name, grade_num, x); 

    //cout << x << endl;

    calc_average(grade_num, average, x);

    Report(stud_name, average, x);

    /*for (int i = 0; i <= (x - 1); i++)
    {
        ConvertScore(average, i);
    }*/
    
    //cout << setw(10) << stud_name[0] << setw(5) << average[0] << setw(3) << ConvertScore(average, 0) << endl;

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
        /*std::cout << names[a]
            << std::setw(4) << grades[a][0]
            << std::setw(4) << grades[a][1]
            << std::setw(4) << grades[a][2]
            << std::setw(4) << grades[a][3]
            << std::setw(4) << grades[a][4] << std::endl;*/
            a++;
    }

    inputFile.close();
    return a;
}

void calc_average(int grades[][TESTNUMBER], double avg[], int b)
{
    double total = 0;
    //int average[20];

    for (int z = 0; z <= (b-1); z++)
    {
        for (int y = 0; y < TESTNUMBER; y++)
        {
            total = grades[z][y] + total;
        }

        avg[z] = total / TESTNUMBER;

        //cout << avg[z] << endl;
        //cout << total << endl;
        total = 0;
    }


}

char ConvertScore(double num_grade[], int a)
{
    char grade = 'z';
    //cout << "Code didn't stop" << endl;
    //int a;
        if (num_grade[a] <= 100 && num_grade[a] >= 90)
        {
            grade = 'A';
        }

        else if (num_grade[a] < 90 && num_grade[a] >= 80)
        {
            grade = 'B';
        }

        else if (num_grade[a] < 80 && num_grade[a] >= 70)
        {
            grade = 'C';
        }

        else if (num_grade[a] < 70 && num_grade[a] >= 60)
        {
            grade = 'D';
        }

        else if (num_grade[a] < 60)
        {
            grade = 'F';
        }
    //cout << grade << endl;
    return grade;
}

void Report(string s_name[], double aver[], int c)
{
    for (int i = 0; i <= (c-1); i++)
    {
        cout << left << setw(10) << s_name[i] 
             << setw(5) << aver[i] 
             << setw(3) << ConvertScore(aver, i) << endl;
    }
}

/*void Report()
{
    string names = 
}*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
