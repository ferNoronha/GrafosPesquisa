#include<stdio.h>
#include<conio.h>
#include<string.h>

struct TpGrafo
{
    int v, a, g, matriz[10][90];
    char vetV[10], vetA[90][3];
    bool simples, regular, completo;
};

void simples(TpGrafo &g)
{
    int cont;
    for(int i=0; i<g.a && g.simples==true; i++)
	{
		cont=0;
		for(int j=0; j<g.v; j++)
		{
			if(g.matriz[j][i]!=0)
				cont++;

		}
		if(cont==1)
			g.simples=false;
	}
	
}

void regularD(TpGrafo &g)
{
	int cont=0;
	for(int i=0;i<g.v && g.regular==true;i++)
	{
		for(int j=0; j<g.a;j++)
		{
			if(g.matriz[j][i]!=0)
				cont+=g.matriz[j][i];
		}
		if(cont!=0)
			g.regular=false;
	}

}

void regularG(TpGrafo &g)
{
    int cont=0, maior= 999;
    for(int i=0; i<g.v && g.regular==true; i++)
    {
        cont=0;
        for(int j=0; j<g.a; j++)
        {
            if(g.matriz[i][j]!=0)
                cont++;
        }
        if(i==0)
            maior=cont;
        else
            if(cont!=maior)
                g.regular = false;
    }
}

void completo(TpGrafo &g)
{
    int cont=0;
    for(int i=0; i<g.v && g.completo==true; i++)
    {
        cont=0;
        for(int j=0; j<g.a; j++)
        {
            if(g.matriz[i][j]!=0)
                cont++;
        }
        if(cont != g.v-1)
            g.completo = false;
    }
}

void alocarG(TpGrafo &g)
{
    int k=0, val;
    int pe, pr;
    char emis, rece;

    while(k<g.a)
    {
        fflush(stdin);
        printf("\nDigite a aresta %d",k);
        scanf("%s",&g.vetA[k]);

        printf("\nDigite o valor: ");
        scanf("%d",&val);
        emis = g.vetA[k][0];
        rece = g.vetA[k][1];

        for(int i=0; i<g.v; i++)
        {
            if(g.vetV[i]==emis)
                pe=i;
            if(g.vetV[i]==rece)
                pr=i;
        }

        g.matriz[pe][k]=val;
        g.matriz[pr][k]=val;
        k++;
    }
}

