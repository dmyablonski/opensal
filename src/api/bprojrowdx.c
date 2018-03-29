/*
----------------------------------------------------------------------------

    OpenSAL is an Open Source Scientific Algorithms Library consisting
    of an API for several hundred math functions. The Library is
    composed of a C source code reference implementation. Commercial
    versions of this library are used as performance accelerators in
    HPEC applications.

    Copyright (C) 2010 Mercury Computer Systems, Inc.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/

----------------------------------------------------------------------------

    Filename:
        bprojrowdx.c

    Description:
        Image Back Projection Over Siblge Row

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "bprojrowdx_selector.h"

SAL_STATUS PREFIX( bprojrowd )(
    SAL_f64 *ROW_START,
    SAL_f64 *PROJECTION,
    SAL_i32 PROJ_NUM,
    SAL_i32 PROJ_SIZE,
    SAL_i32 ROW_COUNT,
    SAL_f64 *PROJ_START,
    SAL_f64 *PROJ_DELTA
)
{
    SAL_CALL_RETURN( PREFIX( bprojrowdx )( ROW_START, PROJECTION, PROJ_NUM, PROJ_SIZE, ROW_COUNT, PROJ_START, PROJ_DELTA, SAL_NX ) );
}

SAL_STATUS PREFIX( bprojrowdx )(
    SAL_f64 *ROW_START,
    SAL_f64 *PROJECTION,
    SAL_i32 PROJ_NUM,
    SAL_i32 PROJ_SIZE,
    SAL_i32 ROW_COUNT,
    SAL_f64 *PROJ_START,
    SAL_f64 *PROJ_DELTA,
    SAL_i32 XFLAG
)
{
    bprojrowdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( bprojrowdx_selector )( ROW_START, PROJECTION, PROJ_NUM, PROJ_SIZE, ROW_COUNT, PROJ_START, PROJ_DELTA, XFLAG, &func );

    ( * func )( ROW_START, PROJECTION, PROJ_NUM, PROJ_SIZE, ROW_COUNT, PROJ_START, PROJ_DELTA, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}
