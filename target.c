int addch (const chtype);
int addchnstr (const chtype *, int);
int addchstr (const chtype *);	
int addnstr (const char *, int);
int addstr (const char *);
int attroff (NCURSES_ATTR_T);			/* generated */
int attron (NCURSES_ATTR_T);			/* generated */
int attrset (NCURSES_ATTR_T);			/* generated */
int attr_get (attr_t *, NCURSES_PAIRS_T *, void *);	/* generated */
int attr_off (attr_t, void *);			/* generated */
int attr_on (attr_t, void *);			/* generated */
int attr_set (attr_t, NCURSES_PAIRS_T, void *);		/* generated */
int baudrate (void);
int beep  (void);		
int bkgd (chtype);
void bkgdset (chtype);
int border (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
int box (WINDOW *, chtype, chtype);	
bool can_change_color (void);
int cbreak (void);				/* implemented */
int chgat (int, attr_t, NCURSES_PAIRS_T, const void *);	/* generated */
int clear (void);		
int clearok (WINDOW *,bool);
int clrtobot (void);	
int clrtoeol (void);
int color_content (NCURSES_COLOR_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*,NCURSES_COLOR_T*);	/* implemented */
int color_set (NCURSES_PAIRS_T,void*);			/* generated */
int COLOR_PAIR (int);				/* generated */
int copywin (const WINDOW*,WINDOW*,int,int,int,int,int,int,int);	/* implemented */
int curs_set (int);		
int def_prog_mode (void);			/* implemented */
int def_shell_mode (void);			/* implemented */
int delay_output (int);				/* implemented */
int delch (void);				/* generated */
void delscreen (SCREEN *);			/* implemented */
int delwin (WINDOW *);				/* implemented */
int deleteln (void);				/* generated */
WINDOW* derwin (WINDOW *,int,int,int,int);	/* implemented */
int doupdate (void);				/* implemented */
WINDOW* dupwin (WINDOW *);			/* implemented */
int echo (void);					/* implemented */
int echochar (const chtype);			/* generated */
int erase (void);				/* generated */
int endwin (void);				/* implemented */
char erasechar (void);				/* implemented */
void filter (void);				/* implemented */
int flash (void);				/* implemented */
int flushinp (void);				/* implemented */
chtype getbkgd (WINDOW *);			/* generated */
int getch (void);				/* generated */
int getnstr (char *, int);			/* generated */
int getstr (char *);				/* generated */
WINDOW* getwin (FILE *);			/* implemented */
int halfdelay (int);				/* implemented */
bool has_colors (void);				/* implemented */
bool has_ic (void);				/* implemented */
bool has_il (void);				/* implemented */
int hline (chtype, int);				/* generated */
void idcok (WINDOW *, bool);			/* implemented */
int idlok (WINDOW *, bool);			/* implemented */
void immedok (WINDOW *, bool);			/* implemented */
chtype inch (void);				/* generated */
int inchnstr (chtype *, int);			/* generated */
int inchstr (chtype *);				/* generated */
WINDOW* initscr (void);				/* implemented */
int init_color (NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T);	/* implemented */
int init_pair (NCURSES_PAIRS_T,NCURSES_COLOR_T,NCURSES_COLOR_T);		/* implemented */
int innstr (char *, int);			/* generated */
int insch (chtype);				/* generated */
int insdelln (int);				/* generated */
int insertln (void);				/* generated */
int insnstr (const char *, int);			/* generated */
int insstr (const char *);			/* generated */
int instr (char *);				/* generated */
int intrflush (WINDOW *,bool);			/* implemented */
bool isendwin (void);				/* implemented */
bool is_linetouched (WINDOW *,int);		/* implemented */
bool is_wintouched (WINDOW *);			/* implemented */
extern NCURSES_EXPORT(const char *) keyname (int);		/* implemented */
int keypad (WINDOW *,bool);			/* implemented */
char killchar (void);				/* implemented */
int leaveok (WINDOW *,bool);			/* implemented */
char* longname (void);				/* implemented */
int meta (WINDOW *,bool);			/* implemented */
int move (int, int);				/* generated */
int mvaddch (int, int, const chtype);		/* generated */
int mvaddchnstr (int, int, const chtype *, int);	/* generated */
int mvaddchstr (int, int, const chtype *);	/* generated */
int mvaddnstr (int, int, const char *, int);	/* generated */
int mvaddstr (int, int, const char *);		/* generated */
int mvchgat (int, int, int, attr_t, NCURSES_PAIRS_T, const void *);	/* generated */
int mvcur (int,int,int,int);			/* implemented */
int mvdelch (int, int);				/* generated */
int mvderwin (WINDOW *, int, int);		/* implemented */
int mvgetch (int, int);				/* generated */
int mvgetnstr (int, int, char *, int);		/* generated */
int mvgetstr (int, int, char *);			/* generated */
int mvhline (int, int, chtype, int);		/* generated */
chtype mvinch (int, int);			/* generated */
int mvinchnstr (int, int, chtype *, int);	/* generated */
int mvinchstr (int, int, chtype *);		/* generated */
int mvinnstr (int, int, char *, int);		/* generated */
int mvinsch (int, int, chtype);			/* generated */
int mvinsnstr (int, int, const char *, int);	/* generated */
int mvinsstr (int, int, const char *);		/* generated */
int mvinstr (int, int, char *);			/* generated */
int mvprintw (int,int, const char *,...)		/* implemented */
int mvscanw (int,int, const char *,...)	/* implemented */
int mvvline (int, int, chtype, int);		/* generated */
int mvwaddch (WINDOW *, int, int, const chtype);	/* generated */
int mvwaddchnstr (WINDOW *, int, int, const chtype *, int);/* generated */
int mvwaddchstr (WINDOW *, int, int, const chtype *);	/* generated */
int mvwaddnstr (WINDOW *, int, int, const char *, int);	/* generated */
int mvwaddstr (WINDOW *, int, int, const char *);	/* generated */
int mvwchgat (WINDOW *, int, int, int, attr_t, NCURSES_PAIRS_T, const void *);/* generated */
int mvwdelch (WINDOW *, int, int);		/* generated */
int mvwgetch (WINDOW *, int, int);		/* generated */
int mvwgetnstr (WINDOW *, int, int, char *, int);	/* generated */
int mvwgetstr (WINDOW *, int, int, char *);	/* generated */
int mvwhline (WINDOW *, int, int, chtype, int);	/* generated */
int mvwin (WINDOW *,int,int);			/* implemented */
chtype mvwinch (WINDOW *, int, int);			/* generated */
int mvwinchnstr (WINDOW *, int, int, chtype *, int);	/* generated */
int mvwinchstr (WINDOW *, int, int, chtype *);		/* generated */
int mvwinnstr (WINDOW *, int, int, char *, int);		/* generated */
int mvwinsch (WINDOW *, int, int, chtype);		/* generated */
int mvwinsnstr (WINDOW *, int, int, const char *, int);	/* generated */
int mvwinsstr (WINDOW *, int, int, const char *);	/* generated */
int mvwinstr (WINDOW *, int, int, char *);		/* generated */
int mvwprintw (WINDOW*,int,int, const char *,...)	/* implemented */
int mvwscanw (WINDOW *,int,int, const char *,...)	/* implemented */
int mvwvline (WINDOW *,int, int, chtype, int);	/* generated */
int napms (int);					/* implemented */
WINDOW* newpad (int,int);		       	/* implemented */
SCREEN* newterm (const char *,FILE *,FILE *);	/* implemented */
WINDOW* newwin (int,int,int,int);	       	/* implemented */
int nl (void);					/* implemented */
int nocbreak (void);				/* implemented */
int nodelay (WINDOW *,bool);			/* implemented */
int noecho (void);				/* implemented */
int nonl (void);					/* implemented */
void noqiflush (void);				/* implemented */
int noraw (void);				/* implemented */
int notimeout (WINDOW *,bool);			/* implemented */
int overlay (const WINDOW*,WINDOW *);		/* implemented */
int overwrite (const WINDOW*,WINDOW *);		/* implemented */
int pair_content (NCURSES_PAIRS_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*);		/* implemented */
int PAIR_NUMBER (int);				/* generated */
int pechochar (WINDOW *, const chtype);		/* implemented */
int pnoutrefresh (WINDOW*,int,int,int,int,int,int);/* implemented */
int prefresh (WINDOW *,int,int,int,int,int,int);	/* implemented */
int printw (const char *,...)			/* implemented */
int putwin (WINDOW *, FILE *);			/* implemented */
void qiflush (void);				/* implemented */
int raw (void);					/* implemented */
int redrawwin (WINDOW *);			/* generated */
int refresh (void);				/* generated */
int resetty (void);				/* implemented */
int reset_prog_mode (void);			/* implemented */
int reset_shell_mode (void);			/* implemented */
int ripoffline (int, int (*)(WINDOW *, int));	/* implemented */
int savetty (void);				/* implemented */
int scanw (const char *,...)		/* implemented */
int scr_dump (const char *);			/* implemented */
int scr_init (const char *);			/* implemented */
int scrl (int);					/* generated */
int scroll (WINDOW *);				/* generated */
int scrollok (WINDOW *,bool);			/* implemented */
int scr_restore (const char *);			/* implemented */
int scr_set (const char *);			/* implemented */
int setscrreg (int,int);				/* generated */
SCREEN* set_term (SCREEN *);			/* implemented */
int slk_attroff (const chtype);			/* implemented */
int slk_attr_off (const attr_t, void *);		/* generated:WIDEC */
int slk_attron (const chtype);			/* implemented */
int slk_attr_on (attr_t,void*);			/* generated:WIDEC */
int slk_attrset (const chtype);			/* implemented */
extern NCURSES_EXPORT(attr_t) slk_attr (void);				/* implemented */
int slk_attr_set (const attr_t,NCURSES_PAIRS_T,void*);	/* implemented */
int slk_clear (void);				/* implemented */
int slk_color (NCURSES_PAIRS_T);				/* implemented */
int slk_init (int);				/* implemented */
char* slk_label (int);				/* implemented */
int slk_noutrefresh (void);			/* implemented */
int slk_refresh (void);				/* implemented */
int slk_restore (void);				/* implemented */
int slk_set (int,const char *,int);		/* implemented */
int slk_touch (void);	      	       		/* implemented */
int standout (void);				/* generated */
int standend (void);				/* generated */
int start_color (void);				/* implemented */
WINDOW* subpad (WINDOW *, int, int, int, int);	/* implemented */
WINDOW* subwin (WINDOW *, int, int, int, int);	/* implemented */
int syncok (WINDOW *, bool);			/* implemented */
chtype termattrs (void);				/* implemented */
char* termname (void);				/* implemented */
void timeout (int);				/* generated */
int touchline (WINDOW *, int, int);		/* generated */
int touchwin (WINDOW *);				/* generated */
int typeahead (int);				/* implemented */
int ungetch (int);				/* implemented */
int untouchwin (WINDOW *);			/* generated */
void use_env (bool);				/* implemented */
void use_tioctl (bool);				/* implemented */
int vidattr (chtype);				/* implemented */
int vidputs (chtype, NCURSES_OUTC);		/* implemented */
int vline (chtype, int);				/* generated */
int vwprintw (WINDOW *, const char *,va_list);	/* implemented */
int vw_printw (WINDOW *, const char *,va_list);	/* generated */
int vwscanw (WINDOW *, const char *,va_list);	/* implemented */
int vw_scanw (WINDOW *, const char *,va_list);	/* generated */
int waddch (WINDOW *, const chtype);		/* implemented */
int waddchnstr (WINDOW *,const chtype *,int);	/* implemented */
int waddchstr (WINDOW *,const chtype *);		/* generated */
int waddnstr (WINDOW *,const char *,int);	/* implemented */
int waddstr (WINDOW *,const char *);		/* generated */
int wattron (WINDOW *, int);			/* generated */
int wattroff (WINDOW *, int);			/* generated */
int wattrset (WINDOW *, int);			/* generated */
int wattr_get (WINDOW *, attr_t *, NCURSES_PAIRS_T *, void *);	/* generated */
int wattr_on (WINDOW *, attr_t, void *);		/* implemented */
int wattr_off (WINDOW *, attr_t, void *);	/* implemented */
int wattr_set (WINDOW *, attr_t, NCURSES_PAIRS_T, void *);	/* generated */
int wbkgd (WINDOW *, chtype);			/* implemented */
void wbkgdset (WINDOW *,chtype);			/* implemented */
int wborder (WINDOW *,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);	/* implemented */
int wchgat (WINDOW *, int, attr_t, NCURSES_PAIRS_T, const void *);/* implemented */
int wclear (WINDOW *);				/* implemented */
int wclrtobot (WINDOW *);			/* implemented */
int wclrtoeol (WINDOW *);			/* implemented */
int wcolor_set (WINDOW*,NCURSES_PAIRS_T,void*);		/* implemented */
void wcursyncup (WINDOW *);			/* implemented */
int wdelch (WINDOW *);				/* implemented */
int wdeleteln (WINDOW *);			/* generated */
int wechochar (WINDOW *, const chtype);		/* implemented */
int werase (WINDOW *);				/* implemented */
int wgetch (WINDOW *);				/* implemented */
int wgetnstr (WINDOW *,char *,int);		/* implemented */
int wgetstr (WINDOW *, char *);			/* generated */
int whline (WINDOW *, chtype, int);		/* implemented */
chtype winch (WINDOW *);				/* implemented */
int winchnstr (WINDOW *, chtype *, int);		/* implemented */
int winchstr (WINDOW *, chtype *);		/* generated */
int winnstr (WINDOW *, char *, int);		/* implemented */
int winsch (WINDOW *, chtype);			/* implemented */
int winsdelln (WINDOW *,int);			/* implemented */
int winsertln (WINDOW *);			/* generated */
int winsnstr (WINDOW *, const char *,int);	/* implemented */
int winsstr (WINDOW *, const char *);		/* generated */
int winstr (WINDOW *, char *);			/* generated */
int wmove (WINDOW *,int,int);			/* implemented */
int wnoutrefresh (WINDOW *);			/* implemented */
int wprintw (WINDOW *, const char *,...)		/* implemented */
int wredrawln (WINDOW *,int,int);		/* implemented */
int wrefresh (WINDOW *);				/* implemented */
int wscanw (WINDOW *, const char *,...)	/* implemented */
int wscrl (WINDOW *,int);			/* implemented */
int wsetscrreg (WINDOW *,int,int);		/* implemented */
int wstandout (WINDOW *);			/* generated */
int wstandend (WINDOW *);			/* generated */
void wsyncdown (WINDOW *);			/* implemented */
void wsyncup (WINDOW *);				/* implemented */
void wtimeout (WINDOW *,int);			/* implemented */
int wtouchln (WINDOW *,int,int,int);		/* implemented */
int wvline (WINDOW *,chtype,int);		/* implemented */
int tigetflag (const char *);		/* implemented */
int tigetnum (const char *);		/* implemented */
char* tigetstr (const char *);		/* implemented */
int putp (const char *);				/* implemented */
char* tparm (const char *, ...);	/* special */
char* tparm (const char *, NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG,NCURSES_TPARM_ARG);	/* special */
char* tparm_varargs (const char *, ...);	/* special */
char* tiparm (const char *, ...);		/* special */
int getattrs (const WINDOW *);			/* generated */
int getcurx (const WINDOW *);			/* generated */
int getcury (const WINDOW *);			/* generated */
int getbegx (const WINDOW *);			/* generated */
int getbegy (const WINDOW *);			/* generated */
int getmaxx (const WINDOW *);			/* generated */
int getmaxy (const WINDOW *);			/* generated */
int getparx (const WINDOW *);			/* generated */
int getpary (const WINDOW *);			/* generated */
typedef int (*NCURSES_WINDOW_CB)(WINDOW *, void *);
typedef int (*NCURSES_SCREEN_CB)(SCREEN *, void *);
bool is_term_resized (int, int);
char* keybound (int, int);
extern NCURSES_EXPORT(const char *) curses_version (void);
int assume_default_colors (int, int);
int define_key (const char *, int);
int get_escdelay (void);
int key_defined (const char *);
int keyok (int, bool);
int resize_term (int, int);
int resizeterm (int, int);
int set_escdelay (int);
int set_tabsize (int);
int use_default_colors (void);
int use_extended_names (bool);
int use_legacy_coding (int);
int use_screen (SCREEN *, NCURSES_SCREEN_CB, void *);
int use_window (WINDOW *, NCURSES_WINDOW_CB, void *);
int wresize (WINDOW *, int, int);
void nofilter(void);
WINDOW* wgetparent (const WINDOW *);	/* generated */
bool is_cleared (const WINDOW *);	/* generated */
bool is_idcok (const WINDOW *);		/* generated */
bool is_idlok (const WINDOW *);		/* generated */
bool is_immedok (const WINDOW *);	/* generated */
bool is_keypad (const WINDOW *);		/* generated */
bool is_leaveok (const WINDOW *);	/* generated */
bool is_nodelay (const WINDOW *);	/* generated */
bool is_notimeout (const WINDOW *);	/* generated */
bool is_pad (const WINDOW *);		/* generated */
bool is_scrollok (const WINDOW *);	/* generated */
bool is_subwin (const WINDOW *);		/* generated */
bool is_syncok (const WINDOW *);		/* generated */
int wgetdelay (const WINDOW *);		/* generated */
int wgetscrreg (const WINDOW *, int *, int *); /* generated */
