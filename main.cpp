#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Categoria {                 // Structure declaration
    int numCat;                    // Member (int variable)
    int numQtde;                   // Member (string variable)
};                                 // Structure variable

struct Filme {
    int inicio;
    int final;
    int cat;
};

bool my_compare(Filme a, Filme b){
    return a.final < b.final; // ordenando pelo horario de filme que termina primeiro
}

int main()
{
    int numFilmes_lidos;
    int numCategorias_lidas;
    cin >> numFilmes_lidos;
    cin >> numCategorias_lidas;

    vector<Categoria> categorias; // vector com structs de categorias (seus números e qtde de filmes possíveis)

    for (int i = 1; i <= numCategorias_lidas; i++) {
        Categoria categoria;
        categoria.numCat = i;
        cin >> categoria.numQtde;
        categorias.push_back(categoria);
    }

    // Leitura do vetor de categorias
    cout << "Vetor categorias:" << endl;
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Número da Categoria: " << categorias[i].numCat << "\t";
        cout << "Quantidade da Categoria: " << categorias[i].numQtde << endl;
    }
    

    vector<Filme> filmes;

    for (int i = 0; i < numFilmes_lidos; i++)
    {
        Filme filme;
        cin >> filme.inicio;
        cin >> filme.final;
        cin >> filme.cat;
        filmes.push_back(filme);
    }
    

    // Ordenar o vetor de filmes pelo horário final do filme
    sort(filmes.begin(), filmes.end(), my_compare);

    // Leitura do vetor de filmes (ordenado)
    cout << endl;
    cout << "Vetor filmes:" << endl;
    for (int i = 0; i < filmes.size(); i++) {
        cout << "Horário de início do filme: " << filmes[i].inicio << "\t";
        cout << "Horário do final do filme: " << filmes[i].final << "\t";
        cout << "Categoria pertencente: " << filmes[i].cat << endl;
    }

    // Guardar na "mochila" (resposta) os filmes
    vector<Filme> maratona;
    int final_atual = 0;
    bool primeiro = true;

    for(auto& filme : filmes){
        // categorias está ordenada em ordem crescente de categoria [1...4]
        if(categorias[filme.cat-1].numQtde > 0){
            if (primeiro){
                maratona.push_back(filme);
                primeiro = false;
                categorias[filme.cat-1].numQtde -= 1;
                final_atual = filme.final;
            }
            if (filme.inicio >= final_atual){
                maratona.push_back(filme);
                categorias[filme.cat-1].numQtde -= 1;
                final_atual = filme.final;
            }
        }
    }

    // Leitura do vetor da maratona dos filmes escolhidos 
    cout << endl;
    cout << "Vetor maratona:" << endl;
    for (int i = 0; i < maratona.size(); i++) {
        cout << "Horário de início do filme: " << maratona[i].inicio << "\t";
        cout << "Horário do final do filme: " << maratona[i].final << "\t";
        cout << "Categoria pertencente: " << maratona[i].cat << endl;
    }

    return 0;
}
