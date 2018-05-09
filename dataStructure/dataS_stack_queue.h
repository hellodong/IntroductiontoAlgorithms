/*  
 * @file 	
 * @brief	
 * @details 
 * @author   purefarmer <464224357@hzdusun.com> 
 * @date     
 * @par Copyright (c):purefarmer 
 */

#ifndef _DATAS_STACK_QUEUE_H_
#define _DATAS_STACK_QUEUE_H_

#ifdef __cplusplus 
extern "C" 
{ 
#endif 


typedef StackEment_t char;

typedef struct
{
    int top;
    int size;
    StackEment_t *elmentPtr;
}DataStack_t;


int dataS_stack_init(DataStack_t *stack, StackEment_t *buffer, const int size);

int dataS_stack_push(DataStack_t *stack, StackEment_t element);

int dataS_stack_pop(DataStack_t *stack, StackEment_t *elementPtr);


#ifdef __cplusplus 
} 
#endif

#endif /* dataS_stack_queue.h */
