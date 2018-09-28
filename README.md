# wncurses
![progress](http://progressed.io/bar/40?title=progress) ![build](https://img.shields.io/badge/build-passing-brightgreen.svg) ![license](https://img.shields.io/badge/license-WTFPL-brightgreen.svg)

NCURSES in MS cmd.

### Functions implemented(132/330)

Recently found that the ncurses is really convient for building beautiful programs in the form of command line.

However there is no a windows version. What I found now is only a uncomplete version: <http://github.com/justinmeza/wincurses>

If this is built up, It will be fairly easy to transfer some linux applications to the windows console application.

So I decided to build it(hopeully don't mess up). (18/8/23)

The problems are way more than I thought. (18/9/11)

(Complain)The Windows console only provides 3 bits to constrol the color, which means there are only 8 colors.

Currently refactoring(18/9/23)

###TO DO LIST
- [x] scanw
- [x] keypad
- [x] intrflush
- [x] leaveok
