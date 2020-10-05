////////////////////////////////////////
// OPTIX 2
// Author: epsilon5
// License: NA
// Description: testing ground for OPTIX
////////////////////////////////////////

#include "optix.h"

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Other available headers: stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h */

/* uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */
void testMenu(void) {
    //x is 40 to 280
    //y is 60 to 180
    //we don't need this, it's already done
    //the new menu stuff will do it all for us
    struct optix_menu_t *m = &optix_menu[optix_guidata.currmenu];
    const char *entries = "Transmission`Resistance`Civil Unrest`";
    const char *title = "Mutate";
    uint8_t maxlines = 3;
    uint8_t textspacing = 15;
    uint8_t width = 160;
    uint8_t xprint;
    uint8_t yprint;
    uint8_t numlines;
    uint8_t currline;
    uint8_t currentselection;
    uint8_t titlewidth = 12;
    char temp[2] = " ";
    bool enterpressed;
    numlines = optix_AddMenu(0, 0, 0, 0, 0, 0, 0, 0, entries, NULL);
    if (numlines < maxlines) maxlines = numlines;
    optix_DeleteLastMenu();
    currline = 0;
    currentselection = 0;
    enterpressed = false;
    xprint = 160 - width / 2;
    yprint = 120 - (titlewidth + maxlines * textspacing) / 2;
    optix_AddMenu(xprint, yprint + titlewidth, 0, 0, 1, numlines, 100, textspacing, entries, NULL);
    optix_guidata.currmenu = optix_guidata.nummenus - 1;
    m = &optix_menu[optix_guidata.currmenu];
    while (kb_AnyKey()) kb_Scan();
    while ((!m->enterpressed) || (kb_Data[6] & kb_Enter) || (kb_Data[1] & kb_2nd)) {
        optix_UpdateCurrMenu();
        gfx_SetColor(optix_guicolors.colora);
        gfx_FillRectangle(xprint - 1, yprint + titlewidth - 1, width + 2, maxlines * textspacing + 2);
        gfx_SetColor(optix_guicolors.colorb);
        gfx_Rectangle(xprint - 1, yprint + titlewidth - 1, width + 2, maxlines * textspacing + 2);
        //gfx_Rectangle(xprint + 1, yprint + titlewidth + 1, (width + 2 * padding) - 2, (maxlines * textspacing + (2 * padding)) - 2);
        //make some triangles (not now though, they're a little off and I like the box better)
        /*gfx_FillTriangle(xprint - 5, yprint - 5 + textspacing, xprint - 5 + textspacing, yprint - 5 + textspacing, xprint - 5 + textspacing, yprint - 5);
        gfx_FillTriangle(xprint - 5 + width, yprint - 5 + textspacing, xprint - 5 + width - textspacing, yprint - 5 + textspacing, xprint - 5 + width - textspacing, yprint - 5);*/
        gfx_FillRectangle(xprint - 1, yprint - 1, width + 2, titlewidth);
        optix_CusText(true);
        gfx_PrintStringXY(title, 160 - gfx_GetStringWidth(title) / 2, yprint + (titlewidth / 2 - 4));
        //indicate that scrolling can be done if applicable
        if (numlines > maxlines) {
            if (m->menumin > 0 && m->menumin < m->numoptions - maxlines) temp[0] = 18;
            else if (m->menumin > 0) temp[0] = 24;
            else if (m->menumin < m->numoptions - maxlines) temp[0] = 25;
            gfx_PrintStringXY(temp, xprint + width - gfx_GetStringWidth(temp), yprint + (titlewidth / 2 - 4));
        }
        optix_RenderMenu(optix_guidata.currmenu);
        gfx_SwapDraw();
    }
    optix_DeleteLastMenu();
}
/* Put function prototypes here */

