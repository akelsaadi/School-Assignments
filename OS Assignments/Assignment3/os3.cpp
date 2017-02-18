#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <fcntl.h>


using namespace std;

struct Per{
   string name;
   string spot;
   size_t time_wait;
   size_t time_arrive;
};


// the semaphores
sem_t *AE_mutex;
char sem_AE_mutex[] = "mutex";

sem_t *AE_capulet;
char sem_AE_capulet[] = "capulet";

sem_t *AE_montague;
char sem_AE_montague[] = "montague";



//mem

const int CAPULET = 0;
const int MONTAGUE = 1;
const int TIME = 2;


int memSid;
int *Data;
long keyMem;
const int memsize = 12;

main()
{
    int id;
	Per curr_person;
	size_t last_arr_time = 0;
	string name_pre = "";

	AE_mutex = sem_open(sem_AE_mutex, O_CREAT, 0600, 1);
	AE_montague = sem_open(sem_AE_montague, O_CREAT, 0600, 1);
	AE_capulet = sem_open(sem_AE_capulet, O_CREAT, 0600, 1);

	keyMem = 1286957;
	memSid = shmget(keyMem, memsize, 0600 | IPC_CREAT);
	Data = (int *) shmat(memSid, NULL, 0);

	while(cin)
	{
		cin>>curr_person.spot;
		cin>>curr_person.name;
		cin>>curr_person.time_arrive;
		cin>>curr_person.time_wait;
		if (curr_person.name == name_pre) continue;
		else name_pre = curr_person.name;
		sleep(curr_person.time_arrive-last_arr_time);
		cout << curr_person.spot << " "
		     << curr_person.name 
		     << " arrived on time "
		     << curr_person.time_arrive << endl << endl;

		//main process
		id = fork();
		if(id == 0)
		{
			if(curr_person.spot == "Montague")
			{
				//montague 
				sem_wait(AE_montague);
				cout << curr_person.spot << " "
				     << curr_person.name
				     << " enters the piazza" << endl << endl;

				sem_wait(AE_mutex);
				(*(Data + MONTAGUE))++;
				cout << "There are " << *(Data + CAPULET)
				     << " Capulet(s) and " << *(Data + MONTAGUE)
				     << " Montague(s) on the piazza."  << endl << endl;
				sem_post(AE_mutex);
				sem_post(AE_capulet);

				sleep(curr_person.time_wait);
				sem_wait(AE_capulet);

				cout << curr_person.spot << " "
				     << curr_person.name
				     << " leaves the piazza." << endl << endl;

				sem_wait(AE_mutex);
				(*(Data + MONTAGUE))--;

				cout << "There are " << *(Data + CAPULET)
				     << " Capulet(s) and " << *(Data + MONTAGUE)
				     << " Montague(s) on the piazza." << endl << endl;
				sem_post(AE_mutex);
				sem_post(AE_montague);


			      	_exit(0);	
			}
			else{

				sem_wait(AE_capulet);

				cout << curr_person.spot << " "
				     << curr_person.name 
				     << " enters the piazza." << endl << endl;

				sem_wait(AE_mutex);
				(*(Data + CAPULET))++;
				cout << "There are " << *(Data + CAPULET)
				     << " Capulet(s) and " << *(Data + MONTAGUE)
				     << " Montague(s) on the piazza."  << endl << endl;
				sem_post(AE_mutex);
				sem_post(AE_montague);

				sleep(curr_person.time_wait);

				sem_wait(AE_montague);


				cout << curr_person.spot << " "
				     << curr_person.name 
				     << " leaves the piazza." << endl << endl;

				sem_wait(AE_mutex);
				(*(Data + CAPULET))--;
				cout << "There are " << *(Data + CAPULET)
				     << " Capulet(s) and " << *(Data + MONTAGUE)
				     << " Montague(s) on the piazza." <<  endl << endl;
				sem_post(AE_mutex);
				sem_post(AE_capulet);

				_exit(0);
			}
		}

		last_arr_time = curr_person.time_arrive;
	}

	while(wait(NULL) > 0)
	{

	}

	shmdt(Data);
	shmctl(memSid, 0, IPC_RMID);

	sem_close(AE_capulet);
	if (sem_unlink(sem_AE_capulet) != 0)
	{
		cout << "Semaphore was not deleted: " << sem_AE_capulet << endl;
	}

	sem_close(AE_montague);
	if (sem_unlink(sem_AE_montague) != 0)
	{
		cout << "Semaphore was not deleted: " << sem_AE_montague << endl;
	}

	sem_close(AE_mutex);
	if (sem_unlink(sem_AE_mutex) != 0)
	{
		cout << "mutex was not deleted: " << sem_AE_mutex << endl;
	}

}