function odswiez_czas()
		{
			var dzisiaj = new Date();
			
			var sekunda = dzisiaj.getSeconds();
			if(sekunda<10) sekunda="0"+sekunda;
			var minuta = dzisiaj.getMinutes();
			if(minuta<10) minuta="0"+minuta;
			var godzina = dzisiaj.getHours();
			if(godzina<10) godzina="0"+godzina;
			
			var dzien = dzisiaj.getDate();
			if(dzien<10) dzien="0"+dzien;
			var miesiac = dzisiaj.getMonth()+1;
			if(miesiac<10) miesiac="0"+miesiac;
			
			var rok = dzisiaj.getFullYear();
			document.getElementById("clock").innerHTML = dzien+"-"+miesiac+"-"+rok+"<br> "+godzina+":"+minuta+":"+sekunda;
			setTimeout("odswiez_czas()",1000);
		}