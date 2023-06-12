#include<stdio.h>
//structure to respresent a process
typedef struct{
    int processid;
    int burstTime;
    int priority;
}Process;
  
  void fcfs(Process processes[],int n){
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;

    printf("\nFCFS Scheduling Algorithm:\n");
    for(int i=0;i<n;i++){
        printf("Process %d is running\n",processes[i].processid);
        waitingTime+=processes[i].burstTime;
        printf("Process %d is finished. Waitingtime:%d\n",processes[i].processid,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average waiting time:%.2f\n",averageWaitingTime);
  }

  void sjn(Process processes[],int n){
    int totalTime=0;
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nSJN Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processes[j].burstTime>processes[j+1].burstTime){
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("process %d is running.\n",processes[i].processid);
        waitingTime+=totalTime;
        totalTime+=processes[i].burstTime;
        printf("process %d is finished.Waiting time:%d\n",processes[i].processid,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time:%.2f\n",averageWaitingTime);   
  }
  void priorityScheduling(Process processes[],int n){
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nPriority Scheduling Alogrithm");
    for(int i=0;i<n;i++){
        printf("process %d is running.\n",processes[i].processid);
        waitingTime+=processes[i].burstTime;
         printf("process %d is finished.Waiting time:%d\n",processes[i].processid,waitingTime);
        totalWaitingTime+=waitingTime;
  }
  averageWaitingTime=totalWaitingTime/n;
  printf("Average Waiting Time:%.2f\n",averageWaitingTime);   
  }
  int main(){
    int n;
    printf("enter the no of processes:");
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++){
        printf("Enter the details for process %d:\n",i+1);
        processes[i].processid=i+1;
        printf("Enter burst time:");
        scanf("%d",&processes[i].burstTime);
         printf("Enter priority:");
        scanf("%d",&processes[i].priority);
    }
     fcfs(processes,n);
    sjn(processes,n);
    priorityScheduling(processes,n);
    return 0;
  }
