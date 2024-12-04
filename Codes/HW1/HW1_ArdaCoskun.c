#include <stdio.h>

int main()
{
  char courseSection[20] = "2";
  char studentId[20] = "240508008";
  char name[20] = "Arda Coskun";

  char labAssistantName[25] = "Muhammed Faruk Sahin";

  printf("%s, %s\n", studentId, name);
  printf("%s\n", courseSection);
  printf("%s", labAssistantName);

  return 0;
}
