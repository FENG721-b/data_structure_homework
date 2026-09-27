#include <stdio.h>

#define QUEUE_MAX_NUM 100

typedef struct{
    int queue[QUEUE_MAX_NUM];
    int front;
    int rear;
    int s;
}Queue_Type;

Queue_Type myQueue;

/* 队列初始化 */
void InitQueue(Queue_Type *p)
{
    p->front = 1;
    p->rear  = 1;
    p->s = 0;
}

/* 入队操作 */
void InQueue(Queue_Type *p, int m, int x)
{
    if((p->s == 1) && (p->rear == p->front))
        printf(" overflow!\n ");
    else{
        p->rear += 1;
        if(p->rear == m+1)
            p->rear = 1;
        p->queue[p->rear - 1] = x;
        p->s = 1;
    }
}

/* 出队操作 */
int OutQueue(Queue_Type *p, int m)
{
    int y;
    if(p->s == 0)
        printf(" underflow!\n ");
    else{
        p->front = p->front%m + 1;
        y = p->queue[p->front - 1];
        if(p->front == p->rear)
            p->s = 0;
        return y;
    }
}

/* 获取队首元素 */
int GetFront(Queue_Type *p, int m)
{
    if(p->s == 0){
        printf(" queue is empty!\n ");
        return -1;
    }
    return p->queue[p->front % m];
}

/* 获取队尾元素 */
int GetRear(Queue_Type *p)
{
    if(p->s == 0){
        printf(" queue is empty!\n ");
        return -1;
    }
    return p->queue[p->rear - 1];
}

/* 检查队列是否已满 */
int QueueFull(Queue_Type *p)
{
    if((p->s == 1) && (p->rear == p->front))
        return 1;
    else
        return 0;
}

/* 检查队列是否为空 */
int QueueEmpty(Queue_Type *p)
{
    if(p->s == 0)
        return 1;
    else
        return 0;
}

/* 打印队列中所有元素 */
void PrintQueue(Queue_Type *p, int m)
{
    int i;
    if(p->s == 0){
        printf(" 队列为空\n ");
        return;
    }
    printf(" 队列元素: ");
    i = p->front % m + 1;
    while(i != p->rear){
        printf("%d ", p->queue[i - 1]);
        i = i % m + 1;
    }
    printf("%d\n", p->queue[p->rear - 1]);
}

int main()
{
    int val;

    printf("===== 循环队列综合编程应用 =====\n\n");

    /* 初始化队列 */
    InitQueue(&myQueue);
    printf("1. 初始化队列完成\n\n");

    /* 1. 依次入队元素: 10, 20, 30, 40 */
    printf("操作1：依次入队元素 10, 20, 30, 40\n");
    InQueue(&myQueue, QUEUE_MAX_NUM, 10);
    InQueue(&myQueue, QUEUE_MAX_NUM, 20);
    InQueue(&myQueue, QUEUE_MAX_NUM, 30);
    InQueue(&myQueue, QUEUE_MAX_NUM, 40);
    PrintQueue(&myQueue, QUEUE_MAX_NUM);
    printf("\n");

    /* 2. 出队两个元素 */
    printf("操作2：出队两个元素\n");
    val = OutQueue(&myQueue, QUEUE_MAX_NUM);
    printf("  出队元素: %d\n", val);
    val = OutQueue(&myQueue, QUEUE_MAX_NUM);
    printf("  出队元素: %d\n", val);
    PrintQueue(&myQueue, QUEUE_MAX_NUM);
    printf("\n");

    /* 3. 入队元素: 50, 60, 70 */
    printf("操作3：入队元素 50, 60, 70\n");
    InQueue(&myQueue, QUEUE_MAX_NUM, 50);
    InQueue(&myQueue, QUEUE_MAX_NUM, 60);
    InQueue(&myQueue, QUEUE_MAX_NUM, 70);
    PrintQueue(&myQueue, QUEUE_MAX_NUM);
    printf("\n");

    /* 4. 获取队首元素 */
    printf("操作4：获取队首元素\n");
    val = GetFront(&myQueue, QUEUE_MAX_NUM);
    printf("  队首元素: %d\n", val);
    printf("\n");

    /* 5. 获取队尾元素 */
    printf("操作5：获取队尾元素\n");
    val = GetRear(&myQueue);
    printf("  队尾元素: %d\n", val);
    printf("\n");

    /* 6. 检查队列是否已满 */
    printf("操作6：检查队列是否已满\n");
    if(QueueFull(&myQueue))
        printf("  队列已满\n");
    else
        printf("  队列未满\n");
    printf("\n");

    /* 7. 出队所有元素 */
    printf("操作7：出队所有元素\n");
    printf("  依次出队: ");
    while(!QueueEmpty(&myQueue)){
        val = OutQueue(&myQueue, QUEUE_MAX_NUM);
        printf("%d ", val);
    }
    printf("\n");
    printf("\n");

    /* 8. 检查队列是否为空 */
    printf("操作8：检查队列是否为空\n");
    if(QueueEmpty(&myQueue))
        printf("  队列为空\n");
    else
        printf("  队列非空\n");

    printf("\n===== 程序结束 =====\n");
    return 0;
}
