/* color.h - Copyright (C) 2016 Aaron Ryan Klingler

   Definitions for printing colors in an ANSI/VT100 terminal
   Use them like so:
   
	printf(TEXT_RED "Whatever You Want" ATTR_RESET);

   or this way:

	printf("%s%s%s", TEXT_RED, "This is a message", ATTR_RESET);
     
*/

#define ATTR_RESET   "\e[0m"
#define ATTR_BOLD    "\e[1m"
#define ATTR_DIM     "\e[2m"
#define ATTR_STAND   "\e[3m"
#define ATTR_UNDR    "\e[4m"
#define ATTR_BLINK   "\e[5m"
#define ATTR_INVERT  "\e[7m"
#define ATTR_INVIS   "\3[8m"

#define TEXT_BLACK   "\e[30m"
#define TEXT_RED     "\e[31m"
#define TEXT_GREEN   "\e[32m"
#define TEXT_ORANGE  "\e[33m"
#define TEXT_BLUE    "\e[34m"
#define TEXT_PURPLE  "\e[35m"
#define TEXT_CYAN    "\e[36m"
#define TEXT_WHITE   "\e[37m"

#define BG_BLACK     "\e[40m"
#define BG_RED       "\e[41m"
#define BG_GREEN     "\e[42m"
#define BG_ORANGE    "\e[43m"
#define BG_BLUE      "\e[44m"
#define BG_PURPLE    "\e[45m"
#define BG_CYAN      "\e[46m"
#define BG_WHITE     "\e[47m"
