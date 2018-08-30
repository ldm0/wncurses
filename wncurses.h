#ifndef __WNCURSES_H
#define __WNCURSES_H

#define SWAPBUFFER_FRONT	0
#define SWAPBUFFER_BACK		1

typedef int						bool;
//coord short
typedef struct	_coord_s_st		COORD_S;
typedef struct	_window_st		WINDOW;

struct _coord_s_st{
	//the underscore means the val is private(cannot be accessed by outside world)
	short _y, _x;
};

struct _window_st{
    //beg coord means the upper left corner 
    //and the _max coord means the lower right corner position
	COORD_S		_cur, _beg, _max, _size;

    //the former is the front buffer
	HANDLE		_swapbuffer[2];

    /* option values set by user */
    struct window_state{
        bool	_notimeout  :1;	/* no time out on function-key entry? */
        bool	_clear      :1;	/* consider all data in the window invalid? */
        bool	_leaveok    :1;	/* OK to not reset cursor on exit? */
        bool	_scroll     :1;	/* OK to scroll this window? */
        bool	_idlok      :1;	/* OK to use insert/delete line? */
        bool	_idcok      :1;	/* OK to use insert/delete char? */
        bool	_sync       :1;	/* window in sync mode? */
        bool	_use_keypad :1;	/* process function keys into KEY_ symbols? */
        //bool	_immed      :1;	/* window in immed mode? (not yet used) */
        int     _delay;	        /* 0 = nodelay, <0 = blocking, >0 = delay */
    }_state;
};

extern	int		COLS;
extern	int		LINES;
extern  WINDOW  *stdscr;

extern  WINDOW*  initscr    (void);

#endif