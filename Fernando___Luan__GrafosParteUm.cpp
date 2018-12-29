#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

// Fernado de Almeida Noronha - 101426348
// Luan Lourenço Esteves - 101426879

bool espelho(int matriz[10][10], int ordem)
{
    //verificando espelho
	bool grafo = true;
	for(int i=0;i<ordem && grafo==true;i++)
    {
        for(int j=0; j < ordem && grafo == true; j++)
        {
            if(matriz[i][j]!=0)
                if(matriz[j][i]!=0)
                    grafo=true;
                else
                    grafo = false;
        }
    }

    return grafo;

}

bool testesimples(int matriz[10][10], int ordem)
{
    //verifica se é simples
    bool simples = true;
     for(int i=0, j=0; j < ordem; i++, j++)
        {
            if(matriz[i][j]!=0)
                simples=false;
        }
    return simples;
}

void testegrafo(int matriz[10][10], int ordem)
{
        bool completo;
        //verifica se é simples
        bool simples = testesimples(matriz, ordem);
        bool regular = true;

        int grau, grauBase;
        for(int i=0;i<ordem && regular==true;i++)
        {
            grau = 0;
            for(int j=0; j < ordem ; j++)
            {
                if(matriz[i][j]!=0)
                    grau++;
                if(i==0)
                    grauBase = grau;
            }
            if(grau != grauBase)
                regular = false;
        }


        int cont = 0, result = ((ordem-1)*ordem)/2;
        for(int i=0; i<ordem; i++)
        {
            grau = 0;
            for(int j=0; j < ordem ; j++)
            {
                if(matriz[i][j]!=0)
                    cont++;
            }
        }
        if(cont/2 == result)
            completo = true;
        else
            completo = false;

        printf("\n\n");
        printf("Grafo");
        if(simples)
            printf("\nSimples");
        if(regular)
            printf("\n%d Regular", grauBase);
        if(completo)
            printf("\nK - %d Completo", ordem);

}

void testedigrafo(int matriz[10][10], int ordem)
{
        //verifica se é simples
        bool simples = testesimples(matriz, ordem);
        bool regular = true;
        int grauR, grauBaseR, grauE, grauBaseE;

        for(int i=0;i<ordem && regular==true;i++)
        {
            grauE = 0;
            for(int j=0; j < ordem ; j++)
            {
                if(matriz[i][j]!=0)
                    grauE++;
                if(i==0)
                    grauBaseE = grauE;
            }
            if(grauE != grauBaseE)
                regular = false;
        }

        if(regular)
        {
            for(int j=0;j<ordem && regular==true;j++)
            {
                grauR = 0;
                for(int i=0; i < ordem ; i++)
                {
                    if(matriz[i][j]!=0)
                        grauR++;
                    if(j==0)
                        grauBaseR = grauR;
                }
                if(grauR != grauBaseR)
                    regular = false;
            }
        }


        printf("\n\n");
        printf("Digrafo");
        if(simples)
            printf("\nSimples");
        if(regular)
            printf("\nE %d Regular\nR %d Regular", grauBaseE, grauBaseR);
}

int main()
{
	int ordem = 0, perW, perH;
	bool regular, completo;

	printf("Informe a Ordem do Grafo:");
	scanf("%d", &ordem);
	char v[ordem], v1,v2;
	int matriz[10][10], numero;

	for(int i = 0; i<ordem; i++)
		for(int j = 0; j<ordem; j++)
			matriz[i][j] = 0;

	for(int i = 0; i <ordem; i++)
	{
		printf("\nInforme o Vertice[%d]", i);
		scanf("%s", &v[i]);
	}

	printf("Informe o Valor:");
	scanf("%d", &numero);

	while(numero != 0)
	{
	    fflush(stdin);
		printf("Informe a Vertice H:");
		scanf("%c", &v1);
        fflush(stdin);
		printf("Informe a Vertice W:");
		scanf("%c", &v2);
		perH = 0;
		while(v1 != v[perH])
		perH++;

		if(perH>=ordem)
		{
			printf("Nao Encontrado");
		}else
		{
			perW = 0;
			while(v2 != v[perW])
			perW++;

			if(perW>=ordem)
			{
				printf("Nao Encontrado");
			}else{
				matriz[perH][perW] = numero;
			}
		}
        fflush(stdin);
		printf("Informe o Valor:");
		scanf("%d", &numero);
	}

	printf("  ");
	for(int i = 0; i<ordem; i++)
	printf(" %c", v[i]);
	printf("\n\n");

	for(int i = 0; i<ordem; i++)
	{
		printf("%c ", v[i]);
		for(int j = 0; j<ordem; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}


	//é grafo?
	bool grafo = espelho(matriz, ordem);



	//verifica se é simples
    //bool simples = simples(matriz);


    if(grafo)
    {
        //grafo
        testegrafo(matriz, ordem);
    }
    else
    {
        //digrafo
        testedigrafo(matriz, ordem);
    }

    getch();
}










