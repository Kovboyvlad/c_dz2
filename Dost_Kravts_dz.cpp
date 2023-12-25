#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <stdlib.h>

int* menyaem(int* arrays)
{
    for (int b = 0;b<11;b = b+2) {
        int c = arrays[b];
        arrays[b] = arrays[b+1];
        arrays[b+1] = c;
    }
    return arrays;
}
void vivod(int* arrays)
{
    for (int i = 0; i<12;i++){
        std::cout << arrays[i] << " ";
    }
    std::cout << std::endl;
    
}
void zapolnitel(int** array2, int stolb, int strok){
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = 0; i<strok; i++){
        for (int j = 0; j<stolb; j++){
            array2[i][j] = std::rand() % 41 + 10;
        }
    }
} 
void vivod2(int** array2, int stolb, int strok)
{
    for (int i = 0; i<strok; i++){
        for (int j = 0; j<stolb; j++){
            std::cout << array2[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
}
double plus(double a, double b) {  /*nomer5*/
    return a + b;
}

double minus(double a, double b) { /*nomer5*/
    return a - b;
}

double multiply(double a, double b) { /*nomer5*/
    return a * b;
}

double delenie(double a, double b) { /*nomer5*/
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "STOP!!!!!!!! WHYYYY???" << std::endl;
        return 0;
    }
}
int main()
{
    // 3. Объявите указатель на массив типа int и выделите память память для 12-ти элементов. Необходимо написать функцию, которая поменяет значения четных и нечетных ячеек массива. 
    std::cout << "3 nomer" << std::endl;
    int* arrays = new int[12];
    for (int i = 0; i<12; i++) {
        arrays[i] = i+1;
    }
    vivod (arrays);
    menyaem(arrays);
    vivod (arrays);
    std::cout << std::endl;
    delete[] arrays;
    
    
    // 4. Объявить и заполнить двумерный динамический массив случайными числами от 10 до 50
    std::cout << "4 nomer" << std::endl;
    int strok,stolb;
    std::cout << "Vvedite stroki = ";
    std::cin >> strok;
    std::cout << "Vvedite stolbtsy = ";
    std::cin >> stolb;
    int **array2 = new int*[strok];
    for (int i = 0; i < strok; i++){
        array2[i] = new int[stolb];
    }
    zapolnitel(array2, stolb, strok);
    vivod2(array2, stolb, strok);
    delete[] array2;
    
    // 5. 
    std::cout << "5 nomer" << std::endl;
    double (*Operatsii)(double, double);
    double n1, n2;
    char symbol;
    while (true)
    {
        std::cout << "Vvedite chisla 1 potom simvol operatsii (+, -, *, /) potom 2 chislo" << std::endl;
        std::cin >> n1;
        std::cin >> symbol;
        std::cin >> n2;
        switch (symbol) {
        case ' ':
            break;
        case '+':
            Operatsii = plus;
            break;
        case '-':
            Operatsii = minus;
            break;
        case '*':
            Operatsii = multiply;
            break;
        case '/':
            Operatsii = delenie;
            break;
        default:
            std::cout << "Oshibka! neverniy simvol ili vveden probel" << std::endl;
            return 1;
        }
    double otvet = Operatsii(n1,n2);
    std::cout << otvet << std::endl;
    }
    
    return 0;
}
