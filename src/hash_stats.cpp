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
    int   slots = 17;
    int   blocks = 3;
    table<dni> experiment_1(slots,blocks,1,1);
    
    table<dni> experiment_2(slots,blocks,2,2);
    
    table<dni> experiment_3(slots,blocks,3,3);
    
    table<dni> experiment_4(slots,blocks,1,4);


// Modification table
    table<dni> experiment_modif(slots,blocks,4,1);
    

    float load = 0.2;

    int loops = 20;

    /*DNI test bench*/
    int n = load*slots*blocks;
    int bench_size = 2*n;
    std::vector<dni> keys;
    initialize_bench(keys, bench_size);

    for ( int i = 0; i < n; i++ )
        experiment_1.insert(keys[i]); 
        
    for ( int i = 0; i < n; i++ )
        experiment_2.insert(keys[i]); 
        
    for ( int i = 0; i < n; i++ )
        experiment_3.insert(keys[i]); 
        
    for ( int i = 0; i < n; i++ )
        experiment_4.insert(keys[i]);  
        
    for ( int i = 0; i < n; i++ )
        experiment_modif.insert(keys[i]);    


    std::cout << "\n\n\n\t\t\t\t\t\t\t\t TABLA: " << experiment_4.hasher() << " | " << experiment_4.explorer() << "\n\n";
    experiment_4.write(std::cout);

    std::cout << "\n\n\n\t\t\t\t\t\t\t\t TABLA: " << experiment_3.hasher() << " | " << experiment_3.explorer() << "\n\n";
    experiment_3.write(std::cout);
    
    std::cout << "\n\n\n\t\t\t\t\t\t\t\t TABLA: " << experiment_2.hasher() << " | " << experiment_2.explorer() << "\n\n";
    experiment_2.write(std::cout);

    std::cout << "\n\n\n\t\t\t\t\t\t\t\t TABLA: " << experiment_1.hasher() << " | " << experiment_1.explorer() << "\n\n";
    experiment_1.write(std::cout);



    std::cout << "\n\n\n\t\t\t\t\t\t\t\t TABLA MODIFICACIÓN: " << experiment_modif.hasher() << " | " << experiment_modif.explorer() << "\n\n";
    experiment_modif.write(std::cout);

    std::cout << "\n\n\n\tCeldas\tClaves\tDispersion\tExploracion\tCarga\tPruebas\n";
    std::cout << "\t" << experiment_1.size();
    std::cout << "\t" << experiment_1.slot_size();
    std::cout << "\t" << experiment_1.hasher();
    std::cout << "\t\t" << experiment_1.explorer();
    std::cout << "\t\t" << load;
    std::cout << "\t" << loops;
    

    std::cout <<"\n\n\t\t\tMinimo\tMedio\tMaximo\n";

    int min = BOUND;
    int max = 0;
    int med = 0;

    dni::reset_c();
    for (int i = 0; i < n; i++)
    {
        experiment_1.search(keys[i]);
        if (dni::nth_compare() > max)
            max = dni::nth_compare();
        if (dni::nth_compare() < min)
            min = dni::nth_compare();
        med += dni::nth_compare();
    }
    med = med/n;
    std::cout << "\tBusquedas:\t" << min << "\t" <<med<< "\t" << max;
    
    min = BOUND;
    max = 0;
    med = 0;


    dni::reset_c();    
    for (int i = n; i < bench_size; i++)
    {
        experiment_1.search(keys[i]);
        if (dni::nth_compare() > max)
            max = dni::nth_compare();
        if (dni::nth_compare() < min)
            min = dni::nth_compare();
        med += dni::nth_compare();
    }
    med = med/n;
    std::cout << "\n\tInsercion:\t" << min << "\t" <<med<< "\t" << max;

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


