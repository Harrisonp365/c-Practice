#include "Token_stream.h"
#include "std_lib_facilities.h"
#include "Methods.h"

using namespace std;

int main()
{
    try
    {
        calculate();
        return 0;
    }

    catch (exception& e)
    {
        cerr << e.what() << "\n";
        return 1;
    }

    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}
