/*  
 * @file 	
 * @brief	
 * @details 
 * @author   purefarmer <464224357@hzdusun.com> 
 * @date     
 * @par Copyright (c):purefarmer 
 */
#include <string.h>


/*  
 * @brief        
 * @param[out]   
 * @param[in]   
 * @return       
 * @see         
 * @note        
 */
int dataS_stack_init(DataStack_t *stack, StackEment_t *buffer, const int size)
{
    int ret = 0;

    stack->top = 0;
    stack->size = size;
    stack->elmentPtr=buffer;
    memset(stack->elmentPtr,0x00, sizeof(StackEment_t) * size);

    return ret;
}

/*  
 * @brief        
 * @param[out]   
 * @param[in]   
 * @return       
 * @see         
 * @note        
 */
int dataS_stack_push(DataStack_t *stack, StackEment_t element)
{
    int ret = -1;

    if (stack->top - 1 == stack->size) {
        return -1;
    }
    ret = 0;
    memcpy(stack->elmentPtr + stack->top, &element, sizeof(element));
    stack->top++;
    return ret;
}

/*  
 * @brief        
 * @param[out]   
 * @param[in]   
 * @return       
 * @see         
 * @note        
 */
int dataS_stack_pop(DataStack_t *stack, StackEment_t *elementPtr)
{
    int ret = -1;

    if (0 == stack->top) {
        return ret;
    }
    ret = 0;
    stack->top--;
    memcpy(elementPtr, stack->elmentPtr + stack->top, sizeof(StackEment_t));
    return ret;
}



