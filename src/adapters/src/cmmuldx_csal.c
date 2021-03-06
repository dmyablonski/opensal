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
        cmmuldx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cmmuldx_csal )(
    SAL_cf64 *c_A,
    SAL_i32 I,
    SAL_cf64 *c_B,
    SAL_i32 J,
    SAL_cf64 *c_C,
    SAL_i32 K,
    SAL_i32 MC,
    SAL_i32 NC,
    SAL_i32 NA,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32      i, j, k;
    SAL_i32      ncj;
    SAL_f64   sumi, sumr, ai, ar, bi, br;
    SAL_f64  *aptr, *bptr;
    SAL_f64  *A, *B, *C;

    A = ( SAL_f64 * ) c_A;
    B = ( SAL_f64 * ) c_B;
    C = ( SAL_f64 * ) c_C;

    if ( ( MC == 0 ) || ( NC == 0 ) || ( NA == 0 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        return;
    }

    ncj = ( ( SAL_i32 ) NC ) * J;

    for ( i = 0; i < MC; i++ )
    {
        for ( j = 0; j < NC; j++ )
        {
            aptr = A;
            bptr = B;
            sumr = 0.0;
            sumi = 0.0;

            for ( k = 0; k < NA; k++ )
            {
                ar = *aptr;
                ai = *( aptr + 1 );
                br = *bptr;
                bi = *( bptr + 1 );
                sumr += ( ar * br );
                sumr -= ( ai * bi );
                sumi += ( ar * bi );
                sumi += ( ai * br );

                aptr += I;
                bptr += ncj;
            }

            *C = sumr;
            *( C + 1 ) = sumi;

            B += J;
            C += K;
        }

        A = aptr;
        B -= ncj;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
