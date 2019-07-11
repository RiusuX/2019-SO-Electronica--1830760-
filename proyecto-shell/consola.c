#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

void substring(char s[], char sub[], int p)
{
   	int c = 0;
   	while (c < strlen(s))
	{
  		sub[c] = s[p+c];
  		c++;
   	}
   	sub[c] = '\0';
}
char *trim(char *s)
{
	char *start = s;
	while(*start && isspace(*start))
		++start;
	char *i = start;
	char *end = start;
	while(*i)
	{
		if( !isspace(*(i++)) )
			end = i;
	}
	*end = 0;
	return start;
}

void environset(char* argv0)
{
	//codigo para establecer en cwd la variable de entorno shell
	char cwd[250];
	char process_name[80];
	substring(argv0,process_name,1);
	getcwd(cwd, sizeof(cwd));
	strcat(cwd, process_name);
	setenv("SHELL", cwd, 1);
}

char *stringout(char *command)
{
	char *out;
   	char string[2] = ">";
	char *token;
	token = strtok(command, string);
	out   = token;
	token = strtok(NULL, string);
	if (token != NULL)
	{
		token    = trim(token);
		int file = open(token, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
		dup2(file,STDOUT_FILENO);
		close(file);
	}
	return out;
}
char *stringin(char *command)
{
	char *in;
	char string[2] = "<";
	char *token;
	token = strtok(command, string);
	in    = token;
	token = strtok(NULL, string);
	if (token != NULL)
	{
		token    = trim(token);
		int file = open(token, O_RDONLY);
		dup2(file,STDIN_FILENO);
		close(file);
	}
	return in;
}

void argumentsshell(char *command, char **args)
{
	char string[2] = " ";
	char *token;
	token = strtok(command, string);
	token = trim(token);
	args[0] = token;
	token = strtok(NULL, string);
	int i = 1;
	while( token != NULL ) 
	{
		token = trim(token);
		args[i] = token;
		token = strtok(NULL, string);
		i++;
	}
	args[i] = NULL;
}


int main(int argc, char** argv)
{
	pid_t pid;
	char command[150];
	char cd[150];
	environset(argv[0]);

	int ilast = 0;
	int i = 0;
	char commands[100][50];

	if (argv[1] != NULL)
	{
		FILE *file;
	 	char characters[150];
	 	file = fopen(argv[1],"r");

	 	if (file == NULL)
	 		exit(1);
	 	else
	    {
	 	    while (feof(file) == 0)
	 	    {
	 			fgets(characters,150,file);
	 			strcpy(commands[i], characters);
	 			i++;
	 	    }
	 	    ilast = i;
	    }
	   	fclose(file);
	   	i = 0;
	}

	
  	while (1)
	{
		if(ilast > 0)
		{
			if (i==ilast)
				exit(0);
			strcpy(command, commands[i]);
			i++;
		}
		else
		{
			char cwd[250];
			getcwd(cwd, sizeof(cwd));
			printf("%s> ", cwd);
    		gets(command);	
		}

		if (strcmp(command,"quit") == 0)
			exit(0);
  		if (strcmp(command,"dir") == 0)
			system("ls");
 	 	else if(strcmp(command,"cd") == 0)
 	 		system("pwd");
		else if(strncmp(command,"cd ",3) == 0)
		{
			substring(command, cd, 3);
			if(cd[0]==32 || cd[0]==0)
				system("pwd");
			else  if (chdir(cd) != 0)  
				printf("Directory %s not found \n", cd);
		}
		else if (strcmp(command, "clr") == 0)
   			system("clear");
		else if(strcmp(command,"environ")==0)
			system("printenv");
		else if(strncmp(command,"echo ",5)==0)
			system(command);
		else if(strncmp(command,"pause",4)==0)
		{
			char enter;
			while(1)
			{
				enter = getchar();
				if(enter == 10)
					break;
			}
		}
		else if(strcmp(command,"help more")==0)
		{
			puts("i. cd <directory> - Change the current default directory to <directory>. If the");
			puts("<directory> argument is not present, report the current directory.");
			puts("ii. clr - Clear the screen.");
			puts("iii. dir <directory> - List the contents of directory <directory>.");
			puts("iv. environ - List all the environment strings.");
			puts("v. echo <comment> - Display <comment> on the display followed by a new line");
			puts("vi. help more - Display the user manual.");
			puts("vii. pause - Pause operation of the shell until 'Enter' is pressed.");
			puts("viii. quit - Quit the shell.\n");
			
			puts("Command line input is interpreted as program invocation.\n");
			
			puts("If the shell is invoked with a command line argument:");
			puts("myshell batchfile");
			puts("the batchfile is assumed to contain a set of command lines for the shell to process.");
			puts("When the end-of-file is reached, the shell exit.\n");
			
			puts("The shell support i/o-redirection on either or both stdin and/or stdout.");
			puts("That is, the command line");
			puts("programname arg1 arg2 < inputfile > outputfile");
			puts("will execute the program programname with arguments arg1 and arg2, the stdin");
			puts("FILE stream replaced by inputfile and the stdout FILE stream replaced by");
			puts("outputfile.");
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				char *shell = getenv("SHELL");
				char shellenv[80];
				sprintf(shellenv, "PARENT=%s", shell);
				char *envp[] = {shellenv, NULL};

				char *out = stringout(command);
				char *in  = stringin(out);
				char *args[100];
				argumentsshell(in, args);

				int execvpereturn;
				execvpereturn = execvpe(args[0], args, envp);
				if(execvpereturn == -1)
					exit(0);
			}
			else
				wait(NULL);
  		} 	
	}	
}