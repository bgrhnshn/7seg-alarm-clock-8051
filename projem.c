#include <89c51rd2.h>
#include <stdio.h>
int i=0;
unsigned int saniye,dakika,saat,a=0;
unsigned int asan,adak,asat,gs1=0,gs2=0,gd1=0,gd2=0,gsn1=0,gsn2=7,sdak;
unsigned int clock[6]=0;
int ms50,flagsn,r=0;
char gelensayi;
int gelen_saat,gelen_dak,gelen_san;
unsigned char tablo[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay()
{
   int c, d;
   
   for (c = 0; c <= 10; c++)
       for (d = 1; d <=500; d++)
       {}
}

int main()
{
	SCON = 0x50;
	TMOD=0x21;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TH1=0xFD;
	TR1=1;
	TR0=1;
	ES=1;
	EA=1;
	ET0=1;
	P2_7=0;
	
	while(1)
	{
			if(a!=0)
			{
				a=1;
				if(saat==asat)
				{
					if(dakika==adak)
					{
						if(saniye==asan)
							P2_7=1;
					}
						else if(dakika==sdak){
							P2_7=0;
						a=0;}
						else
						{}
			}
	}


		
	}
}

int asciinumber(char gelensayi)
{
		switch(gelensayi)
		{
			case '0' : return 0;
			case '1' : return 1; 
			case '2' : return 2; 
			case '3' : return 3; 
			case '4' : return 4; 
			case '5' : return 5; 
			case '6' : return 6; 
			case '7' : return 7; 
			case '8' : return 8; 
			case '9' : return 9; 
		}
}

	void seri_port() interrupt 4 
	{
		if(RI==1)
		{
			
			RI=0;
			gelensayi=SBUF;
					
					if(i==0)
					{ 
						gs1=asciinumber(gelensayi);
						i++;
					}

					else if(i==1)
					{ 
						gs2=asciinumber(gelensayi);
						i++;
					}
					
					 else if(i==2)
					{ 
						gd1=asciinumber(gelensayi);
						i++;
					}
					
					else if(i==3)
					{ 
						gd2=asciinumber(gelensayi);
						i++;
					}
					
					else if(i==4)
					{ 
						gsn1=asciinumber(gelensayi);
						i++;
					}
					
					else if(i==5)
					{ 
						gsn2=asciinumber(gelensayi);
						i++;
					}
				
				
				 if(i==6){
					 
				gelen_saat=(gs1*10)+gs2;
				gelen_dak=(gd1*10)+gd2;
				gelen_san=(gsn1*10)+gsn2;
				
				asat=gelen_saat;
				adak=gelen_dak;
					 sdak=gelen_dak+1;
				asan=gelen_san;
					i=0;
					 a=1;
				}
		}
	}
	
	
		
	void timer0() interrupt 1
	{
		
		TH0=(65536-50000)/256;
		TL0=(65536-50000)%256;	
		
		if(r==0)
		{
		P1=tablo[clock[0]];
		P2_5=0;
		delay();
		P2_5=1;
			r++;
		}
		
		else if(r==1)
		{
		P1=tablo[clock[1]];
		P2_4=0;
		delay();
		P2_4=1;
			r++;
		}
		
		else if(r==2)
		{
		P1=tablo[clock[2]];
		P2_3=0;
		delay();
		P2_3=1;
			r++;
		}
		
		else if(r==3)
		{		
		P1=tablo[clock[3]];
		P2_2=0;
		delay();
		P2_2=1;
		r++;
		}
		else if(r==4)
		{
		P1=tablo[clock[4]];
		P2_1=0;
		delay();
		P2_1=1;
		r++;
		}
		else if(r==5)
		{	
		P1=tablo[clock[5]];
		P2_0=0;
		delay();	
		P2_0=1;
		r=0;
		}
	
			
		TF0=0;
		ms50++;
		TH0=-50000;
		TL0=-50000;
		
		if(ms50==20)
		{
			flagsn=1;
			ms50=0;
		}
		
		if(flagsn==1)
		{
			flagsn=0;
			saniye++;
		}
		
			
		
		if(saniye==60)
		{
			saniye=0;
			clock[0]=0;
			clock[1]=0;
			dakika++;
		}
		else
		{
			clock[0]=saniye%10;
			clock[1]=saniye/10;
			
		}
		
		
		if(dakika==60)
		{
			dakika=0;
			clock[2]=0;
			clock[3]=0;
			saat++;
		}
		else
		{
			clock[2]=dakika%10;
			clock[3]=dakika/10;
			
		}
		
		
		if(saat==24)
		{
			saat=0;
			clock[4]=0;
			clock[5]=0;
		}
		else
		{
			clock[4]=saat%10;
			clock[5]=saat/10;
		}
	}
		
		