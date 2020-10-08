#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
	int math;
	int chemistry;
	int english;

}degrees;

typedef struct
{
	char student_name[20];
	int student_ID;
	degrees student_degrees;
	struct student_info* next_student;
}student_info;

void Add_student();
void Delete_Node(int ID);
void Search_LinkedList(int ID);

struct student_info* gbfirst_student = NULL;
//struct student_info* gblast_student =NULL;
//struct student_info* new_student = NULL;





int main()
{
	Add_student();

	return 0;
}




/*
function that add a link
*/
void Add_student()
{
	student_info* new_student=(student_info*)gbfirst_student ;
	//student_info* gbfirst_student;
	static student_info* gblast_student = NULL;
	//FIRST NODE
	if ((student_info*)gbfirst_student == NULL)
	{
		student_info* new_student = (student_info*)malloc(sizeof(student_info));
		gbfirst_student = (struct student_info*)new_student;
		//new_student->next_student = NULL;
		gblast_student = new_student;

	}
	else
	{
		/*while (gblast_student->next_student!=NULL)
		{
			gblast_student =(student_info*)gblast_student->next_student;
		}
		*/
		new_student = (student_info*)malloc(sizeof(student_info));
		//new_student->next_student = NULL;
		gblast_student->next_student = (struct student_info*)new_student;
		gblast_student = new_student;

	}



	printf("please enter the sudent name");
	fflush(stdin);
	scanf("%s" ,new_student->student_name );
	//gets(new_student->student_name);
	printf("\nenter the ID");
	fflush(stdin);
	scanf("%d", &new_student->student_ID);
	printf("\nenter the degrees");
	printf("\n math degree:");
	fflush(stdin);
	scanf("%d", &new_student->student_degrees.math);
	printf("\n chemistry degree:");
	fflush(stdin);
	scanf("%d", &new_student->student_degrees.chemistry);
	printf("\n english degree:");
	fflush(stdin);
	scanf("%d", &new_student->student_degrees.english);
	new_student->next_student = NULL;



}



void Search_LinkedList(int ID)
{
	//student_info* new_student;
	//student_info* gbfirst_student;
	//student_info* gblast_student;
	student_info* ps = (student_info*)gbfirst_student;
	int done = 0;
	if ((struct student_info*)gbfirst_student == NULL)
	{
		printf("the linked list is empty\n");
	}
	else
	{
		while (ps->next_student != 0)
		{
			if (ID == ps->student_ID)
			{
				done = 1;
				break;
			}
			else
			{
				done = 0;
			}
			ps = (student_info*)ps->next_student;
		}
		if (done == 0)
		{
			printf("your Id is not in the linked list");
		}
		else
		{
			printf("\nID:%d\nmath degree:%d\nchemistry degree:%d\nenglish degree:%d\n", ps->student_ID, ps->student_degrees.math, ps->student_degrees.chemistry, ps->student_degrees.english);
		}


	}


}



void Delete_Node(int ID)
{
	student_info* last = NULL;
	student_info* sndLast = NULL;
	sndLast = (student_info*)gbfirst_student;
	last = sndLast;
	if ((struct student_info*)gbfirst_student == NULL)
	{
		printf("the linked list is empty\n");
	}
	else
	{
		while (ID != sndLast->student_ID)
		{
			last = sndLast;
			sndLast = (student_info*)sndLast->next_student;
		}

		last->next_student = sndLast->next_student;
		sndLast->next_student = NULL;
		free(sndLast);
	}


}
