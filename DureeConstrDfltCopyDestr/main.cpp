#include <iostream>
#include <duree.h>

using namespace std;

int main()
{
    NsUtil::Duree d(9000);
    cout << endl;
    delete &d;
    return 0;
}
