#include <stdio.h>
#define kisi 120 # Sinif Mevcudu 

int main()
{
    int number1,number2,number3,number4,vize,final,vize_x=0,final_x=0,vize_final_x=0,a=0,gecti,kaldi;
    int dizi[kisi][kisi*2];
    float sinif_ortalamasi,ortalama,kisi_ortalama;
    char letter1,letter12,letter123,letter2,letter3,letter4,letter5,letter45;

    // Bir ogrenci sinavdan '0'(sıfır) alabildigi icin tum notları '-1'(eksibir) olarak tanımlıyoruz.
    // ------------------------------------
    for(int i=0; i<kisi; i++)
    {
        dizi[i][0] = -1;
        dizi[i][1] = -1;    
    }
    // ------------------------------------

    printf("\n** OGRENCI NOT VE BILGI SISTEMINE HOS GELDINIZ ** \n\n");

    // Tum ıslemleri yalnızca 1 kere yapmamak adına while dongusune alıyoruz.
    // ----------------------------------------------------------------------------------------WHİLE-------------------------------------------------------------------------------------------------------------------------------
    while (1)
    {
        // Kullanıcının yapabilecegi islemlerin listesini acıyoruz.
        // ----------MENU-------------
        printf("[1] Bilgi Girisi\n[2] Listeleme\n[3] Ortalama Hesapla\n[4] Notu girilmeyen ogrencileri listele\n[5] istatistik bilgisi\n[6] Cikis\nSeciminiz : ");
        scanf("%d",&number1);
        printf("\n");
        // ----------MENU-------------

        // Islemlerin daha sade , anlasılır ve bilgisayarı yormayacak sekilde olması adına switch/case yapısı kullanıyoruz.
        // ----------SWİTCH/CASE--------------
        switch (number1)
        {
        case 1:
            printf("[A] Herkesin vize ve final notlarini girmek icin [a] tusuna basiniz.\n[B] Istenilen kisinin vize ve final notlarini girmek icin [b] tusuna basiniz\n[M] Menu'ye donmek icin Herhangi bir tusa basiniz.\nSeciminiz : ");
            scanf(" %c", &letter1);
            printf("\n");
            
            if(letter1 == 'a' || letter1 == 'A')
            {
                printf("[V] Yalnizca vize not girisi yapmak icin [v] tusuna basiniz.\n[F] Yalnizca final not girisi icin [f] tusuna basiniz.\n[H] Vize ve Final notlarini girmek icin [h] tusuna basiniz.\nSeciminiz : ");
                scanf(" %c", &letter12);
                printf("\n");

                if (letter12 == 'h' || letter12 == 'H')
                {
                    // Dizimiz 2 boyutlu oldugu icin 2 tane for dongusu ile elemanlarimizi aliyoruz.
                    // -----------------------
                    for(int i=0; i<kisi; i++)
                    {
                        // while dongusu kullanılmasının sebebi vize ve final notlarinin 0(sıfır)'ın altında ve 100'un ustunde olamayacagı icin eger tanımsız deger girilirse sistem tekrardan not girilmesini isteyecektir.
                        // -----------------------
                        while (1)
                        {
                            printf("%d.Kisinin Vize Notunu Giriniz : ", i+1);
                            scanf("%d",&vize);
                            printf("%d.Kisinin Final Notunu Giriniz : ", i+1);
                            scanf("%d",&final);
                            printf("\n");

                            dizi[i][0] = vize;
                            dizi[i][1] = final;

                            if ( vize>100 || vize < 0 || final >100 || final <0)
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (vize<=100 && final <=100 && final >=0 && vize >=0)
                            {
                                break;
                            }
                        }
                        // -----------------------
                    }
                    // -----------------------
                }
                else if(letter12 == 'v' || letter12 == 'V')
                {
                    for(int i=0; i<kisi; i++)
                    {
                        // while dongusu kullanılmasının sebebi vize ve final notlarinin 0(sıfır)'ın altında ve 100'un ustunde olamayacagı icin eger tanımsız deger girilirse sistem tekrardan not girilmesini isteyecektir.
                        // -----------------------
                        while (1)
                        {
                            printf("%d.Kisinin Vize Notunu Giriniz : ", i+1);
                            scanf("%d",&vize);
                            printf("\n");

                            dizi[i][0] = vize;

                            if ( vize>100 || vize < 0)
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (vize<=100 && vize >=0)
                            {
                                break;
                            }
                        }
                        // -----------------------
                    }
                }
                else if(letter12 == 'f' || letter12 == 'F')
                {
                    for(int i=0; i<kisi; i++)
                    {
                        // while dongusu kullanılmasının sebebi vize ve final notlarinin 0(sıfır)'ın altında ve 100'un ustunde olamayacagı icin eger tanımsız deger girilirse sistem tekrardan not girilmesini isteyecektir.
                        // -----------------------
                        while (1)
                        {
                            printf("%d.Kisinin Final Notunu Giriniz : ", i+1);
                            scanf("%d",&final);
                            printf("\n");

                            dizi[i][1] = final;

                            if ( final>100 || final < 0)
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (final<=100 && final >=0)
                            {
                                break;
                            }
                        }
                        // -----------------------
                    }
                }
                printf("\n");
            }

            else if (letter1 == 'b' || letter1 == 'B')
            {
                while (1)
                {
                    printf("Kacinci kisinin notlarini girmek istiyorsunuz. (ornek : 1.kisi ise 1 yazmaniz yeterlidir.)\nSeciminiz : ");
                    scanf(" %d",&number2);
                    printf("\n");

                    // Kisi sayisi asildigi zaman uyari verip kullanıcıdan tekrar deger istemeliyiz.
                    // -----------------------------
                    if (number2 > kisi || number2 <=0)
                    {
                        printf("HATA! 1 ile %d arasinda sayi giriniz.TEKRAR GIRINIZ\n\n",kisi);
                    }
                    else
                    {
                        break;
                    }
                    // -----------------------------
                }

                printf("[V] Yalnizca vize not girisi yapmak icin [v] tusuna basiniz.\n[F] Yalnizca final not girisi icin [f] tusuna basiniz.\n[H] Vize ve Final notlarini girmek icin [h] tusuna basiniz.\nSeciminiz : ");
                scanf(" %c", &letter123);
                printf("\n");

                if (letter123 == 'h' || letter123 == 'H')
                {
                    for (int i=0; i<1; i++)
                    {
                        while (1)
                        {

                            printf("%d.Kisinin Vize Notunu Giriniz : ", number2);
                            scanf("%d",&vize);
                            printf("%d.Kisinin Final Notunu Giriniz : ", number2);
                            scanf("%d",&final);

                            dizi[number2-1][0] = vize;
                            dizi[number2-1][1] = final;

                            if ( vize>100 || vize < 0 || final >100 || final <0)
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (vize<=100 && final <=100 && final >=0 && vize >=0)
                            {
                                break;
                            }
                        }

                    }
                }
                else if (letter123 == 'v' || letter123 == 'V')
                {
                    for (int i=0; i<1; i++)
                    {
                        while (1)
                        {

                            printf("%d.Kisinin Vize Notunu Giriniz : ", number2);
                            scanf("%d",&vize);

                            dizi[number2-1][0] = vize;

                            if ( vize>100 || vize < 0 )
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (vize<=100 && vize >=0)
                            {
                                break;
                            }
                        }
                    }
                }
                else if (letter123 == 'f' || letter123 == 'F')
                {
                    for (int i=0; i<1; i++)
                    {
                        while (1)
                        {

                            printf("%d.Kisinin Final Notunu Giriniz : ", number2);
                            scanf("%d",&final);

                            dizi[number2-1][1] = final;

                            if ( final>100 || final < 0 )
                            {
                                printf("Gecersiz not girisi lutfen 0-100 arasinda deger giriniz\n");
                            }
                            else if (final<=100 && final >=0)
                            {
                                break;
                            }
                        }
                    }
                }
                printf("\n");
            }
            else
            {
                printf("Menu'ye donuldu\n");
                break;
            }
            break;
        
        case 2:
            printf("[A] Tum ogrencilerin vize ve final notlarini listelemek istiyorsaniz lutfen [a] tusuna basiniz.\n[B] Yalnizca belirttiginiz kisiyi listelemek istiyorsaniz [b] tusuna basiniz.\n[M] Menu'ye donmek icin Herhangi bir tusa basiniz.\nSeciminiz : ");
            scanf(" %c", &letter2);
            printf("\n");

            if (letter2 == 'a' || letter2 == 'A')
            {
                printf(" * Tum Ogrencilere Ait Vize Ve Final Not Listesi * \n\n");

                for(int k=0; k<kisi; k++)
                {
                    // Ogrenci not listesini tablo seklinde yapmak icin internetten bulmus oldugum %-10s , %-10d ifadeleri isimi kolaylastirmis oldu. s = string , d = integer veri tiplerini 10,5 ise verilecek boslukları ifade etmektedir.
                    printf("%-10s | %-5s | %-5s","Ogrenci", "Vize", "Final");
                    printf("\n");
                    printf("%-10d | %-5d | %-5d\n",k+1,dizi[k][0],dizi[k][1]); 
                }  
                printf("\n");
            }

            else if(letter2 == 'b' || letter2 == 'B')
            {
                while (1)
                {
                    printf("Hangi ogrenci notlarini listelemek istiyorsunuz. (ornek : 1.kisinin ise 1 yazmaniz yeterlidir.)\nSeciminiz : ");
                    scanf(" %d",&number3);
                    printf("\n");

                    if (number3 > kisi || number3 <=0)
                    {
                        printf("HATA! 1 ile %d arasinda sayi giriniz.TEKRAR GIRINIZ\n\n",kisi);
                    }
                    else
                    {
                        break;
                    }
                }
                printf("%-10s | %-5s | %-5s","Ogrenci", "Vize", "Final");
                printf("\n");
                printf("%-10d | %-5d | %-5d\n\n",number3,dizi[number3-1][0],dizi[number3-1][1]);
            }
            else
            {
                printf("Menu'ye donuldu\n\n");
                break;
            }
            break;

        case 3:
            printf("[A] Tum ogrencilerin ortalamasini hesaplamak istiyorsaniz [a] tusuna basiniz.\n[B] Istenilen ogrencinin ortalamasini hesaplamak istiyorsaniz [b] tusuna basiniz.\n[M] Menu'ye donmek icin Herhangi bir tusa basiniz.\nSeciminiz : ");
            scanf(" %c", &letter3);
            printf("\n");

            if (letter3 == 'a' || letter3 == 'A')
            {
                ortalama = 0.0;
                int a = 0;
                for(int i=0; i<kisi; i++)
                {
                    if (dizi[i][0] != -1 && dizi[i][1] != -1)
                    {
                        ortalama += dizi[i][0]*0.4 + dizi[i][1]*0.6;
                        a = a + 1;
                    }
                }
                if (a > 0)
                {
                    sinif_ortalamasi = ortalama / a;

                    printf(" * Sinif ortalamasi * : %.2f\n\n",sinif_ortalamasi);
                }
                else
                {
                    printf("Ogrenci notlari girilmemis!\n");
                }
            }

            if(letter3 == 'b' || letter3 == 'B')
            {
                while (1)
                {
                    printf("Hangi ogrenci not ortalamasini listelemek istiyorsunuz. (ornek : 1.kisinin ise 1 yazmaniz yeterlidir.)\nSeciminiz : ");
                    scanf(" %d", &number4);
                    printf("\n");

                    if (number4 > kisi || number4 <=0)
                    {
                        printf("HATA! 1 ile %d arasinda sayi giriniz.TEKRAR GIRINIZ\n\n",kisi);
                    }
                    else
                    {
                        break;
                    }
                }

                if (dizi[number4-1][0] == -1 && dizi[number4-1][1] == -1)
                {
                    printf("Ogrenci vize ve final sinavlarina girmedigi icin not ortalamasi hesaplanamiyor!\n\n");
                } 
                else if(dizi[number4-1][0] == -1)
                {
                    printf("%d.kisinin vize notu girilmemis veya ogrenci sinava girmedi.Ortalamayi dogru sekilde yapabilmek icin vize notunu 0'a esitliyoruz.\n", number4);
                    dizi[number4-1][0] = 0;
            
                }
                else if(dizi[number4-1][1] == -1)
                {
                    printf("%d.kisinin final notu girilmemis veya ogrenci sinava girmedi.Ortalamayi dogru sekilde yapabilmek icin final notunu 0'a esitliyoruz.\n", number4);
                    dizi[number4-1][1] = 0;
                }
                if (dizi[number4-1][0] > -1 && dizi[number4-1][1] > -1)
                {
                    kisi_ortalama = dizi[number4-1][0]*0.4 + dizi[number4-1][1]*0.6;
                    printf("%d.ogrencinin ortalamasi : %.2f\n\n",number4,kisi_ortalama);
                }
            }

            else
            {
                printf("Menu'ye donuldu\n");
                break;
            }
            break;
        
        case 4:
        
            printf(" * Notu Girilmeyen Ogrenciler * \n\n");

            int e_not = 0;

            for (int i=0; i<kisi; i++)
            {   
                if(dizi[i][0] == -1 || dizi[i][1] == -1)
                {
                    e_not = 1;
                    break;
                }
            }

            if (e_not == 0)
            {
                printf("Tum ogrencilerin notlari girilmistir.\n\n");
            }

            else
            {
                printf("Notu girilmeyen ogrenciler var.\n[L] Listelemek icin [l] tusuna basiniz.\n[M] Menu'ye donmek icin herhangi bir tusa basiniz.\nSeciminiz : ");
                scanf(" %c",&letter45);
                printf("\n");

                if (letter45 == 'l' || letter45 == 'L')
                {
                    for (int i=0; i<kisi; i++)
                    {
                        if(dizi[i][0] == -1 && dizi[i][1] == -1)
                        {
                            printf("%-10s | %-5s | %-5s","Ogrenci", "Vize", "Final");
                            printf("\n");
                            printf("%-10d | %-5d | %-5d\n",i+1,dizi[i][0],dizi[i][1]);
                        }
                    }
                }

                else
                {
                    printf("Menu'ye Donuldu\n\n");
                    break;
                }
            }
            printf("\n");
            break;

        case 5:
            printf("[A] Sinif ortalamasi icin [a] tusuna basiniz.\n[B] Sinava giren kisi sayisi icin [b] tusuna basiniz.\n[C] Sinava girmeyen kisi sayisi icin [c] tusuna basiniz.\n[D] Tum ogrencilerin (vize+final) notlarini gormek icin [d] tusuna basiniz.\n[E] (a)(b)(c)(d) Oncullerin tumunu listelemek icin [e] tusuna basiniz.\n[F] Tum bilgileri gostermek icin [F] tusuna basiniz\n[M] Menu'ye donmek icin Herhangi bir tusa basiniz.\nSeciminiz : ");
            scanf(" %c", &letter5);
            printf("\n");

            if (letter5 == 'a' || letter5 == 'A')
            {
                if(sinif_ortalamasi > 0.00 + 1e-6)
                {
                    printf(" * Tum sinif ortalamasi * : %.2f\n\n",sinif_ortalamasi);
                }

                else
                {
                    ortalama = 0.0;
                    int a = 0;
                    for(int i=0; i<kisi; i++)
                    {
                        if (dizi[i][0] != -1 && dizi[i][1] != -1)
                        {
                            ortalama += dizi[i][0]*0.4 + dizi[i][1]*0.6;
                            a = a + 1;
                        }
                    }
                    if (a > 0)
                    {
                        sinif_ortalamasi = ortalama / a;

                        printf(" * Sinif ortalamasi * : %.2f\n\n",sinif_ortalamasi);
                    }
                    else
                    {
                        printf("Ogrenci notlari girilmemis!\n");
                    }
                }
            }

            else if (letter5 == 'b' || letter5 == 'B')
            {
                for (int i=0; i<kisi; i++)
                {
                    if (dizi[i][0] == -1)
                    {
                        printf("%d.ogrencinin vize notu girilmemis\n",i+1);
                        vize_x = vize_x + 1;
                        
                    }
                    if(dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin final notu girilmemis\n",i+1);  
                        final_x = final_x + 1;
                    }
                    if(dizi[i][0] == -1 && dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin vize ve final notu girilmemis\n",i+1); 
                        vize_final_x = vize_final_x + 1;
                    }
                }

                printf(" * Hem vize hem de final sinavina giren ogrenci sayisi * : %d\n", kisi - (vize_final_x));
                printf(" * Sadece vize sinavina giren ogrenci sayisi * : %d\n", kisi-vize_x);
                printf(" * Sadece final sinavina giren ogrenci sayisi * : %d\n\n", kisi-final_x);    
            }

            else if (letter5 == 'c' || letter5 == 'C')
            {
                for (int i=0; i<kisi; i++)
                {
                    if (dizi[i][0] == -1)
                    {
                        printf("%d.ogrencinin vize notu girilmemis\n",i+1);
                        vize_x = vize_x + 1;
                        
                    }
                    if(dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin final notu girilmemis\n",i+1);  
                        final_x = final_x + 1;
                    }
                    if(dizi[i][0] == -1 && dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin vize ve final notu girilmemis\n",i+1); 
                        vize_final_x = vize_final_x + 1;
                    }
                }

                printf(" * Hem vize hem de final sinavina girmeyen ogrenci sayisi * : %d\n", vize_final_x);
                printf(" * Sadece vize sinavina girmeyen ogrenci sayisi * : %d\n", vize_x);
                printf(" * Sadece final sinavina girmeyen ogrenci sayisi * : %d\n\n", final_x);
            }

            else if(letter5 == 'd' || letter5 == 'D')
            {
                for(int i=0; i<kisi; i++)
                {
                    kisi_ortalama = (dizi[i][0]*0.4) + (dizi[i][1]*0.6);
                    printf("%d.Ogrencinin (vize+final) notu : %.2f\n\n",i+1,kisi_ortalama);
                }
            }

            else if(letter5 == 'e' || letter5 == 'E')
            {
                for (int i=0; i<kisi; i++)
                {
                    if (dizi[i][0] == -1)
                    {
                        printf("%d.ogrencinin vize notu girilmemis\n",i+1);
                        vize_x = vize_x + 1;
                        
                    }
                    if(dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin final notu girilmemis\n",i+1);  
                        final_x = final_x + 1;
                    }
                    if(dizi[i][0] == -1 && dizi[i][1] == -1)
                    {
                        printf("%d.ogrencinin vize ve final notu girilmemis\n",i+1); 
                        vize_final_x = vize_final_x + 1;
                    }
                }
                if (sinif_ortalamasi >! 0.00 + 1e-6)
                {
                    ortalama = 0.0;
                    int a = 0;
                    for(int i=0; i<kisi; i++)
                    {
                        if (dizi[i][0] != -1 && dizi[i][1] != -1)
                        {
                            ortalama += dizi[i][0]*0.4 + dizi[i][1]*0.6;
                            a = a + 1;
                        }
                    }
                    if (a > 0)
                    {
                        sinif_ortalamasi = ortalama / a;
                    }
                    else
                    {
                        printf("Ogrenci notlari girilmemis!\n");
                    }
                }
                
                printf(" * Sinif ortalamasi * : %.2f\n",sinif_ortalamasi);
                printf(" * Sinava giren ogrenci sayisi * : %d\n", kisi - (vize_final_x));
                printf(" * Sinava girmeyen ogrenci sayisi * : %d\n\n", vize_final_x);

                printf(" * Vize sinavina giren ogrenci sayisi  * : %d\n",kisi-vize_x);
                printf(" * Final sinavina giren ogrenci sayisi * : %d\n",kisi-final_x);
                printf(" * Vize sinavina girmeyen ogrenci sayisi * : %d\n", vize_x);
                printf(" * Final sinavina girmeyen ogrenci sayisi * : %d\n\n", final_x);
            }

            else if (letter5 == 'f' || letter5 == 'F')
            {
                // Ard arda if kullanmamın sebebi vize ve final sinavina girmeyen ogrenci oldugu zaman ilk basta if ifadesi ile vize girmeyen oldugu icin digerlerine bakmadan cıkıyor ama hepsi if olursa hepsini kontrol edip gecmek zorunda.
                // ------------------------------------------------
                for (int i=0; i<kisi; i++)
                {
                    if (dizi[i][0] == -1)
                    {
                        vize_x = vize_x + 1;
                        
                    }
                    if(dizi[i][1] == -1)
                    {
                        final_x = final_x + 1;
                    }
                    if(dizi[i][0] == -1 && dizi[i][1] == -1)
                    {
                        vize_final_x = vize_final_x + 1;
                    }
                }
                // ------------------------------------------------

                // Sınıf ortalamasını eger ortalama hesaplama bolumunde hesaplanmaz ise burada tekrardan hesaplıyoruz.
                // -------------------------------------------
                if (sinif_ortalamasi >! 0.00 + 1e-6)
                {
                    ortalama = 0.0;
                    int a = 0;
                    for(int i=0; i<kisi; i++)
                    {
                        if (dizi[i][0] != -1 && dizi[i][1] != -1)
                        {
                            ortalama += dizi[i][0]*0.4 + dizi[i][1]*0.6;
                            a = a + 1;
                        }
                    }
                    if (a > 0)
                    {
                        sinif_ortalamasi = ortalama / a;

                        printf(" * Sinif ortalamasi * : %.2f\n\n",sinif_ortalamasi);
                    }
                    else
                    {
                        printf("Ogrenci notlari girilmemis!\n");
                    }
                }
                // -------------------------------------------

                kisi_ortalama = 0.0;
                for(int k=0; k<kisi; k++)
                {
                    kisi_ortalama = dizi[k][0]*0.4 + dizi[k][1]*0.6;

                    if (dizi[k][1] < 35 || kisi_ortalama < sinif_ortalamasi)
                    {
                        gecti = 0;
                        kaldi = 1;

                    }
                    else
                    {
                        kaldi = 0;
                        gecti = 1;
                    }

                    // Tum islemlerin ardindan her seyi kapsayan bir menu yapmak istedim bu sayede daha kolay anlasilabilir.
                    // -----------------------------------------------------------------
                    printf("%-15s | %-10s | %-10s | %-15s | %-15s | %-10s | %-10s | %-20s | %-20s | %-25s | %-25s | %-30s | %-30s","Ogrenci", "Vize", "Final","Ogrenci_Ortalama","Sinif_Ortalama","Gecti","Kaldi","Vize Sinavina Giren","Final sinavina Giren","Vize Sinavina Girmeyen","Final sinavina Girmeyen","Vize Final Giren","Vize Final Girmeyen");
                    printf("\n");
                    printf("%-15d | %-10d | %-10d | %-15.2f | %-15.2f | %-10d | %-10d | %-20d | %-20d | %-25d | %-25d | %-30d | %-30d\n",k+1,dizi[k][0],dizi[k][1],kisi_ortalama,sinif_ortalamasi,gecti,kaldi,kisi-vize_x,kisi-final_x,vize_x,final_x,kisi-(vize_final_x),vize_final_x);
                    // -----------------------------------------------------------------
                }
            }

            else
            {
                printf("Menu'ye donuldu\n");
                break;
            }
            break;

        case 6:
            printf("Cikis Yapildi\n");
            return 0;
        
        default:
            printf("HATA! Gecersiz Deger Lutfen Menude Belirtilen Degerleri Yaziniz!\n\n");
            break;
        }
        // ----------SWİTCH/CASE--------------
    }
    // ----------------------------------------------------------------------------------------WHİLE-------------------------------------------------------------------------------------------------------------------------------
}