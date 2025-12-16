#include <iostream>

using std::cout;
using std::cin;

int main(){
    const int N=5;
    int dif=-1;
    int arr[N];
    int vault{0}, next{0},now_i{0}, steps{N+1}, rD;

    cout << "Enter Dif(+-int): ";
    cin >> dif;

    rD = dif>=0?dif:(N - abs(N-dif)%N);

    for(int i=0; i<N; ++i) arr[i]=i+1;
    for(int i=0; i<N; ++i) cout << arr[i] << " ";

    cout << "\nSize: " << N << "\t Move for: " << dif << "\n";

    vault = arr[0]; // Костыль.

    if (rD != N && rD != 0)
    while(steps-- > 0){
        next = arr[now_i]; // что-бы не потерять.
        arr[now_i] = vault;
        vault = next;
        now_i = (now_i + rD) % N;
        cout << arr[now_i]  << "<-->" << vault << "\n";
    }

    for(int i=0; i<N; ++i) cout << arr[i] << " ";
    cout << "\n";
    
    system("pause");

}