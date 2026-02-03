# Memory Allocator
We will implement Malloc, Free, Realloc and Calloc.
Malloc is where most of the thinking lies. In buddy allocation systems, we use mmap. 


# Overview of what needs to be done:
In malloc/malloc/realloc (don't have to do all three, recommended if you have time):
- First, priorotize free blocks in the linked list: use the strategies first-fit/ best-fit/ worst-fit + any additional logic for the specific function
- In the absence of free blocks that can be used for the allocation, use SBRK (unless we are implementing buddy allocation in which case we should use MMAP)

In free:
- Add the block to the linked list. 
- Can try to merge (would be more efficient to do if we save more metadata/overhead in the nodes)


# How to handle free memory?
For now we have decided to have a linked list. The linked list will contain the free memory blocks.
For now, the list can just have a next pointer to the next node and the size of the block. 

## How to handle coalescing?
- can try to merge in free for now.

## How to handle allocation with the presence of free space in the list
- need a strategy: best fit? first fit etc ... (do all three)


# Notes:
- Can implement funcs that print the status of the heap (for debugging purposes). Things like amount of free blocks (or amount of free bytes), amount of allocated blocks etc etc. (optional)


# Git Structure
TBD


# Deadline
daeadline: 1 week (2/10/26), flexible can extend. We are using deadlines so we can hold each other accountable.


# Next steps:
We will work on buddy allocation OR kernel (kernel preferrably)