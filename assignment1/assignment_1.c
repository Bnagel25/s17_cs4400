/* Ben Nagel
   U0806348 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a_mode(char *arg, int print);
int b_mode(char *arg, int print);
int c_mode(char *arg, int print);


int main(int argc, char *argv[])
{
  // Parse Inputted Arguments, Handle each mode from main
  if (argc == 1)
  {
    printf("Not Enough Arguments\n");
    return 0;
  }
  else if (argc == 2) 
  {
    a_mode(argv[1], 0);
    return 1;
  }
  else if(argc == 3) 
  {
    char *str = argv[2];
    if(strcmp(argv[1],"-t") == 0)
      {
	if(strcmp(argv[2], "-a") != 0 || strcmp(argv[2], "-b") != 0 || strcmp(argv[3], "-a") != 0)
	  {
	    a_mode(str, 1);
	    b_mode(str, 1);
	    c_mode(str, 1);
	  }
	else
	  {
	    printf("Error In Argument Parsing, Please Provide(-t, -a, -b, -c)\n");
	    return 0;
	  }
      }
    else if (strcmp(argv[1], "-a") == 0)
      {
	a_mode(str, 0);
      }
    else if (strcmp(argv[1], "-b") == 0)
      {
	b_mode(str, 0);
      }
      else if (strcmp(argv[1], "-c") == 0)
      {
	c_mode(str, 0);
      }
      else
	{
	  a_mode(argv[1], 0);
	  a_mode(str, 0);
	}
  }
  else if (argc > 3)
    {
      char *str = argv[3];
      if(strcmp(argv[1], "-t") == 0)
	{
	  if (strcmp(argv[2], "-a") == 0)
	    {
	      a_mode(str, 1);
	    }
	  else if (strcmp(argv[2], "-b") == 0)
	    {
       	      b_mode(str, 1);
	    }
	  else if (strcmp(argv[2], "-c") == 0)
	    {
	      c_mode(str, 1);
	    }
	  else
	    {
	      int i;
	      for(i = 2; i < 4; i++)
		{
		  a_mode(argv[i], 1);
		  b_mode(argv[i], 1);
		  c_mode(argv[i], 1);
		}
	    }
	}
      else if(strcmp(argv[2], "-t") == 0)
	{
	  if(strcmp(argv[1], "-a") == 0)
	    {
	      a_mode(str, 1);
	    }
	  else if(strcmp(argv[1], "-b") == 0)
	    {
	      b_mode(str, 1);
	    }
	  else if(strcmp(argv[1], "-c") == 0)
	    {
	      c_mode(str, 1);
	    }
	}
      else
	{
	  printf("Error bad Arguments \n");
	  return 0;
	}
    }
  else
    {
      printf("ERROR: Bad Arguments \n");
      return 0;
    }
  return 1;

}


/*
  Method used to handle -a mode
*/
int a_mode(char *arg, int print)
{
  // Check first repitions of "j"
  int i = 0;
  if(arg[0] == 106)
    {
      for(i = 1; i < strlen(arg); i++)
	{
	  if(arg[i] != 106)
	    {
	      break;
	    }
	}
    }
  // Check odd number of 's'
  int count = 0;
  for (i = i; i < strlen(arg); i++)
  {
    if (arg[i] == 's')
    {
      count = count + 1;
    }
    else 
      {
	break;
      }
  }
  if(!count&1)
  {
    if(!print)
      {
	printf("no\n");
      }
    return 0;
  }
  // Check an odd number of uppercase letters
  count = 0;
  for (i = i; i < strlen(arg); i++)
  {
    if(arg[i] >= 65 && arg[i] <= 90)
    {
      // Swap 'A' and 'D'
      if(arg[i] == 68)
	{
	  arg[i] = 'A';
	}
      else if (arg[i] == 65)
	{
	  arg[i] = 'D';
	}
      count = count + 1;
    }
    else
      {
	break;
      }
  }
    if(!count&1)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
    if(print)
      {
	printf("%s\n",arg);
	return 1;
      }

    printf("yes\n");
    return 1;
}

/*
  Method used to handle -b mode
 */
