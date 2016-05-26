#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 0
#define PRETO 1
#define N_MAX 1027

//FILE* log;

//Estrutura do No Rubro-Negro
typedef struct NoRN {

	int valor;
	int cor;					// 0 = Rubro , 1 = Preto
	struct NoRN* filho_esq;
	struct NoRN* filho_dir;
	struct NoRN* pai;

}NoRN;

//Estrutura da Arvore Rubro-Negra
typedef struct {

	NoRN* raiz;

}ArvoreRN;

//Faz o raiz da Arvore apontar para NULL
void CriaArvore(ArvoreRN* arvore) {

	arvore->raiz = NULL;
}

//BuscaNo: recebe o no raiz da arvore e um valor e verifica se encontra o valor na arvore
NoRN* BuscaNo(NoRN* raiz, int valor) {
	if (raiz == NULL) {
		return raiz;
	}
	if (raiz->valor > valor) {
		return BuscaNo(raiz->filho_esq, valor);
	}
	if (raiz->valor < valor) {
		return BuscaNo(raiz->filho_dir, valor);
	}
	return raiz;
}

//BuscaNaArvore: recebe a arvore e um valor e chama a funcao BuscaNo para procurar esse valor
int BuscaNaArvore(ArvoreRN arvore, int valor) {
	if (BuscaNo(arvore.raiz, valor)) {
		return 1;
	}
	return 0;
}

//Retorna o endereÃ§o do maior elemento a partir da raiz dada.
NoRN* PercorreOsMaiores(NoRN* raiz) {
	if (raiz == NULL) {
		return raiz;
	}
	if (raiz->filho_dir == NULL) {
		return raiz;
	}
	return PercorreOsMaiores(raiz->filho_dir);
}

//Retorna o endereÃ§o do menor elemento a partir da raiz dada.
NoRN* PercorreOsMenores(NoRN* raiz) {
	if (raiz == NULL) {
		return raiz;
	}
	if (raiz->filho_esq == NULL) {
		return raiz;
	}
	return PercorreOsMenores(raiz->filho_esq);
}

//Retorna o endereco do Menor dos Maiores.
NoRN* MenorDosMaiores(NoRN* raiz) {

	return PercorreOsMenores(raiz->filho_dir);
}

//Retorna o endereco do Maior dos Menores
NoRN* MaiorDosMenores(NoRN* raiz) {
	return PercorreOsMaiores(raiz->filho_esq);
}
//Retorna a cor do no
int Cor(NoRN* no) {
	if (!no) {
		return 1;
	}
	return no->cor;

}

//Troca a cor do no
void TrocaCores(NoRN* raiz) {
	if (raiz) {
		if (raiz->cor) {
			raiz->cor = VERMELHO;
		}
		else {
			raiz->cor = 1;
		}

	}
}

void Trocavalors(NoRN *no1, NoRN *no2) {
	no1->valor = no2->valor;
}

//Faz o pai apontar para um filho inferindo a posicao correta.
void TornePai(NoRN* filho, NoRN* pai) {

	if (pai && filho) {
		if (filho->valor > pai->valor) {
			pai->filho_dir = filho;
		}
		else {
			pai->filho_esq = filho;
		}
	}
}

//Rotacao Simples a Direita.
NoRN* RotacaoSD(NoRN* filho, NoRN* pai) {

	pai->filho_esq = filho->filho_dir;
	if (pai->filho_esq) {
		pai->filho_esq->pai = pai;
	}

	filho->pai = pai->pai;
	TornePai(filho, filho->pai);


	pai->pai = filho;
	filho->filho_dir = pai;

	return filho;
}

//Rotacao Simples a Esquerda.
NoRN* RotacaoSE(NoRN* filho, NoRN* pai) {

	pai->filho_dir = filho->filho_esq;
	if (pai->filho_dir) {
		pai->filho_dir->pai = pai;
	}

	filho->pai = pai->pai;
	TornePai(filho, filho->pai);


	pai->pai = filho;
	filho->filho_esq = pai;

	return filho;
}

//Rotacao Dupla para a Esquerda.
NoRN* RotacaoDE(NoRN* filho, NoRN* pai, NoRN* avo) {

	RotacaoSD(filho, pai);
	return RotacaoSE(filho, avo);

}

//Rotacao Dupla para a Direita.
NoRN* RotacaoDD(NoRN* filho, NoRN* pai, NoRN* avo) {

	RotacaoSE(filho, pai);
	return RotacaoSD(filho, avo);

}

