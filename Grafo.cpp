#include <iostream>
#define MAX_NODI 100
#define INF 1000000000 // Rappresenta l'assenza di connessione

template <typename T>
class Grafo {
private:
    T nodi[MAX_NODI]; // Array dei nodi
    int matriceAdiacenza[MAX_NODI][MAX_NODI]; // Matrice di adiacenza
    bool esisteNodo[MAX_NODI]; // Indica se un nodo esiste
    int numeroNodi = 0; // Numero attuale di nodi

public:
    // Costruttore
    Grafo() {
        for (int i = 0; i < MAX_NODI; ++i) {
            esisteNodo[i] = false;
            for (int j = 0; j < MAX_NODI; ++j) {
                matriceAdiacenza[i][j] = INF;
            }
            matriceAdiacenza[i][i] = 0; // La distanza da un nodo a se stesso è 0
        }
    }

    // Aggiunge un nodo al grafo, in input viene inserito il valore che rappresenta quel nodo (es. nome della cittá)
    void aggiungiNodo(const T& nodo) {
        if (numeroNodi >= MAX_NODI) {
            std::cout << "Errore: numero massimo di nodi raggiunto.\n";
            return;
        }
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                std::cout << "Errore: il nodo esiste già.\n";
                return;
            }
        }
        nodi[numeroNodi] = nodo;
        esisteNodo[numeroNodi] = true;
        numeroNodi++;
    }

    // Aggiunge un arco tra due nodi dando in input i nomi dei nodi e il peso del loro arco
    void aggiungiArco(const T& sorgente, const T& destinazione, int peso) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = peso;
    }

    // Rimuove un nodo dando in input il nome del nodo
    void rimuoviNodo(const T& nodo) {
        int indice = trovaIndice(nodo);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        esisteNodo[indice] = false;
        for (int i = 0; i < MAX_NODI; ++i) {
            matriceAdiacenza[indice][i] = INF;
            matriceAdiacenza[i][indice] = INF;
        }
    }

    // Rimuove un arco tra due nodi dando in input il nome del nodo di partenza e del nodo di arrivo
    void rimuoviArco(const T& sorgente, const T& destinazione) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = INF;
    }

    // Restituisce i nodi adiacenti a un dato nodo
    void nodiAdiacenti(const T& nodo) const {
        int indice = trovaIndice(nodo);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        std::cout << "Nodi adiacenti a " << nodo << ": ";
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && matriceAdiacenza[indice][i] != INF) {
                std::cout << nodi[i] << " (peso: " << matriceAdiacenza[indice][i] << ") ";
            }
        }
        std::cout << "\n";
    }

    // Stampa la matrice di adiacenza
    void stampa() const {
        std::cout << "Matrice di Adiacenza:\n";
        for (int i = 0; i < numeroNodi; ++i) {
            if (!esisteNodo[i]) continue;

            for (int j = 0; j < numeroNodi; ++j) {
                if (!esisteNodo[j]) continue;

                if (matriceAdiacenza[i][j] == INF) {
                    std::cout << "INF ";
                } else {
                    std::cout << matriceAdiacenza[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
    }

    // Verifica se un nodo esiste
    bool verificaNodo(const T& nodo) const {
        return trovaIndice(nodo) != -1;
    }

    // Verifica se un arco esiste
    bool verificaArco(const T& sorgente, const T& destinazione) const {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            return false;
        }
        return matriceAdiacenza[indiceSorgente][indiceDestinazione] != INF;
    }
int arcoMinimo=
grafo.arcoconpesominore(5);
if(Arcominimo !=-1) {
    std::cout <<"L'arco più piccolo con il peso minore dei 5 è:"<<arcominimo<< std::endl;}
    else{
        std::cout <<"non ci sono nodi uscenti."<<std::endl;
    }
return 0;
    
private:
    // Trova l'indice di un nodo
    int trovaIndice(const T& nodo) const {
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Grafo grafo;


    grafo.aggiungiNodo("solo leveling");
    grafo.aggiungiNodo("tower of good");
    grafo.aggiungiNodo("demon slayer");
    grafo.aggiungiNodo("one piece");
    grafo.aggiungiNodo("dragon ball");


    grafo.aggiungiArco("solo leveling", "Tower of good", 200);
    grafo.aggiungiArco("demon slayer", "one piece", 354);
    grafo.aggiungiArco("dragon ball", "solo leveling", 519);
    grafo.aggiungiArco("tower of good", "one piece", 550);
    grafo.aggiungiArco("demon slayer", "solo leveling", 554);
    grafo.aggiungiArco("dragon ball", "one piece", 1139);

    
    grafo.stampaGrafo();

    
    std::cout << "Esiste nodo 'solo leveling': " << grafo.esisteNodo("solo leveling") << std::endl;

    
    std::vector<std::string> adiacenti = grafo.nodiAdiacenti("tower of good");
    std::cout << "Nodi adiacenti a 'tower of good': ";
    for (const std::string& nodo : adiacenti) {
        std::cout << nodo << " ";
    }
    std::cout << std::endl;


    std::cout << "Esiste arco tra "tower of good" e 'solo leveling': " << grafo.esisteArco("tower of good", "solo leveling") << std::endl;

    grafo.rimuoviArco("tower of good", "solo leveling");

    
    grafo.rimuoviNodo("demon slayer");

    grafo.stampaGrafo();

    return 0;
}
