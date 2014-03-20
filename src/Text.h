#ifndef TEXT_INCLUDED
#define TEXT_INCLUDED

#include <vector>
#include <string>

class Text
{
  public:
    // constructors
    Text(std::string title, std::string words);

    // accessors
    int bookmark() const
    {
        return m_bookmark;
    }

    std::string title() const
    {
        return m_title;
    }

    int read(int wpm, int startPlace);



  private:
    void printColor(char c);
    void printWord(std::string word, int sleepTime);
    void clearScreen();

    // Member variables
    std::vector<std::string> m_words;
    int m_bookmark;
    std::string m_title;

};




#endif//TEXT_INCLUDED