//Rotacao para a esquerda.
NoRN* RotacaoEsq(NoRN* filho, NoRN* pai, NoRN* avo) {

	if (filho->valor > pai->valor) {
		return RotacaoSE(pai, avo);
	}
	return RotacaoDE(filho, pai, avo);
}

//Rotacao para a direita
NoRN* RotacaoDir(NoRN* filho, NoRN* pai, NoRN* avo) {

	if (filho->valor < pai->valor) {
		return RotacaoSD(pai, avo);
	}
	return RotacaoDD(filho, pai, avo);
}

//Decide a direcao da Rotacao.
NoRN* Rotaciona(NoRN* filho, NoRN* pai, NoRN* avo) {

	if (pai->valor > avo->valor) {
		return RotacaoEsq(filho, pai, avo);

	}
	else {
		return RotacaoDir(filho, pai, avo);

	}

}


//Encontra o irmao do no. 
NoRN* EncontraIrmao(NoRN* no) {
	if (no->valor > no->pai->valor) {
		return no->pai->filho_esq;
	}
	else {
		return no->pai->filho_dir;
	}
}

//Encontra o avo do no. 
NoRN* EncontraAvo(NoRN *no) {
	return no->pai->pai;
}

//Encontra o tio do no. 
NoRN* EncontraTio(NoRN *no) {
	return EncontraIrmao(no->pai);
}

//Balancea a arvore.
NoRN* Balanceamento(NoRN* filho) {

	NoRN* tio;
	NoRN* avo;

	if (filho->pai) {
		if (Cor(filho->pai) == VERMELHO && Cor(filho) == VERMELHO) {
			avo = filho->pai->pai;
			if (avo != NULL) {
				tio = EncontraIrmao(filho->pai);
				if (Cor(tio)) {
					Rotaciona(filho, filho->pai, avo);
					TrocaCores(avo);
					TrocaCores(avo->pai);
					return Balanceamento(avo->pai);
				}
				else {
					TrocaCores(tio);
					TrocaCores(filho->pai);
					TrocaCores(avo);
					return Balanceamento(avo);

				}
			}
			else {
				return filho->pai;
			}
		}
		else {
			return Balanceamento(filho->pai);
		}
	}
	return filho;

}

//Cria um no.
NoRN* CriaNo(NoRN* pai, int valor) {
	NoRN* aux = (NoRN*)malloc(sizeof(NoRN));

	aux->cor = VERMELHO;
	aux->filho_dir = NULL;
	aux->filho_esq = NULL;
	aux->pai = pai;
	aux->valor = valor;

	return aux;

}

//Insere um no em uma sub-arvore.
NoRN* InsereNo(NoRN* raiz, NoRN* pai, int valor) {
	if (raiz == NULL) {

		raiz = CriaNo(pai, valor);
		TornePai(raiz, pai);
		return Balanceamento(raiz);
	}
	if (raiz->valor > valor) {
		return InsereNo(raiz->filho_esq, raiz, valor);
	}
	if (raiz->valor < valor) {
		return InsereNo(raiz->filho_dir, raiz, valor);
	}
	return Balanceamento(raiz);
}

//Insere um no na arvore.
void InsereNaArvore(ArvoreRN* arvore, int valor) {


}

//Conta o Numero de Nos Pretos por todos os caminhos possiveis do no atual ate alguma folha. 
//Retorna 0 se a raiz contem caminhos de tamanhos diferentes.
int ContaNosPretos(NoRN* raiz, int contagem_atual) {

	int contagem_esq;
	int contagem_dir;

	if (raiz == NULL) {

		return contagem_atual + 1;
	}

	contagem_esq = ContaNosPretos(raiz->filho_esq, contagem_atual + raiz->cor);
	contagem_dir = ContaNosPretos(raiz->filho_dir, contagem_atual + raiz->cor);

	/*	if(contagem_dir != contagem_esq){

	return 0;

	}*/

	return contagem_esq - contagem_dir;

}

/*NoRN *Irmao(NoRN *raiz) {
NoRN *aux = raiz->pai;
if(aux->filho_esq != raiz) {
return aux->filho_esq;
} else
return aux->filho_dir;
}*/

int Semifolha(NoRN raiz) {
	return raiz.filho_esq == NULL && raiz.filho_dir == NULL;
}

