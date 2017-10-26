//*************************************************************//
//*********** Library Inclusion Space *************************//
// Including basic libraries for C code                        //
// <time.h> is used to clock the execution time of the matrix  //
//         multiplication				       //
//*************************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*************************************************************//
#define min(a,b) (a<b?a:b)
//**************************************************************//
//****** Control Block for Datatype Parameterization ***********//
// Parameterizing datatype - int / float / double               //
//               Uncomment the required datatype                //
//  And comment the other types to avoid redeclaration error    //
//**************************************************************//

//#define my_type_t int
//#define my_type_t float
#define my_type_t double

//*************************************************************//

//*************************************************************//
//******* Control of Printf Specifier - To avoid errors *******//
//  Set Value as 1 for int, 2 for float, 3 for double          //
//*************************************************************//

//#define printspecifier 1  // 1 -> INT ,2 for Float ,3 for Double

//*************************************************************//

//*************************************************************//
// This declaration is used to consider the different          //
// ways of declaring an array in C as asked in Assignment      //  
//*************************************************************//

my_type_t B[4096][4096];

//*************************************************************//

//*************************************************************//
//              Main Function where the code is                //
//*************************************************************//

int main(){
	//declaring pointers for matrix multiplication
	my_type_t  **A, **C;// ,**B;
	//declaring variables for fetching size of matrix
	int row1,col1,row2,col2;
	//Input parameter for datatype reference
	//int typedata;
	/* Declaring indexes for calculations */
	int i,j,k;

	//Get datatype from User
	//printf("Enter datatype for Matrices : INT -> 1, FLOAT -> 2, DOUBLE ->3 \n");
	//scanf("%d",&typedata);
	//printf("%f\n",(float)RAND_MAX);
	/* Request the user to input number of columns of the matrices.*/ 
	printf("\nEnter number of rows for first matrix : ");
	scanf("%d", &row1); 
	printf("\nEnter number of columns for first matrix : ");
	scanf("%d", &col1);
	printf("\nEnter number of rows for second matrix : ");
	scanf("%d", &row2);
	printf("\nEnter number of columns for second matrix : ");
	scanf("%d", &col2);
	//Check basic matrix Multiplication rule
	if(col1 != row2)
	{
		printf("\nCannot multiply two matrices."); 
		return(0); 
	}
	


	// Allocating memory for matrices		
	// If User wants multiplication of Integers
	//if(typedata == 1){
		//int **A,**B,**C;
		//printf("Entered\n");
		/* Allocating memory for three matrix rows. */
	A = (my_type_t **) calloc(row1,sizeof(my_type_t *)); 
	//B = (my_type_t **) calloc(row2,sizeof(my_type_t *));
	C = (my_type_t **) calloc(row1,sizeof(my_type_t *));
		/* Allocating memory for the col of three matrices. */
	for(i=0; i<row1; i++)
 		A[i] = (my_type_t *)calloc(col1,sizeof(my_type_t));
	//for(i=0; i<row2; i++) 
 	//	B[i] = (my_type_t *)calloc(col2,sizeof(my_type_t));
	for(i=0; i<row1; i++) 
 		C[i] = (my_type_t *)calloc(col2,sizeof(my_type_t));
	/*Code is here */
	// Initialising Matrix 1
	
	for(i=0; i< row1; i++)
	{
		for(j=0; j< col1; j++)
		{	
			A[i][j] = (my_type_t)(((my_type_t)(rand()%9000)/3000.0) * 5.0);
		}	
	}
	/* Initialising Matrix 2 */
	for(i=0; i< row2; i++)
	{
		for(j=0; j< col2; j++)
		{	
			B[i][j] = (my_type_t)(((my_type_t)(rand()%9000)/3000.0) * 5.0);
			//B[i][j] = (my_type_t)(rand() / RAND_MAX + 1);
		}
	}	
	//*************************************************************//
	//       Main Multiplication Block where Logic is implemented  //
	//   Clock is used here to time the execution of this block    //
	//*************************************************************//
	
	clock_t start = clock();
	int ii2,ii3,s;
	s = 1024;
	for(ii2=0; ii2 < col1; ii2+=s)
	{
		for(ii3=0; ii3 < col2;ii3+=s )
		{
			//C[i][j] = 0;
 			for(i=0; i<row1; i++)
			{
				for(j=ii2;j< min(ii2+s-1,col1);j++)
				{
					for(k=ii3;k<min(ii3+s-1,col2);k++)
					{
						C[i][k] +=  A[i][j] * B[j][k];
					}
				}
			} 
			//C[i][j] +=  A[i][k] * B[k][j];
		}
	}
	clock_t  stop = clock();


	//*************************************************************//
	
	//*************************************************************//
	//     Printing of Matrices happens in the below block         //
	//*************************************************************//

	//Printing the Matrix
/*	if (printspecifier == 1){
		printf("\n\nMatrix 1 :");
        	for(i=0; i< row1; i++)
        	{
                	printf("\n\t\t\t");
                	for(j=0; j < col1; j++)
                	    printf("  %d", A[i][j]);
        	}
	 	printf("\n\nMatrix 2 :");
        	for(i=0; i< row2; i++)
        	{
                	printf("\n\t\t\t");
                	for(j=0; j < col2; j++)
                	   printf("  %d", B[i][j]);
        	}	
	
 
		printf("\n\nResultant matrix :"); 
		for(i=0; i< row1; i++) 
		{
			printf("\n\t\t\t");
			for(j=0; j < col2; j++) 	
			    printf("  %d", C[i][j]);
		}
	}
	else if (printspecifier ==2){
	 	printf("\n\nMatrix 1 :");
                for(i=0; i< row1; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col1; j++)
                            printf("  %f", A[i][j]);
                }
                printf("\n\nMatrix 2 :");
                for(i=0; i< row2; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col2; j++)
                           printf("  %f", B[i][j]);
                }

                 Printing the contents of third matrix. */
/*                printf("\n\nResultant matrix :");
                for(i=0; i< row1; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col2; j++)
                            printf("  %f", C[i][j]);
                }
	

	}
	else {
		 printf("\n\nMatrix 1 :");
                for(i=0; i< row1; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col1; j++)
                            printf("  %lf", A[i][j]);
                }
                printf("\n\nMatrix 2 :");
                for(i=0; i< row2; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col2; j++)
                           printf("  %lf", B[i][j]);
                }

//                 Printing the contents of third matrix. 
                printf("\n\nResultant matrix :");
                for(i=0; i< row1; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col2; j++)
                            printf("  %lf", C[i][j]);
                }

	}
	
//	*************************************************************/
/*	printf("\n\nResultant matrix :");
                for(i=0; i< row1; i++)
                {
                        printf("\n\t\t\t");
                        for(j=0; j < col2; j++)
                            printf("  %d", C[i][j]);
                }
		

	// This line Prints the execution time of Multiplication Logic //
*/	printf("\n\n Time Elapsed for multiplication : %f seconds\n",(double)(stop-start)/CLOCKS_PER_SEC); 
	
	//*************************************************************//
	// Below Logic is to simply free the memory as huge amount of  //
	//   memory is allocated in the above code                     //
	// Please note array B isn't freed as it is defined as global  //
	// variable and the scope is limited to execution time         //
	//*************************************************************//

	// free memory used
        for(i=0; i<row1; i++)
               free(A[i]);
        //for(i=0; i<row2; i++)
        //       free( B[i]);
        for(i=0; i<row1; i++)
               free(C[i]);
	free(A);
	//free(B);
	free(C);
	return(0);
	
}
//*************************************************************//
//                  END OF PROGRAM                             //
//*************************************************************//


