#include <stdio.h>

#define TOP_SPACE    "\n\n\n\n\n"
#define BOTTOM_SPACE "\n\n\n\n\n"
#define OFFSET       "          "

int main()
{
  printf(TOP_SPACE);
  printf(OFFSET "IIIIIIIII\n");
  for(short i = 0; i <= 8; i++)
  {
    printf(OFFSET "   III\n");
  }
  printf(OFFSET "IIIIIIIII");
  printf(BOTTOM_SPACE);

  return 0;
}
