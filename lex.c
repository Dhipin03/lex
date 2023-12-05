#include<stdio.h>
#include<string.h>
#include<ctype.h>

int iskey(char str[])
{
    int f = 0;
    char keywords[4][10] = {"int", "float", "void", "main"};
    for (int i = 0; i <= 4; i++)
    {
        if (strcmp(keywords[i], str) == 0)
            f = 1;
        break;
    }
    return f;
}

int main()
{
    FILE *fp1;
    fp1 = fopen("i.txt", "r");
    char str[100], ch[100], op[] = "+-*/=", sy[] = ";{}";
    int i, j, f = 0, s = 0, c = 0;

    while (fscanf(fp1, "%s", ch) == 1)
    {
        for (i = 0; i < 5; i++)
        {
            if (*ch == op[i])
            {
                printf("%s is operator\n", ch);
                f = 1;
            }
        }
        for (i = 0; i < 2; i++)
        {
            if (*ch == sy[i])
            {
                printf("%s is symbol\n", ch);
                s = 1;
            }
        }
        for (i = 0; i < 9; i++)
        {
            if (isdigit(*ch))
            {
                printf("%s is constant\n", ch);
                f = 1;
                s = 1;
                break;
            }
        }

        if (iskey(ch) == 1)
            printf("%s is keyword\n", ch);
        else
        {
            if (f == 0 && s == 0)
                printf("%s is identifier\n", ch);
        }
    }

    fclose(fp1);
    return 0;
}
