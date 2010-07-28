/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  Copyright (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "a1.h"

#if !defined A1D_H_INCLUDED
#define A1D_H_INCLUDED

int A1D_Initialize(int A1_thread_level,
               int A1_num_threads,
               int A1_num_memtypes,
               A1_memtype_t A1_memtypes[]);

int A1D_Finalize(void);

int A1D_Malloc(void **ptr, int bytes);

int A1D_Free(void *ptr);

int A1D_GlobalBarrier();

int A1D_Put(int target, void* src, void* dst, int bytes);

int A1D_Get(int target, void* src, void* dst, int bytes);

int A1D_PutS(int target, void* source_ptr, int *src_stride_ar, void* target_ptr,\
         int *trg_stride_ar, int *count, int stride_levels);

int A1D_Flush(int proc);

int A1D_Flush_all();

void A1D_Rank(int* rank);

void A1D_Rank(int* size);

unsigned long long A1D_Time();

#endif /* A1D_H_INCLUDED */
