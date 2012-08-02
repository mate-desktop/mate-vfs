/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* mate-vfs-module-callback.h - registering for callbacks from modules

   Copyright (C) 2001 Eazel, Inc
   Copyright (C) 2001 Free Software Foundation
   Copyright (C) 2001 Maciej Stachowiak

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

   Authors: Maciej Stachowiak <mjs@noisehavoc.org>
            Seth Nickell <snickell@stanford.edu>
	    Michael Fleming <mfleming@eazel.com>
*/

#ifndef MATE_VFS_MODULE_CALLBACK_H
#define MATE_VFS_MODULE_CALLBACK_H

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * MateVFSModuleCallback:
 * @in: data passed from module to application.
 * @in_size: size of @in bytes.
 * @out: data passed from application to module.
 * @out_size: size of @out in bytes.
 * @callback_data: user data passed when connecting the callback.
 *
 * Modules use a #MateVFSModuleCallback to send data to
 * client applications and request data from them synchronously.
 *
 * The format of @in and @out is determined by the callback name.
 **/
typedef void (* MateVFSModuleCallback) (gconstpointer in,
					 gsize         in_size,
					 gpointer      out,
					 gsize         out_size,
					 gpointer      callback_data);

typedef void (* MateVFSModuleCallbackResponse) (gpointer response_data);

/**
 * MateVFSAsyncModuleCallback:
 * @in: data passed from module to application.
 * @in_size: size of @in bytes.
 * @out: data passed from application to module.
 * @out_size: size of @out in bytes.
 * @response: #MateVFSModuleCallbackResponse that must be invoked when the request is satisfied.
 * @response_data: data that must be passed to @response when the request is satisfied.
 * @callback_data: user data passed when connecting the callback.
 *
 * Modules use a #MateVFSModuleCallback to send data to
 * client applications and request data from them asynchronously.
 *
 * The application is expected to invoke the @response with @response_data
 * when it is able to satisfy the request.
 *
 * The format of @in and @out is determined by the callback name.
 **/
typedef void (* MateVFSAsyncModuleCallback) (gconstpointer                  in,
					      gsize                          in_size,
					      gpointer                       out,
					      gsize                          out_size,
					      gpointer                       callback_data,
					      MateVFSModuleCallbackResponse response,
					      gpointer                       response_data);


void mate_vfs_module_callback_set_default       (const char                  *callback_name,
						  MateVFSModuleCallback       callback,
						  gpointer                     callback_data,
						  GDestroyNotify               destroy_notify);
void mate_vfs_module_callback_push              (const char                  *callback_name,
						  MateVFSModuleCallback       callback,
						  gpointer                     callback_data,
						  GDestroyNotify               destroy_notify);
void mate_vfs_module_callback_pop               (const char                  *callback_name);

void mate_vfs_async_module_callback_set_default (const char                  *callback_name,
						  MateVFSAsyncModuleCallback  callback,
						  gpointer                     callback_data,
						  GDestroyNotify               destroy_notify);
void mate_vfs_async_module_callback_push        (const char                  *callback_name,
						  MateVFSAsyncModuleCallback  callback,
						  gpointer                     callback_data,
						  GDestroyNotify               destroy_notify);
void mate_vfs_async_module_callback_pop         (const char                  *callback_name);

#ifdef __cplusplus
}
#endif

#endif

