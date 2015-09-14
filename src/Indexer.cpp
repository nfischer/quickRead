#include <string>
#include <iostream> // necessary for operator << and >>
#include <fstream>
#include <vector>
#include <stdlib.h> // for exit()

#include "Indexer.h"
#include "Text.h"

using namespace std;

Indexer::Indexer()
  : m_Texts()
{ }
Indexer::Indexer(const string loadFile)
{
  // nothing yet
  cout << loadFile << endl;
}

Indexer::~Indexer()
{
  vector<Text*>::iterator p;
  for (p = m_Texts.begin(); p < m_Texts.end(); p++)
  {
    delete *p;
  }
}

Text* Indexer::getNext()
{
  vector<Text*>::iterator p = m_Texts.begin();

  return NULL; // DEBUG
}


void Indexer::add(string title, string path)
{
  // std::vector<Text*> m_Texts;
  string fullText;

  // Open file
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
    cerr << "Unable to open file";
    exit(1); // should exit here?
  }


  // Create new Text object
  Text* t = new Text(title, fullText);

  // Add to index
  m_Texts.push_back(t);
}
