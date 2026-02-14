#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H
#include <stdlib.h>

/***
 * explicit free list, containing block size and next free block
 ****/

typedef struct Node{
    /***
     alignments issues ??
     ***/
    size_t block_size;
    struct Node* next;
} Node;

// TODO: need to put these in a C file.
extern Node* free_list_head;

void remove_block_from_free_list(Node*);
void* find_best_block(size_t);
void insert_newly_freed_block_into_list(Node* freed_block);
void zero_out_allocated_memory();

inline void* find_best_block(size_t size) {
    // we want to find the min positive diff. if the diff is negative, we will ignore the block
    // because size_t is unsigned, the actual assigned value here is the largest possible number
    size_t min = -1;
    Node* best_block = NULL;
    size_t best_block_size = -1;
    Node* itr = free_list_head;
    while(itr) {
        size_t pot_min = itr -> block_size - size;
        if (itr -> block_size >= size && min >= pot_min) {
            min = pot_min;
            best_block = itr;
            best_block_size = itr -> block_size + sizeof(Node);
        }
        itr = itr -> next;
    }
    // splitting the block and assigning size
    if (best_block) {
        // advancing ptr to the splitting spot.
        // a lot of assumptions are made here: the split block is big enough to contain
        // at least a Node
        char* temp = (char*)best_block;
        temp += size;
        ((Node*)temp) -> block_size = best_block_size - size;
        best_block -> block_size = size;
        Node* best_block_next = best_block -> next;
        best_block -> next = (Node*)temp;
        if (best_block_next) {
            ((Node*)temp) -> next = best_block_next;
        }
        remove_block_from_free_list(best_block);
    }
    return best_block;
}

inline void insert_newly_freed_block_into_list(Node* freed_block) {
    Node* temp = free_list_head;
    free_list_head = freed_block;
    free_list_head -> next = temp;
}

inline void remove_block_from_free_list(Node* freed_block) {
    if (free_list_head == freed_block) {
        free_list_head = free_list_head -> next;
    }
    Node* itr = free_list_head;
    while (itr != NULL && itr -> next != NULL) {
        if (itr -> next == freed_block) {
            Node* temp = freed_block;
            itr -> next = freed_block -> next;
            // this is basically freeing the block
            temp -> next = NULL;
        }
        itr = itr -> next;
    }
}

inline void zero_out_allocated_memory() {

}


#endif //UNTITLED_UTILS_H