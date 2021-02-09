# Scheduler

Adds a soft real-time requirement to a process. Every time the scheduler is called, it is checked if the real-time guarantees of process with soft- realtime requirements are being met or not. We give higher priority to a processes soft-realtime requirement compared to the vruntime that is normally considered. Everytime a process is selected through the RB-tree, we compare to all other process with soft-realtime requirements and see which one of those require the CPU more urgently than the one selected through the regular RB-tree. The one that urgently requires CPU time need to be scheduled before the one selected through CFS.


There is also a system call (rtnice) to modify the tasks soft-realtime requirements, which takes argument the PID and the realtime guarantees needed. rtnice has a corresponding user program with the same name which should actually do the system call rtnice to perform the said operation with the supplied PID.
