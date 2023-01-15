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
            }
            h1{
                font-size: 2em;   
            }
        </style>
    </head>
    <body>
        <h1>Botão no browser</h1>
        <p id = "pressionado">Pressionado: </p>

        <script>
            refresh();
            setInterval(refresh, 100);
            function refresh(){
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.onreadystatechange = function(){
                    if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
                        var res = document.getElementById("pressionado");
                        res.innerHTML = "Pressionado " + JSON.parse(xmlhttp.responseText).pressionado;
                    }
                }
                xmlhttp.open('GET', 'http://10.0.0.125/pressionado', true);
                xmlhttp.send();
            }

        </script>
    </body>
    </html>
)=====";
