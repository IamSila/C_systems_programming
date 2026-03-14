#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
  char content[10];
  int i;

  char *content_ptr = (char *)malloc(sizeof(char) * 30);

  snprintf(content, sizeof(content), "%s\n", "Hello");
 
  for (i = 0; i < sizeof(content); i++)
  {
    content_ptr[i] = content[i];
  }
  content_ptr[i + 1] = '\0';

  i = 0;

  while (content_ptr[i] != '\n')
  {
     printf("%c", (content_ptr[i]));
    i++;
  }
   
  free(content_ptr);
  return (0);
}
