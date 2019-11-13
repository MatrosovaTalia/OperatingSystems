#include <stdio.h>

int allDone(int done[], int len);
void updateA(int resources[], int A[], int len);
int canExecute(int process[], int A[], int len);
void checkForDeadlock(FILE* input);

int main (){

    FILE* in_dl = fopen("input_dl.txt", "r");
    FILE* in_ok = fopen("input_ok.txt", "r");

    checkForDeadlock(in_dl);
    checkForDeadlock(in_ok);
}

int allDone(int done[], int len){
    for (int i = 0; i < len; i++){
        if (done[i] == 0){
            return 0;
        }
    }
    return 1;
}

int canExecute(int process[], int A[], int len){
    for (int i = 0; i < len; i++){
        if (process[i] > A[i]){
            return 0;
        }
    }
    return 1;
}

void updateA(int resources[], int A[], int len){
    for (int i = 0; i < len; i++){
        A[i] += resources[i];
    }
}

void checkForDeadlock(FILE* input){
    int rn; // number of resources
    int pn; // number of processes

    fscanf(input, "%d", &rn);
    fscanf(input, "%d", &pn);

    int E[rn];
    int A[rn];

    for (int i = 0 ; i < rn; i++){
        fscanf(input, "%d ", &E[i]);
    }

    for (int i = 0; i < rn; i++){
        fscanf(input, "%d ", &A[i]);
    }

    int allocated[pn][rn];
    int processes[pn][rn];


    for (int i = 0; i < pn; i++){
        for (int j = 0 ; j < rn; j++){
            fscanf(input, "%d ", &allocated[i][j]);
        }
    }

    for (int i = 0; i < pn; i++){
        for (int j = 0 ; j < rn; j++){
            fscanf(input, "%d ", &processes[i][j]);
        }
    }
    int done[pn];
    for (int i = 0; i < pn; i++){
        done[i] = 0;
    }

    int deadlock = 0;
    while (!allDone(done, pn) && !deadlock){
        deadlock = 1;
        int procNum;
        for (int i = 0; i < pn; i++){
            if (done[i] == 0 && canExecute(processes[i], A, rn)){
                deadlock = 0;
                updateA(allocated[i], A, rn);
                done[i] = 1;
            }
        }
    }


    if (deadlock){
        FILE* outWithDL = fopen("output_dl.txt","w");
        fprintf(outWithDL, "Deadlock processes: \n");
        for (int i = 0; i < pn; i++){
            if (!done[i]){
                fprintf(outWithDL, "%d ", i + 1);
            }
        }
    }

    if(!deadlock){
        FILE* outOK = fopen("output_ok.txt", "w");
        fprintf(outOK, "There is no deadlock\n");
    }

}

