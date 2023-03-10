#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registrar()//fun��o criada � necess�rio chama-la dentro da fun�� oprincipal no caso a "main". O programa se torna mais otimizado com fun��es
{
	char arquivo[40];//cria��o de variaveis/strings
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
	
	/*printf("Voc� escolheu Registro\n");
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");	
		printf("%s", conteudo);
		printf("\n\n ");	
	}
	
	system("pause");
		
	/*printf("Voc� escolheu Consultar\n");
	system("pause");*/
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");// Declarando o idioma local
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n ");
		system("pause");
	}
	
	
	/*printf("Voc� escolheu Deletar\n");
	system("pause");*/
}




int main()
{
	int opcao=0;//varial tipo "int" onde opcao recebe 0
	int laco=1;
	
	for(laco=1;laco=1;)//repet��o tipo "for" temos que chamar a variavel;falar qual valor ela deve alcan�ar; e incrementar ou decrementar para finalizar o la�o. Nesse caso n�o estamos incrementando pois queremos que sempre aconte�a esse prog.
	{
	    
	    system("cls");// com "system" falamos com o sistema (no meu caso windows), e o "cls" serve para limpar a tela, ou seja todas as mensagens anteriores ser�o apagadas.
	    
		setlocale(LC_ALL, "Portuguese");// Declarando o idioma local
			
		printf("### Cart�rio da EBAC ###\n\n");// titulo do projeto (as "#" s�o apenas visuas - "printf" serve para demonstrar na pagina do usuario)
		printf("Escolha a op��o desejada do menu:\n\n");// Titulo da pagina "\n" serve para pular de linha
		printf("\t1 - Registrar Nomes\n");// Op��es "\t" serva para dar um espa�amento nas pagina
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Esse Software � do WandersonCS\n");// identifica��o do "desenvolvedor"
		printf("Op��o: ");
		
		scanf("%d", &opcao);// o "scanf" tem como objetivo escanear o q o usuario coloca e o "%d" pede para armazenar a varial tipo "inteiro" e estamos alocando o valor em "opcao"
		
		system("cls");
		
		switch(opcao)//"switch" � um tipo de condicional que trabalha nos "casos" possiveis se torna melhor quando temos varias op��es. onde a variavel correponde as casos possiveis.
		{
			case 1://chama o caso em especfico, e o que se deve acontecer est� abaixo.
			registrar();//Aqui � a resposta caso a condi��o seja atendida. Nesse caso estamos chamando a fun��o "registrar".
			break;// aqui o "case 1" "quebra", ou seja, ele fecha as a��es para esse caso.
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;	

			default:// na op��o "default" corresponde a tudo que n�o se aplica como caso.
			printf("Esta op��o n�o est� disponivel\n");
			system("pause");
			break;	
		}
		
		
		
		/* Para estudo...
		if(opcao==1)// o "if" � a pergunta "se?" onde podemos ter op��es de escolha e a pergunta � se a varivael � igual a "0" fa�a o que etiver nas chaves
		{
			printf("Voc� est� no 1\n");//Aqui � a resposta caso a condi��o seja atendida.
			system("pause");
		}
		if(opcao==2)
		{
			printf("Voc� est� no 2\n");
			system("pause");
		}
		if(opcao==3)
		{
			printf("Voc� est� no 3\n");
			system("pause");
		}
		if(opcao>=4 || opcao<=0)// o "||" serve como "ou" neste caso temos duas condi��es para serem atendidas: Se a variavel for maior igual a 4 "OU" menor igual 0 execute essa "a��o".  
		{
			printf("Esta op��o n�o est� disponivel\n");
			system("pause");
		}*/
	
	}
}
