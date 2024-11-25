/*
 * Student_System.c
 *
 *  Created on: Nov 24, 2024
 *      Author: Ziad Abdelhakeem :)
 */

#include "Student_System.h"

FILE *students_file, *updated_students_file;

static void print_student_info(struct student_info *student);
static struct student_info *search_student_by_roll(FIFO_Buf_st *students_queue, int roll);


FIFO_Status_st students_sys_init(FIFO_Buf_st *students_queue, Item *item, int length)
{
	// Check parameters validity
	if(!students_queue || !item || !length)
	{
		DPRINTF("Student System Queue Initialization Failed\n");
		return FIFO_NULL;
	}

	// FIFO Initialization process
	students_queue->base = item;
	students_queue->head = students_queue->base;
	students_queue->tail = students_queue->base;
	students_queue->length = length;
	students_queue->counter = 0;

	DPRINTF("Student System Queue Initialization Passed\n");
	return FIFO_NO_ERROR;
}


void add_student_from_file(FIFO_Buf_st *students_queue)
{
	Item new_student;
	int i;

	// Opening a student.txt file with option read
	students_file = fopen("students.txt", "r");

	// Check if the file exist and there is data or not
	if(students_file == NULL)
	{
		DPRINTF("\n  SORRY :( :( :(   student.txt file not found. \n");
		DPRINTF("\n  SORRY :( :( :(   adding students from file failed. \n");
		return;
	}

	// Reading students until end of file this using of feof == Check end of file
	while(!feof(students_file))
	{
		// Reading roll number of the student
		fscanf(students_file, "%d", &new_student.roll_number);

		// Check if the roll number is exists
		if(search_student_by_roll(students_queue, new_student.roll_number) != NULL)
		{
			// Printing that we find a number with other student
			DPRINTF("\n SORRY :( :( :(   Roll number %d is already taken\n", new_student.roll_number);

			// Ignore the rest of the line
			fscanf(students_file, "%*[^\n]");

			// Start over form next line in text file
			continue;
		}

		// Reading data first name, last name and GPA sequential
		fscanf(students_file, "%s", new_student.first_name);
		fscanf(students_file, "%s", new_student.last_name);
		fscanf(students_file, "%f", &new_student.GPA);

		// Reading course IDs
		for (i = 0; i < COURSES_NUMBER; ++i)
		{
			fscanf(students_file, "%d", &new_student.course_id[i]);
		}

		// Enqueue new student
		if((FIFO_enqueue(students_queue, new_student))== FIFO_NO_ERROR)
		{
			DPRINTF("\n[INFO] Roll number %d is saved successfully\n", new_student.roll_number);
		}
		else
		{
			DPRINTF("\n SORRY :( Adding students by file failed :( :( \n");
			return;
		}
	}

	DPRINTF("\n[INFO] Students details are Saved Successfully  :) :) :) \n");

	// Closing the file
	fclose(students_file);
}





void add_student_manualy(FIFO_Buf_st *students_queue)
{
	Item new_student;
	int i;

	DPRINTF("\n=== Please Enter  student data ===\n");
	DPRINTF("\tPlease Enter  roll number: ");
	scanf("%d", &new_student.roll_number);

	// Scan if the roll number which Please Enter ed is exist
	if(search_student_by_roll(students_queue, new_student.roll_number))
	{
		DPRINTF("\n SORRY :( :( :(   Roll number %d is already taken\n", new_student.roll_number);
		DPRINTF("\n SORRY :( :( :(   Adding student manually failed\n");
		return;
	}

	// If not, Continue reading other data
	DPRINTF("\tPlease Enter  first name: ");
	scanf("%s", new_student.first_name);

	DPRINTF("\tPlease Enter  second name: ");
	scanf("%s", new_student.last_name);

	DPRINTF("\tPlease Enter  GPA: ");
	scanf("%f", &new_student.GPA);

	DPRINTF("\tPlease Enter  Courses IDs\n");
	for (i = 0; i < COURSES_NUMBER; ++i)
	{
		DPRINTF("\t\tPlease Enter  Courses no.%d: ",i+1);
		scanf("%d", &new_student.course_id[i]);
	}

	// Add new student
	if(FIFO_enqueue(students_queue, new_student) == FIFO_NO_ERROR)
	{
		DPRINTF("\n[INFO] Student details us saved successfully\n");
	}
	else
	{
		DPRINTF("\n SORRY :( :( :(   Adding students manually failed\n");
		return;
	}
}


