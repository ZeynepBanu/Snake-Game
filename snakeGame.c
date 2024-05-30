#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{ 
    int randomSayix, randomSayiy;
	int x, y;
	int i, j;
	int yemekSayisi, k=0;
	int kalanYemekSayisi;
	int yilanKonumx, yilanKonumy;

	
	printf("Oyun alani boyutlarini giriniz.\n");
	scanf("%d %d", &x, &y);
	
	int A[x][y];
	
	//A'nýn hücreleri -1 olarak atanýr.
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			A[i][j]=-1;
		}
	}
	
	srand(time(NULL));
	
	
	int yemekSayisiHata=1;
	printf("Yemek sayisini giriniz.\n");
	//Yemek sayýsý oyun alanýndan daha büyük mü diye kontrol edilir.
	while (yemekSayisiHata==1)
	{
	    scanf("%d", &yemekSayisi);
	
		if(yemekSayisi<(x*y))
		   yemekSayisiHata=0;
		else
		{
		   yemekSayisiHata=1;
		   printf("Hatali yemek sayisi.Tekrar giriniz.\n");
	    }
	}
	
	kalanYemekSayisi=yemekSayisi;
	//Yemeklerin koordinatlarý randomlanarak belirlenir.
	while(k!=yemekSayisi)
	{  
	   
	   randomSayix= rand() %x;
	   randomSayiy= rand() %y;
       
	   if(A[randomSayix][randomSayiy]==-1)
	   {
	   	  A[randomSayix][randomSayiy]=0;
	      k=k+1;
	   }
	}
	
	int yilan[yemekSayisi+1][2];
	
	for(i=0;i<yemekSayisi+1;i++)
	{
		for(j=0;j<2;j++)
		{
			yilan[i][j]=-1;
		}
		
	}
	int m=0;
	
	//Yýlanýn konumu randomlanarak belirlenir.
	//Yýlanýn konumu saklanýr.
	while(m!=1)
	{
	   yilanKonumx= rand() %x;
	   yilanKonumy= rand() %y;
	   
	   if(A[yilanKonumx][yilanKonumy]==-1)
	   {
	   	  A[yilanKonumx][yilanKonumy]=1;
	      m=m+1;
	   }
	}

	yilan[0][0]=yilanKonumx;
	yilan[0][1]=yilanKonumy;
	
	printf("Yapabileceginiz hareketler u/d/l/r.\n");
	
	char hareket;
	int hareketSayisi=0;
	int carpisma=0;
	
    //Oyun tahtasýný bastýrýr.
	for(i=-1;i<x+1;i++)
	{
		for(j=-1;j<y+1;j++)
		{
			//Çerçeveyi bastýrýr.
			if(i==-1 || i==x || j==-1 || j==y)
			{
				printf("*");
			}
			//Oyun alanýný bastýrýr.
			else
			{
				if(A[i][j]==-1)
			        printf(" ");
			    else   
			        printf("%d", A[i][j]);
			}
				
		}
	printf("\n");
	}

	int yilanUzunlugu2=1;
	int yemekHucresi=0;//Yýlan yemek hücresinin içine girdiðinde bu flag set edilir.
	while(carpisma==0 && kalanYemekSayisi!=0)
	{
		yemekHucresi=0;
		printf("Hareketinizi giriniz: \n");
		scanf(" %c", &hareket);
		printf("Hareketiniz: %c\n", hareket);
		
		if(hareket=='u' || hareket=='U')
		{   
		    A[yilanKonumx][yilanKonumy]=-1;
			yilanKonumx=yilanKonumx-1;
			
			if(A[yilanKonumx][yilanKonumy]==-1)
			   A[yilanKonumx][yilanKonumy]=1;
			else
			{
				yilanUzunlugu2=yilanUzunlugu2+1;
				A[yilanKonumx][yilanKonumy]=1;
				kalanYemekSayisi=kalanYemekSayisi-1;
				yemekHucresi=1;
			}
			   
			   
			if(yilanKonumx==-1)
			{
				carpisma=1;
			}
			
			hareketSayisi=hareketSayisi+1;
		}
		
		if(hareket=='d' || hareket=='D')
		{
			A[yilanKonumx][yilanKonumy]=-1;
			yilanKonumx=yilanKonumx+1;
			
			if(A[yilanKonumx][yilanKonumy]==-1)
			   A[yilanKonumx][yilanKonumy]=1;
			else
			{
				yilanUzunlugu2=yilanUzunlugu2+1;
				A[yilanKonumx][yilanKonumy]=1;
				kalanYemekSayisi=kalanYemekSayisi-1;
				yemekHucresi=1;
			}
			
			if(yilanKonumx==x)
			{
				carpisma=1;
			}
			
			hareketSayisi=hareketSayisi+1;
		}
		if(hareket=='l' || hareket=='L')
		{
			A[yilanKonumx][yilanKonumy]=-1;
			yilanKonumy=yilanKonumy-1;
			
			if(A[yilanKonumx][yilanKonumy]==-1)//Yýlanýn geldiði bölme boþ ise
			   A[yilanKonumx][yilanKonumy]=1;
			else//Yýlanýn geldiði bölmede yemek varsa
			{
				yilanUzunlugu2=yilanUzunlugu2+1;//Yýlanýn uzunluðunu arttýrýyoruz.
				A[yilanKonumx][yilanKonumy]=1;
				kalanYemekSayisi=kalanYemekSayisi-1;
				yemekHucresi=1;
			}
			
			if(yilanKonumy==-1)
			{
				carpisma=1;
			}
			
			hareketSayisi=hareketSayisi+1;
		}
		if(hareket=='r' || hareket=='R')
		{
			A[yilanKonumx][yilanKonumy]=-1;
			yilanKonumy=yilanKonumy+1;
			
			if(A[yilanKonumx][yilanKonumy]==-1)
			   A[yilanKonumx][yilanKonumy]=1;
			else
			{
				yilanUzunlugu2=yilanUzunlugu2+1;
				A[yilanKonumx][yilanKonumy]=1;
				kalanYemekSayisi=kalanYemekSayisi-1;
				yemekHucresi=1;
			}
			
			if(yilanKonumy==y)
			{
			   carpisma=1;
		    }
		    
		    hareketSayisi=hareketSayisi+1;
		}
		
		int yilanUzunlugu;
	    yilanUzunlugu=yemekSayisi-kalanYemekSayisi+1;
		
		if(carpisma==0 || kalanYemekSayisi==0)
		{
			int AA[x][y]; //Gecici oyun alaný matrisi. A matrisi ile yilan dizisinin birlesimini icerir.
			int yyilan[yemekSayisi+1][2]; //Gecici yilan dizisi, gercek yilan dizisindeki bilgileri guncellerken kullanmak icin
			//Gecici yilan matrisinin tum hucrelerini -1 olarak atar.
			for (i = 0; i < yemekSayisi+1; i++)
			{
				for(j=0;j<2; j++)
				{
					yyilan[i][j]=-1;
				}
			}
			
			yyilan[0][0]=yilanKonumx;
			yyilan[0][1]=yilanKonumy;

            //yilan matrisinin konum bilgilerini gunceller
			for(i=1;i<yemekSayisi+1&&i<yilanUzunlugu2;i++)
			{
				for(j=0;j<2;j++)
				{
					yyilan[i][j]=yilan[i-1][j];
				}
			}
			for(i=0;i<yemekSayisi+1;i++)
			{
				for(j=0;j<2;j++)
				{
					yilan[i][j]=yyilan[i][j];
				}
			}


			//AA matrisini A matrisine eþitler
			for(i=0;i<x;i++)
			{
				for(j=0;j<y;j++)
				{
					AA[i][j] = A[i][j];
				}
			}

			//oyun alani ile yilan matrisini birleþtir
			for(i=0;i<yemekSayisi+1;i++)
			{
				if(yemekHucresi==1)
				{
					if(yilan[i][0]!=-1&&yilan[i][1]!=-1&&i<yilanUzunlugu-1)
					  AA[yyilan[i][0]][yyilan[i][1]]=(i+1)% 10;
				}
				else
				{
					if(yilan[i][0]!=-1&&yilan[i][1]!=-1)
					  AA[yyilan[i][0]][yyilan[i][1]]=(i+1)% 10;
				}
			}
			//Oyun tahtasýný bastýrýr.
			for(i=-1;i<x+1;i++)
			{
				for(j=-1;j<y+1;j++)
				{
					//Çerçeveyi bastýrýr.
					if(i==-1 || i==x || j==-1 || j==y)
					{
						printf("*");
					}
					//Oyun alanýný bastýrýr.
					else
					{
						if(AA[i][j]==-1)
					        printf(" ");
					    else   
					        printf("%d", AA[i][j]);
					}
					
				}
			printf("\n");
			}
			printf("Hamle: %d\n", hareketSayisi);
		}
		
		if(kalanYemekSayisi==0)
		{
			printf("Tebrikler. Hamle Sayisi: %d Yilan Uzunlugu: %d", hareketSayisi, yilanUzunlugu2);
		}
		
		if(carpisma==1)
		{
			printf("Kaybettiniz. Hamle: %d Yilan Uzunlugu: %d Kalan Yemek Sayisi: %d\n", hareketSayisi, yilanUzunlugu, kalanYemekSayisi);
		}
	}
	
	return 0;
}
