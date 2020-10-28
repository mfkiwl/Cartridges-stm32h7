/*
 * Copyright (c) 2019 Kim Jørgensen
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************
 * Derived from Draco Browser V1.0C 8 Bit (27.12.2009)
 * Created 2009 by Sascha Bader
 *
 * The code can be used freely as long as you retain
 * a notice describing original source and author.
 *
 * THE PROGRAMS ARE DISTRIBUTED IN THE HOPE THAT THEY WILL BE USEFUL,
 * BUT WITHOUT ANY WARRANTY. USE THEM AT YOUR OWN RISK!
 *
 * Newer versions might be available here: http://www.sascha-bader.de/html/code.html
 */
#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include <joystick.h>
#include "base.h"

static int getJoy(void)
{
    uint8_t debounce = 0;

    if (joy_read(JOY_2) & JOY_MASK)
    {
        while (++debounce);
        if (joy_read(JOY_2) & JOY_MASK)
        {
            return 1;
        }
    }

    return 0;
}

uint8_t waitKey(void)
{
	revers(1);
	textcolor(COLOR_VIOLET);
	cputs("PRESS A KEY");
	revers(0);

    while(getJoy());
    while (1)
    {
        if (kbhit())
        {
            return cgetc();
        }

        if (getJoy())
        {
            while(getJoy());
            break;
        }
    }

	return 0;
}
