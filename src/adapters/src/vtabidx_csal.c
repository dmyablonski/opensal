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
        vtabidx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vtabidx_csal )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_f64 *S1,
    SAL_f64 *S2,
    SAL_f64 *C,
    SAL_i32 M,
    SAL_f64 *D,
    SAL_i32 L,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, x;
    SAL_f64 f, p;

    M--;

    for ( i = 0; i < N; i++ )
    {
        p = *A;
        p *= *S1;
        p += *S2;

        if ( p <= 0.0 )
            *D = C[0];
        else
        {
            x = ( SAL_i32 ) p;

            if ( x >= M )
                *D = C[M];
            else
            {
                f = p - ( SAL_f64 ) x;
                *D = ( 1.0 - f ) * C[x];
                *D += f * C[x+1];
            }
        }

        A += I;
        D += L;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}