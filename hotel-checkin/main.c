#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main()
{
    //Pegando as informa��es de carecteres por regi�o
    setlocale(LC_ALL, "Portuguese");

    //Op��es de Quartos com Pre�os por Di�ria
    int QuartoCompartilhado = 30;
    int Quarto2pessoas = 45;
    int Suite2pessoas = 55;
    int Suite3pessoas = 70;
    int SuiteFamilia = 85;
    int CabanaPequena = 60;
    int CabanaGrande = 80;
    int SuiteDiplomata = 130;
    int SuitePresidencial = 175;
    int CafedaManha = 15;
    int servicoquarto = 10;

    //Outros Itens
    int total = 0; //Total da Tarifa
    int diarias; //Quantidade de Di�rias da Reserva
    int quarto; //Tipo de Quarto Selecionado
    char nomeAcompanhante; //Nome dos Acompanhantes no Quarto
    int rgCrianca; //RG ou Passaporte da Crian�a
    int rgAdulto; //RG ou Passaporte do Adulto
    int qtdCriancas; //Quantidade de Crian�as/Menores de Idade
    int qtdHospedes; //Quantidade de Hospedes no Total incluindo o pagador
    int opcao1; //Referente a op��o do Caf� da Manh�
    int opcao2; //Referente a op��o do Servi�o de Quarto
    float calculocafe; //C�lculo do caf� da manh�, a cada 2 hospedes uma nova tarifa de caf� � adicionada
    int calculoservico; //C�lculo da Adi��o do Servi�o de Quarto
    int posneg; //Teste de Positivo ou Negativo se � crian�a
    int inseridos = 0;

    //Para o n�mero do quarto
    int numeroQuarto; //Numero do Quarto em que o hospede ficar�
    int i; //Vari�vel de C�lculo


    //Sistema de Login Completo para Acesso ao Sistema
    char login[15] = "arcobaleno"; //Login Correto
    char logininserido[15]; //Login by User
    char senha[15] = "napolesitalia"; //Senha Correta
    char senhainserida[15]; //Senha by User
    int tentativas = 1; //N�mero de tentativas j� realizadas pelo user
    int loginefetuado = 0; //0 quando n�o for verdadeiro e 1 quando for verdadeiro

    do {
        printf("Digite o seu Login: ");
        scanf("%s", logininserido);

        printf("Digite a sua Senha: ");
        scanf("%s", senhainserida);

        if(tentativas < 3){
            if (strcmp(login, logininserido) == 0 && strcmp(senha, senhainserida) == 0) {
                printf("Voc� est� logado com sucesso!\n\n");
                loginefetuado = 1;
            }else {
                printf("Os dados que voc� inseriu est�o incorretos, tente novamente\n\n");
                tentativas += 1;
            }
        } else {
            printf("Voc� atingou o n�mero m�ximo de tentativas.\n");
            sleep(1);
            printf("Reiniciando o Sistema por seguran�a\n\n");
            exit (1);
        }
    }
    while(!loginefetuado);


    //Se o Login for bem sucedido, continuar aqui
    //Incializa��o do Programa
    printf("Sistema Check-In do Hotel Arcobaleno Palace\n");
    printf("===========================================\n\n");
    sleep(2);


    //Op��es de Quartos Dispon�veis
    printf("As opcoes de quartos disponiveis atualmente sao: \n");
    printf("Quarto Compartilhado (Codigo 123)    Quarto 2 Pessoas (Codigo 482)\n");
    printf("Suite 2 Pessoas (Codigo 407)         Suite 3 Pessoas (Codigo 237)\n");
    printf("Suite Familia (Codigo 567)           Cabana Pequena (Codigo 983)\n");
    printf("Cabana Grande (Codigo 647)           Suite Diplomota (Codigo 745)\n");
    printf("Suite Presidencial (Codigo 327)\n\n");

    printf("===========================================\n\n");


    //In�cio do Check-In
    //Boas Vindas
    printf("Seja muito bem-vindo(a) ao Hotel Arcobaleno Palace!\n\n");
    sleep(2);

    //Quantidade de diarias que o hospede deseja
    printf("Quantas di�rias o H�spede deseja?");
    scanf("%d", &diarias);
    printf("Voc� selecinou: %d di�rias\n", diarias);

    //Quantidade de hospedes
    printf("Quantos h�spedes h� no total?(incluindo crian�as e o H�spede Financiador)");
    scanf("%d", &qtdHospedes);
    printf("Voc� selecionou %d h�spedes\n", qtdHospedes);

    printf("Qual o tipo de quarto que o(a) h�spede financiador deseja?");
    scanf("%d", &quarto);


    //Verifica��o dos Valores e Apresenta��o do Resultado Final
    if(quarto == 123) {
        total = QuartoCompartilhado * diarias * qtdHospedes; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 482) {
        total = Quarto2pessoas * diarias * qtdHospedes/ 2; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 407) {
        total = Suite2pessoas * diarias * qtdHospedes/ 2; //C�lculo do Booking
       //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 482) {
        total = Quarto2pessoas * diarias * qtdHospedes/ 2; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 237) {
        total = Suite3pessoas * diarias * qtdHospedes/ 3; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 567) {
        total = SuiteFamilia * diarias * qtdHospedes/ 4; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 983) {
        total = CabanaPequena * diarias * qtdHospedes/2; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 647) {
        total = CabanaGrande * diarias * qtdHospedes/ 2; //C�lculo Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 745) {
        total = SuiteDiplomata * diarias * qtdHospedes/ 2; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 327) {
        total = SuitePresidencial * diarias * qtdHospedes/ 4; //C�lculo do Booking
        //Cadastro dos H�spedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede � menor de idade? (Digite 1 para sim ou 2 para n�o)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Crian�a Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Aten��o! O H�spede est� com muitas crian�as, fique atento(a)! \n");
            }
            printf("%d crian�as cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste h�spede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Pr�ximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adi��o do caf� da manha a reserva
        printf("O H�spede Financiador deseja caf� da manh�? (Digite 1 para sim e 2 para n�o)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manh� na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Caf� da Manha n�o estar� incluso na reserva\n");
        }
        //Pergunta sobre a adi��o do servi�o de quarto a reserva
        printf("O H�spede Financiador deseja servi�o de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Servi�o de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Servi�o de Quarto n�o estar� incluso na reserva\n");
        }
        //Apresenta��o Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do H�spede � de %d reais brasileiros.\n",total);
        printf("O H�spede tem %d crian�as junto a ele. \n", qtdCriancas);
        printf("O H�spede Financiador se acomodar� no quarto com mais %d h�spede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d � o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }
    else {
        printf("O N�mero do Tipo de Quarto Digitado est� incorreto\n");
        printf("Reinciando o Sistema\n\n");
        main();
    }

    return 0;
}
