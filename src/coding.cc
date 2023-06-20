#include "coding.h"

int main()
{
    string a = "asd,wdwd,,,,zxczxc,asdasd";
    vector<string> vec_str;
    boost::algorithm::split(vec_str,a,boost::algorithm::is_any_of(","));
    for (string str:vec_str)
    {
        cout<<str<<endl;
    }
    

    return 0;
}