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
        fcs_ziptx.c

    Description:
        Fast Convolution and Correlation

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fcs_ziptx_selector.h"

SAL_STATUS PREFIX( fcs_zipt )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_zf32 *T,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fcs_ziptx )( SETUPP, A, C, K, T, LOG2N, FLAG, SAL_NNN ) );
}

SAL_STATUS PREFIX( fcs_ziptx )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_zf32 *T,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    fcs_ziptx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fcs_ziptx_selector )( SETUPP, A, C, K, T, LOG2N, FLAG, X, &func );

    ( * func )( SETUPP, A, C, K, T, LOG2N, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

