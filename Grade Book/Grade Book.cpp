// Grade Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int TESTNUMBER = 5;
int ReadTxt(string file, string names[], int grades[][TESTNUMBER], int a);
void calc_average(int grades[][TESTNUMBER], double avg[], int a);
char ConvertScore(double num_grade[], int a);
void Report(string s_name[], double avg[], int a);

int main()
{
    string stud_name[20];
    double average[20];
    int x = 0;
    int grade_num[20][TESTNUMBER];
    string filename = "StudentGrades.txt";

    //Set 'x' equal to the number of names in the file
    x = ReadTxt(filename, stud_name, grade_num, x); 

    // Calculate the average grade for each student
    // and put the value in the 'average' array
    calc_average(grade_num, average, x);

    // Display the data
    Report(stud_name, average, x);

}

int ReadTxt(string file, string names[20],int grades[20][TESTNUMBER], int a)
{
    ifstream inputFile(file);

    //Ends program if the file cannot be opened
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file";
        exit(EXIT_FAILURE);
    }

    // While the file is opened, fill the values of the name
    // and grades array, and keep track of the number of
    // names/lines in the txt file
    while (inputFile >> names[a] >> grades[a][0] >> grades[a][1] >> 
           grades[a][2] >> grades[a][3] >> grades[a][4])
    {
            a++;
    }

    inputFile.close();
    return a;
}

void calc_average(int grades[][TESTNUMBER], double avg[], int a)
{
    // Initalize value of total to 0
    double total = 0;

    // First for loop is for each student
    for (int z = 0; z <= (a-1); z++)
    {
        //Second for loop is for the grades of each student
        for (int y = 0; y < TESTNUMBER; y++)
        {
            total = grades[z][y] + total;
        }

        avg[z] = total / TESTNUMBER;

        // Resets value of total for each student
        total = 0;
    }


}

char ConvertScore(double num_grade[], int a)
{
    // This function outputs a character value based on a numerical score

    char grade = 'z';

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

    return grade;
}

void Report(string names[], double avg[], int a)
{
    // First Row serves as a title for the table shown
    
    cout << left << setw(10) << "Students"
         << setw(10) << "Averages"
         << setw(8) << "Grades" << endl << endl;
    
    // Diplays the names, average scores, and Letter Grades for each student
    for (int i = 0; i <= (a-1); i++)
    {
        cout << left << setw(10) << names[i]
             << setw(10) << avg[i] 
             << setw(8) << ConvertScore(avg, i) << endl;
    }
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
