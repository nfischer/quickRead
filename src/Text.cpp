#include <iostream>
#include <unistd.h> // for sleep()
#include <time.h> // for nanosleep()
#include "Text.h"

using namespace std;

Text::Text(string title, string words)
{
    m_title = title;

    cout << "Reading in your text..." << endl;

    // Read through to count number of spaces ( = number of words)
    int numSpaces = 0;
    for (unsigned int k=0; k < words.size(); k++)
    {
        if (words[k] == ' ')
            numSpaces++;
    }

    m_words.reserve(numSpaces); // so we don't have to reallocate

    int wordNum=0;
    m_words.push_back(""); // ensures size is appropriate
    int inputStringSize = words.size();

    //cout << "size is " << m_words.size() << endl;
    //cout << "capacity is " << m_words.capacity() << endl;


    for (unsigned int k=0; k < inputStringSize; k++)
    {
        if (words[k] == ' ' && m_words[wordNum].size() == 0)
            continue; // don't add blank words

        else if (words[k] != ' ')
        {
            m_words[wordNum] += words[k];
        }
        else
        {
            wordNum++;
            m_words.push_back(""); // increases size of vector
        }
    }

    cout << "Your text has been added successfully." << endl;
}


void Text::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void Text::printColor(char c)
{
   cout << "\033[1;31m" << c << "\033[0m";
}

void Text::printWord(string word)
{
    const int INDENT = 6;
    const int BOXSIZE = 16;
    clearScreen();

    // get to center of screen
    for (int k=0; k < 6; k++) // move down
        cout << endl;

    for (int k=0; k < INDENT; k++) // move right
        cout << ' ';

    //////////////////////////////////
    // print first half of box
    //////////////////////////////////

    for (int k=0; k < INDENT+BOXSIZE; k++)
        cout << '*';
    cout << endl;

    // start the line
    for (int k=0; k < INDENT; k++) // move right
        cout << ' ';

    cout << "* ";

    // calculate center of word
    int focalPoint = word.size()/2; // good enough for now

    // printChars
    for (int k=0; k < word.size(); k++)
    {
        if (k == focalPoint)
            printColor(word[k]);
        else
            cout << word[k];
    }


    //////////////////////////////////
    // print second half of box
    //////////////////////////////////

    // complete the line
    for (int k=0; k < BOXSIZE - (signed)word.size(); k++) // shift right
        cout << ' ';
    cout << " *";
    cout << endl;

    for (int k=0; k < INDENT; k++) // move right
        cout << ' ';

    // print 1st half of box
    for (int k=0; k < INDENT+BOXSIZE; k++)
        cout << '*';
    cout << endl;
}


int Text::read(int wpm, int startPlace)
{
    double sleepCount = 60.0/wpm; // in seconds

    // clear the screen
    clearScreen();

    cout << "You will soon be reading " << m_title << endl;


    sleepCount *= 1000000000; // in nanoseconds
    timespec req;
    req.tv_sec = 0;
    req.tv_nsec = sleepCount; // in nanoseconds


    int totalWords = m_words.size();
    startPlace = startPlace - 20;
    if ( startPlace < 0)
        startPlace = 0;

    for (m_bookmark=startPlace; m_bookmark < totalWords; m_bookmark++)
    {
        printWord(m_words[m_bookmark]);
        nanosleep(&req, NULL); // sleep for fraction of a second
    }


    return 0;
}
