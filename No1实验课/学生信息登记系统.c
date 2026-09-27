#include <stdio.h>
#include <string.h>

#define LIST_MAX_NUM 100

// 定义学生结构体
typedef struct
{
    char id[20];
    char name[20];
} Student;

// 定义顺序表
typedef struct
{
    Student data[LIST_MAX_NUM];
    int length;
} Linear_List_Type;

// 菜单函数
void printMenu()
{
    printf("\n=== 学生名册管理系统 ===\n");
    printf("0. 录入学生信息\n");
    printf("1. 插入学生信息\n");
    printf("2. 删除学生信息\n");
    printf("3. 查找学生信息\n");
    printf("4. 显示所有学生信息\n");
    printf("5. 退出\n");
    printf("========================\n");
    printf("请选择操作: ");
}

// 初始化顺序表
void InitList(Linear_List_Type *p)
{
    p->length = 0;
}

// 0. 录入学生信息
void InputStudent(Linear_List_Type *p)
{
    int n;
    printf("请输入要录入的学生人数: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (p->length >= LIST_MAX_NUM)
        {
            printf("学生名册已满，无法添加新学生信息。\n");
            break;
        }

        // 插入位置为当前长度
        int index = p->length + i;

        printf("请输入第 %d 个学生的学号: ", index + 1);
        scanf("%s", p->data[index].id);

        printf("请输入第 %d 个学生的姓名: ", index + 1);
        scanf("%s", p->data[index].name);

        p->length++;
    }
    printf("学生信息录入完成\n");
}

// 1. 插入学生信息
void InsertList(Linear_List_Type *p, int i, Student s)
{
    // 判断顺序表是否已满
    if (p->length >= LIST_MAX_NUM)
    {
        printf("表已满\n ");
        return;
    }
    // 判断插入位置是否合法
    if ((i < 1) || (i > p->length + 1))
    {
        printf("插入位置不合法\n ");
        return;
    }
    // 将第i个元素及其之后的元素后移一位
    for (int k = p->length; k >= i; k--)
    {
        p->data[k] = p->data[k - 1];
    }
    // 插入新元素
    p->data[i - 1] = s;
    // 更新顺序表长度
    p->length++;
}

// 2. 删除学生信息
void DeleteList(Linear_List_Type *p, int i)
{
    // 判断顺序表是否为空
    if (p->length == 0)
    {
        printf("表为空\n ");
        return;
    }
    // 判断删除位置是否合法
    if ((i < 1) || (i > p->length))
    {
        printf("删除位置不合法\n ");
        return;
    }
    // 打印删除前的学生信息
    printf("删除前的学生信息:\n");
    for (int k = 0; k < p->length; k++)
    {
        printf("学号: %s, 姓名: %s\n", p->data[k].id, p->data[k].name);
    }

    // 删除第i个元素
    int k;
    for (k = i; k < p->length; k++)
    {
        p->data[k - 1] = p->data[k];
    }
    // 更新顺序表长度
    p->length--;

    // 打印删除后的学生信息
    printf("删除后的学生信息:\n");
    for (k = 0; k < p->length; k++)
    {
        printf("学号: %s, 姓名: %s\n", p->data[k].id, p->data[k].name);
    }
    return;
}

// 3. 查找学生信息
int LocateElem(Linear_List_Type *p, char *id)
{
    for (int i = 0; i < p->length; i++)
    {
        if (strcmp(p->data[i].id, id) == 0)
        {
            return i + 1; // 返回位置，位置从1开始
        }
    }
    return -1;
}

// 4. 显示所有学生信息
void DisplayList(Linear_List_Type *p)
{
    if (p->length == 0)
    {
        printf("学生名册为空。\n");
        return;
    }
    printf("学生信息列表:\n");
    for (int i = 0; i < p->length; i++)
    {
        printf("学号: %s, 姓名: %s\n", p->data[i].id, p->data[i].name);
    }
}

int main()
{
    Linear_List_Type my_list;
    InitList(&my_list);
    int choice;
    while (1)
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            InputStudent(&my_list);
            break;
        case 1:
        {
            Student s;
            int pos;
            printf("请输入要插入的学生学号: ");
            scanf("%s", s.id);
            printf("请输入要插入的学生姓名: ");
            scanf("%s", s.name);
            printf("请输入要插入的位置(从1开始): ");
            scanf("%d", &pos);
            InsertList(&my_list, pos, s);
            break;
        }
        case 2:
        {
            int pos;
            printf("请输入要删除的学生位置(从1开始): ");
            scanf("%d", &pos);
            DeleteList(&my_list, pos);
            break;
        }
        case 3:
        {
            char id[20];
            printf("请输入要查找的学生学号: ");
            scanf("%s", id);
            int pos = LocateElem(&my_list, id);
            if (pos != -1)
                printf("学生信息在第 %d 个位置。\n", pos);
            else
                printf("未找到该学生信息。\n");
            break;
        }
        case 4:
            DisplayList(&my_list);
            break;
        case 5:
            printf("退出系统。\n");
            return 0;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }
    return 0;
}
