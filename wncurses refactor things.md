### Start refactoring the code.
When I started to implement the ncurses function, I did't realize that the states feature like immedok() will influence so many functions.
The code is so duplicate that when I want to add a state feature, I need to change a lot of functions, which is annoying.
Which even more annoying is that the more functions I implement, the more changes should I make, and its very easy to miss one or more functions.

Another thing is I stupidly use one ncurses function to implement another ncurses function, which is fine when I didnot implement the immedok() function.
For example, the waddnstr() function.
Firstly I use multiple waddch() function to implement it.
But after the immedok state implemented, (which means after do something to the virtual screen, the actual screen immediatly syncs)
the screen changes every char is printed.
Things like that is more than a dozen.

What kond of results do I want?
I decided to implement some basic and pure(no annoying state) I/O functions and use the functions to implement the ncurses functions.
And will never use one ncurses function to implement another ncurses funtion.

I want to be a outstanding coder though I am a noob currently. :)
