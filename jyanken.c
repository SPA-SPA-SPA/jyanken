/*猜拳游戏（先赢满3局者胜）*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;          // 玩家
int comp;           // 计算机
int win_no;         // 胜利次数
int lose_no;        // 失败次数
int draw_no;        // 平局次数

char *hd[] = {"石头", "剪刀", "布"};

/*初始处理*/
void initialize(void)
{
    win_no = 0;
    lose_no = 0;
    draw_no = 0;
    srand(time(NULL));
    printf("猜拳游戏开始！");
}

/*运行猜拳游戏*/
void jyanken(void)
{
    int i;
    comp = rand() % 3;                      // 随机生成计算机手势
    
    do
    {
        printf("\n\a石头剪刀布···");
        
        for( i = 0; i < 3; i++)
        {
            printf(" (%d)%s", i, hd[i]);
        }
        printf("：");
        scanf("%d", &human);                // 读取玩家手势
    } while (human < 0 || human > 2);
    
}

/*更新胜利/失败/平局的次数*/
void count_no(int result)
{
    switch(result){
        case 0 : draw_no++;break;           // 平局
        case 1 : lose_no++;break;           // 失败
        case 2 : win_no++;break;            // 胜利
    }
}

/*显示判断结果*/
void disp_result(int result)
{
    switch(result){
        case 0 : puts("平局");break;
        case 1 : puts("你输了");break;
        case 2 : puts("你赢了");break;
    }
}

/*主程序*/
int main(int argc, char const *argv[])
{
    int judge;                      // 胜负
    initialize();                   // 初始处理
    
    do
    {
        jyanken();                  // 运行猜拳游戏
        /*显示计算机与玩家的手势*/
        printf("我出%s，你出%s。\n", hd[comp], hd[human]);
        judge = (human - comp + 3) % 3;                     // 判断胜负
        count_no(judge);                                    // 更新胜利/失败/平局次数
        disp_result(judge);                                 // 显示判断结果
    } while (win_no < 3 && lose_no < 3);
    
    printf(win_no == 3 ? "\n 你赢了。\n" : "\n 我赢了。\n");
    printf("%d胜%d负%d平。\n", win_no, lose_no, draw_no);
    return 0;
}