char *stringinput = NULL;
/* Put all your code here */
void main(void) {
    uint8_t numlines;
    int successes = 0;
    char str1[100];
    char str2[100];
    uint8_t i;
    optix_SetDefaultColors();
    gfx_Begin();
    gfx_FillScreen(optix_guicolors.bgcolor);
    gfx_Blit(0);
    gfx_SetDraw(1);
    //void optix_PrintWordWrap(uint16_t width, uint8_t initialx, uint8_t initialy, uint8_t textspacing, uint8_t currline, uint8_t maxlines) {
    optix_BlaText();
    //numlines = optix_WordWrap("This is a test string to see if the word wrapping is working properly.`Newline`starts here`more`new `lines", 160);
    //gfx_PrintStringXY(optix_wordwraptext[0].text, 5, 5);
    //optix_PrintWordWrap(160, 5, 5, 15, 0, numlines);
    optix_Message("TEST", "More test and seeing if this works properly. I sure hope it does because I do not want to rewrite the function again.", 10, 100, 4);
    /*while(true) {
        kb_Scan();
        if (kb_Data[6] & kb_Clear) break;
        gfx_FillScreen(optix_guicolors.bgcolor);
        gfx_SetTextXY(5, 5);
        optix_WhiText();
        gfx_PrintUInt(successes, 5);
        gfx_SwapDraw();
        optix_Menu("TEST", "NO`NO`PLEASE`NO`crash`crash`crash`", 15, 150, 4);
        successes++;
    }*/
    //optix_Menu("TEST", "NO`NO`PLEASE`NO`", 15, 150, 4);
    //optix_InsertSpecialCharacter();
    //while (true) optix_GetStringInput("Test input", 12, 200, 100);
    optix_WhiText();
    /*for (numlines = 0; numlines < 10; numlines++) {
        gfx_FillScreen(0);
        gfx_SetTextXY(numlines * 10 + 5, 5);
        gfx_PrintChar(stringinput[numlines]);
        gfx_Blit(1);
        delay(100);
    }*/
    //sprintf(str1, "sizeof input : %d", optix_GetStringLength(stringinput));
    //gfx_PrintStringXY(str1, 5, 5);
    //gfx_PrintStringXY(stringinput, 5, 20);
    //while (true) {
    optix_AddMenu(0, 0, 0, 0, 1, 6, 80, 20, "This`is`a`test`menu`more`options`to`see`if`scrolling`works", NULL);
    optix_SetAdvancedMenuCentering(0, 2, 2, 1, 1, 0, 0, 0, 0);
    optix_guidata.currmenu = 0;
    for (i = 0; i < 10; i++) {
        sprintf(str1, "Loading %d%s", i * 10, "%");
        optix_Dialogue(str1, "Loading filesystem...", 10, 160, 4);
        gfx_SwapDraw();
        delay(200);

    }
    while (!optix_menu[optix_guidata.currmenu].enterpressed || kb_Data[6] & kb_Enter) {
        struct optix_menu_t *m = &optix_menu[optix_guidata.currmenu];
        kb_Scan();
        gfx_FillScreen(optix_guicolors.bgcolor);
        optix_UpdateCurrMenu();
        optix_RenderMenu(optix_guidata.currmenu);
        optix_Dialogue("Loading", "Something is loading, which is pretty cool.", 10, 100, 4);
        /*optix_CusText(false);
        sprintf(str1, "numoptions = %d", optix_menu[optix_guidata.currmenu].numoptions);
        gfx_PrintStringXY(str1, 5, 200);
        sprintf(str1, "currselection = %d", optix_menu[optix_guidata.currmenu].currselection);
        gfx_PrintStringXY(str1, 5, 215);
        sprintf(str1, "currmenu = %d", optix_guidata.currmenu);
        gfx_PrintStringXY(str1, 5, 230);
        optix_VertScrollbar(0, 0, m->menumin, m->numoptions - m->height, 10, 100, kb_Data[7]);*/
        gfx_SwapDraw();
    }
    optix_DeleteLastMenu();
    optix_HorizScrollbar(0, 0, 1, 4, 100, 10, false);
    optix_VertScrollbar(0, 0, 1, 1, 10, 100, false);
    gfx_SwapDraw();
    delay(1000);
    //}
    //let's try this
    optix_Menu("TEST", "Play`Statistics`Options`", 12, 150, 3);
    gfx_End();
}


