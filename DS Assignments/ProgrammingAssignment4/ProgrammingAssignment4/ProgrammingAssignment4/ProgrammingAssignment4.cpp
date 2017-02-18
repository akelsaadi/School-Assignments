#include "Controller.h"
#include "View.h"


int main(){
	View v;
	Controller c;
	int choice;
	do{
		v.showOptions();
		cin>>choice;
		switch(choice)
		{
		case 1:
			c.UCLoadData();
			break;
		case 2:
			c.UCDisplayDepth();
			break;
		case 3:
			c.UCDisplayBreath();
			break;
		case 4:
			c.UCDisplayLevel();
			break;
		case 5:
			c.UCSearchRole();
			break;
		case 6:
			c.UCSearchName();
			break;
		case 7:
			c.UCAdd();
			break;
		case 8:
			c.UCRemove();
			break;
		case 9:
			c.UCSave();
			break;
		case 10:
			system("exit");
			break;
		}
	}while (choice !=10);
	system("pause");
	return 0;
}
		




