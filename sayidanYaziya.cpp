#include <iostream>
#include <string>
#include <list>
#include <clocale>


std::string sayidanYaziya(int sayi)
{
    std::string birler[10] = {"", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"};
    std::string onlar[10] = {"", "on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"};
    std::string yuzler[10] = {"", "yüz", "ikiyüz", "üçyüz", "dörtyüz", "beşyüz", "altıyüz", "yediyüz", "sekizyüz", "dokuzyüz"};
    std::string binler[10] = {"", "bin", "ikibin", "üçbin", "dörtbin", "beşbin", "altıbin", "yedibin", "sekizbin", "dokuzbin"};
    std::string onbinler[10] = {"", "onbin", "yirmibin", "otuzbin", "kırkbin", "ellibin", "altmışbin", "yetmişbin", "seksenbin", "doksanbin"};
    std::string yuzbinler[10] = {"", "yüzbin", "ikiyüzbin", "üçyüzbin", "dörtyüzbin", "beşyüzbin", "altıyüzbin", "yediyüzbin", "sekizyüzbin", "dokuzyüzbin"};
    std::string milyonlar[10] = {"", "birmilyon", "ikimilyon", "üçmilyon", "dörtmilyon", "beşmilyon", "altımilyon", "yedimilyon", "sekizmilyon", "dokuzmilyon"};
    
    int basamak = 0, sayi2 = sayi;
    while(sayi2>0)
    {
        sayi2/=10;
        basamak++;
    }
    int basamaklar[basamak];
    sayi2 = sayi;
    for(int i=0;i<basamak;i++)
    {
        basamaklar[i] = sayi2%10;
        sayi2/=10;
    }
    std::string ret;

    for(int i=basamak-1;i>=0;i--)
    {
        if(basamaklar[i]==0) continue;
        if(i==0) ret+=birler[basamaklar[i]];
        if(i==1) ret+=onlar[basamaklar[i]];
        if(i==2) ret+=yuzler[basamaklar[i]];
        if(i==3) ret+=binler[basamaklar[i]];
        if(i==4) ret+=onbinler[basamaklar[i]];
        if(i==5) ret+=yuzbinler[basamaklar[i]];
        if(i==6) ret+=milyonlar[basamaklar[i]];
        ret+=" ";
    }
    // for(int i=0; i<basamak;i++) ret.insert(0,std::to_string(basamaklar[i]));

    return ret;
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    std::cout<<"gimme: ";
    int sayi;
    std::cin>>sayi; 
    std::cout<<sayidanYaziya(sayi)<<std::endl;
    return 0;
}