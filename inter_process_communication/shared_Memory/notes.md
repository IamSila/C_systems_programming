#shared memory
- 2 or more unrealated process can communicate by accessing the same memory.

# shared memory apis
shmget(key_t key, size_t size, int shmflag);
key_t key = ftok() // create key using ftok() sys call
size = size of the shared memory.
shmflag = flags, permissions.

shmat() - attaches the shared memory segment with the address space of the calling process
- returns address of the shared memory and -1 if any error occurs.
void shmat(int shmid, const void *shmaddr, shm_flag);
- the flags are [shm_rdonly, shm_rnd, shm_exec]

shmdt() - detaches the process from the shared memory.
int shmdt(const void *sharedmemory addres  ---> this is value returned by shmat() sys call)





