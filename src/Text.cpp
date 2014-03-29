#include <iostream>
#include <unistd.h> // for sleep()
#include <time.h> // for nanosleep()
//#include <conio.h> // for getch()
#include <windows.h>

#include "Text.h"

const char BREAK_KEY    = 0x71; // == q
const char INCR_SPD_KEY = 0x69; // == i
const char DECR_SPD_KEY = 0x64; // == d
const char KEY_OFFSET   = 0x20;

using namespace std;

Text::Text(string title, string words)
{
    m_title = title;

    cout << "Reading in your text..." << endl;

    // Read through to count number of spaces ( = number of words)
    int totalNumWords = 0;
    for (unsigned int k=0; k < words.size(); k++)
    {
        if (isWordBreak(words[k]) )
            totalNumWords++;
    }

    m_words.reserve(totalNumWords); // so we don't have to reallocate

    // start adding words
    int wordNum=0;
    m_words.push_back(""); // ensures size is appropriate
    int inputStringSize = words.size();

    for (unsigned int k=0; k < inputStringSize; k++)
    {
        if (isWordBreak(words[k]) && m_words[wordNum].size() == 0)
            continue; // don't add blank words

        else if (! isWordBreak(words[k]) )
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

    //// DEBUG
    //cout << "You first few words are:" << endl;
    //for (int k=0; k < 6; k++)
    //    cout << m_words[k] << endl;

    //char waiter;
    //cout << "Waiting: ";
    //cin >> waiter;
}


void Text::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void Text::printColor(char c)
{
   cout << "\033[1;31m" << c << "\033[0m";
}

void Text::printWord(string word, int yourWpm)
{
    const int CENTER = 26;
    const int SHIFTWIDTH = 46;
    clearScreen();

    // get to center of screen
    for (int k=0; k < 6; k++) // move down
        cout << endl;

    //////////////////////////////////
    // print top arrow
    //////////////////////////////////

    shiftRight(CENTER);
    cout << 'v' << endl; // arrow


    // calculate center of word
    int focalPoint;
    if (word.size() < 4)
        focalPoint = word.size()/2;
    else
        focalPoint = (int)(word.size()/2) - 1;


    // printChars
    shiftRight(CENTER - focalPoint);
    for (int k=0; k < word.size(); k++)
    {
        if (k == focalPoint)
            printColor(word[k]);
        else
            cout << word[k];
    }
    cout << endl;


    //////////////////////////////////
    // print bottom arrow
    //////////////////////////////////

    shiftRight(CENTER);
    cout << '^' << endl;


    //////////////////////////////////
    // print your wpm & keypress info
    //////////////////////////////////

    cout << "\n\n\n";

    shiftRight(SHIFTWIDTH);
    cout << "Your WPM: " << yourWpm << endl;

    cout << endl; // add extra spacing

    shiftRight(SHIFTWIDTH);
    cout << "Press " << BREAK_KEY << " to quit" << endl;

    shiftRight(SHIFTWIDTH);
    cout << "Press " << INCR_SPD_KEY << " to increase WPM by 10" << endl;

    shiftRight(SHIFTWIDTH);
    cout << "Press " << DECR_SPD_KEY << " to decrease WPM by 10" << endl;
    
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

    //////////////////////////////////
    // loop over each word
    //////////////////////////////////

    for (m_bookmark=startPlace; m_bookmark < totalWords; m_bookmark++)
    {
        printWord(m_words[m_bookmark], wpm);
        nanosleep(&req, NULL); // sleep for fraction of a second


        //////////////////////////////////
        // Respond to key presses
        //////////////////////////////////

        if (GetAsyncKeyState(BREAK_KEY-KEY_OFFSET) & 0x8000)
            break;
        if (GetAsyncKeyState(INCR_SPD_KEY-KEY_OFFSET) & 0x8000)
        {
            wpm += 10;
            
            // update sleepCount
            sleepCount = 60.0/wpm * 1000000000; // in nanoseconds
            req.tv_nsec = sleepCount;
        }
        if (GetAsyncKeyState(DECR_SPD_KEY-KEY_OFFSET) & 0x8000)
        {
            wpm -= 10;
            if (wpm <= 0)
            {
                wpm = 1; // minimum allowed value
            }

            // update sleepCount
            sleepCount = 60.0/wpm * 1000000000; // in nanoseconds
            req.tv_nsec = sleepCount;
        }

    }


    return 0;
}
