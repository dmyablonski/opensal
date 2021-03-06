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
        fft_roptx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft_roptx_csal )(
    FFT_setup *SETUPP,
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_f32 *T,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_zf32 split_a,
    split_t,
    split_c;

    split_a.realp = A;
    split_a.imagp = A + I;

    split_t.realp = T;
    split_t.imagp = T + 1;

    split_c.realp = C;
    split_c.imagp = C + K;

    if ( FLAG == FFT_FORWARD )
    {
        PREFIX( _csal_fft_zb )( &split_a, ( I << 1 ), &split_t, ( SAL_i32 )2,
                                &split_c, ( K << 1 ), ( LOG2N - 1 ), FLAG, SETUPP );

        PREFIX( _csal_fft_zrp )( &split_c, ( K << 1 ), &split_c, ( K << 1 ), LOG2N, FLAG,
                                 SETUPP );
    }
    else
    {
        PREFIX( _csal_fft_zrp )( &split_a, ( I << 1 ), &split_t, 2, LOG2N, FLAG,
                                 SETUPP );

        PREFIX( _csal_fft_zb )( &split_t, ( SAL_i32 )2, &split_t, ( SAL_i32 )2,
                                &split_c, ( K << 1 ), ( LOG2N - 1 ), FLAG, SETUPP );
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
