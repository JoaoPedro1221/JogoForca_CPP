#include <iostream>
#include <stdlib.h>
using namespace std;

bool verificaVitoria(bool acertos[], int tam)
{
    //a funçao recebe o vetor boleano de acertos e o tamanho, no qual sao as variaveis acima
    // apos percorre o vetor pelo for e verifica se tem alguma casa falsa, enquanto tiver uma casa falsa ela retorna falso indicando q a pessoa nao ganhou o jogo ainda
    // caso contrario, retorna verdadeiro, mostrando que o jogo foi concluido e a pessoa ganhou.
    for(int i=0; i< tam; i++)
        if(acertos[i] == false)
            return false;

    return true;
}
// verificar se a letra q a pessoa digitou esta contida na palavra,
//se tiver mostra que teve acerto , colocando a posiçao dela no vetor de accertos como verdadeira
bool validaLetra(char letra, char palavra[], bool acertos[], int tam)
{
    bool houveAcerto = false;

    for(int i=0; i< tam; i++)
    {
        if(palavra[i] == letra)
        {
            acertos[i] = true;
            houveAcerto = true;
        }
    }

    return houveAcerto;
}

void chances(int n)
{ cout<<"\n\n";
    switch(n)
    {
    case 6:
        cout<<" ___\n";
        cout<<"|          \n";
        cout<<"|          \n";
        cout<<"|           \n";
        cout<<"|=========\n";
        break;
    case 5:
        cout<<" ___\n";
        cout<<"|      O  \n";
        cout<<"|          \n";
        cout<<"|           \n";
        cout<<"|=========\n";
        break;
    case 4:
        cout<<" ___ \n";
        cout<<"|      O \n";
        cout<<"|      | \n";
        cout<<"|           \n";
        cout<<"|=========\n";
        break;
    case 3:
        cout<<" ___ \n";
        cout<<"|      O \n";
        cout<<"|     /| \n";
        cout<<"|           \n";
        cout<<"|========= \n";
        break;
    case 2:
        cout<<" ___ \n";
        cout<<"|      O \n";
        cout<<"|     /|\\ \n";
        cout<<"|           \n";
        cout<<"|========= \n";
        break;
    case 1:
        cout<<" ___ \n";
        cout<<"|      O \n";
        cout<<"|     /|\\ \n";
        cout<<"|     /   \n";
        cout<<"|========= \n";
        break;
    case 0:
        cout<<" ___ \n";
        cout<<"|      O \n";
        cout<<"|     /|\\ \n";
        cout<<"|     / \\  \n";
        cout<<"|========= \n";
        break;
    }
} // essa funcao e so para mostrar o boneco baseado no numero de acertos da pessoa

int main()
{   //dedclaracao de variaveis
    char palavra[50];
    int quantLetras = 0;
    //preenche o vetor com valores predefinidos
    for(int i=0; i< 50; i++) palavra[i] = '*';


    cout << "\nEntre com a palavra escolhida: ";
    cin >> palavra;
    system("cls");

    //para cntar quantas letras tem na palavra
    for (int i=0;i <50; i++)
        if(palavra[i] != '*')
            quantLetras++;

    //para tirar o char '\n' do ENTER
    quantLetras = quantLetras -1;

    char letra;
    int NumChances = 6;
    bool acertos[quantLetras];
    //iniciando os valores do vetor
    for(int i=0; i< quantLetras; i++) acertos[i] = false;

    //comeca o jogo
    // estrutura de repeticao, enquanto isso for verddadeiro ele executa o q ta dentro
    while(verificaVitoria(acertos, quantLetras) == false && NumChances > 0)
    {
        cout << "\nTentativas Restantes: " << NumChances << endl;
        chances(NumChances);
        cout<<"\n\n\n";
        cout<<"PALAVRA SECRETA: ";

        for(int i=0; i<quantLetras; i++)
            {
                if (acertos[i] == false)
                    cout << "-";
                else
                    cout << palavra[i];
            }

        cout<<endl;
        cout<<"Digite uma letra: ";
        cin>>letra;
        if(validaLetra(letra,palavra,acertos,quantLetras) == false)
            NumChances--;
        cout<<endl;
        system("cls");
    }
//acabou o jogo e diz se perdu (com numero de chances =o) ou ganhou
    if(NumChances==0)
    {
        chances(NumChances);
        cout<<" VOCE PERDEU!!\n";
        cout<<" A palavra certa era " <<palavra <<"\n\n\n";
    }

    else
    {
        chances(NumChances);
        cout<<" PARABENS VOCE GANHOU!\n\n\n";
        cout<<" A palavra e " << palavra <<endl;
    }
    system("pause");
    system("cls");
    return 0;
}
