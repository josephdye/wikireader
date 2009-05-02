//
// Authors:	Wolfgang Spraul <wolfgang@openmoko.com>
//
//		This program is free software; you can redistribute it and/or
//		modify it under the terms of the GNU General Public License
//		as published by the Free Software Foundation; either version
//		3 of the License, or (at your option) any later version.
//           

#include "msg.h"
#include "wom_file_format.h"

typedef struct wom_file wom_file_t;

wom_file_t* wom_open(const char* filename);
void wom_close(wom_file_t* womh);

// returned pointer for wom_find_article() and wom_get_next_article() does not need to be freed
const wom_index_entry_t* wom_find_article(wom_file_t* womh, const char* search_string, size_t search_str_len);
// returns 0 if there are no more articles
const wom_index_entry_t* wom_get_next_article(wom_file_t* womh);

void wom_draw(wom_file_t* womh, uint32_t offset_into_articles, uint8_t* frame_buffer_dest, int32_t y_start_in_article, int32_t lines_to_draw);

// TBD: const wom_index_entry_t* wom_get_link(uint32_t offset_into_articles, x, y);
