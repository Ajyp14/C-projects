#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Times.h"

typedef struct Book {

	int b_id;
	char b_name[20];
	char a_name[20];
	char category[20];
	int b_price;
	int rating;
	int isIssued;
	Date issuedate;
	int issuedToSt;

} Book;


typedef struct {
	int s_id;
	char s_name[30];
	long long int w_no;
} Student;

int s_count;
int b_count;

void addBook(Book* ab,Student* s1) {
	int i,temp;


	printf("\nEnter the book ID : ");
	scanf("%d",&ab[b_count].b_id);
	for(i=0; i < b_count; i++) {
		if(ab[i].b_id==ab[b_count].b_id) {
			printf("\nBook id should be 'UNIQUE' ////\nPlease Enter valid book id : ");
			scanf("%d",&ab[b_count].b_id);
		}
	}



	getchar();

	printf("Enter the book name : ");
	gets(ab[b_count].b_name);

	printf("Enter the Author name: ");
	gets(ab[b_count].a_name);

	printf("Enter the Category : ");
	gets(ab[b_count].category);

	printf("Enter the book prize: ");
	scanf("%d",&ab[b_count].b_price);


	printf("Enter the book rating (1-10) : ");
	scanf("%d",&ab[b_count].rating);

	while(ab[b_count].rating<0 || ab[b_count].rating>10 ) {
		printf("Please enter valid rating!!!!  : ");
		scanf("%d",&ab[b_count].rating);
	}

	printf("Enter the '1' if booked is issued , '0' if book is not issued ");
	scanf("%d",&ab[b_count].isIssued);



	if(ab[b_count].isIssued==1) {

		printf("Enter the book issued day : ");
		scanf("%d",&ab[b_count].issuedate.day);

		if(ab[b_count].issuedate.day<0 || ab[b_count].issuedate.day>31) {
			printf("Please Enter valid day: ");
			scanf("%d",&ab[b_count].issuedate.day);
		}


		printf("Enter the book issued month : ");
		scanf("%d",&ab[b_count].issuedate.month);

		if(ab[b_count].issuedate.month<0 || ab[b_count].issuedate.month>12) {
			printf("Please Enter valid Month : ");
			scanf("%d",&ab[b_count].issuedate.month);
		}

		printf("Enter the book issued year : ");
		scanf("%d",&ab[b_count].issuedate.year);

		printf("Enter the student id of student who take book : ");
		scanf("%d",&ab[b_count].issuedToSt);
		//	s_count++;

		for(i=0; i<s_count; i++) {
			if(ab[b_count].issuedToSt==s1[i].s_id) {
				//strcpy(ab[i].b_name)
				printf("\nBooked Added successfully \n");
				b_count++;
				return;
			}
		}

//to add into student database
		s1[s_count].s_id=ab[b_count].issuedToSt;
		printf("Entere the student name : ");
		scanf("%s",&s1[s_count].s_name);

		printf("Entere the student phone number : ");
		scanf("%lld",&s1[s_count].w_no);

		s_count++;
	}



	b_count++;

	printf("\nBooked Added successfully \n");
}


void addStudent(Student* s1) {
	int i;


	printf("Enter the Student Id : ");
	scanf("%d",&s1[s_count].s_id);
	for(i=0; i < s_count; i++) {
		if(s1[i].s_id==s1[s_count].s_id) {
			printf("\nstudent id should be 'UNIQUE' ////\nPlease Enter valid book id : ");
			scanf("%d",&s1[s_count].s_id);
		}
	}


	printf("Entere the student name : ");
	scanf("%s",&s1[s_count].s_name);

	printf("Entere the student phone number : ");
	scanf("%lld",&s1[s_count].w_no);


	s_count++;

}

