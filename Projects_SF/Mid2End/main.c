#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push (sqStack *s,ElemType e)
{
    if (s->top-s->base >=s->stackSize)
    {
        s->base = (ElemType *)realloc (s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;


}

void Pop (sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);

}


int StackLen (sqStack s)
{
    return (s.top - s.base);
}


int main()
{



    sqStack s;


    char c,e;

    InitStack(&s);

    printf("请输入中缀表达式，并以#作为结束:/n");
    scanf("%c",&c);

    while(c!='#')
    {


        if( c>='0' && c<='9')
        {
            printf("%c",c);
        }

        else if(')' == c)
        {
            Pop(&s, &e);
            while ('(' != e)
            {
                printf("%c",e);
                Pop(&s,&e);

            }

        }
        else if('+' == c || '-' == c)
        {
            if(!StackLen(s))
            {
                Push(&s, c);
            }
            else
            {
                    Pop(&s, &e);
                    if ('(' == e)
                    {
                        Push(&s, e);

                    }
                    else
                    {
                        printf("%c",e);

                    }

                Push(&s, c);//该Pop的都Pop了之后，把加或减Push！！！

            }
        }

        else if('*' ==c || '/' == c)
        {

            if (!StackLen(s))
            {
                Push(&s, c);
            }
            else
                {
                    Pop(&s, &e);
                    if ('*' == e || '/' ==e)
                    {
                        printf("%c", e);

                    }
                    else
                    {
                        Push(&s, e);
                    }

                    Push(&s, c);//该Pop的都Pop了之后，把乘或除Push！！！

                }
        }

        else if ('(' == c)
        {
            Push(&s, c);

        }

        else if('#' == c)
        {

            break;

        }

        else
        {
            printf("\n输出格式错误!\n");
            return -1;

        }

        scanf("%c",&c);

    }

    while(StackLen(s))
    {

        Pop(&s, &e);
        printf("%c", e);
    }



    return 0;
}

