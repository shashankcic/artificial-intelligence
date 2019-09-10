#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

using namespace std;
int main()
{
    int n,i, count=0;
    float yj;
    float alp;
    bool complete = false;
    srand((unsigned)time(NULL));

    printf("Enter the number of neurons. \n");
    scanf("%d",&n);

    printf("Enter the number of inputs. \n");
    scanf("%d",&i);

    printf("Enter the alpha value. \n");
    scanf("%f",&alp);

    float x[n][i];
    float Y[i];

    for(int j=0;j<i;j++)
        x[0][j] = 1; //bias input

    for(int k=0;k<i;k++)
    {
        for(int j=1;j<n;j++)
        {
            printf("Enter the %d th neural value of %d th input: \n",j,k);
            scanf("%f",&x[j][k]);
        }
    }

    // for(int k=0;k<i;k++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("\nThe %d th neural value of %d th input: %f\n",j,k,x[j][k]);
    //     }
    // }

    for(int j=0;j<i;j++)
    {
        printf("Enter the %d th expected output: ",j);
        scanf("%f",&Y[j]);
    }

    // for(int j=0;j<i;j++)
    // {
    //     printf("\nThe %d th expected output: %f\n",j,Y[j]);
    // }    

    float w[n];

    for(int j=0;j<n;j++)
    {
        printf("Enter the %d th weight value: ",j);
        scanf("%f",&w[j]);
    }

    // for(int j=0;j<n;j++)
    // {
    //     printf("\nThe %d th weight value: %f\n",j,w[j]);
    // }    

    float netj;

    while(complete==false){
        // complete = false;
        count=0;
        while(complete==false){
            complete = true;
            for(int k=0;k<i;k++)
            {
                //printf("Y value: %f \n",Y[k]);
                yj = 0;
                netj = 0;
                for(int j=0;j<n;j++)
                {
                    netj = netj + x[j][k]*w[k];
                    // printf("NetJ value: %f %d %d \n",netj,k,j);
                }
                yj = (netj > 0) ? 1 : 0; 
                // cout<<"k: "<<k<<" yj: "<<yj<<" Y[k]: "<<Y[k]<<endl;

                //printf("Netj Value: %f Yj value: %f Y value: %f \n",netj,yj,Y[k]);

                for(int j=0;j<n;j++)
                {
                    if(yj==1 && Y[k]==0){
                        w[j] = w[j] - alp * x[j][k];
                        complete = false;
                        // printf("if entered, count: %d yj: %f Y[k]: %f j: %d k: %d w[%d]: %f\n",count,yj,Y[k],j,k,j,w[j]);
                    }
                    else if(yj==0&&Y[k]==1){
                        w[j] = w[j] + alp * x[j][k];
                        complete = false;
                        // printf("else entered, count: %d yj: %f Y[k]: %f j: %d k: %d w[%d]: %f\n",count,yj,Y[k],j,k,j,w[j]);
                    }
                }
            }
            count++;
            if(count>30000){
                break;
            }
            // for(int k=0; k<n; k++)
            //     printf("Weight[%d] is: %f\n",k,w[k]);
        }
        // complete=true;
        for(int m=0;m<n;m++){
            w[m]=(float)(rand())/RAND_MAX;
            printf("\nNew randomly given weight[%d] is: %f\n",m,w[m]);
        }
    }

    printf("\n\nThe final weights are: \n");
    printf("\nCorrect weights found in %d iterations.\n",count);
    for(int k=0; k<n; k++)
        printf("Weight[%d] is: %f\n",k,w[k]);
}