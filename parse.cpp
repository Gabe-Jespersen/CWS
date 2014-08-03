// parse.cpp

#include <vector>
#include <cstring>

using namespace std;

vector<int> parse(int argc, char **argv)
{
    //setting defaults, might be changed by flags
        int defaultWork = 0;

    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if(!strcmp(argv[i], "-D"))
            {
                defaultWork = 1;
            }
        }
    }
    vector<int> toreturn = {defaultWork};
    return toreturn;
}
