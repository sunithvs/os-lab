// Cycle 2 Pipes 1 
// sunith vs
// 20220098
// CS B
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
int main() {

   int returnstatus;
   int pid;

    
   //create pipe
    int size_pipe[2];
    int arr_pipe[2];

    if (pipe(size_pipe) == -1)
    {
        printf("Unable to create pipe 1\n");
        return -1;
    }

   if (pipe(arr_pipe) == -1)
    {
        printf("Unable to create pipe 2\n");
        return -1;
    }


   //create process
   pid = fork();
   if(pid==-1)  {
        printf("Unable to create the process\n");
        return -1;
    }


   if (pid == 0) {     // Child process
    close(size_pipe[1]);
    close(arr_pipe[1]);
    int size;
    read(size_pipe[0], &size, sizeof(size));
    int sub_num_arr[size];
    read(arr_pipe[0], &sub_num_arr, sizeof(sub_num_arr));
    for(int i=0;i<size;i++){
         printf("%d\t", sub_num_arr[i]);
    }

   } else { //Parent process
        //close read pipes
        close(size_pipe[0]);
        close(arr_pipe[0]);
        int size;
        printf("Enter no of elements array : ");
        scanf("%d", &size);
        //read the size of array
        int num_arr[size];
        returnstatus=write(size_pipe[1], &size, sizeof(size));
        if(returnstatus==-1){
            printf("Error occurred");
            return -1;
        }
        //read array elements from user
        printf("Enter the numbers to send: ");
        for(int i=0;i<size;i++){
            scanf("%d",&num_arr[i]);
        }
        returnstatus=write(arr_pipe[1],num_arr, sizeof(num_arr));
        if(returnstatus==-1){
            printf("Error occurred");
            return -1;
        }

    wait(NULL);

   }
   return 0;
}

/*
Output

Enter no of elements array : 4
Enter the numbers to send: 
1
2
3
4
1	2	3	4	
*/
