/*
    2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
    identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    for(;;);
    return 0;
    /*
    Output:
    $ gcc 02.c
    $ ./a.out &
    $ ps aux | grep ./a.out
    mohit     6744 98.5  0.0   4376   804 pts/1    R    19:21   0:27 ./a.out
    mohit     6749  0.0  0.0  21536  1048 pts/1    S+   19:22   0:00 grep --color=auto
    mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ ls /proc/6744
    attr             cpuset   limits      net            personality  smaps_rollup  timerslack_ns
    autogroup        cwd      loginuid    ns             projid_map   stack         uid_map
    auxv             environ  map_files   numa_maps      root         stat          wchan
    cgroup           exe      maps        oom_adj        sched        statm
    clear_refs       fd       mem         oom_score      schedstat    status
    cmdline          fdinfo   mountinfo   oom_score_adj  sessionid    syscall
    comm             gid_map  mounts      pagemap        setgroups    task
    coredump_filter  io       mountstats  patch_state    smaps        timers
    mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ fg
    ./a.out
    ^C
    mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ fg
    bash: fg: current: no such job
    mohit@mohit-300E4Z-300E5Z-300E7Z:~/Downloads/software system/lab$ ls /proc/6744
    ls: cannot access '/proc/6744': No such file or directory
    */

}
