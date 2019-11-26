#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Define statements*/
#define ROWS 20
#define COLUMNS 40

int main (int argc, char *argv[])
{

    FILE *fp;
    int i;
    int k = 0;
    int a;
    int b = 0;
    int x;
    int m;
    int y = 0;
    int z;
    int v;
    int neighbours = 0;
    int grid = 0;
    char line[2000];
    char firstgen[ROWS][COLUMNS] = {""};
    char nextgen[ROWS][COLUMNS] = {""};
    int ticks;
    int tickscheck = 0;
    int ticksnull;
    char choice[10];
    int reduceSpace (char *line);

/*Checking if correct amount of arguments*/
if (argc > 3 || argc < 2)
{
    printf ("Error - invalid number of arguments\n");
    return (0);
}

/*Determining Tick value*/
if (argv[2] == NULL)
{
    ticks = 50;
}
else if (atoi(argv[2]) <= 0)
{
    printf ("Error - incorrect number of ticks, ticks must be > 0\n");
    return (0);
}
else if (atoi(argv[2]) >= 0)
{
    ticks = atoi(argv[2]);
}

/*Checking if file is openable*/
if ((fp = fopen(argv[1], "r")) == NULL)
{
    printf ("Error - could not open file\n");
    return (0);
}

/*Reading in the file*/
if ((fp = fopen(argv[1], "r")) != NULL)
{
    while (fgets(line, 2000, fp) != NULL && k < ROWS)
    {
        reduceSpace (line);
        for (i = 0; i < COLUMNS; i++)
        {
            firstgen[k][i] = line[i];
        }
        k++;
    }
    fclose(fp);
}

/*Converting 1's and 0's to X's and spaces*/
for (x = 0; x < 20; x++)
{
    for (m = 0; m < 40; m++)
    {
        if (firstgen[x][m] == '1')
        {
            firstgen[x][m] = 'X';
        }
        if (firstgen[x][m] == '0')
        {
            firstgen[x][m] = ' ';
        }
    }
}

/*Printing out the grid*/
system ("clear");

/*Top border*/
printf (" ");
while (b < 40)
{
    printf ("-");
    b++;
}
b = 0;
printf ("\n");

/*Contents of grid*/
while (grid < 20)
{
    printf ("|");
    a = 0;
    while (a < 40)
    {
        printf ("%c", firstgen[grid][a]);
        a++;
    }
    printf ("|");
    printf ("\n");
    grid++;
}

/*Bottom border*/
printf (" ");
while (b < 40)
{
    printf ("-");
    b++;
}
printf ("%d\n", ticks);

/*Asking to continue*/
while (y == 0)
{
    printf ("Start? (y or n)\n");
    fgets (choice, 10, stdin);
    if ((strcmp(choice, "y\n") == 0) || (strcmp(choice, "Y\n") == 0) || (strcmp(choice, "n\n") == 0) || (strcmp(choice, "N\n") == 0))
    {
        y = 1;
    }
    else
    {
        printf ("Error - incorrect answer (y or n)\n");
    }
}

if (strcmp(choice, "y\n") == 0 || strcmp(choice, "Y\n") == 0)
{

}
else
{
    return (0);
}

/*THE RULES*/
while (tickscheck < ticks)
{
    for (z = 0; z < 20; z++)
    {
        for (v = 0; v < 40; v++)
        {
            if (firstgen[z][v] == 'X')
            {
                if (firstgen[z-1][v-1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z-1][v] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z-1][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v-1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z][v-1] == 'X')
                {
                    neighbours++;
                }
                /*Rule 1*/
                if (neighbours < 2)
                {
                    nextgen[z][v] = ' ';
                }
                /*Rule 2*/
                if (neighbours == 2 || neighbours == 3)
                {
                    nextgen[z][v] = 'X';
                }
                /*Rule 3*/
                if (neighbours > 3)
                {
                    nextgen[z][v] = ' ';
                }
                neighbours = 0;
            }
            else if (firstgen[z][v] == ' ')
            {
                if (firstgen[z-1][v-1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z-1][v] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z-1][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v+1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z+1][v-1] == 'X')
                {
                    neighbours++;
                }
                if (firstgen[z][v-1] == 'X')
                {
                    neighbours++;
                }
                /*Rule 4*/
                if (neighbours == 3)
                {
                    nextgen[z][v] = 'X';
                }
                if (neighbours < 3 || neighbours > 3)
                {
                    nextgen[z][v] = ' ';
                }
                neighbours = 0;
            }
        }
    }

    int l = 0;

    for (i = 0; i < 20; i++)
    {
        for (x = 0; x < 40; x++)
        {
            if (firstgen[i][x] == nextgen[i][x])
            {
                l++;
            }
        }
    }
    if (l == 800)
    {
        return(0);
    }

    /*Setting firstgen to nextgen*/
    for (i = 0; i < 20; i++)
    {
        for (x = 0; x < 40; x++)
        {
            firstgen[i][x] = nextgen[i][x];
        }
    }

    /*Printing out the grid*/
    system ("sleep 0.25");
    system ("clear");

    /*Top border*/
    b = 0;
    a = 0;
    grid = 0;

    printf (" ");
    while (b < 40)
    {
        printf ("-");
        b++;
    }
    b = 0;
    printf ("\n");

    /*Contents of grid*/
    while (grid < 20)
    {
        printf ("|");
        a = 0;
        while (a < 40)
        {
            printf ("%c", firstgen[grid][a]);
            a++;
        }
        printf ("|");
        printf ("\n");
        grid++;
    }

    /*Bottom border*/
    printf (" ");
    while (b < 40)
    {
        printf ("-");
        b++;
    }
    tickscheck++;
    printf ("%d\n", tickscheck);

    if (tickscheck - 1 == ticks - 1)
    {
    y = 0;
    while (y == 0)
    {
        if (argv[2] == NULL)
        {
            printf ("Do you want to continue for 50 more ticks? (y or n)\n");
        }
        else
        {
            printf ("Do you want to continue for %d more ticks? (y or n)\n", atoi(argv[2]));
        }
        fgets (choice, 10, stdin);
        if ((strcmp(choice, "y\n") == 0) || (strcmp(choice, "Y\n") == 0) || (strcmp(choice, "n\n") == 0) || (strcmp(choice, "N\n") == 0))
        {
            y = 1;
        }
        else
        {
            printf ("Error - incorrect answer (y or n)\n");
        }
    }
        if (strcmp(choice, "y\n") == 0 || strcmp(choice, "Y\n") == 0)
        {
            if (argv[2] == NULL)
            {
                ticksnull = 50;
                ticks = ticksnull + tickscheck;
            }
            else
            {
                ticks = atoi(argv[2]) + (tickscheck);
            }
        }
        else
        {
            return (0);
        }
    }
}

return (0);

}
