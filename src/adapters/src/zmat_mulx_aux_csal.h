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
        zmat_mulx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef ZMAT_MULX_AUX_CSAL_H
#define ZMAT_MULX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( zmat_mul_nn ) ( SAL_zf32 *pA,
    SAL_i32 Atcols,
    SAL_zf32 *pB,
    SAL_i32 Btcols,
    SAL_zf32 *pC,
    SAL_i32 Ctcols,
    SAL_i32 nr_c,
    SAL_i32 nc_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_mul_tn ) ( SAL_zf32 *pAt,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pB,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_mul_nt ) ( SAL_zf32 *pA,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pBt,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_mul_tt ) ( SAL_zf32 *pAt,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pBt,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_mul_nn ) ( SAL_zf32 *pA,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pB,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f32 sum_r;
        SAL_f32 sum_i;

        SAL_f32 a_r;
        SAL_f32 a_i;

        SAL_f32 b_r;
        SAL_f32 b_i;

        SAL_f32 conj_l;
        SAL_f32 conj_r;

        ( void )xflag;

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                sum_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                        : 0.0;
                sum_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                        : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    a_r = pA->realp [ ( i * Atcols ) + n ];
                    a_i = pA->imagp [ ( i * Atcols ) + n ];

                    b_r = pB->realp [ ( n * Btcols ) + j ];
                    b_i = pB->imagp [ ( n * Btcols ) + j ];

                    a_i *= conj_l;
                    b_i *= conj_r;

                    sum_r += ( a_r * b_r ) - ( a_i * b_i );
                    sum_i += ( a_r * b_i ) + ( a_i * b_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = sum_r;
                pC->imagp [ ( i * Ctcols ) + j ] = sum_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_mul_tn ) ( SAL_zf32 *pAt,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pB,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f32 sum_r;
        SAL_f32 sum_i;

        SAL_f32 a_r;
        SAL_f32 a_i;

        SAL_f32 b_r;
        SAL_f32 b_i;

        SAL_f32 conj_l;
        SAL_f32 conj_r;;

        ( void )xflag;

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                sum_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                        : 0.0;
                sum_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                        : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    a_r = pAt->realp [ ( n * Atcols ) + i ];
                    a_i = pAt->imagp [ ( n * Atcols ) + i ];

                    b_r = pB->realp [ ( n * Btcols ) + j ];
                    b_i = pB->imagp [ ( n * Btcols ) + j ];

                    a_i *= conj_l;
                    b_i *= conj_r;

                    sum_r += ( a_r * b_r ) - ( a_i * b_i );
                    sum_i += ( a_r * b_i ) + ( a_i * b_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = sum_r;
                pC->imagp [ ( i * Ctcols ) + j ] = sum_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_mul_nt ) ( SAL_zf32 *pA,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pBt,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f32 sum_r;
        SAL_f32 sum_i;

        SAL_f32 a_r;
        SAL_f32 a_i;

        SAL_f32 b_r;
        SAL_f32 b_i;

        SAL_f32 conj_l;
        SAL_f32 conj_r;

        ( void )xflag;

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                sum_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                        : 0.0;
                sum_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                        : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    a_r = pA->realp [ ( i * Atcols ) + n ];
                    a_i = pA->imagp [ ( i * Atcols ) + n ];

                    b_r = pBt->realp [ ( j * Btcols ) + n ];
                    b_i = pBt->imagp [ ( j * Btcols ) + n ];

                    a_i *= conj_l;
                    b_i *= conj_r;

                    sum_r += ( a_r * b_r ) - ( a_i * b_i );
                    sum_i += ( a_r * b_i ) + ( a_i * b_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = sum_r;
                pC->imagp [ ( i * Ctcols ) + j ] = sum_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_mul_tt ) ( SAL_zf32 *pAt,
                                           SAL_i32 Atcols,
                                           SAL_zf32 *pBt,
                                           SAL_i32 Btcols,
                                           SAL_zf32 *pC,
                                           SAL_i32 Ctcols,
                                           SAL_i32 nr_c,
                                           SAL_i32 nc_c,
                                           SAL_i32 N,
                                           SAL_i32 flag,
                                           SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f32 sum_r;
        SAL_f32 sum_i;

        SAL_f32 a_r;
        SAL_f32 a_i;

        SAL_f32 b_r;
        SAL_f32 b_i;

        SAL_f32 conj_l;
        SAL_f32 conj_r;

        ( void )xflag;

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                sum_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                        : 0.0;
                sum_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                        : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    a_r = pAt->realp [ ( n * Atcols ) + i ];
                    a_i = pAt->imagp [ ( n * Atcols ) + i ];

                    b_r = pBt->realp [ ( j * Btcols ) + n ];
                    b_i = pBt->imagp [ ( j * Btcols ) + n ];

                    a_i *= conj_l;
                    b_i *= conj_r;

                    sum_r += ( a_r * b_r ) - ( a_i * b_i );
                    sum_i += ( a_r * b_i ) + ( a_i * b_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = sum_r;
                pC->imagp [ ( i * Ctcols ) + j ] = sum_i;
            }
        }

        return ( SAL_SUCCESS );
    }

#ifdef __cplusplus
}
#endif

#endif
