#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void funcaoContinuarOuParar(void);//Função para o final de cada cidade
int verificacao(num1,num2,num3);//Verifica a resposta do jogador
int lerOpcoes;
int criaAsOpcoes(item1,item2, item3);//Cria quais opções o usuario poderá selecionar
char opcoes[200], podeSelecionarOpcao1[200],podeSelecionarOpcao2[200],podeSelecionarOpcao3[200], opcaoVazia[]="", opcaoBloqueada[]="Opção bloqueada(você não tem os itens necessários)\n";
int praValidarUmaOpcao=1, praOpcaoVazia=-1;
void inventario(void);//Função para o Inventário do jogador
int  arco=0, flechas=0, danoEspada=0, vidaArmadura=0, espada=0, armadura=0, paes=0, sela=0, carta=0, variavelNula=0,moedas=0,armadilha=0, escudo=0;//Variáveis para inventário
int continuarOuParar=1;//Variáveis para o jogo todo

int main()
{
    setlocale(LC_ALL,"Portuguese");//Configura a acentuação para portugues br   
    //Variaveis cidade 1
    int missaoEscolhida=0, missaoVendedor=0, missaoFerreiro=0, bandidos,mostrarUmaVez=1; 

    printf("\nEm uma noite tranquila quando Rollo, um grande cavaleiro, e seu filho Hoel estavam indo para cidade de Edda, um grupo de três bandidos os assaltaram.\nNo meio de uma intensa luta Rollo sofre um golpe na cabeça e desmaia.\nEle acorda com a luz do sol e percebe que seu filho havia sido sequestrado, e que os bandidos levaram todos os seus pertences.\nEra apenas Rollo e seu cavalo.\n");//Introdução

    printf("\n>Bem vindo(a) a \"EM BUSCA DO FILHO PERDIDO\".\n>Você está pronto para resgatar seu filho?\n>Tome as escolhas certas para conseguir concluir suas missões\n>Realizar todas as missões darão uma expêriencia melhor ao jogador");//Boas vindas

    //Cidade 1 (Edda)
    printf("\n>Depois de se recuperar dos seus ferimentos, Rollo parte em direção a Edda com o objetivo de reencontrar os três bandidos e resgatar seu filho.\n");
    printf("Chegando na cidade de Edda...");
    while (continuarOuParar==1)//Pergunta ao jogador se deseja fazer outra missão ou continuar
    {
       strcpy(opcoes,"\n[1]Falar com o ferreiro\n[2]Falar com o vendedor de alimentos\n");
       verificacao(1,2,2);
       missaoEscolhida=lerOpcoes;
       switch (missaoEscolhida)
        {
        case 1:
            if (missaoFerreiro==0){//Verifica se o jogador já fez a missão
                missaoFerreiro=1;//Indica que o jogador já fez essa missão
                printf("Rollo: Olá amigo você tem um minuto para me ajudar?\n");
                printf("Ferreiro: Oi, vamos ver, o que voce procura?\n");
                printf("Rollo: Na verdade eu preciso de ajuda, ontem eu e meu filho fomos assaltados por 3 bandidos e agora estou sem nada.\n");
                printf("Ferreiro: E onde está seu filho?\n");
                printf("Rollo: Ele foi sequestrado, estou em indo atrás desses bandidos para resgatá-lo.\n");
                printf("Ferreiro: Você deve estar bem preocupado, espero que você consiga reencontralo.\nPosso te dar uma armadura e uma espada que eu não uso mais.\n");
                strcpy(opcoes,">Aceitar ferramentas?\n[1]Sim\n[2]Nao\n");
                verificacao(1,2,2);//Faz a verificação se a opção digitada é valida
                if (lerOpcoes==1){
                    printf("Rollo: Ficarei muito grato se voce fizer isso.\n");
                    armadura=1;
                    espada=1;
                }
            else{
                printf("Rollo: Não precisa, mas obrigado mesmo assim.\n");
            }
                printf("Ferreiro: Nao precisa agradecer, e boa sorte com seu filho.\n");
            }
            else{
                printf(">Você já fez essa missão\n");
            }
            break;
        case 2:
            if (missaoVendedor==0){//Este if else verifica se o jogador ja fez esta missão ou não
                missaoVendedor=1;
                printf("Rollo: Oi amigo, preciso comprar alimentos, mas não tenho nenhum dinheiro. Você pode me ajudar?\n");
                printf("Vendedor: Olá senhor, se você fizer um favor para mim, posso te dar alguma coisa.\n");
                strcpy(opcoes,">Ajudar o vendedor?\n[1]Sim\n[2]Nao\n");
                verificacao(1,2,2);
                if (lerOpcoes==1){
                    printf("Rollo: Posso sim, o que voce precisa?\n");
                }
                else{
                    printf("Rollo: Estou com pressa hoje, talvez outro dia.\n");
                    printf("Vendedor: Tudo bem fica para uma próxima então.\n");
                    break;
                }
                printf("Vendedor: Preciso de ajuda para fazer uma conta.\nPreciso calcular qual que foi meu lucro esse mes.\n");
                printf("Venda total: 1000 moedas\nGastos: 700 moedas\n");//Verificar se a conta está certa
                printf(">Digite o lucro do vendedor: ");
                scanf("%i",&lerOpcoes);
                while (lerOpcoes!=300){
                    printf("\nOps, parece que voce errou a conta tente novamente:\n");
                    scanf("%i", &lerOpcoes);
                }
                printf("Vendedor: Obrigado voce me ajudou muito, vou te servir uma sopa, e posso te dar 2 pães para viagem.\n");
                paes+=2;
                }
                else{
                    printf(">Você já fez essa missão\n");
                }
            break;
        }
        if (missaoEscolhida==1){//Inverte a missão escolhida para o jogador para dizer qual missão falta fazer(linha 100)
            missaoEscolhida=2;
        }
        else{
            missaoEscolhida=1;
        }
        while (mostrarUmaVez==1)//Explica as Opções apenas uma vez
        {
            printf("\n\t>Inventário\nVocê pode consultar seu inventário para saber todos os itens que você tem\n\t>Fazer outra missão\nVocê pode fazer a outra missão disponivel, no seu caso a missão %i\n\t>Continuar\nVocê continua a história do jogo independente de ter feito todas as missões ou não\n",missaoEscolhida);
            mostrarUmaVez=2;
        }
        funcaoContinuarOuParar();
    }
    printf("\n>Rollo continua na cidade até que...\n");
    printf("\nDesconhecido: Oi amigo, ouvi dizer que você está atrás de uns bandidos para resgatar seu filho.\n");
    printf("Rollo: É verdade ontem fomos assaltados e eles levaram meu filho, vou até onde for necessário para encontrar ele de novo\n");
    printf("Desconhecido: Te compreendo, você lembra quantos bandidos eram?\n");
    printf("\n>Digite quantos bandidos eram:");
    scanf("%i", &bandidos);
    printf("\nRollo: Acho que eram %i.\n", bandidos);
    if (bandidos==3){
        printf("Desconhecido: Sei quem são eles, eles sempre compram mantimentos na venda de Dagr a próxima cidade.\n");
    }
    else{
        printf("Desconhecido: Não vi nenhum grupo de %i pessoas suspeitas passando por aqui desde ontem, mas tenho um amigo que pode lhe ajudar.\nEle tem uma venda em Dagr, ele vende tudo o que qualquer um precisar e pode ter informações do grupo.\n", bandidos);
    }
    printf("Rollo: Muito obrigado senhor estou indo para Dagr agora mesmo.\n");
    printf("Desconhecido: Mas tome cuidado, talvez o dono da venda não queira cooperar com você.\n");
    printf("\n>Então Rollo avança em sua jornada rumo a cidade de Dagr...\n");
    
    //Variaveis cidade 2 (Dagr)
    int missaoRancho=0, missaoCantina=0;

    continuarOuParar=1;//Para entra do loop while da cidade 2
    while (continuarOuParar==1)
    {
       strcpy(opcoes,"\n[1]Falar com o senhor do rancho\n[2]Falar com a dona da cantina\n");
       verificacao(1,2,2);
        switch (lerOpcoes)
        {
        case 1:
            if (missaoRancho==0)
            {
                missaoRancho=1;
                printf("Rollo: Olá senhor você tem algo que possa vir a me ajudar na minha jornada, em busca do meu filho  que foi sequestrado?\n");
                printf("Senhor do rancho: Não tenho muita coisa que vai te ajudar mas acabei de adquirir uma sela muito boa,\n eu posso vender ela para você.");//Terminar de escrever
                printf("\n>Com essa sela seu cavalo vai adquirir mais agilidade e velocidade em algum momento necessário.\n");
                printf("Rollo: Qual seria o preço dessa sela senhor?\n");
                printf("Senhor do Rancho: Fiquei comovido com sua história vou fazer por 75 moedas.\n");
                printf("\n>Você tem %i moedas.\n",moedas);
                if (moedas==0){
                    printf("\n>Você não tem moedas suficientes\n");
                    printf("Rollo: Não tenho dinheiro suficiente\n");
                    printf("Senhor do Rancho: Você pode trabalhar na cantina para ganhar moedas, se quiser comprar pode voltar depois\n");
                    break;
                }
                else if (moedas>75){
                    strcpy(opcoes,">Comprar sela por 75 moedas?\n[1]Sim\n[2]Não\n");
                    verificacao(1,2,2);
                    if (lerOpcoes==1){
                        moedas-=75;
                        sela=1;
                        printf("Rollo: Vou comprar, obrigado.\n");
                        printf("Senhor do Rancho: Ótima escolha.\n");
                        missaoRancho=2;
                    }
                    else{
                        printf("Rollo: Não vou levar, mas obrigado pela proposta");
                        printf("Senhor do Rancho: Tudo bem, boa sorte com seu filho\n");
                    }
                }
            }
            else if (missaoRancho==1)
            {
                missaoRancho=2;
                printf(">Você tem %i moedas.\n>Essa é sua ULTIMA chance de comprar a sela.\n", moedas);
                printf("Senhor do rancho: Que bom que você voltou, quer comprar a sela?\n");
                strcpy(opcoes,">Comprar sela por 75 moedas?\n[1]Sim\n[2]Não\n");
                verificacao(1,2,2);
                if (lerOpcoes==1){
                    moedas-=75;
                    sela=1;
                    printf("Rollo: Vou comprar, obrigado.\n");
                    printf("Senhor do Rancho: Ótima escolha.\n");
                }
                else{
                    printf("Rollo: Não vou levar, mas obrigado pela proposta");
                    printf("Senhor do Rancho: Tudo bem, boa sorte com seu filho\n");
                }
            }
            else{
                 printf(">Você já fez essa missão\n");
            }
            break;
        case 2:
            if (missaoCantina==0)
            {
                missaoCantina=1;
                printf("Rollo: Olá você é  a dona da cantina?\n");
                printf("Dona da cantina: Sim, sou eu, no que posso te ajudar?\n");
                printf("Rollo: Eu preciso de dinheiro posso trabalhar pra você?\n");
                printf("Dona da cantina: Você pode me ajudar a servir as mesas até de noite?\n");
                printf("> Rollo trabalhou até o anoitecer.\n");
                moedas=100;
                printf("Dona da cantina: Muito obrigado pela ajuda pegue esse dinheiro, espero que ajude o senhor.\n");
                printf(">Você tem %i moedas\n", moedas);
            }
            else {
            printf(">Você já fez essa missão\n");
            }           
            break;
        }
        funcaoContinuarOuParar();
    }
    
    //Conversa com o dono da venda (indicado pelo desconhecido no fim da cidade 1)
    printf(">Rollo precisa falar com o dono da venda de Dagr para tentar obter informações sobre os bandidos\n");
    strcpy(opcoes,"Falar com o dono de maneira:\n[1]Amigável\n[2]Ameaçadora\n");
    verificacao(1,2,2);
    if (lerOpcoes==1){
        printf("Rollo: Olá senhor, conversei com um amigo seu em Edda que disse que você pode me ajudar.\n");
        printf("Dono da venda: Bom, vamos ver o que posso fazer por você, o que você precisa?\n");
        printf("Rollo: Há alguns dias atrás eu e meu filho fomos assaltados por três bandidos, eles roubaram tudo de mim, e sequestram meu filho.\nSei que você vende tudo para todos, você sabe onde eles podem estar?\n");
        printf("Dono da venda: Não conheço nenhum grupo de bandidos, lamento não poder ajudar.\nTenha um bom dia senhor!\n");
        strcpy(opcoes,"\n[1]Insistir\n[2]Sair da venda\n");
        verificacao(1,2,2);
        if (lerOpcoes==1){
            printf("Rollo: Sei que você está mentindo, me conte logo onde eles estão!\n");
            printf("Dono da venda: Eu não conheço eles, eu juro! Você precisa acreditar!\n");
        }
        else{
            printf("Rollo: Tudo bem, tenha um ótimo dia.\n");
            printf("Dono da venda: Obrigado por acreditar em mim, se precisar é me chamar.\n");
        }
    }
    else{
        printf(">Chegando na venda Rollo pega uma faca e ameaça o vendedor\n");
        printf("Dono da venda: Calma senhor! O que você precisa??? Faço o que você quiser!\n");
        printf("Rollo: Sei que você vende produtos para todos da região,\nquero que me diga se você viu três bandidos levando um garoto nos últimos dias!\n");
        printf("Dono da venda: Desculpe senhor não vi nenhum grupo suspeito, estou falando a verdade! Por favor acredite em mim!");
    }
    printf("\n>Quando de repente...\n>Dois homens suspeitos entram na loja.\n");
    printf("Suspeito:O chefe disse que precisamos comprar comida para aquele menino.\n");
    printf("Dono da venda: Não esperava vocês por aqui! Hã, quero dizer, bom dia senhores! No que posso ajudar vocês?\n");
    printf("Suspeito: Por que não nos esperava? Sempre viemos aqui. O chefe quer comida e precisamos daquele item especial.\n");
    strcpy(opcoes,"\n[1]Perguntar ao dono quem são eles\n[2]Sair da venda\n");
    verificacao(1,2,2);
        if (lerOpcoes==1){
            printf("Rollo: Quem são eles???\n");
            printf("Dono da loja: Não sei eu já disse!\n");
        }
        else{
            printf("\n>Logo depois que Rollo sai da loja reencontra os suspeitos novamente...\n");
            printf("Rollo: Quem são vocês???\n");
        }
        printf("Suspeito: Você quer confusão? Acho melhor você sair daqui logo!\n");
        printf("Rollo: Não quero confusão só quero resgatar meu filho!\n");
        printf("Suspeito: Então é você que está atrás de nós.\n");
        printf("Rollo: Então vocês são os bandidos que sequestram meu filho!");
        printf("\n>Os suspeitos começam a perseguir Rollo\n");
        strcpy(podeSelecionarOpcao1,"\n[1]Lutar\n");
        strcpy(podeSelecionarOpcao2,"\n[2]Fugir com o cavalo\n");
        strcpy(opcoes,"");
        criaAsOpcoes(espada,sela);

        if (lerOpcoes==1){//Ir para fazenda ou não, se não for para fazenda não ganhará a armadilha
            printf("\n>Rollo luta contra os dois capangas e fica ferido, mas felizmente consegue fugir e despistar os bandidos.\n");
            printf(">Enquanto Rollo seguia seu caminho na estrada ele avista uma casa com um fazendeiro que pode lhe ajudar com seus ferimentos\n");
            strcpy(opcoes,"\n>Pedir ajuda para o fazendeiro?\n[1]Sim\n[2]Não\n");
            verificacao(1,2,2);
            if (lerOpcoes==1){
                carta=1;
                printf("\n>Depois de pedir ajuda o fazendeiro acolhe Rollo e eles conversam sobre sua grande missão.\n>No meio da conversa...\n");
                printf("Fazendeiro: Então Rollo, tem alguma forma de eu ajudar você? Já fui cavaleiro também posso ir atrás deles com você\n");
                printf("Rollo: É muita gentileza sua mas não posso aceitar, você já me ajudou muito, preciso fazer isso sozinho.\n");
                printf("Fazendeiro: Tudo bem, ao menos passe a noite aqui, para qual cidade você vai amanhã mesmo?\n");
                printf("Rollo: Vou para Forseti, posso ficar até amanhecer aqui.\n");
                printf("Fazendeiro: Você pode fazer um favor para mim? Preciso que você entregue uma carta para o armeiro da cidade, o nome dele é Hagnar, pode fazer isso por mim?\n");
                printf("Rollo: Com certeza, farei com muito prazer. E quem eu devo dizer que enviou a carta?\n");
                printf("Fazendeiro: muito obrigado amigo, diga que foi Albert quem enviou, mas não leia a carta é um assunto pessoal.\n");
                printf("Rollo: Tudo bem não vou ler.\n");
            } 
        }
        else{
            carta=1;
            printf("\n>Rollo consegue fugir, ele encontra refugio na casa de um fazendeiro, e consegue despistar os bandidos.\n>Depois de o fazendeiro acolher Rollo eles conversam sobre sua grande missão.\n>No meio da conversa...\n");
            printf("Fazendeiro: Então Rollo, tem alguma forma de eu ajudar você? Já fui cavaleiro também posso ir atrás deles com você\n");
            printf("Rollo: É muita gentileza sua mas não posso aceitar, você já me ajudou muito, preciso fazer isso sozinho.\n");
            printf("Fazendeiro: Tudo bem, ao menos passe a noite aqui, para qual cidade você vai amanhã mesmo?\n");
            printf("Rollo: Vou para Forseti, posso ficar até amanhecer aqui.\n");
            printf("Fazendeiro: Você pode fazer um favor para mim? Preciso que você entregue uma carta para o armeiro da cidade, o nome dele é Hagnar, pode fazer isso por mim?\n");
            printf("Rollo: Com certeza, farei com muito prazer. E quem eu devo dizer que enviou a carta?\n");
             printf("Fazendeiro muito obrigado amigo, diga que foi Albert quem enviou, mas não leia a carta é um assunto pessoal.\n");
            printf("Rollo: Tudo bem não vou ler.\n");
        }
        printf(">Rollo segue em direção a Forseti e para no caminho para tomar água\n");
        switch (carta)
        {
        case 0:
            printf(">Rollo está muito ferido e precisa se recuperar, dê algum alimento para ele se recuperar\n");
            strcpy(podeSelecionarOpcao1,"\n[1]Pao\n");
            strcpy(podeSelecionarOpcao2,"");
            strcpy(opcoes,"");
            lerOpcoes=-1;
            criaAsOpcoes(paes,variavelNula); 
            paes-=1;
            break;
        case 1:
            printf(">Quando Rollo está tomando água ele olha para a carta\n");
            strcpy(opcoes,"\n[1]Ler a carta e quebrar a promessa\n[2]Respeitar a promessa\n");
            verificacao(1,2,2);
            if (lerOpcoes==1)
            {
                printf("\n\tOlá Hagnar;\nPreciso que você ajude meu amigo a recuperar seu filho, eu falei que poderia conseguir ajuda se ele quisesse, mas ele disse que precisa fazer isso sozinho;\nVocê é o melhor armeiro que eu conheço e tem as melhores armadilhas, de para ele sua melhor armadilha eu pago você depois, quero de alguma forma poder ajudá-lo;\n\tGrande abraço do seu amigo Albert;\n");
            } 
            else{
                printf(">Rollo bebe água e continua sua viagem.\n");
            }
        }

    //Cidade 3(Forseti)
    int missaoFazendeiro=0,missaoArmeiro=0, missaoFamilia=0;//Variáveis para cidade 3
    
    continuarOuParar=1;
    printf(">O Cavaleiro Rollo chega na cidade de Forseti depois de uma longa jornada cheia de imprevistos da cidade de Dagr.\n");    
    printf(">Ele se depara com várias pessoas pedindo ajuda.\n");
    while (continuarOuParar==1)
    {
        strcpy(podeSelecionarOpcao1,"\n[1]Conversar com o Fazendeiro");
        strcpy(podeSelecionarOpcao2,"\n[2]Falar com a Familía de Vikins");
        strcpy(podeSelecionarOpcao3,"\n[3]Conversar com Armeiro.\n");
        strcpy(opcoes,"");
        criaAsOpcoes(praValidarUmaOpcao,praValidarUmaOpcao,carta);
        switch (lerOpcoes)
        {
        case 1:
            if (missaoFazendeiro==0)
            {
                missaoFazendeiro=1;
                printf("Fazendeiro: Olá cavaleiro, você pode me ajudar?\n");
                strcpy(opcoes,"\n>Ajudar fazendeiro?\n[1]Sim\n[2]Não\n");
                verificacao(1,2,2);
                if (lerOpcoes==1){
                    printf("Rollo: Opa posso sim, no que posso te ajudar?\n");
                    printf("Fazendeiro: Preciso de ajudar pra saber quantos quilos tem nessa pilha de sacos de trigo.\n");
                    printf("Rollo: Quantos sacos tem nessa pilha e qual o peso de de cada saco?\n");
                    printf("Fazendeiro: São extamente 80 sacos de trigo, e cada saco pesa 20kg.\n");
                    printf(">Digite quantos quilos tem a pilha de sacos:\n");
                    scanf("%i",&lerOpcoes);
                    while (lerOpcoes!=1600)
                    {
                        printf("\nOps, parece que voce errou a conta tente novamente:\n");
                        scanf("%i", &lerOpcoes);
                    }
                    printf("Fazendeiro: Obrigado por me ajudar cavaleiro  posso te dar 30 moedas pela ajuda.\n");
                    moedas+=30;
                    
                }
                else{
                    printf("Rollo: Muito obrigado mas não tenho interesse em te ajudar.\n");
                    printf("Fazendeiro: Tudo bem, boa sorte em seu caminho.\n");
                }
            }
            else{
            printf(">Você já fez essa missão\n");
            }   
            break;
        case 2:
            if (missaoFamilia==0){
                missaoFamilia=1;
                printf("Familía Viking: Ei Cavaleiro, o senhor tem um instate?\n");
                printf("Rollo: Oi posso sim.\n");
                printf("Familía Viking: Nos precisamos de ajuda para contar as telhas?\n");
                strcpy(opcoes,"\n>Ajudar a Familía Viking?\n[1]Sim\n[2]Não\n");
                verificacao(1,2,2);
                if (lerOpcoes==1){
                    printf("Rollo: Sim posso, no que posso lhes ajudar?\n");
                    printf("Familía Viking: Nós Precisamos saber quantas telhas serão usadas pra construir o telhado da nossa casa.\n");
                    printf("Familía Viking: São 60 telhas de largura e 20 telhas de comprimento\n");
                    printf("\n>Dica: Para essa conta você fazer precisa fazer largura x comprimento x 2!\n");
                    printf(">Digite quantas telhas serão usadas no telhado da casa:\n");
                    scanf("%i", &lerOpcoes);
                    while (lerOpcoes!=2400){
                      printf("\nOps, parece que voce errou a conta tente novamente:\n");
                      scanf("%i",&lerOpcoes);
                    }
                    printf("Rollo: Vocês vão precisar de 2400 telhas\n");
                    printf("Família Viking: Ok, obrigado pela ajuda, tome essas moedas.\n");
                    moedas+=30;
                }
                else{
                    printf("Hoje não amigos, estou só de passagem na cidade.\n");
                    printf("Familía Viking: Sem problemas, e boa viagem.");
                }
            }
            else{
                printf(">Você já fez essa missão\n");
            }
            break;
        case 3:
            if (missaoArmeiro==0){
            missaoArmeiro=1;
            printf("Rollo: Olá senhor, você tem um minuto?\n");
            printf("Ameiro: Claro, o que você precisa?\n");
            printf("Rollo: Tenho uma carta para você, Albert enviou.\n");
            printf("Armeiro: Faz muito tempo que não falo com ele, ele é um grande amigo.\n");
            printf("Rollo: Com certeza ele é, me ajudou.\n");
            printf(">O Armeiro lê a carta e então.\n");
            printf("Armeiro: E o que trouxe você até aqui?\n");
            printf("Rollo: Estou atrás de três bandidos que sequestram meu filho.\n");
            printf("Armeiro: É um grande desafio, vou te dar uma armadilha, ela pode ser útil para você.\n");
            printf("\n>Você só poderá usar a armadilha em momentos especiais\n");
            armadilha=1;
        }
        else{
            printf(">Você já fez essa missão\n");
        }
            break;
        }
        funcaoContinuarOuParar();
    }   
        //Cidade 4
        printf("\n>Depois de uma longa viagem Rollo chega a Harald e então...\n");
        printf("Padre: Senhor, você precisa nos ajudar, alguns minutos atrás, um bandido assaltou a Igreja e roubou nossos itens! Por favor, precisamos de sua ajuda!\n");
        strcpy(opcoes,"Ajudar o padre?\n[1]Sim\n[2]Não\n");
        verificacao(1,2,2);
        if (lerOpcoes==1)
        {
            printf("Rollo: Posso ajudar, onde ele está?\n");
            printf("Padre: Ele está em uma cabana, ha uns cinco minutos da cidade\n");
            printf(">Então Rollo segue as instruções sobre o local e encontra o bandido\n");
            printf(">Rollo luta contra o bandido e consegue mata-lo.\n");
            strcpy(opcoes,"\n[1]Voltar para a cidade e devolver os pertences recuperados\n[2]Fugir com os pertences roubados e ir para Ingvar\n");
            verificacao(1,2,2);
            if (lerOpcoes==1)
            {
                printf(">Rollo volta para a cidade e devolve os pertences a igreja\n");
                printf("Padre: Muito obrigado senhor você nos salvou.\n");
                printf("Rollo: Não precisa agradecer fiz o que precisava ser feito.\n");
                printf("Padre: Precisamos agradecer sim, tome essas moedas como agradecimento.\n");
                moedas+=120;
                printf("\n>Você tem %i moedas.\n",moedas);
                printf("Rollo: Nossa, são muitas moedas, muito obrigado.");
            }
            else{
                printf("Se tiver que escolher entre o fácil e o certo, opte pelo certo.\n\t2021, Nathalia da Cruz Alvez");//Não fica braba prof <3
                printf("\nBoa sorte na próxima vez");
                exit(0);
            }
        }
        else{
            printf("Rollo: Não posso te ajudar nisso senhor.\n");
            printf("Padre: Tudo bem não vou ficar atrapalhando você.\n");
        }
        printf("\n>Então Rollo segue seu caminho até que...\n");
        printf("Lenhador: Olá senhor, preciso de ajuda para acabar de serrar essa árvore.\n");
        strcpy(opcoes,"Ajudar lenhador?\n[1]Sim\n[2]Não\n");
        verificacao(1,2,2);
        if (lerOpcoes==1){
            printf("Rollo: Posso ajudar o senhor.\n");
            printf("Lenhador: Muito obrigado senhor, sozinho eu nunca iria acabar.\n");
            ("\n>Quando Rollo termina de ajudar o lenhador...\n");
            printf("Lenhador: Isso foi bem mais fácil com sua ajuda, muito obrigado.\n");
            printf("Rollo: Com ajuda sempre conseguimos fazer as coisas.\n");
            printf("Lenhador: Não tenho muito para te oferecer, percebi que você tem uma espada mas não possui nehum arco.\nVou te dar um arco que eu tenho para você poderá ser útil em algum momento");
            printf("\n>Você ganhou uma nova arma, visite seu inventário para mais detalhes\n");
            arco=1;
            flechas=2;
        }
        else{
            printf("Rollo: Não posso ajudar o senhor estou com pressa.\n");
            printf("Lenhador: Que pena eu realmente preciso de ajuda, mas tudo bem.\n");
        }        
        while (continuarOuParar!=0 && continuarOuParar!=1){
            printf("\n[0]Inventário\n[1]Continuar\n");
            scanf("%i", &continuarOuParar);
        }
        if (continuarOuParar==0){
            inventario();
        }
        while (continuarOuParar!=1){
            printf("[1]Continuar\n");
            scanf("%i", &continuarOuParar);
        }
        
        //Emboscada: Depois da ciadade 4
        printf("\n>Rollo está indo para a aldeia de Ingvar quando de repente...\nOs mesmos dois bandidos que ele encontrou na venda de Dagr o surpreendem novamente.\n");
        strcpy(podeSelecionarOpcao1,"[1]Lutar com espada\n");
        strcpy(podeSelecionarOpcao2,"[2]Lutar com o arco\n");
        strcpy(opcoes,"");
        criaAsOpcoes(espada,arco,praOpcaoVazia);
        if (lerOpcoes==1){
            printf(">Rollo luta bravamente contra os bandidos e consegue afujentá-los.\n>Mas seu cavalo fica gravemente ferido por uma flecha, e não resiste ao ferimento.\n");
        }
        else{
            printf(">Rollo tem seu cavalo acertado por uma flecha, que infelizmente não resiste ao ferimento.\n>Mas antes dos bandidos se aproximarem Rollo acerta gravemente um dos bandidos, fazendo-os passar reto em direção a Ingvar.\n");
        }
        printf("\n>Assim não consegue perseguir os bandidos e perde o rastro deles, mas segue a estrada até chegar em Ingvar.\n");

        //Váriaveis cidade 5
        int lista, preco=0;

        //Cidade 5
        printf(">Na chegada ele encontra os guardas da aldeia.\n");
        strcpy(opcoes,"\n>Conversar com  os guardas da aldeia?\n[1]Sim\n[2]Não\n");
        verificacao(1,2,2); 
        if(lerOpcoes==1){
           printf("Rollo: Olá guardas vocês podem me ajudar?\n Eu sofri uma emboscada pelos capangas de um bandido que sequestrou meu filho.\n");
           printf("Guardas da Aldeia: Conhecemos esses capangas, eles não podem entrar na aldeia mas ficamos sabendo que eles foram pra cidade de Siefried.\n");
           printf("Rollo: Muito obrigado por essa informação\n");
            printf("Guardas da Aldeia: Você deve falar com o lorde da aldeia ele vai te ajudar a encontrar o sequestrador.\n");
           }
        else{
          printf("Muito obrigado mas preciso seguir rápido para encontrar meu filho.\n");
          printf("Guardas da Aldeia: Tudo bem mas você deve falar com o Lorde da aldeia ele tem informações preciosas.\n ");
          }
        printf("\n>Rollo vai até o palacio do lorde para pedir informções sobre o sequestrador.\n");
        printf("Lorde da Aldeia: Meus guardas avisaram que você iria aparecer por aqui!\n");
        printf("Rollo : Eles me falaram que você me ajudaria a encontrar o sequestrador do meu filho.\n");
        printf("Lorde da Aldeia: Eu já tive muitos problemas com esse sequestrador,e posso te passar a  localização dele e talvez passar uma lista de coisa que você vai precisar para combater eles.\n ");
        strcpy(opcoes,"\n>Aceitar as informações do lorde da Aldeia\n[1]Sim\n[2]Não\n");
        verificacao(1,2,2);
        if(lerOpcoes==1){
            printf("Lorde  da Aldeia: Sei que eles se escondem em um galpão abandonado na cidade de Siefrid.\nPosso te passar duas listas de ferramentas para você conseguir derrotar ele, tenho uma espada guardada para um momento especial, talvez esse momento chegou, a espada agora é sua.\n");
            espada=2;
            printf("Rollo: Muito obrigado, ela parece ser muito especial mesmo.\n");
            printf("\n>LISTA 1\nArmadura nova\nEspada\nEscudo\nArmadilha\n");
            printf("\n>LISTA 2\nArco\nEspada\nEscudo\nReparar armadura\nTrês pães\n");
            strcpy(opcoes,"\n> Você quer qual lista?\n[1]LISTA 1\n[2]LISTA 2\n");        
            verificacao(1,2,2);
            lista=lerOpcoes;
            if (lerOpcoes==1){
                printf("Lorde da ALdeia: Usando essa lista a você poderá atrair os capangas do sequestrador e prendelos com a armadilha, e usar a armadura, o escudo, e a espada para combater e vencer o sequestrador.\n");
            }
            else{
                printf("Lorde da Aldeia: Usando essa lista  você poderá derrubar os capangas usando o arco,e você vai usar o escudo e a armaduta reparada pra se denfender, mas você não terá força suficiente então terá que comer os pães, e atacar com a espada.\n ");
            }
        }
        else {
            printf(">Rollo seguiu sua jornada sozinho, mas infelizmente não conseguiu derrotar os bandidos.\n");
            exit (0);
        }
        printf("\n>Então Rollo pega a lista e segue em direção para o armeiro da aldeia.\n");
        printf("Armeiro: Olá senhor no que posso te ajudar?\n");
        printf("Rollo: Preciso comprar estas coisas.\n");
        printf("\n>Rollo mostra todos as ferramentas que ele ainda precisa comprar");
        if (lista==1){
            printf("\n>Você precisa comprar:\n\t>Armadura: 60 moeadas\n\t>Escudo: 50 moedas");
            preco=110;
            armadura=2;
            escudo=1;
            if (armadilha==0){
                printf("\n\t>Armadilha:60\n");
                preco+=60;
                armadilha=1;
            }
        }
        else{
            printf("Você precisa comprar:\n\t");
            if (arco==0){
                printf(">Arco: 50 moedas\n\t");
                preco=50;
                arco=1;
            }
            printf(">Flechas: 20 moedas\n\t>Escudo: 50 moedas\n\t>Reparar armadura: 30 moedas\n\tPães: 3 moedas\n"); 
            preco+=103;
            flechas=10;
            escudo=1;
            paes+=3;           
        }     
        printf("\n>Você tem: %i moedas\n",moedas);
        printf(">Você precisa de: %i moedas\n", preco);
        moedas=moedas-preco;
        strcpy(podeSelecionarOpcao1,"\nFinalizar compra?\n[1]Sim\n");
        strcpy(podeSelecionarOpcao2,"");
        strcpy(podeSelecionarOpcao3,"");
        strcpy(opcoes,"");
        criaAsOpcoes(moedas,moedas,moedas);
        printf("\n>Seu inventário foi atualizado");
        while (continuarOuParar!=0 && continuarOuParar!=1){
            printf("\n[0]Inventário\n[1]Continuar\n");
            scanf("%i", &continuarOuParar);
        }
        if (continuarOuParar==0){
            inventario();
        }
        while (continuarOuParar!=1){
            printf("[1]Continuar\n");
            scanf("%i", &continuarOuParar);
        }
        printf("\n>Quando Rollo sai da aldeia ele encontra três caminhos.\n");
        strcpy(opcoes,"\n>Ir para qual cidade?\n[1]Asgard\n[2]Siefried\n[3]Bifrost\n");
        verificacao(1,2,3);
        while (lerOpcoes!=2){
            printf("Opção errada, tente novamente.\n");
            verificacao(1,2,3);
        }
        //Cidade 6 the final(Siefried)
        int garcom=0, homemBebendo=0;

        printf("\n>Depois de adquirir seus equipamentos, Rollo chega em Siefried e vai para o bar da cidade");
        printf(">Rollo precisa encontrar alguém para montar um plano.\n");
        while (lerOpcoes!=3){
            strcpy(opcoes,"\nTentar subornar:\n[1]Garçom\n[2]Homem bebendo whisky\n[3]Homem sozinho na mesa\n");
            verificacao(1,2,3);
            switch (lerOpcoes)
            {
            case 1:
                if (garcom==0){
                    garcom=1;
                    printf("\nGarçom: Olá senhor precisa de algo?\n");
                    printf("Rollo: Preciso resgatar meu filho, mas para isso preciso derrotar uns bandidos, e acho que você pode me ajudar\n.");
                    printf("Garçom: Não posso te asjudar com isso senhor");
                    printf("Rollo: Posso te dar algumas moedas se você me ajudar.\n");
                    printf("Garçom: Desculpa senhor, mas não aceito suborno.\n");
                    printf("\n>Você não teve muita sorte. Tente com outra pessoa.\n");
                }
                else{
                    printf("\n>Você já tentou conversar com essa pessoa.\n");
                }
                break;
            case 2:
                if (homemBebendo==0)
                {
                    homemBebendo=1;
                    printf("Rollo: Oi amigo você tem um minuto?\n");
                    printf("Homem bebendo: Talvez o que você precisa?\n");
                    printf("Rollo: Preciso resgatar meu filho, mas para isso preciso derrotar uns bandidos, e acho que você pode me ajudar\n.");
                    printf("Homem bebendo: Acho que não posso te ajudar.\n");
                    printf("Rollo: Posso te pagar algumas moedas se me ajudar.\n");
                    printf("Homem bebendo: Você acha que sou quem??? Já disse que não vou ajudar você!");
                    printf("Rollo: Tudo bem senhor.\n");
                    printf("Homem bebendo: E nunca mais fale comigo.\n");
                    printf("\n>Você não teve muita sorte. Tente com outra pessoa.\n");
                    break;
                }
                else{
                    printf("\n>Você já tentou conversar com essa pessoa.\n");
                }
            }
        }
        printf("Rollo: Oi amigo você tem um minuto?\n");
        printf("Homem sozinho: Claro o que você precisa?\n");
        printf("Rollo: Preciso de sua ajuda para combater uns bandidos.\n");
        printf("Homem sozinho: Acho um motivo justo, mas quero algo em troca.\n");
        printf("Rollo: Posso te dar %i moedas\n", moedas-1);
        printf("Homem sozinho: Eu aceito, mas o que eu preciso fazer?\n");
        if (lista==1){
            printf("Rollo: Preciso que você atraia os capangas para eu capturá-los com a armadilha.\n");
            printf("Homem sozinho: Tudo bem mas acho bom você conseguir capturar eles.\n");
            printf("Rollo: Pode deixar comigo");
            printf("\n>O plano:\n\tO ajudante de Rollo(homem do bar) atrai a atenção dos capangas e Rollo prende eles na armadilha, e depois luta contra o sequestrador para recuperar seu filho.\n");
            printf("\n>Rollo começa a executar o plano.\n>Depois de seu ajudante chamar a atenção Rollo consegue prender os capangas em sua armadilha.\n");
            }
        else{
            printf("Rollo: Preciso que você atraia os capangas para eu acertá-los com o arco.\n");
            printf("Homem sozinho: Tudo bem mas acho bom você conseguir acertar eles.\n");
            printf("Rollo: Pode deixar comigo");
            printf("\n>O plano:\n\tO ajudante de Rollo(homem do bar) atrai a atenção dos capangas e Rollo acerta eles com o arco, depois luta contra o sequestrador para recuperar seu filho.\n");
            printf("\n>Rollo começa a executar o plano.\n>Depois de seu ajudante chamar a atenção Rollo consegue acertar os capangas com seu arco.\n");
        }
        printf("Ajudante: Boa sorte amigo agora, é com você.\n");
        printf("Rollo: Obrigado, sua ajuda foi muito importante.\n");
        printf("\n>Então Rollo segue em direção ao sequestrador.\n");
        printf("Sequestrador: Você não pode me derrotar.\n");
        printf("Rollo: Você tirou meu filho de mim, só vim recuperar o que é meu.\n");
        printf("\n>Então Rollo começa a lutar contra o sequestrador.\n>Depois de uma grande luta Rollo consegue imobilizar o sequestrador.\n");
        printf("Sequestrador: Por favor não me mate. Eu faço qualquer coisa.");
        strcpy(opcoes,"\nMatar o sequestrador?\n[1]sim\n[2]Não\n");
        verificacao(1,2,2);
        if (lerOpcoes==1){
            printf("Rollo: Você sequestrou meu filho e mandou seus capangas me matarem diversas vezes!\n");
            printf("\n>Então Rollo pega sua espada a mata o sequestrador cumprindo sua promessa.\n");    
        }
        else{
            printf("\n>Rollo não mata o sequestrador, e depois liberta seu filho.\n>Rollo chama as autoridades que prenderam o sequestradror.\n");
        }
        printf("\n>Rollo volta para casa com seu filho e comemararam muito a volta dos dois\n");       
        printf("\n\tOBRIGADO POR JOGAR \"EM BUSCA DO FILHO PERDIDO\"\nFeito por Rafael Antônio Bressanini e Arthur Felipe Luciani Corrêa");
    return 0;
}

