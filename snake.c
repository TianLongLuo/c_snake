#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define MAP_WIDTH 20


//食物位置
int food_x,food_y;
typedef struct Snake{
    int X;
    int Y;
    struct Snake* next;
}snake;
//设置光标位置函数
void SetPos(int x,int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void random_food(snake* head);
void move_snake(snake* head);
void map();
snake* InitSnakeBody();
//打印地图
void map()
{
    for(int i=0;i<MAP_WIDTH;i++)
    {
        for(int j=0;j<MAP_WIDTH;j++)
        {
            if(i>0&&i<MAP_WIDTH-1&&j>0&&j<MAP_WIDTH-1)
            {
                printf("  ");
            }else{
                printf("■");
            }
        }
        printf("\n");
    }
}
//打印蛇
snake* InitSnakeBody()
{
    snake* snake_head;
    snake* snake_body1=(snake*)malloc(sizeof(snake));
    snake_body1->X=20;
    snake_body1->Y=10;
    snake_body1->next=NULL;
    snake_head = snake_body1;
    for(int i=1;i<3;i++)
    {
        snake* nextbody=(snake*)malloc(sizeof(snake));
        nextbody->X=20;
        nextbody->Y=snake_head->Y+1;
        nextbody->next=NULL;
        snake_head->next=nextbody;
        snake_head=snake_head->next;
    }
    snake_head = snake_body1;

    while(snake_head!=NULL)
    {
        SetPos(snake_head->X,snake_head->Y);
        printf("□");
        snake_head=snake_head->next;
    }
    return snake_body1;
    
}
void move_snake(snake* head)
{
    int x=0,y=0;
    int x2=0,y2=0;
    char ch;
    snake* snake_head=head;
    snake* snake_body=snake_head;
    while(1)
    {
        if(kbhit())
        {
            ch=getch();
            while(ch=='a')
            {
                if(kbhit()!=0)
                {
                    break;
                }
                x=snake_head->X;
                y=snake_head->Y;
                snake_head->X-=2;
                SetPos(snake_head->X,snake_head->Y);
                printf("□");
                SetPos(x,y);
                printf("  ");
                snake_head=snake_head->next;
                while(snake_head!=NULL)
                {
                    x2=snake_head->X;
                    y2=snake_head->Y;
                    snake_head->X=x;
                    snake_head->Y=y;
                    x=x2;
                    y=y2;
                    SetPos(snake_head->X,snake_head->Y);
                    printf("□");
                    SetPos(x,y);
                    printf("  ");
                    snake_head=snake_head->next;

                }
                Sleep(500);
                snake_head=snake_body;
                if(snake_head->X==food_x&&snake_head->Y==food_y)
                {
                    while(snake_head->next!=NULL)
                    {
                        snake_head=snake_head->next;
                    }
                    snake* newbody=(snake*)malloc(sizeof(snake));
                    
                    newbody->X=snake_head->X;
                    newbody->Y=snake_head->Y;
                    newbody->next=NULL;
                    snake_head->next=newbody;
                    random_food(snake_body);
                }
                snake_head=snake_body;
                if(snake_head->X<=1||snake_head->X>=39||snake_head->Y<=0||snake_head->Y>=20)
                {
                    system("CLS");
                    printf("You are die!!!");
                    break;
                }
            }
            while(ch=='s')
            {
                if(kbhit()!=0)
                {
                    break;
                }
                x=snake_head->X;
                y=snake_head->Y;
                snake_head->Y+=1;
                SetPos(snake_head->X,snake_head->Y);
                printf("□");
                SetPos(x,y);
                printf("  ");
                snake_head=snake_head->next;
                while(snake_head!=NULL)
                {
                    x2=snake_head->X;
                    y2=snake_head->Y;
                    snake_head->X=x;
                    snake_head->Y=y;
                    x=x2;
                    y=y2;
                    SetPos(snake_head->X,snake_head->Y);
                    printf("□");
                    SetPos(x,y);
                    printf("  ");
                    snake_head=snake_head->next;                   
                }
                Sleep(500);
                snake_head=snake_body;
                if(snake_head->X==food_x&&snake_head->Y==food_y)
                {
                    while(snake_head->next!=NULL)
                    {
                        snake_head=snake_head->next;
                    }
                    snake* newbody=(snake*)malloc(sizeof(snake));
                    
                    newbody->X=snake_head->X;
                    newbody->Y=snake_head->Y;
                    newbody->next=NULL;
                    snake_head->next=newbody;
                    random_food(snake_body);
                }
                snake_head=snake_body;
                if(snake_head->X<=1||snake_head->X>=39||snake_head->Y<=0||snake_head->Y>=20)
                {
                    system("CLS");
                    printf("You are die!!!");
                    break;
                }
            }
            while(ch=='d')
            {
                if(kbhit()!=0)
                {
                    break;
                }
                x=snake_head->X;
                y=snake_head->Y;
                snake_head->X+=2;
                SetPos(snake_head->X,snake_head->Y);
                printf("□");
                SetPos(x,y);
                printf("  ");
                snake_head=snake_head->next;
                while(snake_head!=NULL)
                {
                    x2=snake_head->X;
                    y2=snake_head->Y;
                    snake_head->X=x;
                    snake_head->Y=y;
                    x=x2;
                    y=y2;
                    SetPos(snake_head->X,snake_head->Y);
                    printf("□");
                    SetPos(x,y);
                    printf("  ");
                    snake_head=snake_head->next;

                }
                Sleep(500);
                snake_head=snake_body;
                if(snake_head->X==food_x&&snake_head->Y==food_y)
                {
                    while(snake_head->next!=NULL)
                    {
                        snake_head=snake_head->next;
                    }
                    snake* newbody=(snake*)malloc(sizeof(snake));
                    
                    newbody->X=snake_head->X;
                    newbody->Y=snake_head->Y;
                    newbody->next=NULL;
                    snake_head->next=newbody;
                    random_food(snake_body);
                }
                snake_head=snake_body;
                if(snake_head->X<=1||snake_head->X>=39||snake_head->Y<=0||snake_head->Y>=20)
                {
                    system("CLS");
                    printf("You are die!!!");
                    break;
                }
            }
            while(ch=='w')
            {
                if(kbhit()!=0)
                {
                    break;
                }
                x=snake_head->X;
                y=snake_head->Y;
                snake_head->Y-=1;
                SetPos(snake_head->X,snake_head->Y);
                printf("□");
                SetPos(x,y);
                printf("  ");
                snake_head=snake_head->next;
                while(snake_head!=NULL)
                {
                    x2=snake_head->X;
                    y2=snake_head->Y;
                    snake_head->X=x;
                    snake_head->Y=y;
                    x=x2;
                    y=y2;
                    SetPos(snake_head->X,snake_head->Y);
                    printf("□");
                    SetPos(x,y);
                    printf("  ");
                    snake_head=snake_head->next;

                }
                Sleep(500);
                snake_head=snake_body;
                if(snake_head->X==food_x&&snake_head->Y==food_y)
                {
                    while(snake_head->next!=NULL)
                    {
                        snake_head=snake_head->next;
                    }
                    snake* newbody=(snake*)malloc(sizeof(snake));
                    
                    newbody->X=snake_head->X;
                    newbody->Y=snake_head->Y;
                    newbody->next=NULL;
                    snake_head->next=newbody;
                    random_food(snake_body);
                }
                snake_head=snake_body;
                if(snake_head->X<=1||snake_head->X>=39||snake_head->Y<=0||snake_head->Y>=20)
                {
                    system("CLS");
                    printf("You are die!!!");
                    break;               
                }
            }
        }else{
            x=snake_head->X;
            y=snake_head->Y;
            snake_head->Y--;
            SetPos(snake_head->X,snake_head->Y);
            printf("□");
            SetPos(x,y);
            printf("  ");
            snake_head=snake_head->next;
            while(snake_head!=NULL)
            {
                x2=snake_head->X;
                y2=snake_head->Y;
                snake_head->X=x;
                snake_head->Y=y;
                x=x2;
                y=y2;
                SetPos(snake_head->X,snake_head->Y);
                printf("□");
                SetPos(x,y);
                printf("  ");
                snake_head=snake_head->next;

            }
            Sleep(500);
            snake_head=snake_body;
            if(snake_head->X==food_x&&snake_head->Y==food_y)
            {
                while(snake_head->next!=NULL)
                {
                    snake_head=snake_head->next;
                }
                snake* newbody=(snake*)malloc(sizeof(snake));
                
                newbody->X=snake_head->X;
                newbody->Y=snake_head->Y;
                newbody->next=NULL;
                snake_head->next=newbody;
                random_food(snake_body);
            }
            snake_head=snake_body;
            if(snake_head->X<=1||snake_head->X>=39||snake_head->Y<=0||snake_head->Y>=20)
            {
                system("CLS");
                printf("You are die!!!");
                break;
            }
        }
    }
}

void random_food(snake* head)
{
    snake* snake_head=head;
    int how=0;
    while(1)
    {
        srand((unsigned)time(NULL));
        food_x=rand()%34+2;
        if(food_x%2==1)
        {
            food_x+=1;
        }
        food_y=rand()%18+1;
        while(snake_head!=NULL)
        {
            if(food_x!=snake_head->X&&food_y!=snake_head->Y)
            {
                snake_head=snake_head->next;
            }else{
                how = 1;
                break;
            }
        }
        if(how!=1)
        {
            break;
        }
        how=0;
    }
    SetPos(food_x,food_y);
    printf("○");
}

int main()
{
    //隐藏光标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(handle,&CursorInfo);
    //------------------------------------------------
    map();
    snake* head=InitSnakeBody();
    random_food(head);
    move_snake(head);
    SetPos(0,22);
    system("pause");
    return 0;
}
