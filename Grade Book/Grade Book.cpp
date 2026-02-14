// Grade Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string ReadTxt(string file);

int main()
{
    string filename = "StudentGrades.txt";
    ReadTxt(filename);

}

string ReadTxt(string file)
{
    std::ifstream inputFile("StudentGrades.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error: OCuld not open the file";
        return "";
    }

    //std::string name[20];
    std::string name;
    int average[20];
    int x = 0;
    std::string grade1, grade2, grade3, grade4, grade5;

    while (inputFile >> name >> grade1 >> grade2 >> grade3 >> grade4 >> grade5)
    {
        std::cout << name << std::setw(4) << grade1
            << std::setw(4) << grade2
            << std::setw(4) << grade3
            << std::setw(4) << grade4
            << std::setw(4) << grade5 << std::endl;
    }

    inputFile.close();
    //return 0;
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
