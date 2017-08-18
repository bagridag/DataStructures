/*
Student Name: Burçak AGRIDAG
Student Number: 201140030
Project Number: 5
Operating System: {Windows[7]}
Compile Status: {Compiling}
Program Status: {Working}
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define init 100

char s[init];// s array is initially created
int n; //the length of the string that is given by the user
char seq[init]; // sequence array that holds the longest palindromic sequence

/*append method adds the given characters to a string*/
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

/*reverse method that reverses a string */
void reverse(char *string)
{
   int length, c;
   char *begin, *end, temp;

   length = string_length(string);

   begin = string;
   end = string;

   for ( c = 0 ; c < ( length - 1 ) ; c++ )
      end++;

   for ( c = 0 ; c < length/2 ; c++ )
   {
      temp = *end;
      *end = *begin;
      *begin = temp;

      begin++;
      end--;
   }
}

int string_length(char *pointer) //returns the length of the string
{
   int c = 0;

   while( *(pointer+c) != '\0' )
      c++;

   return c;
}


int max(int a, int b) // finds the maximum of given two numbers
{
    int max;
    if(a>b)
    {
        max= a;
    }
    else
    {
        max= b;
    }

    return max;

}

int longlength(const char*s, int a , int b)//returns the longest lengthed palindromic sequence
{
    if(b-a <=1)
    {
        return b-a;
    }
    else
    {
        if(s[a]==s[b])
        {

            return longlength(s,a+1, b-1)+2;
        }
        else
        {
        return max(longlength(s,a+1,b), longlength(s,a,b-1));
        }
    }
}
void pal(const char* s, int n ,const char* outputFile) //writes the longest palindrome into the output file
{
int i= 0;
   int j= n;
      while(i<j)
      {
          if(s[i]==s[j])
          {
              append(seq,s[i]); //appends s[i] to the end of initially empty sequence array
              i=i+1;
              j=j-1;


          }
          else if(longlength(s,i,j-1)> longlength(s,i+1, j))
          {

              j=j-1;
          }
          else
                {
              i= i+1;
                }
            }
          if(i==j)//when i becomes equal to j
            {
             append(seq, s[i]); //appends s[i] to the end of initially empty sequence array
            }

   FILE* output= fopen(outputFile, "wt");
     fprintf(output, "%d\n", longlength(s,0,n)+1);

        int k;

        for(k= 0; k<strlen(seq); k++) //prints out the first part of the palindrome
        {
            fprintf(output, "%c", seq[k]);

        }
            reverse(seq);
        for(k= 1; k<strlen(seq); k++)// since the second part is the reverse of the first part, prints the reverse of the palindrome
        {
            fprintf(output, "%c", seq[k]);
        }


    }
        void read_input_file(const char* inputFile ) {//reads the input file from the user
                int i,j;

            FILE* input = fopen(inputFile,"r");
                fscanf(input,"%d" ,&n);

                    printf("%d\n", n);// stores the length
                    for(i= 0; i<n; i++)
                        {
                    fscanf(input, "%s", &s[i]);// stores the string into an array
                        }
                    for(i=0; i<n; i++)
                        {
                        printf("%c", s[i]);
                        }
                        printf("\n");
                }


            int main(int argc, char* argv[])
                {
                read_input_file(argv[1]);
                pal(s,n,argv[2]);
                }


