/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  Copyright (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "a1.h"
#include "a1d.h"
#include "a1u.h"

#ifdef A1_USES_MPI_COLLECTIVES
#include "mpi.h"
MPI_Comm A1_COMM_WORLD;
#endif

int A1_Initialize(int thread_level)
{
    int status = A1_SUCCESS;
    static int a1_active = 0;

#   ifdef A1_USES_MPI_COLLECTIVES
    int initialized
#   endif

    A1U_FUNC_ENTER();

    /* FIXME: The profiling interface needs to go here */

    /* FIXME: Locking functionality needs to go here */

#   ifdef HAVE_ERROR_CHECKING
#   endif

    /* we only want this function to run once */
    if(a1_active == 1)
    {
        return status;
    }
    a1_active = 1;

#   ifdef A1_USES_MPI_COLLECTIVES
    MPI_Initialized(&initialized);
    A1U_ERR_POP(initialized!=1, "You need to initialize MPI for collectives");

    MPI_Comm_dup(MPI_COMM_WORLD,A1_COMM_WORLD);
#   endif

    status = A1D_Initialize(thread_level);
    A1U_ERR_POP(status!=A1_SUCCESS, "A1D_Initialize returned error\n");

    status = A1U_Read_parameters();
    A1U_ERR_POP(status!=A1_SUCCESS, "A1U_Read_parameters returned error\n");

    status = A1U_Print_parameters();
    A1U_ERR_POP(status!=A1_SUCCESS, "A1U_Print_parameters returned error\n");

  fn_exit: 
    A1U_FUNC_EXIT();
    return status;

  fn_fail: 
    goto fn_exit;
}
