int allocate_pid() 
{
    int i = 0;
    int pid = b[i/cb] & (1 << (i & (cb-1)));
    while (pid != 0) 
    {
        i++;
        pid = b[i/cb] & (1 << (i & (cb-1)));
    }

    if (i+min_pid > max_pid) return -1;
    b[i/cb] |= 1 << (i & (cb-1));
    return i+min_pid;
}


/* Allocates and returns a pid; returns -1
if unable to allocate a pid (all pids are in use) */

