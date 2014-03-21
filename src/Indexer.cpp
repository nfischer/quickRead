#include <string>
#include <iostream> // temp

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

Text* Indexer::getNext()
{
    return NULL; // DEBUG
}
