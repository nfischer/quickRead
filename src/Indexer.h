#ifndef INDEXER_INCLUDED
#define INDEXER_INCLUDED

#include <string>
#include <set>

class Text;

class Indexer
{
  public:
    // Constructors
    Indexer(); // default
    Indexer(const std::string loadFile);

    Text* getNext();

  private:
    std::set<Text*> m_Texts;

};

#endif//INDEXER_INCLUDED
