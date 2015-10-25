#include <bits/stdc++.h>

using namespace std;

char kb[100];
char s[100];

float prob(float num, int den, int i) { if(i==0) return num; return prob(num/den, den, i-1);}

int main() {
    int T;
    scanf("%d", &T);

    for(int t=1;t<=T;t++) {
        int K, L, S; char temp;
        scanf("%d %d %d", &K, &L, &S);
        for(int i=0; i<25; i++) kb[i]=0;
        for(int i=0; i<K; i++) {scanf(" %c", &temp); kb[temp-'A']++;}
        for(int i=0; i<L; i++) {scanf(" %c", &s[i]);}

        bool match = false;
        int pos = L;
        for(int i=1; i<L; i++) if (!match)
            for(int j=0; j<L-i; j++) {{if (s[i+j]!=s[j]) break;} if (j==L-1) {match=true; pos=i;}}
        int n = (S-L)/pos+1;
        float num = 1; for(int i=0;i<L;i++) {num*=kb[s[i]-'A']/float(K); if (kb[s[i]-'A']==0) n=0;}
        float ans = 0;
        for (int i =1; i<=n; i++) ans += pow(num, i);

        printf("Case #%d: %1.7f\n", t, n*(1-num));


    }
    return 0;
}
