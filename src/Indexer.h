#ifndef INDEXER_INCLUDED
#define INDEXER_INCLUDED

#include <string>
#include <vector>

class Text;

class Indexer
{
  public:
    // Constructors
    Indexer(); // default
    Indexer(const std::string loadFile);

    Text* getNext();
    void add(Text* t);

  private:
    std::vector<Text*> m_Texts;

};

#endif//INDEXER_INCLUDED
