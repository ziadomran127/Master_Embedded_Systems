/*
 ============================================================================
 Name        : Student_System.c
 Author      : Ziad Abdelhakeem :)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Student_System.h"

#define STUDENTS_NUMBER 50


int main(void)
{
	int select_option;
	FIFO_Buf_st students_queue;
	struct student_info students_buffer[STUDENTS_NUMBER];

	
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	students_sys_init(&students_queue, students_buffer, STUDENTS_NUMBER);
	DPRINTF("HELLO EveryOne :) :) :) :)  Welcome to the Student Management System :) :) :) :) :)\n");
	DPRINTF("\nDo you want to recover last database ?!\n");
	DPRINTF("\t1: Yes\n\t2: No\n");
	DPRINTF("Enter your option please : ");
	scanf("%d",&select_option);

	switch (select_option)
	{
		case 1:	add_student_from_update_file(&students_queue);break;
		case 2: break;
		default:break;
	}



	while(1)
	{
		DPRINTF(" =============================\n");
		DPRINTF("\n Choose on of the following options \n");
		DPRINTF("\n\t 1: Add Student Manually");
		DPRINTF("\n\t 2: Add Student From Text File");
		DPRINTF("\n\t 3: Find Student by Roll Number");
		DPRINTF("\n\t 4: Find Student by First Name");
		DPRINTF("\n\t 5: Find Student by Course ID");
		DPRINTF("\n\t 6: Print Students Number");
		DPRINTF("\n\t 7: Delete Student by Roll Number");
		DPRINTF("\n\t 8: Update Student by Roll Number");
		DPRINTF("\n\t 9: View Students");
		DPRINTF("\n\t 10: Exit");
		DPRINTF("\n\n Enter option number: ");

		scanf("%d",&select_option);
		DPRINTF(" ============================= \n");
		switch(select_option)
		{
			case 1: add_student_manualy(&students_queue);break;
			case 2: add_student_from_file(&students_queue);break;
			case 3: find_student_by_roll(&students_queue);break;
			case 4: find_student_by_firstname(&students_queue);break;
			case 5: find_student_by_course(&students_queue);break;
			case 6: print_students_count(&students_queue);break;
			case 7: delete_student_by_roll(&students_queue);break;
			case 8: update_student_by_roll(&students_queue);break;
			case 9: show_students_info(&students_queue);break;
			case 10: update_student_file(&students_queue); return 0;
			default: DPRINTF("\n Wrong Option :( :( :( Try Again \n\n");break;
		}
	}
	return 0;
}
