// parse.cpp

#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<long long int> parse(int argc, char **argv)
{
    //setting defaults, might be changed by flags
        int defaultWork = 0;
        int random = 0;

    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if     (!strcmp(argv[i], "-h")) //checkinng for help
            {
                cout << "\nOptions:\n" <<
                        "\t-h:     This menu\n" <<
                        "\t-d:     Defaults work to 3 (normal)\n\n";
                exit(0);
            }
            else if(!strcmp(argv[i], "-d")) //checking if work is set to default to 3 (normal)
            {
                defaultWork = 1;
            }
            else if(!strcmp(argv[i], "-r")) //deciding if beginning is random
            {
                random = 1;
            }
            else
            {
                cout << "\nOptions:\n" <<
                        "\t-h:     This menu\n\n" <<
                        "\t-r:     Random base stats\n" <<
                        "\t-d:     Defaults work to 3 (normal)\n\n";
                exit(0);
            }
        }
    }
    vector<long long int> toreturn = {defaultWork, random};
    return toreturn;
}