int b_mode(char *arg, int print)
{
  // Check first repitions of "b"                                                                                                  
  int i = 0;
  if(arg[0] == 98)
    {
      for(i = 1; i < strlen(arg); i++)
        {
          if(arg[i] != 98)
            {
              break;
            }
        }
    }
  // Check if decimal match is satisfied                                                                                            
  int decimal_count = 0;
  char *nums;
  nums = (char *) malloc(15); 
  for (i = i; i < strlen(arg); i++)
    {
      if (arg[i] >= 48 && arg[i] <= 57)
	{
	  nums[decimal_count] = arg[i];
	  decimal_count = decimal_count + 1;
	}
      else
	{
	  break;
	}
    }
  if(decimal_count > 3)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }

  // Check if 'n' character is satisfied                                                                                       
  int count = 0;
  for (i = i; i < strlen(arg); i++)
    {
      if (arg[i] == 110)
        {
          count = count + 1;
        }
      else
	{
	  break;
	}
    }
  if(count < 4 || count > 8)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    } 
  // Check odd number of UpperCase Letters is satisfied
  int up_count = 0;
  for (i = i; i < strlen(arg); i++)
    {
      if(arg[i] >= 65 && arg[i] <= 90)
	{                                                                             	    
	 up_count = up_count + 1;
	}
      else
	{
	  break;
	}
    }
  if(!up_count&1)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
  // Check if pattern has the odd positioned numbers of part 2
  int j;
  for(i = i; i < strlen(arg); i++)
    {
      for(j = 1; j < strlen(nums); j = j + 2)
	{
	  if(arg[i] == nums[j])
	    {
	      break;
	    }
	  else
	    {
	      if(!print)
		{
		  printf("no\n");
		}
	      return 0;
	    }
	}
    }

  // Add one 'G' before each 'H'
  char *str;
  str = (char *) malloc(15);
  // Find H
  int added_space = 0;
  for (i = 0; i < strlen(arg); i++)
    {
      if(arg[i] == 72)
	{
	  str[i] = 'G';
	  added_space = added_space + 1;
	}
      str[i + added_space] = arg[i];
    }
  // TODO: Test the Removal
  if(print)
    {
      printf("%s\n", str);
      return 1;
    }
  printf("yes\n");
  return 1;
}

/*
  Method that handles -c mode
 */
int c_mode(char *arg, int print)
{
  // Check for 2 or more 'd's
  int i;
  int count = 0;
  for (i = 0; i < strlen(arg); i++)
    {
      if (arg[i] == 100)
	{
	  count = count + 1;
	}
      else
	{
	  break;
	}
    }
  if(count < 2)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
  // Check between 1-3 decimal digits
  int decimal_count = 0;
  char *nums;
  nums = (char *) malloc(15);
  for (i = i; i < strlen(arg); i++)
    {
      if (arg[i] >= 48 && arg[i] <= 57)
        {
	  nums[decimal_count] = arg[i];
          decimal_count = decimal_count + 1;
        }
      else
	{
	  break;
	}
    }
  if(decimal_count > 3 && decimal_count < 1)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
  // Check for odd number repititions of 'u'
  count = 0;
  for (i = i; i < strlen(arg); i++)
    {
      if (arg[i] == 117)
        {
          count = count + 1;
        }
      else
	{
	  break;
	}
    }
  if(!count&1)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
  // Check that X is reversed
  char *revnums;
  revnums = (char *) malloc(15);
  decimal_count = 0;
  for(i = i; i < strlen(arg); i++)
    {
      if(arg[i] >= 48 && arg[i] <= 57)
	{
	  revnums[decimal_count] = arg[i];
	  decimal_count = decimal_count + 1;
	}
      else
	{
	  break;
	}
    }
  // Reverse the string using K&R algorithm
  int length = strlen(revnums);
  int c,k, j;
  for (k = 0, j = length - 1; k < j; k++,j--)
    {
      c = revnums[k];
      revnums[k] = revnums[j];
      revnums[j] = c;
    }
  if(strcmp(revnums, nums) != 0)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
   // Check Odd number of uppercase characters
  int up_count = 0;
  for (i = i; i < strlen(arg); i++)
    {
      if(arg[i] >= 65 && arg[i] <= 90)
        {
	  up_count = up_count + 1;
        }
      else
        {
          break;
        }
    }
  if(!up_count&1)
    {
      if(!print)
	{
	  printf("no\n");
	}
      return 0;
    }
  //TODO: Remove all 'F's                                                                                                       
  char *str;
  str = (char *) malloc(15);                                                                                                            int added_space = 0;
  for (i = 0; i < strlen(arg); i++)
    {
      if(arg[i] == 70)
        {
          added_space = added_space + 1;
	  continue;
        }
      str[i - added_space] = arg[i];
    }
  if(print)
    {
      printf("%s\n",str);
      return 1;
    }
  printf("yes\n");
  return 1;
  
}