int DuploPreto(NoRN raiz) {
	if (Semifolha(raiz)) {
		return 1;
	}
	if ((raiz.filho_esq != NULL) && (raiz.filho_dir != NULL)) {
		if ((raiz.filho_esq->cor == PRETO) && (raiz.filho_dir->cor == PRETO)) {
			return 1;
		}
	}
	if (raiz.filho_esq == NULL && raiz.filho_dir != NULL) {
		if (raiz.filho_dir->cor == PRETO)
			return 1;
	}
	else if (raiz.filho_esq != NULL && raiz.filho_dir == NULL) {
		if (raiz.filho_esq->cor == PRETO)
			return 1;
	}
	return 0;
}


void ApagaNo(NoRN *no) {
	if (no) {
		if (no->pai) {
			if (no->valor > no->pai->valor) {
				no->pai->filho_dir = NULL;
			}
			else {
				no->pai->filho_esq = NULL;
			}
		}
		free(no);
	}
}

NoRN *RemoveNoPreto(NoRN *raiz);

NoRN *RemoveNoVermelho(NoRN *raiz) {
	printf("Entrei em RemoveNoVermelho\n");
	NoRN *mm, *pai = raiz->pai;
	//se for semifolha
	if (Semifolha(*raiz)) {
		ApagaNo(raiz);
		return pai;
	}

	if (raiz->filho_esq) {
		mm = MaiorDosMenores(raiz);
		if (mm->cor == VERMELHO) {
			Trocavalors(raiz, mm);
			return RemoveNoVermelho(mm);
		}
	}

	if (raiz->filho_dir) {
		mm = MenorDosMaiores(raiz);
		if (mm->cor == VERMELHO) {
			Trocavalors(raiz, mm);
			return RemoveNoVermelho(mm);
		}
	}

	Trocavalors(raiz, mm);
	return RemoveNoPreto(mm);
}

void *RemoveSemifolhaPreto(ArvoreRN *arvore, NoRN *no) {
	printf("Entrei em RemoveSemifolhaPreto\n");
	NoRN *irmao;

	irmao = EncontraIrmao(no);
	if (isfilho_dir(no)) {
		if (irmao->filho_esq) {
			irmao->filho_esq->cor = PRETO;
			if (irmao->pai->cor == VERMELHO) {
				irmao->pai->cor = PRETO;
				TrocaCores(irmao);
			}
			RotacaoSD(irmao, irmao->pai);
		}
		else if (irmao->filho_dir) {
			if (irmao->pai->cor == VERMELHO) {
				irmao->pai->cor = PRETO;
			}
			RotacaoDD(irmao->filho_dir, irmao, irmao->pai);
		}
		else {
			if (Cor(no->pai) == VERMELHO) {
				TrocaCores(no->pai);
				TrocaCores(irmao);
			}
			else {
				TrocaCores(irmao);
				ConsertaRN(arvore, no->pai);
			}
		}
		ApagaNo(no);
		return;
	}
	else {
		if (irmao->filho_dir) {
			irmao->filho_dir->cor = PRETO;
			if (irmao->pai->cor == VERMELHO) {
				irmao->pai->cor = PRETO;
				TrocaCores(irmao);
			}
			RotacaoSE(irmao, irmao->pai);
		}
		else if (irmao->filho_esq) {
			if (irmao->pai->cor == VERMELHO) {
				irmao->pai->cor = PRETO;
			}
			RotacaoDE(irmao->filho_esq, irmao, irmao->pai);
		}
		else {
			if (Cor(no->pai) == VERMELHO) {
				TrocaCores(no->pai);
				TrocaCores(irmao);
			}
		}
		ApagaNo(no);
		return;
	}
}

NoRN *RemoveDuploPreto(NoRN *raiz) {
	NoRN *mm;

	printf("Entrei em RemoveDuploPreto\n");

	if (Semifolha(*raiz)) {
		return RemoveSemifolhaPreto(raiz);
	}
	mm = MaiorDosMenores(raiz);
	printf("%d\n", mm->valor);
	if (mm) {
		if (mm->cor == VERMELHO) {
			Trocavalors(raiz, mm);
			return RemoveNoVermelho(mm);
		}
		Trocavalors(raiz, mm);
	}
	return RemoveNoPreto(mm);
}

int isfilho_dir(NoRN *no) {
	return no->pai->filho_dir == no;
}

