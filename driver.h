/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2016 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RARCH_DRIVER__H
#define __RARCH_DRIVER__H

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#include <boolean.h>
#include <retro_common_api.h>

RETRO_BEGIN_DECLS

#define DRIVERS_CMD_ALL \
      ( DRIVER_AUDIO \
      | DRIVER_VIDEO \
      | DRIVER_INPUT \
      | DRIVER_CAMERA \
      | DRIVER_LOCATION \
      | DRIVER_MENU \
      | DRIVERS_VIDEO_INPUT \
      | DRIVER_WIFI )

enum
{
   DRIVER_AUDIO        = 1 << 0,
   DRIVER_VIDEO        = 1 << 1,
   DRIVER_INPUT        = 1 << 2,
   DRIVER_CAMERA       = 1 << 3,
   DRIVER_LOCATION     = 1 << 4,
   DRIVER_MENU         = 1 << 5,
   DRIVERS_VIDEO_INPUT = 1 << 6,
   DRIVER_WIFI         = 1 << 7
};

enum driver_ctl_state
{
   RARCH_DRIVER_CTL_NONE = 0,
   RARCH_DRIVER_CTL_DEINIT,

   /* Deinitializes drivers.
    * @data is a bitmask which determines 
    * which drivers get deinitialized. */
   RARCH_DRIVER_CTL_UNINIT,

   RARCH_DRIVER_CTL_UNINIT_ALL,

   /* Initializes drivers.
    * @data is a bitmask which determines 
    * which drivers get initialized. */
   RARCH_DRIVER_CTL_INIT,

   RARCH_DRIVER_CTL_INIT_ALL,

   /* Attempts to find a default driver for 
    * all driver types.
    *
    * Should be run before RARCH_DRIVER_CTL_INIT.
    */
   RARCH_DRIVER_CTL_INIT_PRE,

   /* Sets monitor refresh rate to new value by calling
    * video_monitor_set_refresh_rate(). Subsequently
    * calls audio_monitor_set_refresh_rate(). */
   RARCH_DRIVER_CTL_SET_REFRESH_RATE,

   /* Sets audio and video drivers to nonblock state.
    *
    * If nonblock state is false, sets blocking state for both
    * audio and video drivers instead. */
   RARCH_DRIVER_CTL_SET_NONBLOCK_STATE,

   /* Update the system Audio/Video information. 
    * Will reinitialize audio/video drivers.
    * Used by RETRO_ENVIRONMENT_SET_SYSTEM_AV_INFO. */
   RARCH_DRIVER_CTL_UPDATE_SYSTEM_AV_INFO,

   RARCH_DRIVER_CTL_FIND_FIRST,

   RARCH_DRIVER_CTL_FIND_PREV,

   RARCH_DRIVER_CTL_FIND_NEXT,

   /* Find index of the driver, based on @label. */
   RARCH_DRIVER_CTL_FIND_INDEX

};

typedef struct driver_ctx_info
{
   const char *label;
   char *s;
   ssize_t len;
} driver_ctx_info_t;

bool driver_ctl(enum driver_ctl_state state, void *data);

RETRO_END_DECLS

#endif
