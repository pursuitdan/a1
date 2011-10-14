
/* to make sure I haven't broken the API */
/* #include "parmci.h" */
/* #include "armci.h" */

typedef enum
{
    ARMCI_FETCH,
    ARMCI_ADD,
    ARMCI_FETCH_AND_ADD,
    ARMCI_SWAP,
#ifdef SUPPORTS_64BIT_ATOMICS 
    ARMCI_FETCH_LONG,
    ARMCI_ADD_LONG,
    ARMCI_FETCH_AND_ADD_LONG,
    ARMCI_SWAP_LONG
#else
    #warning 64b atomics are not available on this architecture.
#endif
}
armci_rmw_t;

/* for vector calls */
typedef struct
{
    void **src_ptr_array;
    void **dst_ptr_array;
    int  ptr_array_len;
    int bytes;
}
armci_giov_t;

/* NOT USED */
typedef struct
{
    int data[4];
    double dummy[72];
}
armci_hdl_t;

/* NOT USED
typedef struct armci_meminfo_ds
{
  void     *armci_addr;
  void     *addr;
  size_t    size;
  int       cpid;
  long      idlist[64];
}
armci_meminfo_t;
*/

/* initialization and termination */

int PARMCI_Init();
int PARMCI_Init_args(int *argc, char ***argv);

void PARMCI_Finalize();

/* memory management */

int PARMCI_Malloc(void * ptr_arr[], int bytes);
int PARMCI_Free(void * ptr);

void * PARMCI_Malloc_local(int bytes);
int PARMCI_Free_local(void * ptr);

/* NOT USED
void *PARMCI_Memat(armci_meminfo_t * meminfo, int memflg);
void PARMCI_Memget(size_t bytes, armci_meminfo_t * meminfo, int memflg);
*/

/* synchronization */

void PARMCI_Barrier();

void PARMCI_Fence(int proc);
void PARMCI_AllFence();

int PARMCI_Test(armci_hdl_t * nb_handle);
int PARMCI_Wait(armci_hdl_t * nb_handle);
int PARMCI_WaitProc(int proc);
int PARMCI_WaitAll();

/* remote atomic update and mutexes */

long PARMCI_Rmw(int op, void * ploc, void * prem, int extra, int proc);

int PARMCI_Create_mutexes(int num);
int PARMCI_Destroy_mutexes();
void PARMCI_Lock(int mutex, int proc);
void PARMCI_Unlock(int mutex, int proc);

/* blocking one-sided */

int PARMCI_Acc(int optype, void *scale, void *src, void* dst, int bytes, int proc);
int PARMCI_AccS(int optype, void *scale, void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc);
int PARMCI_AccV(int op, void *scale, armci_giov_t * darr, int len, int proc);
int PARMCI_Get(void *src, void *dst, int bytes, int proc);
int PARMCI_GetS(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc);
int PARMCI_GetV(armci_giov_t * darr, int len, int proc);
int PARMCI_Put(void *src, void *dst, int bytes, int proc);
int PARMCI_PutS(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc);
int PARMCI_PutV(armci_giov_t * darr, int len, int proc);

/* non-blocking one-sided */

int PARMCI_NbAccS(int optype, void *scale, void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbAccV(int op, void *scale, armci_giov_t * darr, int len, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbPut(void *src, void *dst, int bytes, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbPutS(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbPutV(armci_giov_t * darr, int len, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbGet(void *src, void *dst, int bytes, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbGetS(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int proc, armci_hdl_t * nb_handle);
int PARMCI_NbGetV(armci_giov_t * darr, int len, int proc, armci_hdl_t * nb_handle);

int PARMCI_Put_flag(void *src, void *dst, int bytes, int *f, int v, int proc);
int PARMCI_PutS_flag(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int *flag, int val, int proc);
int PARMCI_PutS_flag_dir(void *src_ptr, int *src_stride_arr, void *dst_ptr, int *dst_stride_arr, int *count, int stride_levels, int *flag, int val, int proc);

/* CAF extensions */

int PARMCI_PutValueInt(int src, void *dst, int proc);
int PARMCI_PutValueLong(long src, void *dst, int proc);
int PARMCI_PutValueFloat(float src, void *dst, int proc);
int PARMCI_PutValueDouble(double src, void *dst, int proc);

int PARMCI_GetValueInt(void *src, int proc);
long PARMCI_GetValueLong(void *src, int proc);
float PARMCI_GetValueFloat(void *src, int proc);
double PARMCI_GetValueDouble(void *src, int proc);

/**********************************************/
