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
        cexptabx.c

    Description:
        Create Table of Complex Exponentials

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cexptabx_selector.h"

SAL_STATUS PREFIX( cexptab )(
    SAL_cf32 *C,
    SAL_i32 LOG2M,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( cexptabx )( C, LOG2M, FLAG, SAL_NX ) );
}

SAL_STATUS PREFIX( cexptabx )(
    SAL_cf32 *C,
    SAL_i32 LOG2M,
    SAL_i32 FLAG,
    SAL_i32 XFLAG
)
{
    cexptabx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cexptabx_selector )( C, LOG2M, FLAG, XFLAG, &func );

    ( * func )( C, LOG2M, FLAG, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

