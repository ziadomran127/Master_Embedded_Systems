/*
 ============================================================================
 Name        : Linked_List.c
 Author      : Ziad abdelhakeem
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

#define DPRINTF(...)     {fflush(stdout); \
						  fflush(stdin); \		
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}
					  

struct Sdata {
	int Id ;
	char Name[40] ;
	float Height ;
};

struct Sstudent
{
	struct Sdata Student ;
	struct Sstudent* next ;
};


void Fill_The_Record(struct Sstudent* New_Student ) 
{
	char temp_text[40] ;
	DPRINTF("\n Enter The ID : ") ;
	gets(temp_text) ;
	New_Student->Student.Id = atoi(temp_text) ; 

	DPRINTF("\n Enter Student Name :  ") ;
	gets(New_Student->Student.Name) ;

	DPRINTF("\n Enter Student Height : ") ;
	gets(temp_text) ;
	New_Student->Student.Height = atof(temp_text) ;
	
}


struct Sstudent* First = NULL ;

void Add_Student ()
{
	struct Sstudent* New_Student ;
	struct Sstudent* Last ;

	if(First == NULL){
	New_Student = (struct Sstudent*)malloc( sizeof(struct Sstudent) ) ;
	First = New_Student ;
	}
	else 
	{
		Last = First ;
		while(Last->next) 
		{
			Last = Last->next ;
		}
		New_Student = (struct Sstudent*)malloc( sizeof(struct Sstudent) ) ;
		Last->next = New_Student ;
		
	}
	Fill_The_Record(New_Student) ;
	New_Student->next = NULL;
}


int Delete_Student()
{
	char temp_text[20] ;
	int i , selected_id ;
	DPRINTF("\n Enter id to be deleted : ") ;
	gets(temp_text) ;
	selected_id = atoi(temp_text) ;


	if(First)
	{
		struct Sstudent* Pprevious = NULL ;
		struct Sstudent* Pselected = First ;

		while (Pselected)
		{
			if (Pselected->Student.Id == selected_id)
			{
				if(Pprevious)
				{
					Pprevious->next = Pselected->next ;
				}
				else
				{
					First = Pselected->next ;
				}
				free(Pselected) ;
				return 1 ;
			}
				Pprevious = Pselected ;
				Pselected = Pselected->next ;			
		}
	} 
		DPRINTF("\n  Cannot find Student ID   ") ;
		return 0 ;

}



void view_Students()
{
	int count = 0 ; 
	struct Sstudent* Pcurrent = First ;
	if(First ==NULL) 
	DPRINTF(" It,s an empty list :( ");

	while (Pcurrent)
	{
		DPRINTF("=====================") ;
		DPRINTF("\n Record Number = %d" , count+1 ) ;
		DPRINTF("\n ID = %d" , Pcurrent->Student.Id ) ;
		DPRINTF("\n Name = %s" , Pcurrent->Student.Name ) ;
		DPRINTF("\n Height  = %f" , Pcurrent->Student.Height ) ;
		DPRINTF("=====================") ;
		Pcurrent = Pcurrent->next ;
		count++ ;
	}
	
}


void Delete_All()
{
	struct Sstudent* Pcurrent = First ;
	if(First ==NULL) 
	DPRINTF(" It,s an empty list :( ");

	while (Pcurrent)
	{
		struct Sstudent* Ptemp = Pcurrent ;
		Pcurrent = Pcurrent->next ;
		free(Ptemp) ;
		
		
	}
	First = NULL ; 

}

int LengthOfList() 
{
	if(First == NULL)
	{
		printf("\nThe linkedList is empty ") ;
		return 0 ;
	}
	
	
	unsigned int count = 0 ;
	struct Sstudent* Pcurrent = First ;
	while (Pcurrent!=NULL)
	{
		count++ ;
		Pcurrent = Pcurrent->next ;
	}
	return count ;
}
int Nth_Node_From_End(unsigned int n)
{
    struct Sstudent* Pcurrent = First;
    unsigned int Length = LengthOfList();

    if (First == NULL)
    {
        DPRINTF("\nThe linked list is empty.\n");
        return 0;
    }

    if (n > Length)
    {
        DPRINTF("\nInvalid value! The list has only %d nodes.\n", Length);
        return 0;
    }

    unsigned int target_index = Length - n ;  
    unsigned int count = 0;

    
    while (Pcurrent != NULL)
    {
        if (count == target_index)
        {
            DPRINTF("=====================\n");
            DPRINTF("Record Number = %d\n", count + 1);
            DPRINTF("ID = %d\n", Pcurrent->Student.Id);
            DPRINTF("Name = %s\n", Pcurrent->Student.Name);
            DPRINTF("Height  = %f\n", Pcurrent->Student.Height);
            DPRINTF("=====================\n");
            return 1;
        }
        count++;
        Pcurrent = Pcurrent->next;
    }

    return 0;  
}

struct Sdata* Get_Nth( unsigned int index)
{
    struct Sstudent* Pcurrent = First;
    unsigned int count = 0;
	
    
    if (First == NULL)
    {
        DPRINTF("\nThe linked list is empty.\n");
        return NULL;
    }

    while (Pcurrent != NULL)
    {
        if (count == index)
        {
            
            return &(Pcurrent->Student);
        }
        count++;
        Pcurrent = Pcurrent->next;
    }

    
    DPRINTF("\nIndex %d is out of bounds.\n", index);
    return NULL;
}


void main()
{
    char temp_text[40];

    while(1)
    {
        DPRINTF("\n=======================");
        DPRINTF("\n\t Choose on of the following Options \n");
        DPRINTF("\n 1: AddStudent ");
        DPRINTF("\n 2: Delete_Student ");
        DPRINTF("\n 3: view_students ");
        DPRINTF("\n 4: DeleteAll ");
		DPRINTF("\n 5: View Length of list ");
		DPRINTF("\n 6: View the i th choosen") ;
        DPRINTF("\n Enter Option Number :");

        gets (temp_text);
        DPRINTF("\n =======================");

        switch (atoi (temp_text))
        {
        case 1:
            Add_Student();
            break;
        case 2:
            Delete_Student();
            break;
        case 3:
            view_Students();
            break;
        case 4:
            Delete_All();
            break;
			case 5:
            DPRINTF("\n Total number of student = %d" , LengthOfList());
            break;
			case 6:
    DPRINTF("\n Enter the index of the node: ");
    gets(temp_text);
    struct Sdata* result = Get_Nth(atoi(temp_text));

    if (result != NULL)
    {
        DPRINTF("=====================\n");
        DPRINTF("ID = %d\n", result->Id);
        DPRINTF("Name = %s\n", result->Name);
        DPRINTF("Height  = %f\n", result->Height);
        DPRINTF("=====================\n");
    }
    break;

        default:
            DPRINTF("\n wrong option ");
            break;
        }
    }
}
