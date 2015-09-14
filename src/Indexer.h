#ifndef INDEXER_INCLUDED
#define INDEXER_INCLUDED

#include <string>
#include <vector>

class Text;

class Indexer
{
  public:
  // Constructors
  Indexer();
  Indexer(const std::string loadFile);

  // Destructor
  ~Indexer();

  // Functions
  Text* getNext();
  void add(std::string title, std::string path);
  private:
  std::vector<Text*> m_Texts;
};

#endif//INDEXER_INCLUDED
