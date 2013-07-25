#include <stdio.h>
#include "data.h"
int main()
{
	int option = 0;
	int number = 0;
///////////////////////////////////////////
	Chengji a[10];
	read_file(a, &number);
	while(1)
	{
		printf("Please select the option:\n");
		printf("1.Display\n");
		printf("2.Sort\n");
		printf("3.Insert\n");
		printf("4.Delete\n");
		printf("5.Quit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			//////////
			print_info(a,&number);
			break;
			case 2:
			sort_info(a,&number);
			break;
			case 3:
			insert_info(a,&number);
			break;
			case 4:
			delete_info(a,&number);
			break;
			case 5:
			save_info(a,&number);
			printf("exit...\n");
			return 0;
			break;
			default:
			break;
		}
	}
}





