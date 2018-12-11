#include "student.h"
#include "stu_tea_adm_struct.h"
#include "get_cmd.h"
#include "display.h"
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];


//修改密码
void stu_cha_pass(int i)
{
	printf("请输入新的密码:");
	scanf("%s",stu[i].stu_pass_word);
	puts("修改成功!");
	sleep(1);
	stu[i].is_first=1;
}
//显示个人信息
void inf_my(int i)
{
	printf("姓名：%s  语文：%d  数学：%d  英语：%d  平均分：%.2lf  总分：%d\n",stu[i].name,stu[i].ach_chi,stu[i].ach_mat,stu[i].ach_eng,stu[i].ach_avg,stu[i].ach_sco);
	printf("请按任意键返回...");
	getch();
}

//总分排名
void sco_rank(int i)
{
	printf("您的总分排名是%d\n",stu[i].sco_rank);
	printf("按任意键返回...");
	getch();
}
//数学成绩排名
void mat_rank(int i)
{
	printf("您的数学排名是%d\n",stu[i].mat_rank);
	printf("按任意键返回...");
	getch();
}
//英语成绩排名显示
void eng_rank(int i)
{
	printf("您的英语排名是%d\n",stu[i].eng_rank);
	printf("按任意键返回...");
	getch();
}
//语文成绩排名显示
void chi_rank(int i)
{
	printf("您的语文排名是%d\n",stu[i].chi_rank);
	printf("按任意键返回...");
	getch();
}

//在查询成绩排名时选择科目
void switch_course(int i)
{
	printf("请选择你要查询的项目:");
	printf("1.数学");
	printf("2.英语");
	printf("3.语文");
	printf("4.总分");
	printf("5.返回");
	switch(get_cmd('1','5'))
	{
		case '1':mat_rank(i);break;
		case '2':eng_rank(i);break;
		case '3':chi_rank(i);break;
		case '4':sco_rank(i);break;
		case '5':return;
	}
}

int student_use(int x)
{
	//判断是否第一次登录，是则要求修改
	if(0==stu[x].is_first)
	{
		stu_display();
		puts("您使用的是默认密码，请修改密码:");
	    scanf("%s",stu[x].stu_pass_word);
		puts("修改成功！");
		stu[x].is_first=1;
		sleep(1);
	}
	while(1)
	{
		stu_display();
		//根据输入1～4选择功能
		switch(get_cmd('1','4'))
		{
			case '1':stu_cha_pass(x);break;
			case '2':inf_my(x);break;
			case '3':switch_course(x);break;
			case '4':return 0;break;
		}
	}
}

