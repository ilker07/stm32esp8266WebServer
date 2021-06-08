
#include "stm32f4xx.h" 
#include "rcc.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "veri.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



//char html[]="<!DOCTYPE html><html><head><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1.0'><link href='https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6' crossorigin='anonymous'></head><body><style>.bgroup{padding-left:150px;}#ledDurum{margin-top:25px;}</style><form><h2  style='color:black' class='text-center'>LED AÇ KAPAT</h2><div style='text-align:center;margin-top:75px;'><button type='button' id='ledAc' onclick='uygula('ac')' class='btn btn-success' style='width:100px;height:50px'>Aç</button><button type='button' id='ledKapat' onclick='uygula('kapat')' class='btn btn-danger' style='width:100px;height:50px;margin-left:50px;' disabled='true'>Kapat</button></div><h2 id='ledDurum' style='color:red' class='text-center'>KAPALI</h2></form><script>function aL(aU){var aR =new XMLHttpRequest();var deger='yazi';aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;setTimeout(git,1000,'ledKapat');}else{document.getElementById('ledKapat').disabled=true;setTimeout(git,1000,'ledAc');}}};aR.open('GET',aU,true);aR.send();}function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}function git(kimlik){if(kimlik=='ledKapat'){var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='AÇIK';}else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}</script></body></html>";

	 
char html2[1300]="<!DOCTYPE html><html><body>\
<div  style='text-align:center;margin-top:75px;'>\
<button  style='background-color: green;width: 100px;height: 50px;' id='ledAc' onclick='uygula(\"ac\")'>Ac</button>\
<button style='background-color: red;width: 100px;height: 50px;'  id='ledKapat'  onclick='uygula(\"kapat\")' disabled='true'>Kapat</button>\
</div>\
<h2 id='ledDurum' style='text-align:center;color:red;'>KAPALI</h2>\
<script>\
function aL(aU){var aR =new XMLHttpRequest();aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){\
if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;git('ledKapat');}\
else{document.getElementById('ledKapat').disabled=true;git('ledAc');}}};\
aR.open('GET',aU,true);aR.send();}\
function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}\
function git(kimlik) {\
if(kimlik=='ledKapat')\
{var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='ACIK';}\
else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}\
if (performance.navigation.type == 1)\
window.location.assign('http://192.168.1.37/');\
</script></body></html>";

 
char html[]="<!DOCTYPE html><html><head>\
<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6' crossorigin='anonymous'>\
<title>ESP8266 KONTROL</title></head><body>\
<div class='alert alert-primary'>\
<form action='' method='POST' onsubmit='return dogrula()'>\
<div class='mb-3'>\
<label for='kullaniciAdi' class='form-label'>Kullanici Adi</label>\
<input type='text' class='form-control' id='kullaniciAdi' name='kullaniciAdiAlani'>\
</div>\
<p id='kullaniciAdiUyari' style='display:none;'></p>\
<div class='mb-3'>\
<label for='sifre' class='form-label'>Sifre</label>\
<input type='password' class='form-control' id='sifre' name='sifreAlani'>\
</div>\
<p id='sifreUyari' style='display:none;'></p>\
<p id='bilgi' style='display:none;'></p>\
<button type='submit' class='btn btn-primary'>Gonder</button>\
</form>\
</div>\
</div>\
<script>\
function dogrula(){\
var kullaniciKontrol,kullaniciUyarma,sifreKontrol,sifreUyarma,bilgilendirme;\
kullaniciKontrol=document.getElementById('kullaniciAdi').value;\
kullaniciUyarma=document.getElementById('kullaniciAdiUyari');\
sifreKontrol=document.getElementById('sifre').value;\
sifreUyarma=document.getElementById('sifreUyari');\
bilgilendirme=document.getElementById('bilgi');\
if(kullaniciKontrol==''){\
kullaniciUyarma.style.display='block';\
kullaniciUyarma.innerHTML='Kullanici Adi bos olamaz!';\
bilgilendirme.style.display='none';\
return false;}\
if(sifreKontrol==''){\
sifreUyarma.style.display='block';\
kullaniciUyarma.style.display='none';\
sifreUyarma.innerHTML='Sifre bos olamaz!';\
return false;}\
if(kullaniciKontrol!='ilker' || sifreKontrol!='123456'){\
kullaniciUyarma.style.display='none';\
sifreUyarma.style.display='none';\
bilgilendirme.style.display='block';\
bilgilendirme.innerHTML='Kullanici Adi veya sifre hatali!';\
return false;}}\
</script></body></html>";




