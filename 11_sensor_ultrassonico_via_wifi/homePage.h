const char homePage[] =
R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ultrassonico</title>
    <style>
        body{
            background-color: rgb(43, 42, 42);
            font-family: Arial, Helvetica, sans-serif;
            text-align: center;
            color: white;
        }
        h1{
            text-shadow: -2px -2px 2px 3px;
        }

    </style>
</head>
<body>
    <h1>Utilizando sensor ultrassônico</h1>
    <p id="distancia">Distância: </p>

    <script>
        atualiza();
        setInterval(atualiza, 100);
        function atualiza(){
            var req = new XMLHttpRequest();
            req.onreadystatechange = function(){
                if (req.readyState == 4 && req.status == 200){
                    var paragrafo = document.getElementById("distancia");
                    paragrafo.innerText = "Distância: "+ (JSON.parse(req.responseText).distancia) + 'cm'; 
                }

            }
            req.open('GET', 'http://10.0.0.125/distancia', true);
            req.send();
        }
        
    </script>
</body>
</html>
)=====";
