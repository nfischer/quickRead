#include <iostream>
#include <fstream>

#include "Indexer.h"
#include "Text.h" // perhaps remove in the future

using namespace std;

int main()
{
    string fullText;
    string line;
    ifstream myfile ("../TellTaleHeart.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            fullText += line;
        }

        myfile.close();
        //cout << fullText << endl;
    }

    else
    {
        cout << "Unable to open file"; 
        // should exit here?
    }


    Text t1("Test file", fullText);

    t1.read(250, 0);



    return 0;
}
