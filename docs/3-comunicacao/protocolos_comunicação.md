## INTERFACE

O aplicativo possibilita controlar a iluminação do ambiente à distância, é possível também ativar o "modo automático", com isso,  a iluminação é ajustada automaticamente pela aplicação, de acordo com um índice pré programado de incidência ideal de luz. 

![Imagem Protótipo da tela](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/1-especificacacao/img_especificacao/tela_app.PNG)


## PROTOCOLOS DE COMUNICAÇÃO

### Comunicação Arduino (cliente) com Servidor 
A comunicação do Arduino com o servidor para enviar os dados do sensor de luminosidade e, receber os comandos para diminuir ou aumentar a incidência de luz, ocorre por meio do shield Ethernet W5100 que fornece acesso à rede nos protocolos TCP ou UDP.

![Imagem Ethernet Shield](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/2-hardware/img_hardware/ethernet.png)


### Comunicação App (cliente) com Servidor

A comunicação do Aplicativo com o servidor, para o envio e recebimento de mensagens, ocorre por meio do protocolo HTTP. 
