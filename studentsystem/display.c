#include <stdio.h>
#include "display.h"
#include "stu_tea_adm_struct.h"
#include <stdlib.h>
extern Teacher tea[50];
void stu_display(void)
{	
	system("clear");
	puts("***学生信息管理***");
	puts("选择序号进行操作：");
	puts("1.改变自己的密码");
	puts("2.查看自己的成绩");
	puts("3.查看成绩排名");
	puts("4.退出，回到登录界面");
	puts("----------------------");
	puts("请输入指令：");
}
void sup_adm_display(void)
{
	system("clear");
	puts("____________O(∩_∩)O____________");
	puts("|❤ ❤ ❤ 欢迎您，超级管理员❤ ❤ ❤ |");
	puts("|☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ ☺ |");
	puts("|       1、添加管理员          |");
	puts("|       2、删除管理员          |");
	puts("|      3、重置管理员密码       |");
	puts("|      4、解锁管理员帐号       |");
	puts("|      5、显示所有管理员       |");
	puts("|          6、退出             |");
	puts("|______________________________|");
	puts("请输入指令：");
}
void nor_adm_display(void)
{
	system("clear");
	puts(" ❀ ❀ ❀ 欢迎您，管理员！❀ ❀ ❀ ");
	puts("|       1、添加教师         |");
	puts("|       2、删除教师         |");
	puts("|      3、修改教师信息      |");
	puts("|      4、重置教师密码      |");
	puts("|      5、解锁教师账号      |");
	puts("|      6、查询教师信息      |");
	puts("|      7、显示在职教师      |");
	puts("|      8、显示离职教师      |");
	puts("|      9、修改登录密码      |");
	puts("|         0、退出           |");
	puts("|~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
}
void menu_display(void)
{
	system("clear");
	puts("♪♪♪♪欢迎使用学生成绩管理系统♪♪♪♪");
	puts("|                              |");
	puts("|           1、学生            |");
	puts("|                              |");
	puts("|           2、教师            |");
	puts("|                              |");
	puts("|          3、管理员           |");
	puts("|                              |");
	puts("|        4、超级管理员         |");
	puts("|                              |");
	puts("|           5、退出            |");
	puts("|______________________________|");
	puts("请输入您的身份（输入相应数字）：");
}
void tea_display(int i){
	system("clear");
	printf("———————————————————————————————————————————\n");
	printf("         欢迎登录学生管理系统,%s           \n",tea[i].name);
	printf("|         输入１进入学生信息系统       	  |\n");
	printf("|         输入２进入学生成绩系统          |\n");
	printf("|         输入３修改密码                  |\n");
	printf("|         输入４退出学生管理系统          |\n");
	printf("|_________________________________________|\n");
}

void tea_inf_func_display(int i){
	system("clear");
	printf("———————————————————————————————————————————————————————————\n");
	printf("         欢迎使用学信息管理理系统,%s                      \n",tea[i].name);
	printf("|         输入１添加学生 （学号，姓名，性别，年龄）        |\n");
	printf("|         输入２删除学生（记作退学）                       |\n");
	printf("|         输入３修改学生基本信息                           |\n");
	printf("|         输入４重置学生密码                               |\n");
	printf("|         输入５解锁学生账户                               |\n");
	printf("|         输入６根据学生姓名查找学生                       |\n");
	printf("|         输入７显示所有在读学生                           |\n");
	printf("|         输入８显示所有退学学生                           |\n");
	printf("|         输入９退出学生信息管理系统                       |\n");
	printf("|__________________________________________________________|\n");
}

void tea_ach_func_display(int i){
	system("clear");
	printf("———————————————————————————————————————————————————————————\n");
	printf("         欢迎使用学生成绩管理系统,%s                       \n",tea[i].name);
	printf("|         输入１录入成绩（语文，数学，英语）               |\n");
	printf("|         输入２修改成绩                                   |\n");
	printf("|         输入３根据学号或姓名查询学生成绩                 |\n");
	printf("|         输入４按各科成绩排名                             |\n");
	printf("|         输入５退出学生成绩管理系统                       |\n");
	printf("|__________________________________________________________|\n");
}
