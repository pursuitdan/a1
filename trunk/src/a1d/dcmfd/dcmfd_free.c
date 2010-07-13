/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  Copyright (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "a1.h"
#include "a1u.h"
#include "a1d.h"
#include "dcmfdimpl.h"

int A1D_Free(void *ptr)
{
    DCMF_Result result = DCMF_SUCCESS;

    A1U_FUNC_ENTER();

    free(ptr);

  fn_exit:
    A1U_FUNC_EXIT();
    return result;

  fn_fail:
    goto fn_exit;
}
