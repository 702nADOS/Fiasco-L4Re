/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: exit.c 4144 2001-12-07 13:41:02Z xleroy $ */

#include <mlvalues.h>
#include "unixsupport.h"

CAMLprim value unix_exit(value n)
{
  _exit(Int_val(n));
  return Val_unit;                  /* never reached, but suppress warnings */
                                    /* from smart compilers */
}


