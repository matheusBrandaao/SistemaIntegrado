#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char string[20];
char imposto[40] = "IsentoDoImpostoDeRenda!";

int main()
{
sprintf(string, "date\n %s", imposto);
system(string);
}
