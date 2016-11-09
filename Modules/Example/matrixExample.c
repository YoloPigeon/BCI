#define BCI_USE_HEAP
#define BCI_MATRIX_O2
#include "..\..\BCI.h"

task main()
{
	clearDebugStream();

	heap_Init();

  matrix m1, m2, m3;
  matrix_Initialize(&m1, 3, 3);
  matrix_Initialize(&m2, 3, 3);
  matrix_Initialize(&m3, 3, 3);

  float m1Vals[9] = {1,2,3,
  	                 4,5,6,
  	                 7,8,9};
  matrix_Set(&m1, m1Vals);

  float m2Vals[9] = {11,12,13,
  	                 14,15,16,
  	                 17,18,19};
  matrix_Set(&m2, m2Vals);

  matrix_SubtractMatrix(&m1, &m2, &m3);
  for (int i = 0; i < 3; i++)
  {
  	for (int j = 0; j < 3; j++)
  	{
  		writeDebugStreamLine("%d", matrix_Get(&m3, i, j));
  	}
  }

  //Naive implementation takes 2889.6 milliseconds on average
  //Optimized naive implemenetation takes 872 milliseconds on average
 // for (int j = 0; j < 5; j++)
 // {
	//  long startTime, endTime;
	//  int i = 0;
	//  startTime = time1[T1];
	//  for (; i < 100000; i++)
	//  {
	//  	matrix_MultiplyByMatrix(&m1, &m2, &m3);
	//  }
	//  endTime = time1[T1];
	//  writeDebugStreamLine("Time taken: %d", endTime - startTime);
	//}
}
