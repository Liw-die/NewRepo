#ifndef STU_H_ 
#define STU_H_
//一级界面显示字符
#define STU_STR "STU_MAN_SYSTEM"
#define STU_WELCOME "     Welcome to the Student Management System   "
#define STU_1	    "                                                "
#define STU_INCER 	" Increase student Information "//新增
#define STU_QUERY 	" Query    Student Information "//删除
#define STU_FIND 	" Find     Student Information "//查找
#define STU_MODIFY 	" Modify   Student Information "//修改
#define STU_INTE 	"-->"
#define STU_CHAR 	4

//二级界面显示字符
#define _STU_INCER 	"          Increase student Information          "
#define _STU_QUERY 	"          Query    Student Information          "
#define _STU_FIND 	"          Find     Student Information          "//查找
#define _STU_MODIFY "          Modify   Student Information          "//修改
#define _name 	" Please name: "//name新增
#define _age 	" Please age: "	//age新增
#define _id	 	" Please id: "	//id新增
#define _stu_prosper	" stu prosper! "//学生新增成功
#define _stu_fail	" stu fail! "//学生新增失败

#define delete_name	" delete name: "//按名字删除
#define delete_id	" delete id: "//按id删除
#define delete_fail	" Delete Fail!"//删除失败提示字符
#define delete_prosper	" Delete Prosper!"//删除成功提示字符

#define seek_name " Seek Name: "//按姓名查找
#define seek_id " Seek id: "	 //按id查找
#define seek_fail " Seek fail! "	 //查找失败
#define seek_prosper " Seek Prosper! "	 //查找成功

#define amend_name " Amend Name: "//修改姓名
#define amend_id " Amend id: "	 //id修改
#define amend_fail "Successfully modified!"	 //修改成功

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STU.h"
#define uint_32 unsigned int 
#define COO_X 20 //外框的原点坐标X
#define COO_Y 5	 //外框的原点坐标y
#define STU_INTE 	"-->"
#define STU_CHAR 	4

//显示外框
void color_profile();

//一级字符串显示
void show_stu_char();

//一级界面按键检测
void key_show_inte();

//一级界面箭头
void show_stu_inte(int i);

//二级新增界面显示
void show_please();

//二级删除界面显示
void show_delete();

//二级查找界面显示
void show_seek();

//二级修改界面显示
void show_amend();

//显示操作函数
void show_stu();

//清屏函数
void Clear_screen();

#endif // 结束条件编译
