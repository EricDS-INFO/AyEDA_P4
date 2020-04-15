#include <iostream>
#include <cstdlib>
#include <vector>
#include "../include/dni.hpp"
#include "../include/slot.hpp"
#include "../include/table.hpp"

void initialize_bench(std::vector<dni>& keys, int size);
void search_stats(table<dni> experiment, std::vector<dni>& keys, 
                  int loops, int& min, int& med ,int& max);
void insert_stats(table<dni> experiment, std::vector<dni>& keys, 
                  int loops, int& min, int& med ,int& max);


int main(void)
{
    srand(time(NULL));
    /*Hash Table*/
    int   slots = 15;
    int   blocks = 3;
    int   hasher = 1;
    int   explorer = 4;
    table<dni> experiment_h(slots,blocks,hasher,explorer);
    

    float load = 0.2;

    int loops = 20;

    /*DNI test bench*/
    int n = load*slots*blocks;
    int bench_size = 2*n;
    std::vector<dni> keys;
    initialize_bench(keys, bench_size);

    for ( int i = 0; i < n; i++ )
        experiment_h.insert(keys[i]);    

    experiment_h.write(std::cout);
    int min = 0;
    int max = 0;
    int med = 0;


    std::cout << "\n\n\n\tCeldas\tClaves\tDispersion\tExploracion\tCarga\tPruebas\n";
    std::cout << "\t" << experiment_h.size();
    std::cout << "\t" << experiment_h.slot_size();
    std::cout << "\t\t" << experiment_h.hasher();
    std::cout << "\t" << experiment_h.explorer();
    std::cout << "\t" << load;
    std::cout << "\t" << loops;
    

    dni::reset_c();
    experiment_h.search(keys[0]);
    std::cout << dni::nth_compare(); 
    min = dni::nth_compare();
    med = dni::nth_compare();
    max = dni::nth_compare();
    std::cout <<"\n\n\t\t\tMinimo\tMedio\tMaximo\n";
    std::cout << "\tBusquedas:\t" << min << "\t" <<med<< "\t" << max;
    std::cout << "\tInsercion:\t" << min << "\t" <<med<< "\t" << max;

    return 0; 
}


void initialize_bench(std::vector<dni>& keys, int size)
{
    for(int i = 0; i < size; i++)
    {
        dni next_key;
        keys.push_back(next_key);
    }
}


