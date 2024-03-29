/*
 * Copyright (C) ST-Ericsson AB 2010
 *
 * Author: Johan Mossberg <johan.xx.mossberg@stericsson.com> for ST-Ericsson
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _LINUX_DRIVERS_VIDEO_B2R2_INPUT_VALIDATION_H_
#define _LINUX_DRIVERS_VIDEO_B2R2_INPUT_VALIDATION_H_

#include <video/b2r2_blt.h>

#include "b2r2_internal.h"

bool b2r2_validate_user_req(struct b2r2_control *cont,
		struct b2r2_blt_req *req);

#endif
