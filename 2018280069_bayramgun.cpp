#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

char digitals_to_romans(){

   string roman;
   int number;
   std::cout << "Lutfen bir sayi giriniz:" << '\n';
   std::cout << "Lutfen 0 ile 4000 arasinda gecerli bir sayi giriniz..." << '\n';
   cin >> number;
   //sayının 0 ile 4000 arasında olup olmadığına bakıyoruz.
   if ((number > 3999) || (number <= 0)){
       std::cout << "Gecersiz sayi!" << '\n';
       std::cout << "Lutfen 0 ile 4000 arasinda gecerli bir sayi giriniz..." << '\n';
   }else {
       //Binler basamağı için M = 1000k yazdırma.
       if(number >= 1000){
           int kisimBir;
           kisimBir = (number / 1000);
               for(int i = 0; i < kisimBir; i++) roman += 'M';
       }number %= 1000; //binler ile işimiz bitti mod alıp yüzlere geçelim.

       // Yüzler basamağı için C = 100k , CD = 400, D = 500, CM = 900 yazdırma.
       if(number >= 100){

           int kisimIki;
           kisimIki = (number / 100);
           if(kisimIki == 9) roman += "CM";
           else if(kisimIki >= 5){
               roman += 'D';
               for(int i = 0 ; i < kisimIki - 5 ; i++){
               roman += 'C';
               }
           }
           else if(kisimIki == 4) roman += "CD";
           else if(kisimIki >= 1){
               for(int i = 0; i < kisimIki; i++){
               roman += 'C';
           }
           }
       }number %= 100; //yüzler ile işimiz bitti mod alıp onlara geçelim.

       //onlar basamağı için X = 10k , XL = 40, L = 50 , XC = 90 yazdırma.
       if(number >= 10){
           int kisimUc;
           kisimUc = (number / 10);
           if(kisimUc == 9) roman += "XC";
           else if(kisimUc >= 5){
               roman += 'L';
               for(int i = 0 ; i < kisimUc - 5 ; i++){
               roman += 'X';
               }
           }
           else if(kisimUc == 4) roman += "XL";
           else if(kisimUc >= 1){
               for(int i = 0; i < kisimUc; i++){
               roman += 'X';
           }
           }
       }number %= 10;//onlar ile işimiz bitti son olarak mod alıp birlere geçelim.

       //birler basamağı için I = 1k , IV = 4 , V = 5 , IX = 9 yazdırma.
       if(number >= 1){
           int kisimDort;
           kisimDort = (number / 1);
           if(kisimDort == 9) roman += "IX";
           else if(kisimDort >= 5){
               roman += 'V';
               for(int i = 0 ; i < kisimDort - 5 ; i++){
               roman += 'I';
               }
           }
           else if(kisimDort == 4) roman += "IV";
           else if(kisimDort >= 1){
               for(int i = 0; i < kisimDort; i++){
               roman += 'I';
           }
           }
       }number %= 1;

       std::cout << "Roma Rakamlari ile gosterim: " <<roman << '\n';
   }
   return 0;
}

//char değerleri int değerlere döndüren fonksiyon.

    int value(char romans){
    switch(romans){
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }return 0;
    }

    int roman_to_digit(string roman){

        int i, n, ans = 0, p = 0;
        n = roman.length()-1;
            for( i = n; i >= 0; i--){
                if( value(roman[i]) >= p)
                ans += value(roman[i]);
                else
                ans -= value(roman[i]);
                p = value(roman[i]);
            }
        return ans;

    }

 int main(){
    std::cout<< "Menu seciniz:" <<"\n" << "1.(Dijital Sayi Cevirme)" << "\n" << "2.(Roma Rakami Cevirme)" << "\n";
    int giris;
    cin >> giris;
    while (giris == 1){
        std :: cout << "Dijital Sayi Cevirme" << "\n";
        digitals_to_romans();
        if(giris == -1) break;
    }
   while(giris == 2){
        std :: cout << "Roma Rakami Cevirme" << "\n";
        cout << "Lutfen gecerli 'I' ile 'MMMCMXCIX' arasinda gecerli bir deger giriniz." << "\n";
        string s;
        int num;
        cin >> s;
        num=roman_to_digit(s);
        if(num == 0 || num >= 3999)
        cout << "Gecersiz deger!" << "\n";
        else
        cout << "Dijital sayi ile gosterim: " << num << "\n";
        if(giris == -1) break;
    }

    system("pause");
    return 0;
}
