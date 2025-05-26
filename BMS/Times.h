#include<Time.h>
typedef struct Date {
	int day,month,year;
} Date;

Date currentDate()
{
	Date d;
	time_t t=time(NULL);
	struct tm* date = localtime(&t);
	
	d.day=date->tm_mday;
	d.month=date->tm_mon + 1;
	d.year=date->tm_year+1900;
	
	return d;	
}

time_t convertToTime(Date d)
{
	struct tm date = {0};  
	date.tm_mday=d.day;
	date.tm_mon=d.month-1;
	date.tm_year=d.year-1900;

	return mktime(&date);
}

int dateDifference(Date d1 ,Date d2)
{
	time_t t1=convertToTime(d1);
	time_t t2=convertToTime(d2);
	
	
double difference = difftime(t1,t2);
return (int)(difference/(60*60*24));
}