void alocarD(TpGrafo &g)
{
	int	k=0, val=0;
	int pe=0, pr=0;
	char emis, rece;
	while(k<g.a)
    {
        fflush(stdin);
        printf("\nDigite a aresta %d",k);
        scanf("%s",&g.vetA[k]);

        printf("\nDigite o valor: ");
        scanf("%d",&val);
        emis = g.vetA[k][0];
        rece = g.vetA[k][1];

        for(int i=0; i<g.v; i++)
        {
            if(g.vetV[i]==emis)
                pe=i;
            if(g.vetV[i]==rece)
                pr=i;
        }

        g.matriz[pe][k]=val*-1;
        g.matriz[pr][k]=val;
        k++;
    }
	
}
void exibe(TpGrafo g)
{
    printf("\n\n*********************RESULTADO*********************\n");

    for(int i = 0; i<g.a; i++)
        printf(" %s", g.vetA[i]);
    printf("\n");

    for(int i=0; i<g.v; i++)
    {
        printf("%c", g.vetV[i]);
        for(int j=0; j<g.a; j++)
        {
            printf(" %d", g.matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    if(g.g == 1)
        printf("\nGRAFO");
    else
        printf("\nDIGRAFO");

    if(g.simples)
    {
        printf("\nSIMPLES");
        if(g.regular)
            printf("\nREGULAR");
        else
        {
        	printf("\nNao eh regular");
        }
        if(g.g==1)
        {
        	if(g.completo)
            	printf("\nCOMPLETO");	
            else
            	printf("\nNao eh completo");
            	
        }
        else
        {
        	printf("\nNao eh completo");
        }

    }
    else
    {
    	printf("\nNao eh simples");
    	
    	printf("\nNao eh regular");
    	
    	printf("\nNao eh completo");
    }

    getch();
}



int main()
{
    TpGrafo grafo;
    grafo.simples = true;
    grafo.regular = true;
    grafo.completo = true;

    printf("### Matriz Incidencia ###\n");
	printf("0- Digrafo 1- Grafo: ");
	scanf("%d",&grafo.g);
	printf("Digite o numero de Vertices:");
	scanf("\n%d",&grafo.v);
	printf("\nDigite o numero de Aresta:");
	scanf("\n%d",&grafo.a);

	//recebe as vertices
	fflush(stdin);
	for(int i = 0; i <grafo.v; i++)
	{
		printf("\nInforme o Vertice[%d]", i);
		scanf("%s", &grafo.vetV[i]);
	}

	//zera matriz
	for(int i=0; i<grafo.v; i++)
		for(int j=0; j<grafo.a; j++)
			grafo.matriz[i][j] = 0;

	if(grafo.g==1)
	{
		alocarG(grafo);
		simples(grafo);
		if(grafo.simples==true)
	    {
	    	regularG(grafo);
	    	completo(grafo);
		}
		exibe(grafo);
	}
    else
    {
    	alocarD(grafo);
    	simples(grafo);
    	if(grafo.simples==true)
    	{
    		regularD(grafo);
    	}
    	exibe(grafo);
	}
   
}


/*int mainffgfg()
{
	int vertice=0, gd = 0, aresta=0;
	char emis, rece;
	int cont=0;
	bool simples=true;
	int maior=999;
	bool regular= true;
	int k=0, pe, pr, val;

	printf("### Matriz Incidencia ###\n");
	printf("0- Grafo 1- Digrafo: ");
	scanf("%d",&gd);
	printf("Digite o numero de Vertices:");
	scanf("\n%d",&vertice);
	printf("\nDigite o numero de Aresta:");
	scanf("\n%d",&aresta);

	int nm; // numero maximo
	nm = ((vertice-1)*vertice)/2;
	int mat[10][aresta];

	char teste[vertice], taresta[aresta][5];

	//recebe as vertices
	fflush(stdin);
	for(int i = 0; i <vertice; i++)
	{
		printf("\nInforme o Vertice[%d]", i);
		scanf("%s", &teste[i]);
	}

	//zera matriz
	for(int i=0; i<vertice; i++)
		for(int j=0; j<aresta; j++)
			mat[i][j] = 0;

	if(gd==0)
	{
	    //recebe aresta
		k=0;
		while(k<aresta)
		{

			fflush(stdin);
			printf("\nDigite a aresta %d",k);
			scanf("%s",&taresta[k]);

			printf("\nDigite o valor: ");
			scanf("%d",&val);
			emis = taresta[k][0];
			rece = taresta[k][1];

			for(int i=0; i<vertice; i++)
			{
				if(teste[i]==emis)
					pe=i;
				if(teste[i]==rece)
					pr=i;
			}

			mat[pe][k]=val;
			mat[pr][k]=val;
			k++;
		}

		//exibe
		printf("\n\n");
		for(int i = 0; i<aresta; i++)
			printf(" %s", taresta[i]);
		printf("\n");

		for(int i=0; i<vertice; i++)
		{
			printf("%c", teste[i]);
			for(int j=0; j<aresta; j++)
			{
				printf(" %d", mat[i][j]);
			}
			printf("\n");
		}
		getch();
		//validacao
		//simples
		for(int i=0; i<aresta && simples==true; i++)
		{
			cont=0;
			for(int j=0; j<vertice; j++)
			{
				if(mat[j][i]!=0)
					cont++;

			}
			if(cont==1)
				simples=false;
		}
		if(simples==true)
		{
			printf("O grafo e simples");
			printf("\n");


				cont=0, maior= 999;
				for(int i=0; i<vertice && regular==true; i++)
				{
					cont=0;
					for(int j=0; j<aresta; j++)
					{

						if(mat[i][j]!=0)
							cont++;

					}
					if(i==0)
						maior=cont;
					else
						if(cont!=maior)
							regular = false;
				}
				if(regular==true)
					printf("E regular");
				else
					printf("Nao e regular");



			//completo
			printf("\n");
				bool completo = true;
				cont=0;
				for(int i=0; i<vertice && completo==true; i++)
				{
					cont=0;
					for(int j=0; j<aresta; j++)
					{

						if(mat[i][j]!=0)
							cont++;

					}
					if(cont != vertice-1)
						completo = false;
				}
				if(completo==true)
					printf("E completo");
				else
					printf("Nao e completo");



			getch();
		}
		else
			printf("O grafo nao e simples");
		//Regular

	}
	else
	{
		if(gd==1)
		{
			printf("Digrafo\n");

			//recebe aresta
			k=0;
			while(k<aresta)
			{

				fflush(stdin);
				printf("\nDigite a aresta %d",k);
				scanf("%s",&taresta[k]);

			//	printf("\nDigite o valor: ");
			//	scanf("%d",&val);
				emis = taresta[k][0];
				rece = taresta[k][1];

				for(int i=0; i<vertice; i++)
				{
					if(teste[i]==emis)
						pe=i;
					if(teste[i]==rece)
						pr=i;
				}

				mat[pe][k]=-1;
				mat[pr][k]=1;
				k++;
			}

			//exibe
			printf("\n\n");
			for(int i = 0; i<aresta; i++)
				printf(" %s", taresta[i]);
			printf("\n");

			for(int i=0; i<vertice; i++)
			{
				printf("%c", teste[i]);
				for(int j=0; j<aresta; j++)
				{
					printf(" %d", mat[i][j]);
				}
				printf("\n");
			}
			getch();


			//simples
			for(int i=0; i<aresta && simples==true; i++)
			{
				cont=0;
				for(int j=0; j<vertice; j++)
				{
					if(mat[j][i]!=0)
						cont++;

				}
				if(cont==1)
					simples=false;
			}

			if(simples==true)
			{
				printf("\nDigrafo simples");

				//regular
				cont=0;
				for(int i=0;i<vertice && regular==true;i++)
				{
					for(int j=0; j<aresta;j++)
					{
						if(mat[i][j]!=0)
							cont+=mat[i][j];
					}
					if(cont!=0)
						regular=false;
				}

				if(regular==true)
				{
					printf("\nEh regular");
				}
				else
					printf("\nNao eh regular");



			}
			else
				printf("\nDigrafo nao e simples");


		}
	}
}*/

















