#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

int encontrarMenorDistancia(const std::vector<int> &primeiroArray, const std::vector<int> &segundoArray)
{
    int menorDistancia = INT_MAX;

    for (size_t i = 0; i < primeiroArray.size(); ++i)
    {
        for (size_t j = 0; j < segundoArray.size(); ++j)
        {
            int distancia = std::abs(primeiroArray[i] - segundoArray[j]);
            if (distancia < menorDistancia)
            {
                menorDistancia = distancia;
            }
        }
    }

    return menorDistancia;
}

int main()
{
    std::vector<int> primeiroArray = {-1, 5, 10, 20, 23, 3, 37, 60, 70, 80};
    std::vector<int> segundoArray = {26, 6, 134, 135, 15, 17, 28, 50, 46, 55};

    if (primeiroArray.size() < 10 || segundoArray.size() < 10)
    {
        std::cerr << "Os arrays devem ter tamanho maior ou igual a 10." << std::endl;
        return 1;
    }

    int menorDistancia = encontrarMenorDistancia(primeiroArray, segundoArray);
    std::cout << "A menor distância é: " << menorDistancia << std::endl;

    return 0;
}
