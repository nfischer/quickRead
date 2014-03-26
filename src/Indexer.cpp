#include <string>
#include <iostream> // temp
#include <vector>

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
    vector<Text*>::iterator p = m_Texts.begin();

    return NULL; // DEBUG
}


void Indexer::add(Text* t)
{
    // std::vector<Text*> m_Texts;
    m_Texts.push_back(t);
}
