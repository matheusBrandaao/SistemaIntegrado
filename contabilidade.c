#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
int status;
int sal;

void sinais(int signum)
{
switch(signum)
{
case SIGUSR1:
printf("Sinal recebido. Aguardar a conclusão do processo filho!");
break;
case SIGUSR2:
printf("Sinal recebido. Ainda em processamento...");
break;
}

}
void abreNavegador()
{
char string[20];
char url[] = "www.receita.fazenda.gov.br";
sprintf(string, "firefox --new-window %s", url);
system(string);
}

void contabilidade(int salario)
{
sal = (salario/12);
if(sal < 2000)
{
pid_t pid = fork();
switch(pid){
	case -1:
	perror("Erro no fork\n");
	exit(-1);
	break;
	
	case 0:
	system("./simplificado");
	printf("Filho, PID: %d \n Pai, PID: %d \n", getpid(), getppid());
	default:
	printf("Filho, PID: %d \n Pai, PID: %d \n", getpid(), getppid());
	pid = wait(&status);
	printf("Pai: Filho (PID: %d) terminou, Status = %d", getpid(), WEXITSTATUS(status));
}
printf("PID: %d terminando...\n", getpid());
}
if(sal >= 2000)
{
abreNavegador();
}
}

int main(int argc, char *argv[])
{
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = &sinais;
if(argc == 1){
printf("Não foi passado o salario por linha de comando\n");
}else{
contabilidade(atoi(argv[1]));

if(sigaction(SIGUSR1, &sa, NULL) != 0){
perror("Falha ao istalar tratador de sinal SIGUSR1");
exit(-1);
}
if(sigaction(SIGUSR2, &sa, NULL) != 0){
perror("Falha ao istalar tratador de sinal SIGUSR2");
exit(-1);
}
for(;;){}
return 0;
}
}
