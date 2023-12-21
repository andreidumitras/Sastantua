# Sastantua
 - (C) August 2016
 - Individual bootcamp project
 - Academy+Plus Cluj-Napoca

# Description
Sastantua is a project that displays the Sastantua Pyramid at stdout. The size of the pyramid is given as a command line argument.

# Implementation
The project was implemented in the sastantua.c file, with the help of ft_putchar() function. The only allowed function was write(3), from <unistd.h>. The main file is here for test purposes.

The project was the first individual project from the C Bootcamp of the Academy+Plus. It was originally design for Linux/macOS.

# Usage
To compile the Sastantua project, one can use the gcc compiler:
```bash
gcc -o sastantua main.c ft_putchar.c sastantua.c
```
Sastantua can be run as follows:
```bash
./sastantua 5
# usage: ./sastantua [size]
```