NoRN *RemoveNoPreto(NoRN *no) {
	printf("ENtrei em RemoveNoPreto\n");
	if (!no) {
		return no;
	}

	if (DuploPreto(*no)) {
		printf("Em duplopreto %d\n", no->cor);
		return RemoveDuploPreto(no);
	}

	if (isfilho_dir(no)) {
		printf("ENtrei em is_filho_dir\n");
		if (no->filho_esq) {
			if (no->filho_esq->cor == VERMELHO) {
				Trocavalors(no, no->filho_esq);
				return RemoveNoVermelho(no->filho_esq);
			}
		}
		Trocavalors(no, no->filho_dir);
		return RemoveNoVermelho(no->filho_dir);
	}
	else {
		printf("no Else ;)\n");
		if (Cor(no->filho_dir) == VERMELHO) {
			Trocavalors(no, no->filho_dir);
			return RemoveNoVermelho(no->filho_dir);
		}
		Trocavalors(no, no->filho_esq);
		return RemoveNoVermelho(no->filho_esq);
	}
	printf("saí\n");
}

int RemoverDaArvoreRN(NoRN *raiz, int elem) {
	printf("ENtrei em RemoverDaArvoreRN\n");
	if (raiz == NULL) {
		printf("oi anavi\n");
		return 0;
	}
	if (raiz->valor == elem) {
		printf("Encontrei o nozinho %d\n", elem);

		if (raiz->cor == PRETO) {
			RemoveNoPreto(raiz);
		}
		else {
			RemoveNoVermelho(raiz);
		}
		return 1;
	}if (raiz->valor < elem) {
		printf("passei pelo %d\n", raiz->valor);
		return RemoverDaArvoreRN(raiz->filho_dir, elem);
	}
	else
	{
		printf("passei pelo %d\n", raiz->valor);
		return RemoverDaArvoreRN(raiz->filho_esq, elem);
	}
}

//Insere valors atraves de um arquivo de texto.
void InsereArquivoArvore(ArvoreRN* arvore, FILE* arquivo) {
	int no_valor;

	while (!feof(arquivo)) {
		fscanf(arquivo, "%d%*c", &no_valor);
		arvore->raiz = InsereNo(arvore->raiz, NULL, no_valor);
		arvore->raiz->cor = 1;
	}

}

//Remove valors atraves de um arquivo de texto.
void RemoveArquivoArvore(ArvoreRN* arvore, FILE* arquivo) {
	int no_valor;

	while (fscanf(arquivo, "%d%*c", &no_valor) == 1) {
		printf("%d %p\n", no_valor, arvore->raiz);
		printf("%d\n", RemoverDaArvoreRN(arvore->raiz, no_valor));
	}

}

void InsereNaArvoreRN(ArvoreRN* arvore, char* string) {

	FILE* arquivo;

	arquivo = fopen(string, "r");
	if (!arquivo) {

		printf("Erro ao abrir o arquivo %s! Encerrando Programa...\n", string);
		exit(1);
	}

	CriaArvore(arvore);

	InsereArquivoArvore(arvore, arquivo);
	fclose(arquivo);

}
//Funcoes responsaveis pela EXIBICAO dos valors

