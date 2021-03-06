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
        cvsmax_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cvsmax_csal )(
    SAL_cf32 *c_A,
    SAL_i32 I,
    SAL_cf32 *c_S,
    SAL_cf32 *c_C,
    SAL_i32 K,
    SAL_cf32 *c_D,
    SAL_i32 L,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i;
    SAL_f32  ar, ai, cr, ci, sr, si;
    SAL_f32  *A, *S, *C, *D;

    A = ( SAL_f32 * ) c_A;
    S = ( SAL_f32 * ) c_S;
    C = ( SAL_f32 * ) c_C;
    D = ( SAL_f32 * ) c_D;

    sr = *S;
    si = *( S + 1 );

    for ( i = 0; i < N; i++ )
    {
        ar = *A;
        ai = *( A + 1 );
        cr = *C;
        ci = *( C + 1 );
        *D = ( sr * ar ) - ( si * ai ) + cr;
        *( D + 1 ) = ( sr * ai ) + ( si * ar ) + ci;
        A += I;
        C += K;
        D += L;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
