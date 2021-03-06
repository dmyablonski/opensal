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
        fixrd_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

SAL_i32 PREFIX( _csal_fixrd_ieee )( SAL_f64 *dp )
{
    SAL_i32  i;
    SAL_f64  d;

    d = *dp;

    if ( d < ( SAL_f64 ) 0.0 )
        d = -d;

    d += ( SAL_f64 ) 0.5;
    i = ( SAL_i32 ) d;

    if ( d == ( SAL_f64 ) i )
        i &= -2;

    if ( *dp < ( SAL_f64 ) 0.0 )
        i = -i;

    SAL_SET_PATH_CSAL();
    return( i );
}
