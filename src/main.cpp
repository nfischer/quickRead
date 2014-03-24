#include <iostream>
#include <fstream>

#include "Indexer.h"
#include "Text.h" // perhaps remove in the future

const int MY_WPM = 100;

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

    ifstream otherfile ("../Finnegans_Wake.txt");
    if (otherfile.is_open())
    {
        while ( getline (otherfile,line) )
        {
            fullText += line;
        }

        otherfile.close();
        //cout << fullText << endl;
    }

    else
    {
        cout << "Unable to open file"; 
        // should exit here?
    }
    Text t2("Finnegans Wake", fullText);

    t1.read(MY_WPM, 0);



    return 0;
}
