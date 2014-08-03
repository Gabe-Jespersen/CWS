// parse.cpp

#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<int> parse(int argc, char **argv)
{
    //setting defaults, might be changed by flags
        int defaultWork = 0;

    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if((!strcmp(argv[i], "-h")) || (!strcmp(argv[i], "-H")) || (!strcmp(argv[i], "help")))
            {
                cout << "\nOptions:\n" <<
                        "\t-h:     This menu\n" <<
                        "\t-d:     Defaults work to 3 (normal)\n\n";
                exit(0);
            }
            if(!strcmp(argv[i], "-d")) //checking if work is set to default to 3 (normal)
            {
                defaultWork = 1;
            }
        }
    }
    vector<int> toreturn = {defaultWork};
    return toreturn;
}