void display(Book* bs) {

	if(bs->isIssued==1) {
		printf("| %d\t\t  %s\t %s\t  %s\t    %d\t\t  %d\t\t%d\t  %d-%d-%d\t     %d \n",bs->b_id,bs->b_name,bs->a_name,bs->category,bs->b_price,bs->rating,bs->isIssued,bs->issuedate.day,bs->issuedate.month,bs->issuedate.year,bs->issuedToSt);
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
	} else {
		printf("| %d\t\t  %s\t %s\t  %s\t    %d\t\t  %d\t\t%d ",bs->b_id,bs->b_name,bs->a_name,bs->category,bs->b_price,bs->rating,bs->isIssued);
		printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
	}
}


void displayAll(Book* bs) {
	int i;
	printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

	for(i=0; i < b_count; i++) {

		if(bs[i].isIssued==1) {
			printf("| %d\t\t  %s\t %s\t  %s\t    %d\t\t  %d\t\t%d\t  %d-%d-%d\t     %d \n",bs[i].b_id,bs[i].b_name,bs[i].a_name,bs[i].category,bs[i].b_price,bs[i].rating,bs[i].isIssued,bs[i].issuedate.day,bs[i].issuedate.month,bs[i].issuedate.year,bs[i].issuedToSt);
			printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
		} else {
			printf("| %d\t\t  %s\t %s\t  %s\t    %d\t\t  %d\t\t%d ",bs[i].b_id,bs[i].b_name,bs[i].a_name,bs[i].category,bs[i].b_price,bs[i].rating,bs[i].isIssued);
			printf("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
		}
	}
}

void bookHardcoded(Book* bs ) {
	bs[b_count].b_id=101;
	strcpy(bs[b_count].b_name,"Chhaava");
	strcpy(bs[b_count].a_name,"Shivaji sawant");
	strcpy(bs[b_count].category,"Historical");
	bs[b_count].b_price=499;
	bs[b_count].rating=9;
	bs[b_count].isIssued=1;
	bs[b_count].issuedate.day=13;
	bs[b_count].issuedate.month=1;
	bs[b_count].issuedate.year=2025;
	bs[b_count].issuedToSt=203;
	b_count++;

	bs[b_count].b_id=102;
	strcpy(bs[b_count].b_name,"Mrutyunjay");
	strcpy(bs[b_count].a_name,"Shivaji sawant");
	strcpy(bs[b_count].category,"Fiction");
	bs[b_count].b_price=299;
	bs[b_count].rating=8;
	bs[b_count].isIssued=1;
	bs[b_count].issuedate.day=2;
	bs[b_count].issuedate.month=1;
	bs[b_count].issuedate.year=2025;
	bs[b_count].issuedToSt=201;
	b_count++;

	bs[b_count].b_id=103;
	strcpy(bs[b_count].b_name,"Bhagvat Gita");
	strcpy(bs[b_count].a_name,"Shivaji sawant");
	strcpy(bs[b_count].category,"Religious");
	bs[b_count].b_price=499;
	bs[b_count].rating=9;
	bs[b_count].isIssued=0;
//	bs[b_count].issuedate.day=13;
//	bs[b_count].issuedate.month=9;
//	bs[b_count].issuedate.year=2024;
	b_count++;

	bs[b_count].b_id=104;
	strcpy(bs[b_count].b_name,"The Exorcist");
	strcpy(bs[b_count].a_name,"William Blatty");
	strcpy(bs[b_count].category,"Horror");
	bs[b_count].b_price=600;
	bs[b_count].rating=7;
	bs[b_count].isIssued=1;
	bs[b_count].issuedate.day=3;
	bs[b_count].issuedate.month=4;
	bs[b_count].issuedate.year=2023;
	bs[b_count].issuedToSt=202;
	b_count++;

	bs[b_count].b_id=105;
	strcpy(bs[b_count].b_name,"DesignPattern");
	strcpy(bs[b_count].a_name,"Erich Gamma");
	strcpy(bs[b_count].category,"Technical");
	bs[b_count].b_price=249;
	bs[b_count].rating=5;
	bs[b_count].isIssued=1;
	bs[b_count].issuedate.day=12;
	bs[b_count].issuedate.month=7;
	bs[b_count].issuedate.year=2024;
	bs[b_count].issuedToSt=204;
	b_count++;

	bs[b_count].b_id=106;
	strcpy(bs[b_count].b_name,"GunahonKaDev");
	strcpy(bs[b_count].a_name,"D. bharti");
	strcpy(bs[b_count].category,"Entertainment");
	bs[b_count].b_price=199;
	bs[b_count].rating=8;
	bs[b_count].isIssued=0;
//	bs[b_count].issuedate.day=13;
//	bs[b_count].issuedate.month=9;
//	bs[b_count].issuedate.year=2024;
	b_count++;

}
void studentHardcoded(Student* s1) {
	s1[s_count].s_id=201;
	strcpy(s1[s_count].s_name,"Ajay Pawar");
	s1[s_count].w_no=9910126547;
	s_count++;

	s1[s_count].s_id=202;
	strcpy(s1[s_count].s_name,"nikhil dev");
	s1[s_count].w_no=7788554499;
	s_count++;

	s1[s_count].s_id=203;
	strcpy(s1[s_count].s_name,"Ajay Pawar");
	s1[s_count].w_no=9988774455;
	s_count++;

	s1[s_count].s_id=204;
	strcpy(s1[s_count].s_name,"Prasad nal");
	s1[s_count].w_no=7788993322;
	s_count++;

	s1[s_count].s_id=205;
	strcpy(s1[s_count].s_name,"vijay das");
	s1[s_count].w_no=9910126547;
	s_count++;

	s1[s_count].s_id=206;
	strcpy(s1[s_count].s_name,"Rao Patil");
	s1[s_count].w_no=8899443377;
	s_count++;
}
void removeBook(Book* Rm) {
	int Rem,i,j,flag=0;
	printf("enter the book Id to remove from datadbase :");
	scanf("%d",&Rem);

	for(i=0; i < b_count; i++) {
		if(Rem==Rm[i].b_id) {
			flag=1;
			for(j=i; j< b_count ; j++) {
				Rm[j]=Rm[j+1];
			}
			b_count--;
			printf("\nbook removed Successfully ");
			break;
		}
	}
	if(!flag) {
		printf("\nBook not found....");
	}
}

void searchBook(Book* bs) {
	int choice=0,i;
	char b_name[30];
	int flag=0,ID;

	while(1) {



		printf("\n\n1.Search Book by Book Name\n2.Search Book by Book id\n3.stop searching ");
		printf("\nPlease Enter the choice : ");
		scanf("%d",&choice);
		getchar();
		if(choice==1) {
			printf("\nEnter book name to search : ");
			gets(b_name);

			printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

			for(i=0; i<b_count; i++) {
				if(!strcmp(strupr(bs[i].b_name),strupr(b_name))) {
					flag=1;

					display(&bs[i]);
				}

			}
			if(!flag) {
				printf("\nnot found \n");
			}
			flag=0;

		} else if(choice==2) {

			printf("\nEnter book 'ID' to search : ");
			scanf("%d",&ID);

			printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

			for(i=0; i<b_count; i++) {
				if(ID==bs[i].b_id) {

					flag=1;
					display(&bs[i]);

				}

			}

			if(!flag) {
				printf("\nnot found \n");
			}
			flag=0;

		} else if(choice==3) {
			break;
		} else {
			printf("\ninvlaid choice!!! ");
		}
	}

}

void shwoAuthors(Book *bs) {
	char an[30];
	int i;
	int flag=0;

	getchar();

	printf("\nEnter the Author's Name :");
	gets(an);

	printf("\nThe Books Written by Mr.%s :  \n",an);


	printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");


	for(i=0; i < b_count; i++) {
		if(!strcmp(strupr(bs[i].a_name),strupr(an))) {
			flag=1;
			display(&bs[i]);

		}

	}
	if(!flag) {
		printf("\nnot found \n");
	}

}
void showCategory(Book* bs) {
	char sc[30];
	int i;
	int flag=0;

	getchar();

	printf("\n available Category  : \n1.Historical\n2.Fictional\n3.religious\n4.Horror\n5.Entertainment\n6.Technical\n7. Press 0 to go back\n.Entere the category which one you want : ");
	gets(sc);

	if(sc=="0") {
		return;
	}

	printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

	for(i=0; i<b_count; i++) {
		if(!strcmp(strupr(bs[i].category),strupr(sc))) {
			flag=1;

			display(&bs[i]);
		}

	}
	if(!flag) {
		printf("\nnot found \n");
	}
}

void update(Book* bs,Student *s1) {
	int i,j,ID,flag=0,temp;
	int choice;

	while(1) {
		printf("\n1.To change the book price \n2.To change the book rating\n3.To update Issued status \n4.To Update Issued Date\n5.To Update students Id\n6.back ");
		printf("\nEnter the choice :  ");
		scanf("%d",&choice);
		if(choice==1) {
			printf("\nEnter the book Id to changed the price :");
			scanf("%d",&ID);
			for(i=0; i<b_count; i++) {
				if(bs[i].b_id==ID) {
					flag=1;
					printf("\n1.Enter the new price of book  : ");
					scanf("%d",&bs[i].b_price);
					printf("\n %d Id Prize changed successfull !!!!\n",ID);
				}

			}
			if(!flag) {
				printf("\ninvalid id !!\n");
			}
			flag=0;
		} else if(choice==2) {
			printf("\nEnter the book Id to changed the rating :");
			scanf("%d",&ID);
			for(i=0; i<b_count; i++) {
				if(bs[i].b_id==ID) {
					flag=1;
					printf("\n1.Enter the new rating of book  (1-10): ");
					scanf("%d",&bs[i].rating);
					while(bs[i].rating<0 || bs[i].rating>10 ) {
						printf("\nPlease enter valid rating (1-10)!!!!\n");
						scanf("%d",&bs[i].rating);
					}
					printf("\n %d Id rating changed successfull !!!!\n",ID);
				}

			}
			if(!flag) {
				printf("\ninvalid id !!\n");
			}
			flag=0;
		} else if(choice==3) {
			printf("\nEnter the book Id to changed the Issued status :");
			scanf("%d",&ID);
			for(i=0; i<b_count; i++) {
				if(bs[i].b_id==ID) {
					flag=1;
					printf("\n1.Enter the Issued Status (0-not issued)and(1-issued)  : ");
					scanf("%d",&bs[i].isIssued);
					while(bs[i].isIssued< 0 || bs[i].isIssued > 1 ) {
						printf("\nPlease enter valid Issued Status (0-not issued)and(1-issued)!!!! : ");
						scanf("%d",&bs[i].isIssued);
					}
					printf("\n %d Id ,Issued status changed successfull !!!!\n",ID);

					if(bs[i].isIssued==1) {
						printf("Enter the new  issued day : ");
						scanf("%d",&bs[i].issuedate.day);

						if(bs[i].issuedate.day<0 || bs[i].issuedate.day>31) {
							printf("Please Enter valid day: ");
							scanf("%d",&bs[i].issuedate.day);
						}


						printf("Enter the new  issued month : ");
						scanf("%d",&bs[i].issuedate.month);

						if(bs[i].issuedate.month<0 || bs[i].issuedate.month>12) {
							printf("Please Enter valid Month : ");
							scanf("%d",&bs[i].issuedate.month);
						}

						printf("Enter the new  issued year : ");
						scanf("%d",&bs[i].issuedate.year);

					} else {
						bs[b_count].issuedate.day=0;
						bs[b_count].issuedate.month=0;
						bs[b_count].issuedate.year=0;
					}
				}

			}
			if(!flag) {
				printf("\ninvalid id !!\n");
			}
			flag=0;

		} else if(choice==4) {
			printf("\nEnter the book Id to changed the date :");
			scanf("%d",&ID);



			for(i=0; i<b_count; i++) {
				if(bs[i].b_id==ID && bs[i].isIssued==1) {
					flag=1;
					printf("Enter the new  issued day : ");
					scanf("%d",&bs[i].issuedate.day);

					if(bs[i].issuedate.day<0 || bs[i].issuedate.day>31) {
						printf("Please Enter valid day: ");
						scanf("%d",&bs[i].issuedate.day);
					}


					printf("Enter the new  issued month : ");
					scanf("%d",&bs[i].issuedate.month);

					if(bs[i].issuedate.month<0 || bs[i].issuedate.month>12) {
						printf("Please Enter valid Month : ");
						scanf("%d",&bs[i].issuedate.month);
					}

					printf("Enter the new  issued year : ");
					scanf("%d",&bs[i].issuedate.year);

					printf("\n Date changed successfully !!\n");
				}

				if(bs[i].b_id==ID && bs[i].isIssued!=1) {
					printf("\n%d book Id Status is not Issued  (0) ,thats why you cannot allowed to change the date !!!\n",ID);
					flag=1;
				}
			}

			if(!flag) {
				printf("\ninvalid id !!\n");
			}
			flag=0;
		} else if(choice==5) {

			printf("Enter the book id to update their student Id : ");
			scanf("%d",&ID);

			for(i=0; i<b_count; i++) {
				if(bs[i].b_id==ID && bs[i].isIssued!=1) {
					printf("\n%d book Id Status is not Issued  (0) ,thats why there is no student ID to Update  !!!\n",ID);
					flag=1;
					break;
				}
				if(bs[i].b_id==ID && bs[i].isIssued==1) {
					flag=1;
					temp=bs[i].issuedToSt;
					printf("Enter the new student id : ");
					scanf("%d",&bs[i].issuedToSt);
						
					printf("\n '%d' Book Id's , Student Id : '%d' Changed to '%d' !!! \n",ID,temp,bs[i].issuedToSt);

					for(j=0;j<s_count;j++)
					{
						if(temp==s1[j].s_id)
						{
							s1[j].s_id=bs[i].issuedToSt;
						}
					}
				}

			}
			if(!flag) {
				printf("\nInvalid Book id\n");
			}
			flag=0;
		}

		else if(choice==6) {
			break;
		} else
			printf("\nInvalid choice !!!!\n");
	}
}

void sort(Book *bs) {
	int choice=0,i,j;
	Book t;
	int flag;
	char ch[30];


	while(1) {

		printf("\n1.Sort books price wise (lowest-highest) \n2.Sort books price wise (highest-lowest) \n3.Sort books  Rating-wise (lowest-hights) \n4.Sort books rating-wise (highest-lowests) \n5.back");
		printf("\nEnter the choice : ");
		scanf("%d",&choice);

		if(choice==1) {


			for(i=b_count-1; i>0; i--) {
				flag=0;
				for(j=0; j<i; j++) {
					if(bs[j].b_price>bs[j+1].b_price) {
						flag=1;

						t=bs[j];
						bs[j]=bs[j+1];
						bs[j+1]=t;

					}

				}
				if(flag==0) {
					break;
				}

			}

			displayAll(bs);
		}

		else if(choice==2) {
			for(i=b_count-1; i>0; i--) {
				flag=0;
				for(j=0; j<i; j++) {                     //or j<n but it is not better way to travrese for loop
					if(bs[j].b_price<bs[j+1].b_price) { //descending  if(a[j]<a[j+i])
						flag=1;

						t=bs[j];
						bs[j]=bs[j+1];
						bs[j+1]=t;

					}

				}
				if(flag==0) {
					break;
				}

			}

			displayAll(bs);
		} else if(choice==3) {
			for(i=b_count-1; i>0; i--) {
				flag=0;
				for(j=0; j<i; j++) {
					if(bs[j].rating>bs[j+1].rating) {
						flag=1;

						t=bs[j];
						bs[j]=bs[j+1];
						bs[j+1]=t;

					}

				}
				if(flag==0) {
					break;
				}

			}
		} else if(choice==4) {

			for(i=b_count; i>0; i--) {
				flag=0;
				for(j=0; j<i; j++) {
					if(bs[j].rating<bs[j+1].rating) {
						flag=1;

						t=bs[j];
						bs[j]=bs[j+1];
						bs[j+1]=t;

					}

				}
				if(flag==0) {
					break;
				}

			}
			displayAll(bs);
		} else if(choice==5) {
			break;
		} else {
			printf("\nInvalid choice !!!!");
		}
	}
}


void showIssuedBooks(Book* bs) {
	int i;
	printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n| book ID\t| book name\t| Author name\t| book Category\t| book prize | book rating | IsIssued\t| IssueDate\t| Student Id");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

	for(i=0; i<b_count; i++) {
		if(bs[i].isIssued==1)
			display(&bs[i]);
	}

}
void showOutOfDate(Book* bs,Student* s1) {
	int i,res;

	Date d1=currentDate();
 
	for(i=0; i<b_count; i++) {
		if(bs[i].isIssued==1) {

			res = (- dateDifference(bs[i].issuedate,d1));
		
	
			if(res>=30) {
				printf("\nextend days : %d \n",res-30);
				int tempStudID=bs[i].issuedToSt;
				printf(" Please submit book |%s|",bs[i].b_name);
				int j;
				for(j=0;j<s_count;j++){
					if(s1[j].s_id==tempStudID){
						printf(" ( message is sent to  : %lld , Student id : %d )\n",s1[j].w_no,s1[j].s_id);
					}
				}

				
				
				
			}
		}

	}
}


void main() {
	int choice,i;

	int num_book=6;      //initial
	int num_stud=7;

	b_count=0;
	s_count=0;

	Book* bs=(Book*)malloc(num_book * sizeof(Book));
	if(bs==NULL) {
		printf("Storage not get!!!\n");
		exit(0);
	}

	s_count=0;

	Student* s1=(Student*)malloc(num_stud*sizeof(Student));
	if(bs==NULL) {
		printf("Storage not get!!!\n");
		exit(0);
	}

	bookHardcoded(bs);
	studentHardcoded(s1);



	while(1) {
		printf("\n1.Add Book \n2.Remove book\n3.Search Book\n4.Shwo Author's Book\n5.Show category Books\n6.Update Book Data\n7.Display Sorted Books\n8.Display all books\n9.See Issued Book\n10.Show Dateline over\n11.Close the App");
		printf("\nPlease Enter the choice : ");
		scanf("%d",&choice);

		if(choice==1) {

			if(b_count>=num_book) {
				num_book=num_book + 2;
				bs=(Book*)realloc((bs), num_book * sizeof(Book));

				if((bs)==NULL) {
					printf("Memory not get!!!\n");
					exit(0);
				}
			}
			if(s_count>=num_stud ) {
				num_stud = num_stud * 2;

				s1=(Student*)realloc((s1),num_stud * sizeof(Student));

				if(s1==NULL) {
					printf("Memory not get!!!\n");
					exit(0);
				}
			}


			addBook(bs,s1);
		} else if(choice==2) {
			removeBook(bs);
		} else if(choice==3) {
			searchBook(bs);
		} else if(choice==4) {
			shwoAuthors(bs);
		} else if(choice==5) {
			showCategory(bs);
		} else if(choice==6) {
			update(bs,s1);
		} else if(choice==7) {
			sort(bs);
		} else if(choice==8) {
			displayAll(bs);
		} else if(choice==9) {
			showIssuedBooks(bs);
		} else if(choice==10) {
			showOutOfDate(bs,s1);
		} else if(choice==11) {
			exit(1);
		} else {
			printf("\ninvalid Input!!!!");
		}

	}
}


