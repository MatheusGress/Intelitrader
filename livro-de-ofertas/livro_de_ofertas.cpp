#include <iostream>
#include <vector>

using namespace std;

struct Oferta
{
    int posicao;
    double valor;
    int quantidade;
};

void imprimirOfertas(const vector<Oferta> &ofertas)
{
    cout << "" << endl;
    cout << "LIVRO DE OFERTA" << endl;
    cout << "POSICAO\tVALOR\tQUANTIDADE" << endl;
    for (const auto &oferta : ofertas)
    {
        cout << oferta.posicao << "\t" << oferta.valor << "\t" << oferta.quantidade << endl;
    }
}

int main()
{
    int numNotificacoes;
    cin >> numNotificacoes;

    vector<Oferta> ofertas;

    for (int i = 0; i < numNotificacoes; ++i)
    {
        int posicao, acao, quantidade;
        double valor;
        char virgula;

        cin >> posicao >> virgula >> acao >> virgula >> valor >> virgula >> quantidade;

        // Verifica se VALOR e QUANTIDADE são positivos 
        if (valor <= 0 || quantidade <= 0)
        {
            continue; // Ignora a entrada inválida
        }

        if (acao == 0)
        { // INSERIR
            ofertas.push_back({posicao, valor, quantidade});
        }
        else if (acao == 1)
        { // MODIFICAR
            for (auto &oferta : ofertas)
            {
                if (oferta.posicao == posicao)
                {
                    oferta.valor = valor;
                    oferta.quantidade = quantidade;
                    break;
                }
            }
        }
        else if (acao == 2)
        { // DELETAR
            for (auto it = ofertas.begin(); it != ofertas.end(); ++it)
            {
                if (it->posicao == posicao)
                {
                    ofertas.erase(it);
                    break;
                }
            }
        }
    }

    imprimirOfertas(ofertas);

    return 0;
}
