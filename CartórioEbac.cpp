#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registrar()//função criada é necessário chama-la dentro da funçã oprincipal no caso a "main". O programa se torna mais otimizado com funções
{
	char arquivo[40];//criação de variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
	
	FILE *file;//Cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo;
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome para cadastro: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome para cadastro: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo para cadastro: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	/*printf("Você escolheu Registro\n");
	system("pause");// no "pause" paramos o programa e aguardamos o usuario digitar alguma coisa para seguir com ele.*/
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");// Declarando o idioma local
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;//Cria o arquivo
	file = fopen(cpf, "r");//ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");	
		printf("%s", conteudo);
		printf("\n\n ");	
	}
	
	system("pause");
		
	/*printf("Você escolheu Consultar\n");
	system("pause");*/
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");// Declarando o idioma local
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n ");
		system("pause");
	}
	
	
	/*printf("Você escolheu Deletar\n");
	system("pause");*/
}




int main()
{
	int opcao=0;//varial tipo "int" onde opcao recebe 0
	int laco=1;
	
	for(laco=1;laco=1;)//repetção tipo "for" temos que chamar a variavel;falar qual valor ela deve alcançar; e incrementar ou decrementar para finalizar o laço. Nesse caso não estamos incrementando pois queremos que sempre aconteça esse prog.
	{
	    
	    system("cls");// com "system" falamos com o sistema (no meu caso windows), e o "cls" serve para limpar a tela, ou seja todas as mensagens anteriores serão apagadas.
	    
		setlocale(LC_ALL, "Portuguese");// Declarando o idioma local
			
		printf("### Cartório da EBAC ###\n\n");// titulo do projeto (as "#" são apenas visuas - "printf" serve para demonstrar na pagina do usuario)
		printf("Escolha a opção desejada do menu:\n\n");// Titulo da pagina "\n" serve para pular de linha
		printf("\t1 - Registrar Nomes\n");// Opções "\t" serva para dar um espaçamento nas pagina
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Esse Software é do WandersonCS\n");// identificação do "desenvolvedor"
		printf("Opção: ");
		
		scanf("%d", &opcao);// o "scanf" tem como objetivo escanear o q o usuario coloca e o "%d" pede para armazenar a varial tipo "inteiro" e estamos alocando o valor em "opcao"
		
		system("cls");
		
		switch(opcao)//"switch" é um tipo de condicional que trabalha nos "casos" possiveis se torna melhor quando temos varias opções. onde a variavel correponde as casos possiveis.
		{
			case 1://chama o caso em especfico, e o que se deve acontecer está abaixo.
			registrar();//Aqui é a resposta caso a condição seja atendida. Nesse caso estamos chamando a função "registrar".
			break;// aqui o "case 1" "quebra", ou seja, ele fecha as ações para esse caso.
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;	

			default:// na opção "default" corresponde a tudo que não se aplica como caso.
			printf("Esta opção não está disponivel\n");
			system("pause");
			break;	
		}
		
		
		
		/* Para estudo...
		if(opcao==1)// o "if" é a pergunta "se?" onde podemos ter opções de escolha e a pergunta é se a varivael é igual a "0" faça o que etiver nas chaves
		{
			printf("Você está no 1\n");//Aqui é a resposta caso a condição seja atendida.
			system("pause");
		}
		if(opcao==2)
		{
			printf("Você está no 2\n");
			system("pause");
		}
		if(opcao==3)
		{
			printf("Você está no 3\n");
			system("pause");
		}
		if(opcao>=4 || opcao<=0)// o "||" serve como "ou" neste caso temos duas condições para serem atendidas: Se a variavel for maior igual a 4 "OU" menor igual 0 execute essa "ação".  
		{
			printf("Esta opção não está disponivel\n");
			system("pause");
		}*/
	
	}
}
