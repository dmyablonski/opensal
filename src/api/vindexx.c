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
        vindexx.c

    Description:
        Vector Index

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "vindexx_selector.h"

SAL_STATUS PREFIX( vindex )(
    SAL_f32 *A,
    SAL_f32 *B,
    SAL_i32 J,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( vindexx )( A, B, J, C, K, N, SAL_NX ) );
}

SAL_STATUS PREFIX( vindexx )(
    SAL_f32 *A,
    SAL_f32 *B,
    SAL_i32 J,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    vindexx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( vindexx_selector )( A, B, J, C, K, N, XFLAG, &func );

    ( * func )( A, B, J, C, K, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

