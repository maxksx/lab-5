#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void genArray( double * A, unsigned int Size);

int main()
{
   unsigned int N;
   double * A, * B;
   double temp;

   unsigned int j;

   FILE * fp_input, * output, * outbin;

   fp_input = fopen("F:\\5.txt " , "r" );
   if( fp_input == NULL ){
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }

   fscanf(fp_input, "%u", &N);


   printf("%u", N);

   A = (double *) calloc(N, sizeof(double) );
   if( A == NULL ){
       printf("\nError");
       printf("\nPress any key to exit...");
       getch();
       exit(1);
   }


   genArray( A, N );

   output = fopen("F:\\6.txt", "w");
   if( output == NULL ){
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }


   for(j = 0;   j < N; j++)
      fprintf(output, "%lf\n", A[j] );


   outbin = fopen("F:\\5.bin ", "wb");
   if( outbin == NULL ){
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }


   fwrite(&N, sizeof(unsigned int), 1, outbin  );
   // for(j = 0;   j < N; j++)
   //  fwrite(&A[j], sizeof(double), 1, outbin  );
    fwrite(&A[0], sizeof(double), N, outbin  );
   // fwrite( A, sizeof(double), N, outbin  );

    if ( ( fclose(fp_input) != 0 ) || ( fclose(output) != 0 ) || ( fclose(outbin) != 0 ) )
      printf("\nError");

   outbin = fopen("F:\\5.bin", "rb");
   if( outbin == NULL ){
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }

   N = 0;
   fread(&N, sizeof(unsigned int), 1, outbin);
   printf("\n\nSize = %u", N);


   B = (double *)malloc(N * sizeof(double) );
   if( B == NULL ){
      printf("Error\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }

   fread( B, sizeof(double), N, outbin  );
   for(j=0; j<N; j++)
        printf("B[%u]=%.2lf", j, B[j]);


  free(A);
  free(B);

  if( fclose(outbin) != 0 ){
      printf("\n\n\nCannot close a file!!!");
      exit(1);
  }


    return 0;
}





void genArray( double * A, unsigned int N)
{
   int j;

   for( j = 0;  j < N;  j++ )
   {
      printf ("/nA[%d]=",j);
      scanf("%.2lf",&*(A+j));
   }
}
