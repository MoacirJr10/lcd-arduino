## Flappy LCD Game (Arduino + Joystick + LCD 16x2)

Um projeto simples para estudantes e entusiastas que estão aprendendo a utilizar o Arduino.

Este jogo é uma versão textual do Flappy Bird, utilizando um Arduino Uno, um joystick analógico e
um display LCD 16x2. Ideal para quem deseja praticar lógica, eletrônica básica e programação em C++ no Arduino.

## Objetivo

Desvie dos obstáculos utilizando o joystick para controlar a posição do personagem (>) no display LCD.

## Componentes

1x Arduino Uno
1x LCD 16x2
1x Joystick analógico
1x Potenciômetro 10kΩ
1x Resistor 220Ω (para o backlight do LCD)
1x Protoboard
Jumpers (cabos de conexão)

## Simulação no Tinkercad

Você pode simular este projeto no Tinkercad Circuits utilizando os seguintes nomes:

## Item Nome no Tinkercad

Arduino UNO Arduino Uno R3
LCD 16x2 LCD (16x2)
Potenciômetro 10kΩ Rotary Potentiometer
Joystick analógico Joystick
Resistor 220Ω Resistor
Protoboard Breadboard
Cabos Wire ou Breadboard wire

# 🔌 Conexões do Circuito

## 📱 LCD 16x2 com Potenciômetro

```mermaid
graph LR
    subgraph "LCD 16x2"
        L1[1 - VSS]
        L2[2 - VDD]
        L3[3 - VO]
        L4[4 - RS]
        L5[5 - RW]
        L6[6 - E]
        L11[11 - D4]
        L12[12 - D5]
        L13[13 - D6]
        L14[14 - D7]
        L15[15 - LED+]
        L16[16 - LED-]
    end
    
    subgraph "Arduino"
        D2[D2]
        D3[D3]
        D4[D4]
        D5[D5]
        D11[D11]
        D12[D12]
        GND1[GND]
        V5V1[5V]
    end
    
    subgraph "Potenciômetro"
        POT[Pino Central]
    end
    
    L1 --> GND1
    L2 --> V5V1
    L3 --> POT
    L4 --> D12
    L5 --> GND1
    L6 --> D11
    L11 --> D5
    L12 --> D4
    L13 --> D3
    L14 --> D2
    L15 --> RES[Resistor 220 ohms]
    RES --> V5V1
    L16 --> GND1
```

### 📋 Tabela de Conexões - LCD

| Pino LCD | Nome | Conexão |
|----------|------|---------|
| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | VO | Pino central do potenciômetro |
| 4 | RS | Arduino D12 |
| 5 | RW | GND |
| 6 | E | Arduino D11 |
| 11 | D4 | Arduino D5 |
| 12 | D5 | Arduino D4 |
| 13 | D6 | Arduino D3 |
| 14 | D7 | Arduino D2 |
| 15 | LED+ | 5V (com resistor 220Ω) |
| 16 | LED- | GND |

---

## 🎛️ Potenciômetro (Contraste LCD)

```mermaid
graph TD
    subgraph "Potenciômetro"
        PE[Pino Esquerdo]
        PC[Pino Central]
        PD[Pino Direito]
    end
    
    PE --> GND2[GND]
    PD --> V5V2[5V]
    PC --> LCD3[LCD Pino 3 - VO]
```

### 📋 Tabela de Conexões - Potenciômetro

| Pino | Conexão |
|------|---------|
| Esquerdo | GND |
| Central | LCD Pino 3 (VO) |
| Direito | 5V |

---

## 🕹️ Joystick Analógico

```mermaid
graph LR
    subgraph "Joystick"
        JG[GND]
        JV[+5V]
        JY[VRy]
        JX[VRx]
        JS[SW]
    end
    
    subgraph "Arduino"
        GND3[GND]
        V5V3[5V]
        A1[A1]
        NC1[Não Conectado]
        NC2[Opcional]
    end
    
    JG --> GND3
    JV --> V5V3
    JY --> A1
    JX -.-> NC1
    JS -.-> NC2
```

### 📋 Tabela de Conexões - Joystick

| Pino Joystick | Conexão Arduino | Status |
|---------------|-----------------|--------|
| GND | GND | ✅ Conectado |
| +5V | 5V | ✅ Conectado |
| VRy | A1 | ✅ Conectado |
| VRx | - | ❌ Não utilizado |
| SW | - | ⚠️ Opcional |

---

## ⚡ Resumo das Conexões

### Alimentação
- **5V** → LCD VDD, LCD LED+ (via resistor), Potenciômetro (direito), Joystick +5V
- **GND** → LCD VSS, LCD RW, LCD LED-, Potenciômetro (esquerdo), Joystick GND

### Sinais Digitais
- **D2** → LCD D7
- **D3** → LCD D6  
- **D4** → LCD D5
- **D5** → LCD D4
- **D11** → LCD E (Enable)
- **D12** → LCD RS (Register Select)

### Sinais Analógicos
- **A1** → Joystick VRy (Eixo Y)

### Controle
- **Potenciômetro Central** → LCD VO (Contraste)

## Código

O código completo do jogo está no arquivo: `lcd_flappy/lcd_flappy.ino`


## Abrir os jogos

Cada sketch está em pasta própria: `lcd_flappy/lcd_flappy.ino` ou `doom/doom.ino`. Abra apenas um por vez na IDE Arduino. O diagrama acima é do Flappy; o Doom possui controles próprios e deve ser testado separadamente.
