#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int N=100;
    int P=20;
    float p [P]; // Matrix for humming distance
    float arr [N][P];        // 10 vectors of 100 values 
    float num;              
    srand(time(0)); 

printf("Stored Patterns \n");
//Assigning random values (1/-1) to the vectors 
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<P;j++)
                {
                    num = (rand() % (10 - 0 + 1)) + 0;
                    if(num<6)   
                        arr[i][j]=-1;       
                    else
                        arr[i][j]=1;       
      //             printf("%f ", arr[i][j]);
                }
        //           printf("\n");
        } 


float w[N][N]; //N x N metrics for synaptic weights

//Assigning synaptic weight values
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<N;j++)
          {
              w[i][j]=0;
              for(int k=0;k<P;k++)
              {
              w[i][j] = ((arr[i][k]*arr[j][k])/N) + (w[i][j]);
              }
    //          printf("%f ",w[i][j]);
          }
      //    printf("\n");
      }

    float S[N]; //Extra test vector 

    //Assinging random values
    for(int i=0;i<N;i++)
    {
        
                    num = (rand() % (10 - 0 + 1)) + 0;
                    if(num<6)   
                        S[i]=-1;       
                    else
                        S[i]=1;       
     
  //  S[i] = arr[i][2];
  //  S[0] = -1*arr[0][2];
    }
//printf("Initial Si \n");
for(int i=0;i<N;i++)
    {
  //                  printf("%f \n",S[i]);
    
    }

    

for(int k=0;k<P;k++)
{

    for(int i=0;i<N;i++)
        {
            num=0;
            for(int j=0;j<N;j++)
   {
                num=w[i][j]*S[j] + num;          
   }
   if(num<0)   
                        S[i]=-1;       
                    else
                        S[i]=1;       

        //Calculating humming distance
for (int i=0;i<P;i++)
{
    num=0;
    for(int j=0;j<N;j++)
    {
        if(S[j]!=arr[j][i])
        num++;
    }
    p[i]=num;
}

        }     
        printf("Hamming Distance \n");
for(int i=0;i<P;i++)
{
    printf("%f ",p[i]);
}
printf(" \n");
}
//printf("Final Si \n");
for(int i=0;i<N;i++)
    {
 //                   printf("%f \n",S[i]);
    
    }






    
    return 0;
}
