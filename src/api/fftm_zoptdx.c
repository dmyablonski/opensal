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
        fftm_zoptdx.c

    Description:
        Multiple Out-of-place Split Complex Fourier Transform

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fftm_zoptdx_selector.h"

SAL_STATUS PREFIX( fftm_zoptd )(
    SAL_fft64 *SETUPP,
    SAL_zf64 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf64 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fftm_zoptdx )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2N, M, FLAG, SAL_NNN ) );
}

SAL_STATUS PREFIX( fftm_zoptdx )(
    SAL_fft64 *SETUPP,
    SAL_zf64 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf64 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    fftm_zoptdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fftm_zoptdx_selector )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2N, M, FLAG, X, &func );

    ( * func )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2N, M, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

