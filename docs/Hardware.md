# Especificação de Hardware Estufa Inteligente - Smart Light.

## Lista de Peças

Para esse projeto, foram utilizados os componentes descritos a seguir.

**Arduino UNO R3**

O Arduino Uno R3 é a placa Arduino mais vendida e usada atualmente. Costuma ser a primeira opção de muitos, pois apresenta uma ótima quantidade de portas disponíveis e grande compatibilidade com os Shields Arduino.

![Imagem Ardino Uno R3](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/arduinoR3.png)


**Dimmer Shield Arduino - 110 Vac E 220 Vac - 1 Canal**

O Dimmer Shield é um shield para Arduíno. É utilizado para controlar a potência de aparelhos elétricos domésticos, por exemplo, lâmpada incandescente, lâmpadas fluorescente ou LED dimerizáveis, ventilador de mesa e de teto, liquidificador, entre outros.
Compatível com o Arduino UNO R3

*Especificações técnicas* 

Corrente máxima: 8 A
Tensão Máxima de pico: 400 V
 Com dissipador incluso:
 - Potência máxima com dissipador incluso – 127 Volts: 400 Watts.  
 - Potência máxima com dissipador incluso – 220 Volts: 800 Watts.

Com dissipador externo maior:
 - Potência máxima com dissipador externo maior – 127 Volts: 1016 Watts.
 - Potência máxima com dissipador externo maior – 220 Volts: 1760 Watts.

![Imagem Dimmer Shield](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/dimmer.png)


**Ethernet Shield W5100**

O Ethernet Shield W5100 permite que uma placa Arduino conecte-se a internet. É baseado no chip ethernet da WIZnet ethernet W5100 que fornece acesso à rede (IP) nos protocolos TCP ou UDP e é facilmente utilizado usando a biblioteca Ethernet Library e SD Library. Este shield suporta até quatro conexões de socket simultâneas. É compatível com o Arduino UNO R3.

![Imagem Ethernet Shield](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/ethernet.png)

**Lâmpada**

Led Dimerizável

*Especificações técnicas*

Tensão Elétrica: 110V  
Cor da Luz: Branca  
Potência: 10W  
Tipo de Soquete: E27  
Formato: Bulbo  


![Imagem Lâmpada Led](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/lampada.png)

**Protoboard**

A protoboard permite montar circuitos eletrônicos de forma muito simples, já que não requer soldagem nos contatos.
São 100 pontos de distribuição e 300 pontos de conexão terminal. Possui coordenadas coloridas para facilitar a visualização.

*Especificações técnicas*
   
Furos: 400  
Material: Plástico ABS  
Para terminais e condutores de 0,3 a 0,8 mm (20 a 29 AWG)  
Resistência de Isolamento: 100MO min.  
Tensão Máxima: 500v AC por minuto  
Faixa de Temperatura: -20 a 80°C  
Dimensões: 8,3 x 5,5 x 1,0 cm


![Imagem Protoboard](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/protoboard.png)


**Módulo GY-30 Sensor de Luminosidade - BH1750FVI**

O Sensor de Luz BH1750FVI é capaz de medir a intensidade da luz em lux na faixa de 1 a 65535 lx, sendo ideal para aplicação em sistemas de controle de iluminação automático ou apenas circuitos para medição da luz ambiente nos mais diversos tipos de projetos robóticos ou de automação residencial.

*Especificações técnicas*

Modelo: GY-30
Tensão de alimentação: 3V a 5V
Interface: Serial I2C
Resposta: próxima à do olho humano
Resolução: 1lx (lux)
- Faixa de medição: 1 ~ 65535lx
- Baixa variação de medição: +/- 20%

![Imagem Módulo GY-30](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/img_hardware/modulo_gy30.png)

## Esquema Eletrônico

![alt text](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/Circuito_Estufa.png)