//Função para verificar se o jogador digitou a opção correta
int verificacao(num1,num2,num3){//máximo de opções que existem no jogo: 3
    lerOpcoes=-1;
    while (lerOpcoes!=num1 && lerOpcoes!=num2 && lerOpcoes!=num3)
    {
        printf(opcoes);
        scanf("%i",&lerOpcoes);
    }
    return 0;
}

void funcaoContinuarOuParar(void){//Função para o final de cada cidade
    continuarOuParar=-1;
    while (continuarOuParar!=0 && continuarOuParar!=1 && continuarOuParar!=2){
        printf("\n\t[0]Consultar Inventário\n\t[1]Fazer outra missão\n\t[2]Continuar\n");
        scanf("%i", &continuarOuParar);
    }
    if (continuarOuParar==0){//Chama a função inventário para mostrar o inventário do jogador
        inventario();
        while (continuarOuParar!=1 && continuarOuParar!=2){
        printf("\n\t[1]Fazer outra missão\n\t[2]Continuar\n");
        scanf("%i", &continuarOuParar);
        }
    }
    return 0;
}

//Cria quais opções o usuario poderá selecionar
int criaAsOpcoes(item1,item2,item3){
    if (item1>0 && item2==0 && item3==0){//1
        printf("%s %s %s",podeSelecionarOpcao1, opcaoBloqueada, opcaoBloqueada );
        verificacao(1,1,1);
    }
    else if (item1>0 && item2>0 && item3==0){//1 e 2
        printf("%s %s %s", podeSelecionarOpcao1,podeSelecionarOpcao2, opcaoBloqueada);
        verificacao(1,2,2);
    }
    else if (item1>0 && item2>0 && item3>0){// 1 e 2 e 3
        printf("%s %s %s", podeSelecionarOpcao1,podeSelecionarOpcao2, podeSelecionarOpcao3);
        verificacao(1,2,3);
    }
    else if (item1==0 && item2>0 && item3==0){//2
        printf("%s %s %s", opcaoBloqueada,podeSelecionarOpcao2, opcaoBloqueada);
        verificacao(2,2,2);
    }
    else if (item1==0 && item2>0 && item3>0){//2 e 3
        printf("%s %s %s", opcaoBloqueada,podeSelecionarOpcao2, podeSelecionarOpcao3);
        verificacao(2,2,3);
    }
    else if (item1==0 &&item2==0 && item3>0){//3
        printf("%s %s %s", opcaoBloqueada,opcaoBloqueada, podeSelecionarOpcao3);
        verificacao(3,3,3);
    }
    else if (item1>0 && item2>0 && item3==-1){
        printf("%s %s %s", podeSelecionarOpcao1,podeSelecionarOpcao2, opcaoVazia);
        verificacao(1,2,2);
    }
    else if (item1==0 && item2>0 && item3==-1){
        printf("%s %s %s", opcaoBloqueada,podeSelecionarOpcao2, opcaoVazia);
        verificacao(2,2,2);
    }
    else if (item1>0 && item2==0 && item3==-1){
        printf("%s %s %s", podeSelecionarOpcao1,opcaoBloqueada, opcaoVazia);
        verificacao(1,1,1);
    }
    
    else{//Finaliza o jogo se o usuário não tem os itens necessários
            printf("\nVocê não tem os itens necessários para continuar\nDica: Tente fazer todas as missões para desblquear todas as opções");
            exit(0);
        }
    return 0;
}

