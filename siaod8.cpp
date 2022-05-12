#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

void randomArr(int* &arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}
void printArr(int*& arr , int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortBubble(int*& arr, int n){
    int last=n;
    bool ok;
    do{
        last=last-1;
        ok=true;
        for(int i=0; i<last; i++){
            if(arr[i]>arr[i+1]){
                int x=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=x;
                ok=false;
            }
        }
    }while(!ok);
}

void sortCounting(int*& arr, int n){
    // Находим максимальный элемент
    int maximum = -1;
    for(int i=0;i<n;i++){
        maximum = max(arr[i], maximum);
    }
    // Создаем массив count длиной maximum+1
    int count[maximum+1];
    for (int i = 0; i <= maximum; ++i) {
        count[i] = 0;
    }

    // Заполняем массив count
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }


    for(int i=1;i<=maximum;i++){
        count[i] += count[i-1];
    }



    int sorted_arr[n];

    for(int i=0;i<n;i++){
        sorted_arr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }


    for (int i = 0; i < n; ++i) {
        arr[i] = sorted_arr[i];
    }
}


void sortQuicksort(int *arr, int n) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = n - 1;

    //Центральный элемент массива
    int mid = arr[n / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(arr[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        sortQuicksort(arr, j + 1);
    }
    if (i < n) {
        //"Првый кусок"
        sortQuicksort(&arr[i], n - i);
    }
}




int main() {

    int n = 15;
    int* arr = new int[n];

    randomArr(arr, n);
    printArr(arr, n);

    unsigned int start_time = clock();

    //sortBubble(arr, n);
    sortCounting(arr,n);

    //sortQuicksort(arr,n);


    cout << clock() - start_time << endl;
    printArr(arr, n);



    return 0;
}