//Exibe uma especie de menu para o usuario
int Menu() {
	int opcao;
	//system("cls || clear");
	printf("-------------Arvore Rubro-Negra-------------\n\n");
	printf("\n\t\t\t   --------- MENU ---------- \n");
	printf("1 - Inserir na Arvore\n");
	printf("2 - Remover da Arvore\n");
	printf("3 - Busca na Arvore\n");
	printf("4 - Visualizar a Arvore\n");
	printf("5 - Sair do programa\n");
	printf("Digite sua opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

//Exibe um menu para insercao na arvore
void MenuParaInsercao(ArvoreRN* arvore) {
	char string[30];
	//system("clear || cls");
	printf("-------------Arvore Rubro-Negra-------------\n\n");
	printf("\t\t\t----------- Insercao -----------\n\n");
	printf("Digite o nome do arquivo ou local que contem\nos valors a serem inseridos na arvore:\n");
	scanf("%s", string);
	printf("\n\nInserindo...\n");
	InsereNaArvoreRN(arvore, string);
	printf("\nPronto!\n");
	fflush(stdin);
	getchar();
}

//Exibe um menu para remocao da arvore
void MenuParaRemocao(ArvoreRN* arvore) {
	FILE* arquivo;
	char string[30];

	//system("clear || cls");
	printf("\t\t\t----------- Remocao -----------\n\n");
	printf("Digite o nome do arquivo ou local que contem\nos valors a serem removidos da arvore:\n");
	scanf("%s", string);
	printf("\n\nRemovendo...\n");
	arquivo = fopen(string, "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo %s! Encerrando Programa...\n", string);
		exit(1);
	}
	RemoveArquivoArvore(arvore, arquivo);
	printf("\nPronto!\n");
	fflush(stdin);
	getchar();

}

//Exibe um menu para busca na arvore
void MenuParaBusca(ArvoreRN arvore) {
	int chave;

	//	system("clear || cls");
	printf("-------------Arvore Rubro-Negra-------------\n\n");
	printf("\n----------- Busca -----------\n\n");
	printf("Digite o valor que se deseja buscar: ");
	scanf("%d*c", &chave);
	printf("\n\nBuscando...\n");

	if (BuscaNaArvore(arvore, chave)) {
		printf("Encontrado!\n");
	}
	else {
		printf("Nao Encontrado!\n");
	}
	fflush(stdin);
	getchar();
}

//Imprime os nos da arvore.
void Horizontal(NoRN* raiz, int nivel) {
	int l = nivel;

	if (raiz == NULL) {
		while (l--) printf("\t");
		printf("NULL(1)\n");
		return;
	}

	Horizontal(raiz->filho_dir, nivel + 1);
	while (l--) printf("\t");
	printf(" %d(%d)\n", raiz->valor, raiz->cor);
	Horizontal(raiz->filho_esq, nivel + 1);
}

//retorna o maior de dois números
/*int maior(int a, int b) {
if(a > b) return a;
else return b;
}
//calcula altura de uma árvore
int altura(NoRN *raiz) {
if(!raiz) {
return 0;
}
return maior(altura(raiz->filho_esq), altura(raiz->filho_dir))+1;
}
int imprimirArvore(NoRN *raiz)
{
int i, alt = altura(raiz);
char string[alt][N_MAX*7];
for (i = 0; i < alt; i++)
sprintf(string[i], "%80s", " ");
imprimirArvoreInterno(raiz, 0, 0, 0, alt, string);
for (i = 0; i < alt; i++)
printf("%s\n", string[i]);
}
int imprimirArvoreInterno(NoRN *raiz, int e_esquerda, int distancia, int nivelAtual, int alt, char str[][N_MAX*7])
{
char strAux[alt];
int i, esquerda, direita, tamanhoNo = 7; //tamanhoNo: tamanho do nó que será impresso. No caso, um inteiro de 4 posiçoes + parênteses
if (!raiz) return 0;
sprintf(strAux, "(%05d)", raiz->valor);
esquerda  = imprimirArvoreInterno(raiz->filho_esq,  1, distancia, nivelAtual + 1, alt, str);
direita = imprimirArvoreInterno(raiz->filho_dir, 0, distancia + esquerda + tamanhoNo, nivelAtual + 1, alt, str);
for (i = 0; i < tamanhoNo; i++)
str[nivelAtual][distancia + esquerda + i] = strAux[i];
if (nivelAtual && e_esquerda) {

for (i = 0; i < tamanhoNo + direita; i++)
str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2 + i] = '-';
str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2] = '.';
} else if (nivelAtual && !e_esquerda) {
for (i = 0; i < esquerda + tamanhoNo; i++)
str[nivelAtual - 1][distancia - tamanhoNo/2 + i] = '-';
str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2] = '.';
}
return esquerda + tamanhoNo + direita;
}*/

//Mostra uma arvore, juntamente do fator de balanceamento da mesma
void MostrarArvore(ArvoreRN arvore)
{
	//	system("clear || cls");
	printf("-------------Arvore Rubro-Negra-------------\n\n");
	printf("Obs: Cada no vem acompanhado de sua cor dentro de uma tupla.\n0 -> Vermelho\n1 -> Preto\n\n");
	printf("Se o numero de nos pretos por caminho for 0, entao a arvore se encontra desbalanceada.\n\n");
	printf("Numero de nos Pretos por caminho: %d\n", ContaNosPretos(arvore.raiz, 0));
	Horizontal(arvore.raiz, 0);
	fflush(stdin);
	getchar();
}
/*
int main() {

	ArvoreRN arvoreRN;

	int opcao = 1, sair = 0;

	while (sair != 1) {
		//system("cls || clear");

		opcao = Menu();
		switch (opcao) {
		case 1:
			MenuParaInsercao(&arvoreRN);
			break;
		case 2:
			MenuParaRemocao(&arvoreRN);
			break;
		case 3:
			MenuParaBusca(arvoreRN);
			break;
		case 4:
			MostrarArvore(arvoreRN);
			break;
		case 5:
			sair = 1;
			break;

		default:
			printf("Comando invalido! Tente novamente.\n");
			break;
		}
	}

	return 0;
}*/