void inventario(){//Função para o Inventário do jogador
    printf("\n>Inventário\n");
        switch (espada,armadura)//Regula a força dos equipamentos
        {
        case 1:
            danoEspada=40;
            vidaArmadura=50;
            break;
        case 2:
            danoEspada=50;
            vidaArmadura=60;
        }
    if (espada==0 && armadura==0 && arco==0 && paes==0)//Mostra o status dos equipamentos
    {
        printf("\n>Nenhum item no inventário até o momento\n");
    }
    else{
        printf("\n>Moedas: %i\n", moedas);
        if (espada>0){
            printf("\n>Espada nivel %i\n\tDano: %i\n",espada, danoEspada);
        }
        else{
            printf("\n>Item não encontrado\n");
        }    
        if (armadura>0){
            printf("\n>Armadura nivel %i\n\tProteção: %i\n",armadura, vidaArmadura);
        }
        else{
            printf("\n>Item não encontrado\n");
        }
        if (escudo>0){
            printf("\n>Escudo\n\t>Proteção: 40\n");
        }
        else{
            printf("\n>Item não encontrado\n");
        }
        if (armadilha>0){
            printf("\nArmadilha(só pode ser usada em momentos especiais)\n");
        }
        else{
            printf("\n>Item não encontrado\n");
        }    
        if (arco>0){
            printf("\n>Arco nivel 1\n\tDano: 60\n\tFlechas: %i\n",flechas);
        }
        else{
            printf("\n>Item não encontrado\n");
        }
        if (sela>0){
            printf("\n>Sela para o cavalo\n");
        }
        else{
            printf("\n>Item não encontrado\n");
        }    
        if (paes>0){
            printf("\n>Pães: %i\n",paes);
        }
        else{
            printf("\n>Item não encontrado\n");
        }
    }    
    return 0;
}