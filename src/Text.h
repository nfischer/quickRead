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
    // helper functions
    void printColor(char c);
    void printWord(std::string word, int yourWpm);
    void clearScreen();
    void shiftRight(int indent)
    {
        for (int k=0; k < indent; k++) // move right
            std::cout << ' ';
    }

    bool isWordBreak(char c) // inlined
    {
        return c == ' ' || c == '\n' || c == '\t';
    }

    // Member variables
    std::vector<std::string> m_words;
    int m_bookmark;
    std::string m_title;

};




#endif//TEXT_INCLUDED
