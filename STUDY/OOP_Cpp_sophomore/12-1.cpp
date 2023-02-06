#include <iostream>
#include <fstream>

using namespace std;

class File
{
private:
    string filename;

public:
    File(string s) { filename = s; }
    double readfile();
};
double File::readfile()
{
    ifstream f;
    f.open(filename);
    double Average = 0, Score, Count = 0;
    while (!f.eof())
    {
        f >> Score;
        Average += Score;
        ++Count;
    }
    Average /= Count;
    f.close();
    return Average;
}

int main(void)
{
    File t("12-1.txt");
    cout << t.readfile();
    return 0;
}