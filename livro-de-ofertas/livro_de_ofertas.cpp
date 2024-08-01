#include <iostream>
#include <vector>

struct Offer
{
    int positionProduct;
    double valueProduct;
    int amountProduct;
};

void printOffers(const std::vector<Offer> &offers)
{
    std::cout << "\nLIVRO DE OFERTA\n";
    std::cout << "POSIÇÃO\tVALOR\tQUANTIDADE\n";
    for (const auto &offer : offers)
    {
        std::cout << offer.positionProduct << "\t" << offer.valueProduct << "\t" << offer.amountProduct << "\n";
    }
}

bool positionExists(const std::vector<Offer> &offers, int position)
{
    for (const auto &offer : offers)
    {
        if (offer.positionProduct == position)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int numNotifications;
    std::cin >> numNotifications;

    std::vector<Offer> offers;

    for (int i = 0; i < numNotifications; ++i)
    {
        int positionProduct, action, amountProduct;
        double valueProduct;
        char comma;

        std::cin >> positionProduct >> comma >> action >> comma >> valueProduct >> comma >> amountProduct;

        // Verifica se valueProduct e amountProduct são positivos
        if (valueProduct <= 0 || amountProduct <= 0)
        {
            continue; // Ignora a entrada inválida
        }

        if (action == 0)
        { // INSERT
            if (!positionExists(offers, positionProduct))
            {
                offers.push_back({positionProduct, valueProduct, amountProduct});
            }
        }
        else if (action == 1)
        { // MODIFY
            for (auto &offer : offers)
            {
                if (offer.positionProduct == positionProduct)
                {
                    offer.valueProduct = valueProduct;
                    offer.amountProduct = amountProduct;
                    break;
                }
            }
        }
        else if (action == 2)
        { // DELETE
            for (auto it = offers.begin(); it != offers.end(); ++it)
            {
                if (it->positionProduct == positionProduct)
                {
                    offers.erase(it);
                    break;
                }
            }
        }
    }

    printOffers(offers);

    return 0;
}
