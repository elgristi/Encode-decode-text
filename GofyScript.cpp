#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main(){

    std::string Metodo;
    std::string Palabra;

    std::cout << "Dime una palabra: ";
    // IMPORTANTE: Usamos getline porque cin >> Palabra corta en el primer espacio
    std::getline(std::cin, Palabra);
    
    std::cout << "Metodo (!Decode = Decodificar, otro = Codificar): ";
    std::cin >> Metodo;

    if(Metodo == "!Decode")
    {   
        std::string PalabraFinal = "";
        std::string NumActual = "";

        for(int i = 0; i < Palabra.size(); i++)
        {
            if(Palabra[i] == '$')
            {
                if(!NumActual.empty()) {
                    int NumeroActualInt = std::stoi(NumActual);
                    // Usamos round para evitar errores de precisión decimal con sqrt
                    char Letra = static_cast<char>(std::round(std::sqrt(NumeroActualInt)));
                    PalabraFinal += Letra;     
                    NumActual = "";           
                }
            }
            else if(Palabra[i] == '#') { // Detectamos tu marcador de espacio
                PalabraFinal += " ";
            }
            else if(isdigit(Palabra[i])) { // Solo acumulamos si es un número
                NumActual += Palabra[i];
            }
        }
        std::cout << "Decodificado: " << PalabraFinal << "\n";
    }
    else {
        for(char Char : Palabra) {
            if(Char == ' ') { // Si es espacio, ponemos #
                std::cout << "#";
            }
            else {
                int CharASCII = static_cast<int>(Char);
                std::cout << CharASCII * CharASCII << "$";
            }           
        }
        std::cout << "\n";
    }

    return 0;
}