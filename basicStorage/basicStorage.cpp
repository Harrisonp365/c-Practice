//The project will build, in order for it to work you need to change"filename" with a current file name. This will delete the original file so ensure you are happy for it to delete or create a new file

/*#include <iostream>
#include <fstream>


int main()
{
    char filename[MAX_PATH + 1];

    std::cout << "Enter a file name and press enter: " << std::endl;
    cin.getline(filename, _MAX_PATH);
    ofstream file_out(filename);

    if (!file_out)
    {
        std::cout << filename << " cout not be opened" << std::endl;

        return -1;
    }

    std::cout << filename << " was opened." << std::endl;
    file_out << "I read my" << std::endl;
    file_out << "first c++ book" << std::endl;
    file_out.close();

    return 0;
}*/

//--------------------------------------------------------
//Random Access Write to binary file
#include <iostream>
#include <fstream>
using namespace std;

int getInt(int defaultValue);

int main()
{
    char filename[_MAX_PATH + 1];
    int n = 0;
    char name[20];
    int age = 0;
    int recsize = sizeof(name) + sizeof(int);

    std::cout << "Enter a file name and press enter: " << std::endl;
    cin.getline(filename, _MAX_PATH);
    
    //Open File for binary write.
    fstream fbin(filename, ios::binary | ios::out);
    if (!fbin)
    {
        cout << "Could not open " << filename << endl;
        return -1;
    }

    //Get record number to write to
    cout << "Enter file record number: ";
    n = getInt(0);

    cout << "Enter name: ";
    cin.getline(name, sizeof(name) - 1);
    cout << "Enter age: ";
    age = getInt(0);

    //Write data to file
    fbin.seekp(n * recsize);
    fbin.write(name, sizeof(name) - 1);
    fbin.write((char*)(&age), sizeof(int));
    fbin.close();
    return 0;
}

#define COL_WIDTH 80 

int getInt(int defaultValue)
{
    char s[COL_WIDTH + 1];
    cin.getline(s, COL_WIDTH);

    if (strlen(s) == 0)
        return defaultValue;
    return atoi(s);
}