void find_student_by_firstname(FIFO_Buf_st *students_queue)
{
	Item *student = students_queue->tail;
	char input_name[NAME_LENGTH], i;

	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Find student by first name failed\n");
		return;
	}

	DPRINTF("\nPlease Enter  First Name: ");
	scanf("%s",input_name);

	// Loop inside queue
	for (i = 0; i < students_queue->counter; ++i)
	{
		// Compare between two string the input name and the name in queue to search about it
		if (!(strcmp(input_name, student->first_name)))
		{
			print_student_info(student);
			return;
		}
		else
		{
			DPRINTF("\n SORRY :( :( :(   %s in not found\n",input_name);
			return;
		}

		// Check if we reach the last item in the queue
		if((student +1) == (students_queue->base + students_queue->length))
		{
			// Set to the start
			student = students_queue->base;
		}
		else
		{
			// Just go to the next tail :D
			student++;
		}
	}
}



void find_student_by_roll(FIFO_Buf_st *students_queue)
{
	int input_number;
	Item *student;
	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Find student by roll number failed\n");
		return;
	}

	// Please Enter  roll number you want to find
	DPRINTF("\nPlease Enter  roll number: ");
	scanf("%d", &input_number);

	// Scan in the queue to find this roll number
	student = search_student_by_roll(students_queue, input_number);

	// Check if we find roll number in the queue
	if (student == NULL)
	{
		DPRINTF("\n SORRY :( :( :(   Roll number %d in not found\n", input_number);
		return;
	}
	else
	{
		// If we found the roll number lets print all data
		print_student_info(student);
	}
}


void find_student_by_course(FIFO_Buf_st *students_queue)
{
	Item *student;
	int input_id, i, j, number_enroled_student = 0;

	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Find student by course failed\n");
		return;
	}

	// Get the ID want to search about
	DPRINTF("\nPlease Enter  Course ID: ");
	scanf("%d", &input_id);

	// Loop inside queue
	student = students_queue->tail;
	for (i = 0; i < students_queue->counter; ++i)
	{
		// Scan inside every item
		for(j = 0; j < COURSES_NUMBER; ++j)
		{
			// Check if we find student have this ID
			if(student->course_id[j] == input_id)
			{
				print_student_info(student);
				number_enroled_student++;
				DPRINTF("\n");
				break;
			}
		}

		// Check if we reach the last item in the queue
		if((student +1) == (students_queue->base + students_queue->length))
		{
			// Set to the start
			student = students_queue->base;
		}
		else
		{
			// Just go to the next tail :D
			student++;
		}
	}

	// Check if not found in any student
	if(number_enroled_student == 0)
	{
		DPRINTF("\n SORRY :( :( :(   Course id %d is not found\n", input_id);
	}
	else
	{
		DPRINTF("\n[INFO] Total number of students enrolled: %d\n", number_enroled_student);
	}
}


