
//state needed:
// the background char (!!!please reference the test_bkgdset test file)
// is cbreak
// is raw
// the

//------------------------output functions----------------------------
//general attentions
/*
 * 1. after the \n was added, the cells after line was changed into the background char 
 */

int addch(const chtype);
int addchnstr(const chtype *, int);
int addchstr(const chtype *);
int addnstr(const char *, int);
int addstr(const char *);
int border(chtype, chtype, chtype, chtype, chtype, chtype, chtype, chtype);
int box(WINDOW *, chtype, chtype);
/*
 * The routine chgat changes the attributes of 
 * a given number of characters starting at the current cursor location of stdscr.
 * It does not update the cursor and does not perform wrapping. 
 * A character count of -1 or greater than the remaining window width means to 
 * change attributes all the way to the end of the current line. 
 */
int chgat(int, attr_t, NCURSES_PAIRS_T, const void *); /* generated */
/* 
 * linux man page says copy blanks but the test in ncurses shows
 * the program actually copys the background member if the window struct
 */
int erase(void);

//the clear calls the erase and calls the clearok too
int clear(void);
int clearok(WINDOW *, bool);
//also copys the background to fill the
int clrtobot(void);
int clrtoeol(void);

//--------------------------change output state funtions----------------------

// the void * is must null and the details have not been tested
int color_set(NCURSES_PAIRS_T, void *);            /* generated */
int attroff(NCURSES_ATTR_T);                       /* generated */
int attron(NCURSES_ATTR_T);                        /* generated */
int attrset(NCURSES_ATTR_T);                       /* generated */
int attr_get(attr_t *, NCURSES_PAIRS_T *, void *); /* generated */
int attr_off(attr_t, void *);                      /* generated */
int attr_on(attr_t, void *);                       /* generated */
int attr_set(attr_t, NCURSES_PAIRS_T, void *);     /* generated */
// pass the normal char input instantly
int cbreak(void);
int nocbreak(void);
// pass all the input to the program
int raw(void);
int noraw(void);
/*
 * change every cell has the same char inputed in the window 
 */
int bkgd(chtype);
/*
 * change the bckground state in window struct
 */
void bkgdset(chtype);

//---------------------------output the state--------------------------------

#define baudrate() (0)
int beep(void);
bool can_change_color(void);

//---------------------------private functions----------------------------------

int _waddch(const chtype); //purelly addch
