#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void write()
{
    ofstream myStream("file_path.txt");
    if (!myStream.is_open())
        return;
    myStream << "Bruhhh" << endl;
    myStream.close();
}

void read()
{
    string lineOfFile;
    ifstream myStream("file_path.txt");
    if (!myStream.is_open())
        return;
    while (getline(myStream, lineOfFile))
        cout << lineOfFile << endl;
    myStream.close();
}