void update_student_by_roll(FIFO_Buf_st *students_queue)
{
	Item *update_student, *student;
	int i, input_roll , input_option, input_new_roll, flag = 0;

	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Delete student by roll number failed\n");
		return;
	}

	// Please Enter  roll number you want to update
	DPRINTF("\nPlease Enter  roll number: ");
	scanf("%d", &input_roll);

	// Search about the input roll to get its whole item
	update_student = search_student_by_roll(students_queue, input_roll);

	// Check if we find roll number in the queue
	if (update_student == NULL)
	{
		DPRINTF("\n SORRY :( :( :(   Roll number %d in not found\n", input_roll);
		return;
	}
	else
	{
		// If we found the roll number lets print all data
		DPRINTF("\n==== Student data ====\n");
		print_student_info(update_student);
	}

	DPRINTF("\nWhich date do you want to change ?\n");
	DPRINTF("\t 1: The Roll Number\n");
	DPRINTF("\t 2: The First Name\n");
	DPRINTF("\t 3: The Second Name\n");
	DPRINTF("\t 4: The GPA Score\n");
	DPRINTF("\t 5: The Courses ID\n");
	DPRINTF("Please Enter  your option: ");

	// Get the option
	scanf("%d",&input_option);
	switch (input_option)
	{
		case 1:
			DPRINTF("Please Enter  the new roll number: ");
			scanf("%d",&input_new_roll);

			student = students_queue->tail;
			// Loop inside the queue
			for (i = 0; i < students_queue->counter; ++i)
			{
				// Check if we find the the roll we search about to break
				if (student->roll_number == input_new_roll)
				{
					// Get out form for loop
					DPRINTF("\n SORRY :( :( :(   This Roll Number %d is exist\n",input_new_roll);

					// If we find a roll number match set flag
					flag = 1;
					break;
				}

				// Check if we reach the last item in the queue
				if((student + 1) == (students_queue->base + students_queue->length))
				{
					student = students_queue->base;
				}
				else
				{
					// Just go to the next tail :D
					student++;
				}
			}

			// If the flag doesn't changed this mean that no roll number match
			if(flag == 0)
			{
				update_student->roll_number = input_new_roll;
				DPRINTF("\n[INFO] The Roll Number %d in updated successfully\n", input_new_roll);
			}
			break;

		case 2:
			DPRINTF("Please Enter  the new first name: ");
			scanf("%s", update_student->first_name);
			DPRINTF("\n[INFO] The First Name %s in updated successfully\n",update_student->first_name);
			break;

		case 3:
			DPRINTF("Please Enter  the new last name: ");
			scanf("%s", update_student->last_name);
			DPRINTF("\n[INFO] The Last Name %s in updated successfully\n",update_student->last_name);
			break;

		case 4:
			DPRINTF("Please Enter  the new GPA: ");
			scanf("%f", &update_student->GPA);
			DPRINTF("\n[INFO] The GPA Score %0.1f in updated successfully\n", update_student->GPA);
			break;

		case 5:
			DPRINTF("Please Enter  the course number from %d to %d: ", 1, COURSES_NUMBER);
			scanf("%d", &input_option);
			DPRINTF("Please Enter  the new course id: ");
			scanf("%d", &update_student->course_id[input_option - 1]);
			DPRINTF("\n[INFO] The Course ID %d in updated successfully\n", update_student->course_id[input_option - 1]);
			break;

		default:
			break;
	}
}

// Update students and what we do in file
void update_student_file(FIFO_Buf_st *students_queue)
{
	Item *student;
	int i, j;

	// Opening a update_students.txt file with w option to write in it
	updated_students_file = fopen("update_students.txt", "w");

	// Check if the file exist and there is data or not
	if(students_file == NULL)
	{
		DPRINTF("\n  SORRY :( :( :(   update_students.txt create failed. \n");
		DPRINTF("\n  SORRY :( :( :(   update students file failed. \n");
		return;
	}

	student = students_queue->tail;
	// Loop inside the queue
	for (i = 0; i < students_queue->counter; ++i)
	{
		// Write into file
		DPRINTF(updated_students_file, "%d ", student->roll_number);
		DPRINTF(updated_students_file, "%s ", student->first_name);
		DPRINTF(updated_students_file, "%s ", student->last_name);
		DPRINTF(updated_students_file, "%0.1f ", student->GPA);

		for(j = 0; j < COURSES_NUMBER ; ++j)
		{
			DPRINTF(updated_students_file, "%d ", student->course_id[j]);
		}

		// New line after every Item
		DPRINTF(updated_students_file, "\n");

		// Check if we reach the last item in the queue
		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			// Just go to the next tail :D
			student++;
		}

	}
	DPRINTF("\n[INFO] Update Students details are saved in file successfully\n");

	// Closing the file
	fclose(updated_students_file);
}


