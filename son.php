

<!DOCTYPE html>
<html>
    
    <body>
     
        
        <div  style="text-align:center;margin-top:75px;">
         
            <button  style="background-color: green;width: 100px;height: 50px;" id="ledAc" onclick='uygula("ac")'>Ac</button> 
            
            <button style="background-color: red;width: 100px;height: 50px;"  id="ledKapat"  onclick='uygula("kapat")' disabled="true">Kapat</button> 
        </div>      
 
    <h2  id="ledDurum" style="text-align:center;color: red;">KAPALI</h2>
  
    
	<script>
     
    function aL(aU)
    {
       
        var aR =new XMLHttpRequest();
        aR.onreadystatechange=function(){
            if(this.readyState==4 && this.status==200)
            {
             
              if(aU=="LEDON")
              {
              document.getElementById('ledAc').disabled=true;
              setTimeout(git, 1000, 'ledKapat');
              }
              else
              {
              
              document.getElementById('ledKapat').disabled=true;
              setTimeout(git, 1000, 'ledAc');
              }
            }
        };
    aR.open("GET","yazi.txt",true);
    aR.send();
    }

    function uygula(durum)
    {
     
        
      if(durum=='ac')
      {
       aL('LEDON');
      
      }
       else
       aL('LEDOFF');
       
    }

    function git(kimlik) 
    {
        if(kimlik=='ledKapat')
        {
              var deger=document.getElementById('ledDurum');
              deger.style.color="green";
              deger.innerHTML="ACIK";

        }
        else
        {
              var deger=document.getElementById('ledDurum');
              deger.style.color="red";
              deger.innerHTML="KAPALI";
        }
         
        document.getElementById(kimlik).disabled=false;
    }


    /*
    @media(max-width:768px)
    {
      .class1
      {
          özellik
      }

    }

    */
   </script>
   </body>
   </html>