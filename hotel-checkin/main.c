#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main()
{
    //Pegando as informações de carecteres por região
    setlocale(LC_ALL, "Portuguese");

    //Opções de Quartos com Preços por Diária
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
    int diarias; //Quantidade de Diárias da Reserva
    int quarto; //Tipo de Quarto Selecionado
    char nomeAcompanhante; //Nome dos Acompanhantes no Quarto
    int rgCrianca; //RG ou Passaporte da Criança
    int rgAdulto; //RG ou Passaporte do Adulto
    int qtdCriancas; //Quantidade de Crianças/Menores de Idade
    int qtdHospedes; //Quantidade de Hospedes no Total incluindo o pagador
    int opcao1; //Referente a opção do Café da Manhã
    int opcao2; //Referente a opção do Serviço de Quarto
    float calculocafe; //Cálculo do café da manhã, a cada 2 hospedes uma nova tarifa de café é adicionada
    int calculoservico; //Cálculo da Adição do Serviço de Quarto
    int posneg; //Teste de Positivo ou Negativo se é criança
    int inseridos = 0;

    //Para o número do quarto
    int numeroQuarto; //Numero do Quarto em que o hospede ficará
    int i; //Variável de Cálculo


    //Sistema de Login Completo para Acesso ao Sistema
    char login[15] = "arcobaleno"; //Login Correto
    char logininserido[15]; //Login by User
    char senha[15] = "napolesitalia"; //Senha Correta
    char senhainserida[15]; //Senha by User
    int tentativas = 1; //Número de tentativas já realizadas pelo user
    int loginefetuado = 0; //0 quando não for verdadeiro e 1 quando for verdadeiro

    do {
        printf("Digite o seu Login: ");
        scanf("%s", logininserido);

        printf("Digite a sua Senha: ");
        scanf("%s", senhainserida);

        if(tentativas < 3){
            if (strcmp(login, logininserido) == 0 && strcmp(senha, senhainserida) == 0) {
                printf("Você está logado com sucesso!\n\n");
                loginefetuado = 1;
            }else {
                printf("Os dados que você inseriu estão incorretos, tente novamente\n\n");
                tentativas += 1;
            }
        } else {
            printf("Você atingou o número máximo de tentativas.\n");
            sleep(1);
            printf("Reiniciando o Sistema por segurança\n\n");
            exit (1);
        }
    }
    while(!loginefetuado);


    //Se o Login for bem sucedido, continuar aqui
    //Incialização do Programa
    printf("Sistema Check-In do Hotel Arcobaleno Palace\n");
    printf("===========================================\n\n");
    sleep(2);


    //Opções de Quartos Disponíveis
    printf("As opcoes de quartos disponiveis atualmente sao: \n");
    printf("Quarto Compartilhado (Codigo 123)    Quarto 2 Pessoas (Codigo 482)\n");
    printf("Suite 2 Pessoas (Codigo 407)         Suite 3 Pessoas (Codigo 237)\n");
    printf("Suite Familia (Codigo 567)           Cabana Pequena (Codigo 983)\n");
    printf("Cabana Grande (Codigo 647)           Suite Diplomota (Codigo 745)\n");
    printf("Suite Presidencial (Codigo 327)\n\n");

    printf("===========================================\n\n");


    //Início do Check-In
    //Boas Vindas
    printf("Seja muito bem-vindo(a) ao Hotel Arcobaleno Palace!\n\n");
    sleep(2);

    //Quantidade de diarias que o hospede deseja
    printf("Quantas diárias o Hóspede deseja?");
    scanf("%d", &diarias);
    printf("Você selecinou: %d diárias\n", diarias);

    //Quantidade de hospedes
    printf("Quantos hóspedes há no total?(incluindo crianças e o Hóspede Financiador)");
    scanf("%d", &qtdHospedes);
    printf("Você selecionou %d hóspedes\n", qtdHospedes);

    printf("Qual o tipo de quarto que o(a) hóspede financiador deseja?");
    scanf("%d", &quarto);


    //Verificação dos Valores e Apresentação do Resultado Final
    if(quarto == 123) {
        total = QuartoCompartilhado * diarias * qtdHospedes; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 482) {
        total = Quarto2pessoas * diarias * qtdHospedes/ 2; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 407) {
        total = Suite2pessoas * diarias * qtdHospedes/ 2; //Cálculo do Booking
       //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 482) {
        total = Quarto2pessoas * diarias * qtdHospedes/ 2; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 237) {
        total = Suite3pessoas * diarias * qtdHospedes/ 3; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 567) {
        total = SuiteFamilia * diarias * qtdHospedes/ 4; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 983) {
        total = CabanaPequena * diarias * qtdHospedes/2; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 647) {
        total = CabanaGrande * diarias * qtdHospedes/ 2; //Cálculo Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 745) {
        total = SuiteDiplomata * diarias * qtdHospedes/ 2; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }

    else if(quarto == 327) {
        total = SuitePresidencial * diarias * qtdHospedes/ 4; //Cálculo do Booking
        //Cadastro dos Hóspedes
        do {
        printf("Qual o Nome do(a) Hospede Financiador ou o que o(a) acompanha?");
        scanf("%s", &nomeAcompanhante);
        printf("Este hospede é menor de idade? (Digite 1 para sim ou 2 para não)");
        scanf("%d", &posneg);
        if (posneg == 1) {
            printf("Insira o RG ou Passaporte deste menor de idade: \n");
            scanf("%d", &rgCrianca);
            printf("Dados da Criança Salvos com Sucesso\n");
            qtdCriancas += 1;
            inseridos += 1;
            //Alerta
            if (qtdCriancas >= 4) {
            printf("Atenção! O Hóspede está com muitas crianças, fique atento(a)! \n");
            }
            printf("%d crianças cadastradas\n", qtdCriancas);
        }
        else {
            printf("Insira o RG ou Passaporte deste hóspede: \n");
            scanf("%d", &rgAdulto);
            printf("Dados do Adulto Salvos com Sucesso\n");
            inseridos += 1;
        }
        printf("Próximo Acompanhante, se existir.\n\n");
    }
    while (inseridos < qtdHospedes);
        //Pergunta sobre a adição do café da manha a reserva
        printf("O Hóspede Financiador deseja café da manhã? (Digite 1 para sim e 2 para não)\n");
        scanf("%d", &opcao1);
        //Calculo do Cafe da Manhã na Reserva do Cliente
        if(opcao1 == 1) {
            calculocafe = CafedaManha * diarias *(qtdHospedes / 2);
            total = total + calculocafe;
        }
        else {
            printf("Café da Manha não estará incluso na reserva\n");
        }
        //Pergunta sobre a adição do serviço de quarto a reserva
        printf("O Hóspede Financiador deseja serviço de quarto? (Digite 1 para sim e 2 para nao)\n");
        scanf("%d", &opcao2);
        //Pergunta sobre o Serviço de Quarto
        if(opcao2 == 1) {
            calculoservico = servicoquarto * diarias;
            total = total + calculoservico;
        }
        else {
            printf("Serviço de Quarto não estará incluso na reserva\n");
        }
        //Apresentação Final
        printf("===========================================\n\n");
        printf("O Valor Total da Reserva do Hóspede é de %d reais brasileiros.\n",total);
        printf("O Hóspede tem %d crianças junto a ele. \n", qtdCriancas);
        printf("O Hóspede Financiador se acomodará no quarto com mais %d hóspede(s).\n", qtdHospedes - 1);
        //Numero do Quarto do Hospede (Varia entre 1 a 100)
        for (i = 1; i <= 10; i++)
        {
            numeroQuarto = rand() % 100 + 1;
            printf ("%d é o numero do quarto deste hospede \n", numeroQuarto);
            getch();
        }
    }
    else {
        printf("O Número do Tipo de Quarto Digitado está incorreto\n");
        printf("Reinciando o Sistema\n\n");
        main();
    }

    return 0;
}