void add_student_from_update_file(FIFO_Buf_st *students_queue)
{
	Item new_student;
	int i;

	// Opening a update_students.txt file with option read
	updated_students_file = fopen("update_students.txt", "r");

	// Check if the file exist and there is data or not
	if(updated_students_file == NULL)
	{
		DPRINTF("\n  SORRY :( :( :(   updated_students_file.txt file not found. \n");
		DPRINTF("\n  SORRY :( :( :(   adding students from update file failed. \n");
		return;
	}

	// Reading students until end of file this using of feof == Check end of file
	while(!feof(updated_students_file))
	{
		// Reading roll number of the student
		fscanf(updated_students_file, "%d", &new_student.roll_number);

		// Check if the roll number is exists
		if(search_student_by_roll(students_queue, new_student.roll_number) != NULL)
		{
			// Printing that we find a number with other student
			DPRINTF("\n SORRY :( :( :(   Roll number %d is already taken\n", new_student.roll_number);

			// Ignore the rest of the line
			fscanf(updated_students_file, "%*[^\n]");

			// Start over form next line in text file
			continue;
		}

		// Reading data first name, last name and GPA sequential
		fscanf(updated_students_file, "%s", new_student.first_name);
		fscanf(updated_students_file, "%s", new_student.last_name);
		fscanf(updated_students_file, "%f", &new_student.GPA);

		// Reading course IDs
		for (i = 0; i < COURSES_NUMBER; ++i)
		{
			fscanf(updated_students_file, "%d", &new_student.course_id[i]);
		}

		// Enqueue new student
		if((FIFO_enqueue(students_queue, new_student))== FIFO_NO_ERROR)
		{
			DPRINTF("\n[INFO] Roll number %d is saved successfully\n", new_student.roll_number);
		}
		else
		{
			DPRINTF("\n SORRY :( :( :(   Adding students by update file failed\n");
			return;
		}
	}

	DPRINTF("\n[INFO] Students Recover are saved successfully\n");

	// Closing the file
	fclose(updated_students_file);
}


static struct student_info *search_student_by_roll(FIFO_Buf_st *students_queue, int roll)
{
	int i ;
	// we start from the tail because form base we can fine that there is no data stored / removed
	Item *student = students_queue->tail;

	// Loop inside the queue
	for (i = 0; i < students_queue->counter; ++i)
	{
		// Check if we find the the roll we search about to break
		if (student->roll_number == roll)
		{
			// Get out form for loop
			break;
		}

		// Check if we reach the last item in the queue
		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			// Just go to the next tail :D
			student++;
		}
	}

	// Check if we couldn't fine the roll number and we reach last item
	if(i == students_queue->counter)
	{
		// Return NULL
		student = ((void*)0);
	}

	// Return the struct of the roll we found
	return student;
}


void delete_student_by_roll(FIFO_Buf_st *students_queue)
{
	int input_number, i, flag = 0;
	Item *student;

	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Delete student by roll number failed\n");
		return;
	}

	// Please Enter  roll number you want to delete
	DPRINTF("\nPlease Enter  roll number: ");
	scanf("%d", &input_number);

	student = students_queue->base;
	// Loop inside queue
	for (i = 0; i < students_queue->counter; ++i)
	{
		if(student->roll_number == input_number)
		{
			// Deleting student
			*student = *(students_queue->tail);

			// Update counter of queue
			students_queue->counter--;

			// Check if we reach the last item in the queue
			if((students_queue->tail + 1) == (students_queue->base + students_queue->length))
			{
				// Set to the start
				students_queue->tail = students_queue->base;
			}
			else
			{
				// Just go to the next tail :D
				students_queue->tail++;
			}

			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
		student++;
	}

	if(flag == 1)
	{
		DPRINTF("\n[INFO] The Roll Number is removed successfully\n");
	}
	else
	{
		DPRINTF("\n SORRY :( :( :(   This Roll Number %d not found\n",input_number);
	}
}



