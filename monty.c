#include "monty.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	char *arg;
	int value;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \t\n");
		line_number++;
		if (sscanf(line, "%31s%d", opcode, &value) == 2)
		{
			printf("Opcode: %s, Value: %d\n", opcode, value);
		}
		arg = strtok(NULL, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{
			if (!arg || !is_integer(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(line);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(arg));
		}
		else if (opcode && strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if(opcode && strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}

		free(line);
		line = NULL;
		len = 0;
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

