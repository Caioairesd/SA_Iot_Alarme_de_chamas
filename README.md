# 📘 Sistema Detector de Chamas com Arduino -- Projeto IoT

Este projeto consiste em um sistema de detecção de chamas utilizando o
sensor **KY-026**, integrado a um **Arduino Uno**, com alerta visual,
sonoro e feedback no **display LCD I2C**.

Desenvolvido como parte da Situação de Aprendizagem (SA) de **Internet
das Coisas (IoT)** do curso Técnico em Desenvolvimento de Sistemas --
SENAI.

------------------------------------------------------------------------

## 👥 Integrantes

-   **Caio Aires**
-   **Caio Battisti** 

------------------------------------------------------------------------

## Resumo do Projeto

O sistema detecta a presença de chamas através do sensor **KY-026**,
acionando automaticamente:

-   🚨 **Buzzer (alarme sonoro)**
-   💡 **LED vermelho (alerta visual)**
-   📟 **Display LCD 16x2 I2C** exibindo alerta de perigo

Também há um **botão de reset**, responsável por desativar o alarme e
retornar o sistema ao estado inicial.

------------------------------------------------------------------------

## Componentes Utilizados

-   Arduino UNO
-   Sensor de chama KY-026
-   Display LCD 16x2 + módulo I2C
-   Buzzer
-   Botão
-   LED vermelho
-   Protoboard
-   Jumpers

------------------------------------------------------------------------

## Funcionamento do Sistema

1.  O sensor KY-026 monitora continuamente a presença de fogo (radiação
    infravermelha).
2.  Quando o fogo é detectado:
    -   LED acende
    -   Buzzer toca intermitentemente
    -   LCD exibe mensagem de alerta
3.  O alarme permanece ativo até que o botão seja pressionado.
4.  Após o reset, o sistema volta ao modo de monitoramento.

------------------------------------------------------------------------

## 🔁 Fluxo Lógico do Sistema

    [Monitorando] → [Chama detectada?]
             ↓ Não                     ↓ Sim
    [Continua monitorando]     [Ativa LED + Buzzer + LCD]
                                       ↓
                         [Botão de Reset pressionado?]
                               ↓ Sim             ↓ Não
                         [Desativa Alarme]   [Mantém Alerta]
                                       ↓
                                [Retorna ao início]

------------------------------------------------------------------------

## 🖼️ Imagens do Projeto

### 📌 Maquete física do projeto

![Maquete do Projeto](Imagens/Maquete.jpeg)

------------------------------------------------------------------------

### 📌 Diagrama do circuito (LCD + Módulo I2C)

![Painel LCD com Módulo
I2C](Imagens/Diagrama.jpg)

------------------------------------------------------------------------

## 🧪 Como Executar o Projeto

1.  Realize a montagem do circuito conforme o diagrama.
2.  Faça upload do código para o Arduino usando a IDE.
3.  Ligue o sistema.
4.  Aproxime uma chama do sensor para testar o detector.
5.  Após ativado, pressione o botão para resetar o alarme.

------------------------------------------------------------------------

## 💾 Versionamento

Este repositório possui commits simulando a evolução natural do projeto:

-   Estrutura inicial
-   Declaração de pinos
-   Primeira leitura do sensor
-   LED de alerta
-   Buzzer
-   Implementação do botão
-   Integração do LCD
-   Versão final com debounce, mensagens e lógica completa

------------------------------------------------------------------------

## 📚 Tecnologias Utilizadas

-   Arduino IDE
-   Linguagem C/C++
-   Biblioteca **LiquidCrystal_I2C**
-   Sensor **KY-026**

------------------------------------------------------------------------

## 📄 Licença

Este projeto está sob a licença MIT --- utilização livre.