uint16_t boyut=0;
bool postGeldi=0;
uint8_t id=0;
char *ptr=NULL;
#define BUFFER 1024
char acik[1500];
char kapali[1500];
bool durum=0;
volatile uint16_t msn=0;
//char ip[20]="";

void degistir(char *src,char*substring,char*degis)
{
	char*ptr=strstr(src,substring);
	if(ptr==NULL)
	{
		GPIOD->BSRR |=1<<13;
	 return;
	}
	memmove(ptr+strlen(degis),ptr+strlen(substring),strlen(ptr)-strlen(substring)+1);
	memcpy(ptr,degis,strlen(degis));
}


void bekle(uint32_t beklenen)
{

  msn=0;
	while(msn<beklenen);
}



volatile char gelenCevap[BUFFER]="";
volatile int sayac=0;
uint8_t mod=0;


void USART2_IRQHandler()   //Espden gelen veriler.
{
	
	NVIC->ICER[1] =1<<6;//Interrupt pasif

 
	if(USART2->SR & 1<<5)  //RX bayrak kontrolu.
	{
		
	 
		gelenCevap[sayac]=USART2->DR;//Veri alindi.
		sayac++;
		if(sayac>BUFFER)
			sayac=0;
		
		
	}
	
	if(USART2->SR & 1<<6) //TX bayrak kontrolu.
	{
		 
		 USART2->SR &=~(1<<6);//Bayrak temizlemek icin.
	}
	
	
	NVIC->ISER[1] =1<<6;//Interrupt aktif.
	
}



void TIM2_IRQHandler(void)
{
   	if (TIM2->SR & (1<<0))  //UIF Bayragi mi
  {
			
			msn++;
			if(msn>=65000)  
			{
				 msn=0;
			}
      TIM2->SR &=~(1<<0); //UIF temizlendi.
  }


}


int main()
	
