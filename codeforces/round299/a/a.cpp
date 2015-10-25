#include <iostream>
#include <cstdio>

using namespace std;

void decimal(int d) {
    switch (d) {
        case 1:
            printf("-one");
            break;
        case 2:
            printf("-two");
            break;
        case 3:
            printf("-three");
            break;
        case 4:
            printf("-four");
            break;
        case 5:
            printf("-five");
            break;
        case 6:
            printf("-six");
            break;
        case 7:
            printf("-seven");
            break;
        case 8:
            printf("-eight");
            break;
        case 9:
            printf("-nine");
            break;
    }
}

void print(int c, int d) {
    switch (c) {
        case 0:
            switch (d) {
                case 0:
                    printf("zero");
                    break;
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
            }
            break;
        case 1:
            switch (d) {
                case 0:
                    printf("ten");
                    break;
                case 1:
                    printf("eleven");
                    break;
                case 2:
                    printf("twelve");
                    break;
                case 3:
                    printf("thirteen");
                    break;
                case 4:
                    printf("fourteen");
                    break;
                case 5:
                    printf("fifteen");
                    break;
                case 6:
                    printf("sixteen");
                    break;
                case 7:
                    printf("seventeen");
                    break;
                case 8:
                    printf("eighteen");
                    break;
                case 9:
                    printf("nineteen");
                    break;
            }
            break;
        case 2:
            printf("twenty");
            decimal(d);
            break;
        case 3:
            printf("thirty");
            decimal(d);
            break;
        case 4:
            printf("forty");
            decimal(d);
            break;
        case 5:
            printf("fifty");
            decimal(d);
            break;
        case 6:
            printf("sixty");
            decimal(d);
            break;
        case 7:
            printf("seventy");
            decimal(d);
            break;
        case 8:
            printf("eighty");
            decimal(d);
            break;
        case 9:
            printf("ninety");
            decimal(d);
            break;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int c, d;

    c = n / 10;
    d = n % 10;

    print(c, d);

    return 0;
}
