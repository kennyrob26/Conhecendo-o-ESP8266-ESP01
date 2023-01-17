const char homePage[] =
R"=====(
<!DOCTYPE html>
    <html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Controlando Led</title>
        <style>
            body{
                font-family: Arial, Helvetica, sans-serif;
                text-align: center;
                background-color: rgb(56, 56, 56);
            }
            h1{
                font-size: 2em;
                color: white;  
                text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.308) ; 
            }
            p{
                color: white;
            }
            button{
                font-weight: bold;
                border-radius: 2px;
                padding: 4px;
                box-shadow: 2px 2px 4px rgba(0, 0, 0, 0.39);
                
            }
        </style>
    </head>
    <body>
        <h1>Botão no browser</h1>
        <p><button id="acender" onclick="acender()" >NotFound</button></p>

        <script>
            var contador = 0;
            
            function acender(){
              
                var xmlhttp = new XMLHttpRequest();
                var estilo = document.getElementById("acender");

                //A condição a abaixo apenas alterna o estado do led
                //Se ele estive em nivel alto vai para nivel baixo
                //E se estiver em nível baixo vai para nivel alto
                //Além de muda o estilo do botão a cada troca de estado
                
                if(contador == 0)
                {
                    //Troca estado do led
                    xmlhttp.open('GET', 'http://10.0.0.125/acender', true);
                    
                    //Estilo do botão
                    estilo.innerText = "ON";
                    estilo.style.background = "green";
                    contador = 1;
                }
                else if(contador == 1)
                {
                    xmlhttp.open('GET', 'http://10.0.0.125/apagar', true);
                    estilo.innerText = "OFF";
                    estilo.style.background = "red";
                    contador = 0;
                    
                }
                xmlhttp.send();  
                
            }

        </script>
    </body>
    </html>
)=====";
