/* PROJETO ESTUFA - SMART LIGHT
 *  Giovanni Vicario
 *  Marco Vallim
 *  Suelen Maia
 *  5K 
 */


/* Declaração de Libraries - Início *********************************************************/

#include <math.h>
#include <Wire.h>
#include <BH1750.h>
#include <SPI.h>
#include <Ethernet.h>

/* Declaração de Libraries - Fim ************************************************************/

/* Declaração de Macros para economizar memória - Início ************************************************************/

#define MAC_PORTA_SERVER_IOT 3035
#define MAC_MAX_TAM_JSON 100
#define MAC_MAX_TAM_VAL_SENSOR 6
#define MAC_INTENSIDADE_LUX "IoTPLLux"
#define MAC_MODO_FUNC_SIS "IoTPLModo"


/* Declaração de Macros - Fim ***************************************************************/

// Variáveis de Rede
byte b_mac[] = {0x00, 0xAB, 0xCB, 0xCD, 0xDE, 0x02};

IPAddress ip_server(201,6,243,44);
//IPAddress ip_server(172,16,39,12);

EthernetClient ec_arduino_client;


/* Declaração de Variáveis Globais - Início *************************************************/

// Sensor de luminosidade -> GY-30
BH1750 vg_sensor_lux;

//Pino digital responsável pelo chaveamento do TRIAC (Dimmer Shield)
int vg_i_triac_load = 3;

// Potência em porcentagem da Lâmpada (atuador) -> incializar com zero
volatile int vg_vi_atuador_power = 0;


/* Declaração de Variáveis Globais - Fim ****************************************************/

/* Declaração de Funções - Início ***********************************************************/

//Função quando o Dimmer detecta a passagem por zero da tensão alternada (senóide)
//Função de interrupção quando a tensão = 0 é identificada
void fn_zero_cross_int()
{

  // Declaração de variáveis
  int i_tempo_triac_off;

  
  //Frequência: 60Hz -> 8,33ms (meio ciclo) (1 ciclo = 1/60 = 16,66 ms)
  //Assim: (8333us - 8,33us) / 100 = 83 (aproximadamente) - Realização de conversão numérica

  //i_tempo_triac_off -> o tempo que o TRIAC permanece desligado quando é detectado
  //o ponto 0 -> senóide e varia de 0 a 8300 microsegundos
  i_tempo_triac_off = (83 * (100 - vg_vi_atuador_power));


  //Se a pausa for menor ou igual a 1 ms, vai dar o comando de ligar a lâmpada -> potência total fornecida
  if (i_tempo_triac_off <= 1000)
  {
    //Liga o pulso do sinal ao TRIAC para que ele passe a conduzir, coloca o
    //pino digital "vg_i_triac_load" em nível alto
    digitalWrite(vg_i_triac_load, HIGH);
  }

  //Se a pausa for maior ou igual a 8000 microsegundos, dar o comando de desligar a lâmpada (carga) - potência zero fornecida
  else if (i_tempo_triac_off >= 8000)
  {
    //Desliga o pulso do sinal ao TRIAC para que ele não conduza, coloca o pino
    //digital "vg_i_triac_load" em nível baixo
    digitalWrite(vg_i_triac_load, LOW);
  }

  //Se a pausa estiver entre 1000 microsegundos e 8000 microsegundos
  else if ((i_tempo_triac_off > 1000) && (i_tempo_triac_off < 8000))
  {
    //Mantém o circuito desligado por (i_tempo_triac_off) microssegundos
    delayMicroseconds(i_tempo_triac_off);
  
    //Envia sinal ao TRIAC para que ele passe a conduzir, coloca o pino digital "vg_i_triac_load" em nível alto para passar a conduzir
    digitalWrite(vg_i_triac_load, HIGH);
  
    //Espera 8 microssegundos para que o TRIAC perceba o pulso
    delayMicroseconds(8);

    //Desliga o pulso do TRIAC, coloca o pino digital "vg_i_triac_load" em nível baixo
    digitalWrite(vg_i_triac_load, LOW);
  }
}



