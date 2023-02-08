#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int ac, char **argv)
{
	char *prompt = "(MYSHELL) $ ";
	char *lineptr;
	size_t n = 0;
	ssize_t ncharout;
	
	char *lineptrcpy = NULL;
	const char *delim = " \n";
	char *token;
	int numtokens = 0;
	(void)ac;
	int i;

	while (1)
	{
		printf("%s", prompt);

		ncharout = getline(&lineptr, &n, stdin);
		if (ncharout == -1)
		{
			printf("EXITING SHELL\n");
			return (-1);
		}


		/*allocate space for copy of lineptr*/

		lineptrcpy = malloc(sizeof(char) * ncharout);
		if (lineptrcpy == NULL)
		{
			printf("memory allocation error\n");
			return (-1);
		}

		/*copy lineptr to lineptrcpy since lineptr will be
		 * destroyed after strtok ends*/

		strcpy(lineptrcpy, lineptr);
		/******splite the lineptr into array of strings to get commands***/

		/*1-calculate total no of tokes */

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			numtokens++;
	                token = strtok(NULL, delim);
		}
		numtokens++;
		/* Allocate space to hold the array of strings */
			argv = malloc(sizeof(char *) * numtokens);
		/* Store each token in the argv array */
			token = strtok(lineptrcpy, delim);
        for (i = 0; token != NULL; i++){
           argv[i] = malloc(sizeof(char) * strlen(token));
             strcpy(argv[i], token);
            token = strtok(NULL, delim);
          }
	        argv[i] = NULL;
	        printf("%s\n", lineptr);
        /* free up allocated memory */ 
        free(lineptr);
	free(argv);
    free(lineptrcpy);
} 
	    return (0);
}
