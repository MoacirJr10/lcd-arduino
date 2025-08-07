#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define JOY_Y A1

int playerPos = 0; 
int obstaclePos = 15;
int obstacleLine = 0; 

bool gameOver = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(JOY_Y, INPUT);
  randomSeed(analogRead(A0)); // Para gerar obstáculos aleatórios
  lcd.print("Pronto!");
  delay(2000);
}

void loop() {
  if (gameOver) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("GAME OVER!");
    delay(2000);
    resetGame();
    return;
  }

  // Leitura do joystick (eixo Y)
  int yVal = analogRead(JOY_Y);
  if (yVal < 400) {
    playerPos = 0; // Linha de cima
  } else if (yVal > 600) {
    playerPos = 1; // Linha de baixo
  }

  // Verifica colisão
  if (obstaclePos == 0 && obstacleLine == playerPos) {
    gameOver = true;
  }

  
  lcd.clear();

  // Desenha o jogador
  lcd.setCursor(0, playerPos);
  lcd.print(">");

  // Desenha obstáculo
  if (obstaclePos > 0) {
    lcd.setCursor(obstaclePos, obstacleLine);
    lcd.print("#");
    obstaclePos--;
  } else {
    obstaclePos = 15;
    obstacleLine = random(0, 2); // Nova linha aleatória
  }

  delay(300);
}

void resetGame() {
  playerPos = 0;
  obstaclePos = 15;
  obstacleLine = 0;
  gameOver = false;
}
