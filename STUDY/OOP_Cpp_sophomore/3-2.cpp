#include <iostream>
#include <iomanip>

using namespace std;

class twodim
{
public:
    void get_twodim(int row, int col);
    float &val(int i, int j);
    void free_twodim();
private:
    int r;
    int c;
    float *a;
};

void twodim::get_twodim(int row, int col)
{
    r = row;
    c = col;
    a = new float[row * col];
}
float &twodim::val(int i, int j)
{
    return a[i * c + j];
}
void twodim::free_twodim()
{
    delete []a;
}

int main()
{
    struct twodim s;
    int i, j;
    s.get_twodim(3, 4);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            s.val(i, j) = 5;

    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 4; j++)
            cout << setw(5) << s.val(i, j);

        cout << endl;
    }
    s.free_twodim();
}