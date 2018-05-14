#include <stdio.h>
#include <conio.h>

#define n 10
main()
{
	float x1[n] = {1,	2,	3,	4,	5,	6,	7,	8,	9,	10};
	float x2[n] = {8,	2,	2,	2,	5,	7,	4,	6,	9.5,9.5};
	float d[n], s_pl = 0, s_min = 0, s = 0, tmp1, tmp2;
	float p, t;
	int i, j;
	printf("x1\tx2");

// Нахождение коэффициента ранговой корреляции Спирмена
    for(i = 0; i < n; i++)
	{
        d[i] = x1[i] - x2[i];
		s += d[i]*d[i];
		printf("\n%.1f\t%.1f", x1[i], x2[i]);
	}

    p = 1 - 6*s/(n*(n*n-1.0));

// Вывод расчетной таблицы
	for(i = 0; i < n; i++)
		printf("\n%.0f\t%.0f\t%.0f\t%.0f", x1[i], x2[i], x1[i] - x2[i],
			(x1[i] - x2[i]) * (x1[i] - x2[i]));
	printf("\n\t\t\t%.0f", s);

// Нахождение коэффициента ранговой корреляции Кендалла и вывод таблицы
	for(i = 0; i < n; i++)
	{
		printf("\n%.0f\t%.0f", x1[i], x2[i]);
		tmp1 = tmp2 = 0;
		for(j = i + 1; j < n; j++)
		{
            if(x2[j] > x2[i]) tmp1++;
			if(x2[j] < x2[i]) tmp2++;
		}
		printf("\t%.0f\t%.0f", tmp1, tmp2);
		s_pl += tmp1;
		s_min += tmp2;
	}
	printf("\n\t\t%.0f\t%.0f", s_pl, s_min);

	t = (s_pl - s_min)/(0.5*n*(n-1));

   	printf("\n\np = %f\nt = %f", p, t);
	getch();
	return 0;
}