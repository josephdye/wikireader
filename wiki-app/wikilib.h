/*
 * Copyright (c) 2009 Openmoko Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WIKILIB_H
#define WIKILIB_H

#ifndef __cplusplus
// for size_t / ssize_t
#include <stddef.h>
#include <stdbool.h>
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef MIN
#define MIN(a,b) ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof((a)) / sizeof((a)[0]))
#endif

#ifndef STATIC_ASSERT
#define STATIC_ASSERT(exp, name) typedef int dummy##name [(exp) ? 1 : -1];
#endif

#define ARTICLE_NEW		0
#define ARTICLE_HISTORY		1
#define ARTICLE_BROWSE		2

enum display_mode_e {

	DISPLAY_MODE_INDEX,
	DISPLAY_MODE_ARTICLE,
	DISPLAY_MODE_HISTORY,
	DISPLAY_MODE_RESTRICTED,
};

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#define ARTICLE_NEW		0
#define ARTICLE_HISTORY		1

/* function prototypes */
int wikilib_init (void);
int wikilib_run (void);
void invert_selection(int old_pos, int new_pos, int start_pos, int height);
unsigned long get_time_ticks(void);
unsigned long time_diff(unsigned long t2, unsigned long t1);
unsigned long seconds_to_ticks(float sec);
void repaint_search(void);
#endif /* WIKILIB_H */