void show_students_info(FIFO_Buf_st *students_queue)
{
	Item *student;
	char i;
	FIFO_Status_st queue_status;

	// Checking if the queue is empty
	queue_status = FIFO_is_empty(students_queue);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		DPRINTF("\n SORRY :( :( :(   Show students info failed\n");
		return;
	}

	DPRINTF("\nAll Students\n\n");

	student = students_queue->tail;
	for (i = 0; i < students_queue->counter; ++i)
	{
		print_student_info(student);
		DPRINTF("\n");

		// Check if we reach the last item in the queue
		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			// Just go to the next tail :D
			student++;
		}
	}
}




void print_students_count(FIFO_Buf_st *students_queue)
{
	int counter = students_queue->counter;
	int capacity = students_queue->length;

	DPRINTF("[INFO] Total number of students is %d\n", counter);
	DPRINTF("[INFO] You can add up to %d students\n", capacity);
	DPRINTF("[INFO] You can add %d more students\n", capacity - counter);

}




static void print_student_info(struct student_info *student)
{
	int i;

	DPRINTF("The student details are\n");
	DPRINTF("\tFirst Name: %s\n", student->first_name);
	DPRINTF("\tLast Name: %s\n", student->last_name);
	DPRINTF("\tRoll Number: %d\n", student->roll_number);
	DPRINTF("\tGPA: %0.1f\n", student->GPA);
	DPRINTF("\tCourses IDs are\n");

	for(i = 0; i < COURSES_NUMBER; i++)
	{
		DPRINTF("\t\tCourse %d id: %d\n", i + 1, student->course_id[i]);
	}
}



FIFO_Status_st FIFO_enqueue(FIFO_Buf_st *fifo_buf, Item item)
{
	// Check parameters validity
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		DPRINTF("FIFO Enqueue failed: Null is passed\n");

		return FIFO_NULL;
	}

	// Check if FIFO is Full ?!
	if((FIFO_is_full(fifo_buf)) == FIFO_FULL)
	{
		DPRINTF("FIFO Enqueue failed: FIFO is full\n");

		return FIFO_FULL;
	}

	// Enqueue new item
	*(fifo_buf->head) = item;

	if((fifo_buf->head + 1) == (fifo_buf->base + fifo_buf->length)) // Check if the head in the end of fifo to start over
	{
		fifo_buf->head = fifo_buf->base;
	}
	else
	{
		fifo_buf->head++;
	}

	fifo_buf->counter++;

	return FIFO_NO_ERROR;
}





FIFO_Status_st FIFO_is_empty(FIFO_Buf_st *fifo_buf)
{
	// Check parameters validity
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		DPRINTF("FIFO is empty failed :( Null is passed\n");

		return FIFO_NULL;
	}

	// Check if the number of items is zero
	if(fifo_buf->counter == 0)
	{
		return FIFO_EMPTY;
	}

	return FIFO_NOT_EMPTY;
}



FIFO_Status_st FIFO_is_full(FIFO_Buf_st *fifo_buf)
{
	// Check parameters validity
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail )
	{
		DPRINTF("FIFO is full failed  :( Null is passed\n");

		return FIFO_NULL;
	}

	// Check if the number of items matches the total buffer length
	if(fifo_buf->counter == fifo_buf->length)
	{
		return FIFO_FULL;
	}

	return FIFO_NOT_FULL;
}
