# Especificação de Hardware - Estufa Inteligente.

## Lista de Peças

Para esse projeto, foram utilizados os componentes descritos a seguir.

**Arduino UNO R3**

O Arduino Uno R3 é a placa Arduino mais vendida e usada atualmente. Costuma ser a primeira opção de muitos, pois apresenta uma ótima quantidade de portas disponíveis e grande compatibilidade com os Shields Arduino.

![alt text](oic_iot_mackenzie-projeto-5K/docs/img_hardware/arduinoR3.png)

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

(imagem)

**Ethernet Shield W5100**

O Ethernet Shield W5100 permite que uma placa Arduino conecte-se a internet. É baseado no chip ethernet da WIZnet ethernet W5100 que fornece acesso à rede (IP) nos protocolos TCP ou UDP e é facilmente utilizado usando a biblioteca Ethernet Library e SD Library. Este shield suporta até quatro conexões de socket simultâneas. É compatível com o Arduino UNO R3.
(imagem)

**Lâmpada**

(imagem)

**Protoboard**

400 pontos.

(imagem)

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

(imagem)

## Esquema Eletrônico

![alt text](https://github.com/KitoVallim/oic_iot_mackenzie-projeto-5K/blob/master/docs/Circuito_Estufa.png)
