#include <stdio.h>
int Printer(int array[], int size, int tabCount, int OriginalSize)
{
  if(OriginalSize % 2 == 0)
  {
    for(int changer = 0; changer < tabCount / 2; changer++)
    {
      printf("\t");
    }
    for(int changer = 0; changer < size; changer++)
    {
      printf("    %d\t",array[changer]);
    }
    printf("\n");
  }
  else
  {
    for(int changer = 0; changer < tabCount / 2; changer++)
    {
      printf("\t");
    }
    for(int changer = 0; changer < size; changer++)
    {
      printf("%d\t",array[changer]);
    }
    printf("\n");
  }
}
int PyramidAddition(int array[], int size, int tabCount)
{
  int OriginalSize = size;
  int NewArray[size - 1] ;
  int changer = 0 ;
  int StupidArrayReplacement = 0 ;
  for(changer = 0; changer < size - 1; changer++)
  {
    NewArray[changer] = array[changer] + array[changer + 1];
  }

  int NewSize = sizeof(NewArray) / sizeof(NewArray[0]);
  if(NewSize == 1)
  {
    StupidArrayReplacement = NewArray[0];
    Printer(NewArray, NewSize, tabCount, OriginalSize);
    return StupidArrayReplacement;
  }
  else
  {
    int result = PyramidAddition(NewArray, NewSize, ++tabCount);
    Printer(NewArray, NewSize, tabCount, OriginalSize);
    return result ;
  }
}
int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10}; //Manually change input
	int size = sizeof(array) / sizeof(array[0]);
	int result = PyramidAddition(array, size, 0);
  int OriginalSize = size;
  int rubbish = 1;
  Printer(array, size, 0, OriginalSize);
  printf("\nFinal Output %d \n",result);
}
