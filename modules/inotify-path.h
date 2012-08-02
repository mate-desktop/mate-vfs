/*
   Copyright (C) 2005 John McCutchan

   The Mate Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Mate Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Mate Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA 02110-1301, USA.

   Authors:.
		John McCutchan <john@johnmccutchan.com>
*/

#ifndef __INOTIFY_PATH_H
#define __INOTIFY_PATH_H

#include "inotify-kernel.h"
#include "inotify-sub.h"

gboolean ip_startup (void (*event_cb)(ik_event_t *event, ih_sub_t *sub));
gboolean ip_start_watching (ih_sub_t *sub);
gboolean ip_stop_watching  (ih_sub_t *sub);

#endif
