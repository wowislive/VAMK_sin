/***************************************************************************
 *   Copyright (C) 2022 by Dmitrii Pavlov   *
 *   e2101942@vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     sin_template.c

 2.  DESCRIPTION
     A program that will print sin() function
 
 3.  VERSIONS
       Original:
         1.0 / mimr

       Version history:

       1.0 release

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <ncurses.h>
#include <unistd.h>
#include <math.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAX_X 80
#define MAX_Y 40
#define MID_X_AXIS MAX_X / 2 - 1
#define MID_Y_AXIS MAX_Y / 2 - 1
#define X_SCALE MAX_X / (2 * M_PI)
#define Y_SCALE MAX_Y / 2

/* Global variables */

/* Global structures */


/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_axis(void);
int scale_sin(float value);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
  initscr();
  draw_axis();

  for(float x = - M_PI; x <= M_PI; x = x + 0.1){
    int y;
    y = scale_sin(sin(x));
    mvaddch(y + MID_Y_AXIS, x * X_SCALE + MID_X_AXIS, '0');
    usleep(5000);
    refresh();
  }

  getch();
  endwin();
  return 0;
}
/* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: draw_axis
 DESCRIPTION: function that draws x and y axes
	Input: void
	Output: void
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void draw_axis(void){
  for(int i = 0; i < MAX_X; i++){
    mvaddch(MID_Y_AXIS, i, '*');
    usleep(5000);
    refresh();

    if(i == MAX_X - 1)                  //if the last character '*' is printed
      mvaddch(MID_Y_AXIS, i + 1, '>');  //then print '>'
  }
  
  for(int i = 0; i < MAX_Y; i++){
    mvaddch(i,MID_X_AXIS, '*');
    usleep(5000);
    refresh();
  }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: scale_sin
 DESCRIPTION: function that scales the value on the y-axis to the desired size
	Input: float number
	Output: int number
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

int scale_sin(float value){  // as value we accept sin(x)
  value = value * Y_SCALE;
  return value;
}
