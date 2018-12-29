#include<stdio.h>
#include<conio.h>


//Fernando de Almeida Noronha
//Luan Lourenço Esteves
//GRAFOS - LISTA
struct TpGrafo
{
	int val;
	char v;
	TpGrafo *prox;	
};



TpGrafo *nc(int valor, char v)
{
	TpGrafo *grafo = new TpGrafo();
	grafo->val=valor;
	grafo->v=v;
	grafo->prox=NULL;

	
	return grafo;
}



void recebeGrafo(TpGrafo *grafo[], int nvertice)
{
	int valor;
	TpGrafo *aux;
	char aresta[5];
	printf("Digite um valor: \n");
	scanf("%d",&valor);
	while(valor!=-1)
	{
		
		printf("Digite uma aresta: \n");
		fflush(stdin);
		scanf("%s",&aresta);
		
		for(int i=0; i<nvertice;i++)
		{
			if(aresta[0]==grafo[i]->v)
			{
				if(grafo[i]->prox==NULL)
					grafo[i]->prox=nc(valor,aresta[1]);
				else
				{
					aux=grafo[i];
					while(aux->prox!=NULL)
						aux=aux->prox;
					aux->prox=nc(valor,aresta[1]);
				}
			}
				
		}
	/*	for(int i=0;i<nvertice;i++)
		{
			if(aresta[1]==grafo[i]->v)
			{
				if(grafo[i]->prox==NULL)
					grafo[i]->prox=nc(valor,aresta[0]);
				else
				{
					aux=grafo[i];
					while(aux->prox!=NULL)
						aux=aux->prox;
					aux->prox=nc(valor,aresta[0]);
				}
			}
		}*/
	
	printf("Digite um valor: \n");
		scanf("%d",&valor);	
	}
}


void exibe(TpGrafo *grafo[], int nvertice)
{
	TpGrafo *aux;
	printf("\n\n------- Exibe -------\n\n");
	for(int i=0; i<nvertice; i++)
	{
		aux=grafo[i];
		while(aux!=NULL)
		{
			printf("  %c ->",aux->v);
			aux=aux->prox;
		}
		printf("\n");
	}
	
}



void completoGrafo(TpGrafo *grafo[], int nvertice)
{
	TpGrafo *aux;
	bool completo = true;
	int cont=0;
	for(int i=0; i<nvertice && completo==true;i++)
	{
		aux=grafo[i]->prox;
		cont = 1;
		
		while(aux!=NULL)
		{
			cont++;
			aux=aux->prox;
		}
		
		if(cont!=nvertice)
			completo=false;
	}
	
	if(completo==true)
		printf("\nCompleto");
	else
		printf("\nNao eh completo");
}

void regularG(TpGrafo *grafo[],int nvertice, bool analise)
{
	TpGrafo *aux;
	int cont=0, maior=0;	
	bool regular = true;
	for(int i=0; i<nvertice && regular == true;i++)
	{
		cont=0;
		aux=grafo[i];
		while(aux!=NULL)
		{
			cont++;
			aux=aux->prox;
		}
		if(i==0)
			maior=cont;
		
		if(cont!=maior)
		{
			regular=false;
		}
	}
	if(regular==true)
	{
		printf("\nEh regular");
		if(analise==true)
			completoGrafo(grafo,nvertice);
		else
			printf("\nEh completo");
	}
	else
	{
		printf("\nNao eh regular");
		printf("\nNao eh completo");
	}
	
}




void grafoSimples(TpGrafo *grafo[], int nvertice, bool analise)
{
	TpGrafo *aux, *aux2;
	bool simples = true;
	char loop;
	
	for(int i=0;i<nvertice && simples==true;i++)
	{
		loop=grafo[i]->v;
		aux=grafo[i]->prox;
		aux2=grafo[i];
		while(aux2!=NULL && simples==true)
		{
			aux=aux2->prox;
			while(aux!=NULL && simples==true)
			{
				if(aux2->v==aux->v)
					simples=false;
				aux=aux->prox;
			}
			aux2=aux2->prox;
		}
	}
	
	if(simples == true)
	{
		printf("\nSimples");
		
			regularG(grafo,nvertice, analise);
		
	}
	else
		printf("\nNao eh simples");
	
}

void grafooudigrafo(TpGrafo *grafo[], int nvertice)
{
	
	TpGrafo *aux, *aux2;
	bool teste=false;
	bool digrafo=false;
	for(int i=0;i<nvertice;i++)
	{
		aux=grafo[i]->prox;
		
		while(aux!=NULL)
		{
			for(int j=0;j<nvertice;j++)
			{
				if(aux->v==grafo[j]->v)
				{
					teste=false;
					aux2=grafo[j]->prox;
					while(aux2!=NULL && teste==false)
					{
						if(grafo[i]->v==aux2->v)
						{
							teste=true;
						}
						aux2=aux2->prox;
					}
					if(teste==false)
						digrafo=true;
				}
			}
			aux=aux->prox;
		}
	
	}
	
	if(digrafo==true)
	{
		printf("Digrafo");
		grafoSimples(grafo,nvertice, false);
	}
	else
	{
		printf("Grafo");
		grafoSimples(grafo, nvertice, true);
	}
}


int main()
{
	
	TpGrafo *grafo[10];
	
	int nvertice;
	char vertice;
	printf("Digite o numero de vertices:");
	scanf("%d",&nvertice);
	
	for(int i=0;i<nvertice; i++)
	{
		printf("Digite a vertice %d",i);
		fflush(stdin);
		scanf("%c",&vertice);
		grafo[i] = new TpGrafo();
		grafo[i] = nc(0,vertice);
	}
	
	recebeGrafo(grafo,nvertice);
	exibe(grafo,nvertice);
	grafooudigrafo(grafo,nvertice);



	getch();
}












