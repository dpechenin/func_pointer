#include <stdio.h>

typedef int (*TFuncAB) (int, int);

int Get5() {
    return 5;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int min (int a, int b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

int GetOne(int arr[], TFuncAB fn) {
    int val = arr[0];
    if (fn != NULL) {
        for (int i = 1; i < 10; ++i) {
            val = fn(val, arr[i]);
        }
    }
    return val;
}

int main() {
    int (*func)();
    func = Get5;
    printf("%d\n", func());
    
    int (*func1) (int, int);
    func1 = max;
    printf("%d\n", func1(55, 6));
    
    TFuncAB func2;
    func2 = max;
    printf("%d\n", func2(55, 6));
    
    func2 = min;
    printf("%d\n", func2(55, 6));
    
    int a[] = {12, 3, 5, 2222, 8, 55, 22, 1, 444, 777};
    printf("%d\n", GetOne(a, max));
    printf("%d\n", GetOne(a, min));
    
    TFuncAB fn[2];
    fn[0] = min;
    fn[1] = max;
    printf("%d\n", fn[0](5, 11));
    printf("%d\n", fn[1](11, 5));
    
    int (*fn1[2]) (int, int); // тоже самое
    fn1[1] = max;
    fn1[0] = min;
    return 0;
}
