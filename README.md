quickRead
=========

A console-based Spritz imitation.

Installation
------------

Unfortunately, this program is only compatible under Cygwin to my
knowledge. It uses a header called <windows.h>, which is only available on
Windows machines. It also uses the nanosleep function, which I believe is
not available except through some unix-like system. Therefore, only some
sort of combination of Windows and unix (ex. Cygwin) will be compatible.

How it works
------------

This app is a console-based spritz imitation. You can check out a spritz
demo by following the link here:

http://www.spritzinc.com/

The basic idea is to flash one word at a time in the same place, allowing
your eyes to move less and therefore read faster. The focal point for the
word is highlighted in red--this is the point in the word your eyes must
focus on to recognize the word. After a set amount of time, the word
changes to the next word in the sentence.

Much like in spritz, the reading speed of the app is adjustable (press i or
d to increase or decrease the speed) and the app will tell you what the
current WPM is.