{
  RCC_Config();//PLL ile sistem 168 Mhz.
	GPIO_Config();
	USART_Config();
	timer_Ayar();
	
	
	
	veri_yollaESP8266(" AT+CWMODE=1\r\n");
	bekle(2000);
	veri_yollaESP8266("AT+CWJAP=\"MiRDEV\",\"995A5C4F2B9E4\"\r\n");//veri_yollaESP8266("AT+CWJAP=\"ILKER\",\"ilkeraykut07\"\r\n");veri_yollaESP8266("AT+CWJAP=\"MiRDEV\",\"995A5C4F2B9E4\"\r\n")
	bekle(5000);
	veri_yollaESP8266("AT+CIPMUX=1\r\n");//1
	bekle(200);
	veri_yollaESP8266("AT+CIPSERVER=1,80\r\n");
	bekle(1000);

	NVIC->ISER[1] =1<<6;//USART2 Kesme Aktif.
	
	memset((char *)gelenCevap,0,sizeof(gelenCevap));
	sayac=0;
	GPIOD->BSRR |=1<<14;
	
	
while(1)
{
  
 

	if(mod==0) 
	{
		  ptr=strstr((char *)gelenCevap,"+IPD");
      if(ptr) //Adres çubuguna IP adresi girildignde bu cevap doner.
			{ 
				 mod++;
				 msn=0;
			}
	}
	
	 if(mod==1 && msn>=300) //Bütün cevabin gelmesi yaklasik 300 ms.
		
		{
			
		
			mod++;
			
			/*
			char* hostptr=NULL;
			hostptr=strstr((char *)gelenCevap,"Host:");
			
			
			
			ip[0]=hostptr[5];
			ip[1]=hostptr[6];
			ip[2]=hostptr[7];
			ip[3]='.';
			
			ip[4]=hostptr[9];
			ip[5]=hostptr[10];
			ip[6]=hostptr[11];
			ip[7]='.';
			
			
			ip[8]=hostptr[13];
			ip[9]='.';
			ip[10]=hostptr[15];
			
			
			//5 6  7  910 11 13 15
			*/
						
			if(strstr((char *)gelenCevap,"LEDON"))
			{
				GPIOD->BSRR |=1<<12; 
				durum=1;
			
			}
			
												 
			else if(strstr((char *)gelenCevap,"LEDOFF"))
			{
			GPIOD->BSRR |=1<<28;
      durum=0;
       
			}
					
			
			
			
			else if(strstr((char *)gelenCevap,"POST"))
			{
					postGeldi=1;
				
          				
			}
			else{
			  postGeldi=0;
				
      
 

			if(durum==1)
				 {
					 
				/*	 
				const	char html2[]="<!DOCTYPE html><html><body>\
<div  style='text-align:center;margin-top:75px;'>\
<button  style='background-color: green;width: 100px;height: 50px;' id='ledAc' onclick='uygula(\"ac\")' disabled='true'>Ac</button>\
<button style='background-color: red;width: 100px;height: 50px;'  id='ledKapat'  onclick='uygula(\"kapat\")'>Kapat</button>\
</div>\
<h2 id='ledDurum' style='text-align:center;color:green;'>ACIK</h2>\
<script>\
function aL(aU){var aR =new XMLHttpRequest();aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){\
if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;git('ledKapat');}\
else{document.getElementById('ledKapat').disabled=true;git('ledAc');}}};\
aR.open('GET',aU,true);aR.send();}\
function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}\
function git(kimlik) {\
if(kimlik=='ledKapat')\
{var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='ACIK';}\
else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}\
if (performance.navigation.type == 1)\
window.location.assign('http://192.168.1.37/');\
</script></body></html>";
				//degistir(html2,"192.100.1.12",ip);
				//strcpy(acik,html2);
				boyut=strlen(html2);//HTML2*/
				
				degistir(html2,"disabled='true'>Kapat<",">Kapat<");
				degistir(html2,">Ac<"," disabled='true'>Ac<");
				//degistir(html2,"disabled='true'>Kapat<",">Kapat<");
				degistir(html2,"color:red;'>KAPALI<","color:green;'>ACIK<");
				boyut=strlen(html2);
				 }
				
				
			if(durum==0)
				 {
					 /*
				const	 char html2[]="<!DOCTYPE html><html><body>\
<div  style='text-align:center;margin-top:75px;'>\
<button  style='background-color: green;width: 100px;height: 50px;' id='ledAc' onclick='uygula(\"ac\")'>Ac</button>\
<button style='background-color: red;width: 100px;height: 50px;'  id='ledKapat'  onclick='uygula(\"kapat\")' disabled='true'>Kapat</button>\
</div>\
<h2 id='ledDurum' style='text-align:center;color:red;'>KAPALI</h2>\
<script>\
function aL(aU){var aR =new XMLHttpRequest();aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){\
if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;git('ledKapat');}\
else{document.getElementById('ledKapat').disabled=true;git('ledAc');}}};\
aR.open('GET',aU,true);aR.send();}\
function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}\
function git(kimlik) {\
if(kimlik=='ledKapat')\
{var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='ACIK';}\
else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}\
if (performance.navigation.type == 1)\
window.location.assign('http://192.168.1.37/');\
</script></body></html>";
					//degistir(html2,"192.100.1.12",ip);
				    //strcpy(kapali,html2);
					  boyut=strlen(html2);*/
						
						
					
				degistir(html2,"disabled='true'>Ac<",">Ac<");
				degistir(html2,">Kapat<","disabled='true'>Kapat<");
				degistir(html2,"color:green;'>ACIK<","color:red;'>KAPALI<");
				boyut=strlen(html2);
            
				 }
			 } 
			id=(((int)ptr[5]-48));  //0,1,2,3,4 bunlardan biri.
			
			char cipsend []="AT+CIPSEND=";//0,length
			char stringSayi[10];
			
			
			if(postGeldi==0)
			 sprintf(stringSayi,"%d,%d\r\n",id,strlen(html));
			else if(postGeldi==1) 
			 sprintf(stringSayi,"%d,%d\r\n",id,boyut);
			
			strcpy(cipsend+strlen(cipsend),stringSayi);
		  veri_yollaESP8266(cipsend);
		
	}
		
	
	 if(mod==2)
	{
		  if(strstr((char *)gelenCevap,">")) //AT+CIPSEND e donen cevap.
			
			{
					
					mod++;
				
				
				 
				 
				  if(postGeldi==0)
					  veri_yollaESP8266(html);
					else if(postGeldi==1)
					{
						if(durum)
						{
							/*
							char html2[]="<!DOCTYPE html><html><body>\
<div  style='text-align:center;margin-top:75px;'>\
<button  style='background-color: green;width: 100px;height: 50px;' id='ledAc' onclick='uygula(\"ac\")' disabled='true'>Ac</button>\
<button style='background-color: red;width: 100px;height: 50px;'  id='ledKapat'  onclick='uygula(\"kapat\")'>Kapat</button>\
</div>\
<h2 id='ledDurum' style='text-align:center;color:green;'>ACIK</h2>\
<script>\
function aL(aU){var aR =new XMLHttpRequest();aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){\
if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;git('ledKapat');}\
else{document.getElementById('ledKapat').disabled=true;git('ledAc');}}};\
aR.open('GET',aU,true);aR.send();}\
function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}\
function git(kimlik) {\
if(kimlik=='ledKapat')\
{var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='ACIK';}\
else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}\
if (performance.navigation.type == 1)\
window.location.assign('http://192.168.1.37/');\
</script></body></html>";
							//degistir(html2,"192.100.1.7",ip);*/
						 veri_yollaESP8266(html2);//html2
						}
					 
						else
						{
							/*
							 char html2[]="<!DOCTYPE html><html><body>\
<div  style='text-align:center;margin-top:75px;'>\
<button  style='background-color: green;width: 100px;height: 50px;' id='ledAc' onclick='uygula(\"ac\")'>Ac</button>\
<button style='background-color: red;width: 100px;height: 50px;'  id='ledKapat'  onclick='uygula(\"kapat\")' disabled='true'>Kapat</button>\
</div>\
<h2 id='ledDurum' style='text-align:center;color:red;'>KAPALI</h2>\
<script>\
function aL(aU){var aR =new XMLHttpRequest();aR.onreadystatechange=function(){if(this.readyState==4 && this.status==200){\
if(aU=='LEDON'){document.getElementById('ledAc').disabled=true;git('ledKapat');}\
else{document.getElementById('ledKapat').disabled=true;git('ledAc');}}};\
aR.open('GET',aU,true);aR.send();}\
function uygula(durum){if(durum=='ac'){aL('LEDON');}else{aL('LEDOFF');}}\
function git(kimlik) {\
if(kimlik=='ledKapat')\
{var deger=document.getElementById('ledDurum');deger.style.color='green';deger.innerHTML='ACIK';}\
else{var deger=document.getElementById('ledDurum');deger.style.color='red';deger.innerHTML='KAPALI';}document.getElementById(kimlik).disabled=false;}\
if (performance.navigation.type == 1)\
window.location.assign('http://192.168.1.37/');\
</script></body></html>";
						 //degistir(html2,"192.100.1.12",ip);*/
						 veri_yollaESP8266(html2);//html2
							 //192.168.1.7
						}
							
					}
					msn=0;
			}

	 
  }
	
	 if(mod==3 && msn>=1000) //AT+CIPSEND gonderildikten sonra 1sn sonra yeni AT komutu gönderilmeli.
	{
		char kapat []="AT+CIPCLOSE=";//0,id
		char stringSayi[5];

		sprintf(stringSayi,"%d\r\n",id);
		strcpy(kapat+strlen(kapat),stringSayi);
		veri_yollaESP8266(kapat);
		
		
		veri_yollaUSBTTL((char *)gelenCevap);
		mod=0;
		msn=0;
		memset((char *)gelenCevap,0,sizeof(gelenCevap));//Array temizlendi.
		sayac=0;
	}
		

}

}




