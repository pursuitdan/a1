/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  Copyright (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "a1.h"
#include "a1d.h"
#include "a1u.h"

void A1_Rank(int* rank) 
{
    A1U_FUNC_ENTER();

    /* FIXME: The profiling interface needs to go here */

    /* FIXME: Locking functionality needs to go here */

#   ifdef HAVE_ERROR_CHECKING
#   endif

    A1D_Rank(rank);

  fn_exit:
    A1U_FUNC_EXIT();
    return;

  fn_fail:
    goto fn_exit;
}

void A1_Size(int* size)
{
    A1U_FUNC_ENTER();

    /* FIXME: The profiling interface needs to go here */

    /* FIXME: Locking functionality needs to go here */

#   ifdef HAVE_ERROR_CHECKING
#   endif

    A1D_Size(size);

  fn_exit:
    A1U_FUNC_EXIT();
    return;

  fn_fail:
    goto fn_exit;
}


unsigned long long A1_Time()
{
    A1U_FUNC_ENTER();

    /* FIXME: The profiling interface needs to go here */

    /* FIXME: Locking functionality needs to go here */

#   ifdef HAVE_ERROR_CHECKING
#   endif

  fn_exit:
    A1U_FUNC_EXIT();  
    return A1D_Time();

  fn_fail:
    goto fn_exit;
}
