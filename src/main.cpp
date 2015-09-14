#include <iostream>
#include <fstream>

#include "Indexer.h"
#include "Text.h" // perhaps remove in the future

const int MY_WPM = 200;

using namespace std;

int main()
{
  // create index
  Indexer index;

  ///////////////////////////////
  // Add first file
  ///////////////////////////////

  string fullText;
  string line;
  ifstream myfile ("../TellTaleHeart.txt");
  if (myfile.is_open())
  {
    while (getline(myfile,line) )
    {
      fullText += (line + '\n');
    }

    myfile.close();
  }

  else
  {
    cout << "Unable to open file";
    // should exit here?
  }


  Text t1("Test file", fullText);


  ///////////////////////////////
  // Add second file
  ///////////////////////////////

  //ifstream otherfile ("../Finnegans_Wake.txt");
  //if (otherfile.is_open())
  //{
  //    while ( getline (otherfile,line) )
  //    {
  //      fullText += line;
  //    }
  //    otherfile.close();
  //    //cout << fullText << endl;
  //}

  //else
  //{
  //    cout << "Unable to open file";
  //    // should exit here?
  //}
  //Text t2("Finnegans Wake", fullText);


  index.add("Finnegans Wake","../Finnegans_Wake.txt");


  t1.read(MY_WPM, 0);



  return 0;
}
