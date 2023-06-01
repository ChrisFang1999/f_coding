#include "coding.h"

int main()
{

    float a = 123123122.132412;
    string b = to_string(a);
    string c;
    
    cout << to_string(round(a * 100) / 100) << endl;

    return 0;
}