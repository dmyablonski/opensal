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
        bprojimgx.c

    Description:
        Back Projection of SIngle Projection over Image

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "bprojimgx_selector.h"

SAL_STATUS PREFIX( bprojimg )(
    SAL_f32 *PROJECTION,
    SAL_f32 *IMAGE,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_i32 *ROW_START,
    SAL_i32 *ROW_COUNT,
    SAL_f32 *PROJ_START,
    SAL_f32 *PROJ_DELTA
)
{
    SAL_CALL_RETURN( PREFIX( bprojimgx )( PROJECTION, IMAGE, NR, NC, ROW_START, ROW_COUNT, PROJ_START, PROJ_DELTA, SAL_NX ) );
}

SAL_STATUS PREFIX( bprojimgx )(
    SAL_f32 *PROJECTION,
    SAL_f32 *IMAGE,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_i32 *ROW_START,
    SAL_i32 *ROW_COUNT,
    SAL_f32 *PROJ_START,
    SAL_f32 *PROJ_DELTA,
    SAL_i32 XFLAG
)
{
    bprojimgx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( bprojimgx_selector )( PROJECTION, IMAGE, NR, NC, ROW_START, ROW_COUNT, PROJ_START, PROJ_DELTA, XFLAG, &func );

    ( * func )( PROJECTION, IMAGE, NR, NC, ROW_START, ROW_COUNT, PROJ_START, PROJ_DELTA, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

