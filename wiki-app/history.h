/*
 *  Copyright (c) 2009 Holger Hans Peter Freyther <zecke@openmoko.org>
 *  Copyright (c) 2009 Matt Hsu <matt_hsu@openmoko.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WL_HISTORY_H
#define WL_HISTORY_H

#include "search.h"

#define HISTORY_RESULT_START 31
//#define HISTORY_RESULT_HEIGHT 10
#define HISTORY_RESULT_HEIGHT 19
#define MAX_HISTORY 256
#define HISTORY_PIXEL_START (HISTORY_RESULT_START - HISTORY_RESULT_HEIGHT + 2)
#define MESSAGE_HISTORY_TITLE "History"
#define MESSAGE_NO_HISTORY "No history"
/*
 * Interface for the History feature
 */

void history_clear(void);

void history_add(const long idx_article, const char *title, int b_keep_pos);
unsigned int history_get_count();
void history_list_init(void);
int history_list_save(int level);

void history_open_article(int new_selection);
void history_reload();
void history_log_y_pos(const long y_pos);
long history_get_y_pos(const long idx_article);
void draw_clear_history(int bFlag);

typedef struct _HISTORY {
	long idx_article;
	long last_y_pos;
	char title[MAX_TITLE_SEARCH];
} HISTORY;

enum history_save_e {

	HISTORY_SAVE_NONE,
	HISTORY_SAVE_POWER_OFF,
	HISTORY_SAVE_NORMAL,
};
#endif
