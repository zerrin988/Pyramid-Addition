# **Pyramid Addition Program**  

This program recursively calculates the **Pyramid Addition** of an array of numbers. 
The program sums nearby/adjacent elements in the array until only one element remains. 
It also prints each step of the process with appropriate indentation to visualize the pyramid-like structure of the additions*.  
###### *For this explanation, there won't be a visual representation for the Pyramids, it will just be aligned to the left.

## Input
You have to manually change the input from the code as there is no Input mechanism impletmented

### **How It Works**  
1. **Array Summation**:  
   - Adds adjacent elements of the array.  
   - Continues summing until one number remains.  

2. **Recursive Process**:  
   - After summing, the new array replaces the old one.  
   - The process repeats with the new array until only one element is left.

3. **Example Run**:  
   - Input: `{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}`  
   - Output:  
     ```plaintext
     1  2  3  4  5  6  7  8  9  10  
     3  5  7  9  11  13  15  17  19  
     8  12  16  20  24  28  32  36  
     20  28  36  44  52  60  68  
     48  64  80  96  112  128  
     112  144  176  208  240  
     256  320  384  448  
     576  704  832  
     1280  1536  
     2816  
     Final Output: 2816
     ```

### **Main Components**  

#### **Printer Function**  
This function is for printing the current state of the array with proper indentation.

```c
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
      printf("    %d\t", array[changer]);
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
      printf("%d\t", array[changer]);
    }
    printf("\n");
  }
}
```

- **Indentation** is set by `tabCount` and printed before each array element.

#### **PyramidAddition Function**  
This function calculates the pyramid sum recursively.

```c
int PyramidAddition(int array[], int size, int tabCount)
{
  int OriginalSize = size;
  int NewArray[size - 1];
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
    return result;
  }
}
```

- **Summing**: Adds adjacent elements and creates a new array.
- **Recursion**: Continues the summing process until a single element is left.

#### **Main Function**  
```c
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Manually change input
    int size = sizeof(array) / sizeof(array[0]);
    int result = PyramidAddition(array, size, 0);
    int OriginalSize = size;
    int rubbish = 1;
    Printer(array, size, 0, OriginalSize);
    printf("\nFinal Output %d \n", result);
}
```

- **Input Array**: Array of integers for which pyramid addition will be performed.  
- **Output**: The final output of pyramid addition is displayed.

### **Notes in Implementation**  
- **Variable naming**: Variables can be named to something meaningfull as this code uses quite meaningless names(as a study conduct/research).

### **Compilation & Execution**  
```sh
gcc pyramid_addition.c -o pyramid_addition
./pyramid_addition
```

### **Example Output**  
```sh
1    2    3    4    5    6    7    8    9    10
3    5    7    9    11    13    15    17    19
8    12    16    20    24    28    32    36
20    28    36    44    52    60    68
48    64    80    96    112    128
112    144    176    208    240
256    320    384    448
576    704    832
1280    1536
2816

Final Output 2816
```
-------------
## License
This project is open-source and available under the [MIT License](LICENSE).
