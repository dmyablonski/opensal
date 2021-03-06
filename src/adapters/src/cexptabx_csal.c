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
        cexptabx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( cexptabx_csal )(
    SAL_cf32 *C,
    SAL_i32 LOG2M,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, m;
    SAL_f64 cos_val, sin_val, twopivm;

    ( void ) FLAG;

    m = ( 1 << LOG2M );
    twopivm = ( SAL_f64 ) TWO_PI / ( SAL_f64 ) ( m );

    if ( m )
    {
        C[0].real = 1.0;
        C[0].imag = 0.0;
    }

    for ( i = 1; i < m; i++ )
    {
        cos_val = COSINE_TWIDDLE( twopivm, i );
        sin_val = SINE_TWIDDLE( twopivm, i );
        C[i].real = ( SAL_f32 ) cos_val;
        C[i].imag = ( SAL_f32 ) sin_val;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
