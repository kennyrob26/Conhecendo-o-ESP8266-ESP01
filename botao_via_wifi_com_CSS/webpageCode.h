const char webpageCode[] =
R"=====(
<!DOCTYPE html>
    <html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Botão por Wifi</title>
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
        <p>Botão 1: <button id = "pressionado">Not found</button></p>

        <script>
            refresh();
            setInterval(refresh, 100);
            function refresh(){
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.onreadystatechange = function(){
                    if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
                        var res = document.getElementById("pressionado");
                        if((JSON.parse(xmlhttp.responseText).pressionado) == 1){
                            res.style.background = "green";
                            res.style.color = "white"
                            res.innerText = "ON";
                        }else if((JSON.parse(xmlhttp.responseText).pressionado) == 0){
                            res.style.background = "red";
                            res.style.color = "white"
                            res.innerText = "OFF";
                        }
                        //res.innerHTML = "Pressionado " + JSON.parse(xmlhttp.responseText).pressionado;
                    }
                }
                xmlhttp.open('GET', 'http://10.0.0.125/pressionado', true);
                xmlhttp.send();
            }

        </script>
    </body>
    </html>
)=====";