// Função que realiza a leitura dos valores dos sensores no servidor
double fn_coleta_valor_iot_server(String fn_in_nome_sensor)
{
  // Declaração de Variáveis
  bool b_flag_sensor_encontrado;
  bool b_flag_realizar_leitura;
  bool b_flag_ler_json;
  int i;
  int j;
  int k;
  int i_conta_aspas;
  char c_char_leitura;
  char c_vet_json[MAC_MAX_TAM_JSON];
  char c_vet_num_valor_sensor[MAC_MAX_TAM_VAL_SENSOR];
  double d_valor_sensor;
  String s_solicita_valor_iot_server;

  // Inicialização de Variáveis
  b_flag_sensor_encontrado = 0;
  b_flag_realizar_leitura = 0;
  b_flag_ler_json = 0;
  i = 0;
  j = 0;
  k = 0;
  i_conta_aspas = 0;
  d_valor_sensor = 0.00;

  s_solicita_valor_iot_server = String("GET /api/dump/sensor/");
  s_solicita_valor_iot_server = String(s_solicita_valor_iot_server + fn_in_nome_sensor);
  s_solicita_valor_iot_server = String(s_solicita_valor_iot_server + "/1");
  

  // Inicia Conexão com o Servidor
  if (ec_arduino_client.connect(ip_server, MAC_PORTA_SERVER_IOT)) 
  {
    Serial.println();
    Serial.println("CONECTADO ao Servidor!");
    Serial.println();

    // Solicita ao server o valor do sensor necessário
      ec_arduino_client.println(s_solicita_valor_iot_server);
      ec_arduino_client.println("Connection: close");
      ec_arduino_client.println();
      b_flag_sensor_encontrado = 1;
      b_flag_realizar_leitura = 1;
    

    // Realizar a leitura dos dados do servidor até a desconexão
    while (b_flag_realizar_leitura == 1)
    {
      // Se houver dados para leitura, realizar a leitura
      if (ec_arduino_client.available()) 
      {
        c_char_leitura = ec_arduino_client.read();
        //Serial.print(c_char_leitura);

        // Caso o caracter for "[" inicializa a leitura do JSON
        if(c_char_leitura == 91)
        {
          b_flag_ler_json = 1;
        }
        
        //Caso o caracter for "]" finaliza a leitura do JSON
        else if (c_char_leitura == 93)  
        {
          b_flag_ler_json = 0;
          c_vet_json[j] = 93;
          c_vet_json[j+1] = '\0';
        }

        // Leitura do JSON
        if(b_flag_ler_json == 1)
        {
          c_vet_json[j] = c_char_leitura;
          j++;
        }
      }

      // Caso a conexão termine indica a não realização da leitura
      if (!ec_arduino_client.connected()) 
      {
        b_flag_realizar_leitura = 0;
      }
    }

    // Finaliza a conexão com o servidor
    Serial.println();
    Serial.println("Desconectado do servidor IoT...");
    Serial.println();
    ec_arduino_client.stop();

    // Tratamento do JSON lido para a extração apenas do valor do sensor (double)
    for(i = 0; c_vet_json[i] != '\0'; i++)
    {
      if(c_vet_json[i] == 34)
      {
        i_conta_aspas++;
      }
      
      if(i_conta_aspas == 7)
      {
        if(c_vet_json[i] != 34)
        {
          if(k < MAC_MAX_TAM_VAL_SENSOR)
          {
            c_vet_num_valor_sensor[k] = c_vet_json[i];
            c_vet_num_valor_sensor[k+1] = '\0';
            k++;
          }
          else
          {
            break;
          }
        }
      }
    }
  }

  // Conversão do valor lido em char para double
  d_valor_sensor = (double)atof(c_vet_num_valor_sensor);
        

  // Retorno da função
  return(d_valor_sensor);

}

/* Declaração de Funções - Fim **************************************************************/


/* Setup Step - Início **********************************************************************/

void setup()
{

  // Inicialização da comunicação Serial
  Serial.begin(9600);

  // Inicialização da Rede Ethernet
  Serial.print("Configurando Rede LAN ... ");
  Ethernet.begin(b_mac);
  
  // Inicialização do I2C (Protocolo de Comunicação)
  Wire.begin();

  // Inicialização do Sensor de Luminosidade
  vg_sensor_lux.begin();

  
  // Inicializar pinos
  pinMode(vg_i_triac_load, OUTPUT);

  // Interrupção
  attachInterrupt(0, fn_zero_cross_int, RISING);

  
}

/* Setup Step - Fim *************************************************************************/



/* Loop Step - Início ***********************************************************************/

void loop()
{
  
  // Declaração de Variáveis
  int i_valor_sensor_lux;
  int i_valor_sensor_modo;
  uint16_t ui16_lux_medido;
  double d_lux_medido_pct;


  // Leitura dos valores do modo de funcionamento do sistema e da intensidade da luz no modo manual
  i_valor_sensor_modo = (int)fn_coleta_valor_iot_server(MAC_MODO_FUNC_SIS);
  i_valor_sensor_lux = (int)fn_coleta_valor_iot_server(MAC_INTENSIDADE_LUX);


  Serial.println(" ");
  Serial.print("Valor Sensor Modo: ");
  Serial.print(i_valor_sensor_modo);
  Serial.println(" ");
  Serial.print("Valor Sensor LUX: ");
  Serial.print(i_valor_sensor_lux); 


  

  // Realiza medição do valor da luminosidade
  ui16_lux_medido = vg_sensor_lux.readLightLevel();

  // Para o modo automático gera o valor da intensidade da lampada
  if (i_valor_sensor_modo == 1)
  {
    vg_vi_atuador_power = map(ui16_lux_medido, 0, 65535, 100, 0);
  }
  else if(i_valor_sensor_modo == 0)
  {
    vg_vi_atuador_power = i_valor_sensor_lux;
  }
  else
  {
    Serial.println();
    Serial.println("Modo de funcionamento invalido...");
  }


  // Delay
  delay(1000);

}

/* Loop Step - Fim **************************************************************************/



























