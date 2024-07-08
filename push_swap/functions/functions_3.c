int check_duplicates(int *tab, int size)
{
    int i;
    int j;

    i = 0;
    while (i <= (size))
    {
        j = i + 1;
        while (j < size - 1)
        {
            if (tab[i] == tab[j])
                return (0);
            j++; 
        }
        i++;
    }
    return 1;
}

int main()
{
    int tab[3] = {1, 2, 1};
	if (!check_duplicates(tab, 3))
	{
		printf("error");
	}
}