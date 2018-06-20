#include<stdio.h>
#include <assert.h>
#define LEATHER_TYPE 0
#define RUBBER_TYPE 1


typedef struct _Shoe
{
     int type;
     void (*print_shoe)(struct _Shoe*);
}SHOE,*PSHOE;

void print_leather_shoe(struct _Shoe* pShoe)  
{  
    assert(NULL != pShoe);  
    printf("This is a leather show!\n");  
}  
  
void print_rubber_shoe(struct _Shoe* pShoe)  
{  
    assert(NULL != pShoe);  
    printf("This is a rubber shoe!\n");  
}


int main(void)
{
    int type = 0;
    PSHOE pShoe = (SHOE*)malloc(sizeof(SHOE));
    assert(NULL != pShoe);  
  
    memset(pShoe, 0, sizeof(SHOE));  
    if(LEATHER_TYPE == type)  
    {  
        pShoe->type = LEATHER_TYPE;  
        pShoe->print_shoe = print_leather_shoe;  
    }  
    else  
    {  
        pShoe->type = RUBBER_TYPE;  
        pShoe->print_shoe = print_rubber_shoe;  
    }
    
    (*pShoe->print_shoe)(pShoe);  
    return 0;
}
